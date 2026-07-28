import os
from typing import List, Dict, Any, Tuple, Optional
from langchain_community.document_loaders import PyPDFLoader
from langchain_text_splitters import RecursiveCharacterTextSplitter
from langchain_huggingface import HuggingFaceEmbeddings, HuggingFacePipeline
from langchain_chroma import Chroma
from langchain_core.prompts import PromptTemplate
from langchain_core.documents import Document
from transformers import pipeline


DEFAULT_PDF_PATH = "/home/soni/Desktop/learning-in-public/Projects/data/Enabl3_Interview_Prep.pdf"
DEFAULT_EMBEDDING_MODEL = "sentence-transformers/all-MiniLM-L6-v2"
DEFAULT_LOCAL_LLM_MODEL = "google/flan-t5-base"


class RAGPipeline:
    def __init__(
        self,
        pdf_path: str = DEFAULT_PDF_PATH,
        chunk_size: int = 600,
        chunk_overlap: int = 100,
        k_retrieval: int = 4,
        llm_type: str = "Local (FLAN-T5)",
        api_key: Optional[str] = None
    ):
        self.pdf_path = pdf_path
        self.chunk_size = chunk_size
        self.chunk_overlap = chunk_overlap
        self.k_retrieval = k_retrieval
        self.llm_type = llm_type
        self.api_key = api_key
        
        self.embeddings = HuggingFaceEmbeddings(model_name=DEFAULT_EMBEDDING_MODEL)
        self.vector_store = None
        self.retriever = None
        self.llm = None
        
        self._initialize_vector_store()
        self._initialize_llm()

    def _initialize_vector_store(self):
        """Load PDF, split into chunks, and index into Chroma vector database."""
        if not os.path.exists(self.pdf_path):
            raise FileNotFoundError(f"PDF file not found at: {self.pdf_path}")
            
        loader = PyPDFLoader(self.pdf_path)
        pages = loader.load()

        splitter = RecursiveCharacterTextSplitter(
            chunk_size=self.chunk_size,
            chunk_overlap=self.chunk_overlap,
            separators=["\n\n", "\n", ".", " "]
        )
        self.chunks = splitter.split_documents(pages)

        # Create Chroma vector store in memory / persistent session
        self.vector_store = Chroma.from_documents(
            documents=self.chunks,
            embedding=self.embeddings,
            collection_name="rag_collection"
        )
        self.retriever = self.vector_store.as_retriever(
            search_kwargs={"k": self.k_retrieval}
        )

    def _initialize_llm(self):
        """Initialize the selected LLM (local HF pipeline or external cloud API)."""
        if self.llm_type == "Groq" and self.api_key:
            from langchain_groq import ChatGroq
            self.llm = ChatGroq(
                api_key=self.api_key,
                model_name="llama3-8b-8192",
                temperature=0.2
            )
        elif self.llm_type == "Google Gemini" and self.api_key:
            from langchain_google_genai import ChatGoogleGenerativeAI
            self.llm = ChatGoogleGenerativeAI(
                google_api_key=self.api_key,
                model="gemini-1.5-flash",
                temperature=0.2
            )
        else:
            # Default: Local HuggingFace Pipeline (google/flan-t5-base)
            pipe = pipeline(
                "text2text-generation",
                model=DEFAULT_LOCAL_LLM_MODEL,
                max_new_tokens=256,
                temperature=0.1
            )
            self.llm = HuggingFacePipeline(pipeline=pipe)

    def query(self, question: str) -> Dict[str, Any]:
        """Query the RAG pipeline with a question and return answer with source chunks."""
        # 1. Retrieve relevant context documents
        retrieved_docs: List[Document] = self.retriever.invoke(question)

        # 2. Format context text
        context_str = "\n\n---\n\n".join([doc.page_content for doc in retrieved_docs])

        # 3. Construct prompt
        prompt_template = """Use the following context snippets to answer the question at the end.
If you do not know the answer based on the context, state that clearly.

Context:
{context}

Question:
{question}

Answer:"""

        prompt = PromptTemplate.from_template(prompt_template)
        formatted_prompt = prompt.format(context=context_str, question=question)

        # 4. Generate answer using LLM
        response = self.llm.invoke(formatted_prompt)

        # Handle different output formats (Chat model vs Base LLM vs HuggingFacePipeline)
        if hasattr(response, "content"):
            answer_text = response.content
        elif isinstance(response, str):
            answer_text = response
        else:
            answer_text = str(response)

        return {
            "question": question,
            "answer": answer_text.strip(),
            "sources": retrieved_docs,
            "context": context_str
        }
