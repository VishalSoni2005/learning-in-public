# 🔬 Vector Search Laboratory

A small **terminal-based semantic search engine** built with **JavaScript**.

The goal of this project is to understand how **embeddings, vector similarity, semantic search, chunking, and vector databases** actually work — without hiding the concepts behind an LLM framework.

> **No UI. No LLM. No RAG framework. Just embeddings + vector search + ChromaDB.**

---

## 🎯 Project Goal

The purpose of this project is to build a simple vector search engine from the ground up and use it as a **laboratory for experimenting with embeddings and semantic search**.

Instead of searching for exact keywords, the application converts text into numerical vectors and searches for content that is **semantically similar**.

For example:

```text
Search:
"How do computers communicate with each other?"

Possible results:

→ "TCP/IP provides protocols for communication between devices."
→ "Networks allow computers to exchange information."
→ "The Internet connects millions of devices."
```

The search does not need to find the exact words from the query.

---

# 🏗️ Architecture

```text
                    ┌─────────────────┐
                    │   Terminal CLI   │
                    └────────┬────────┘
                             │
                ┌────────────┴────────────┐
                │                         │
             INDEX                      SEARCH
                │                         │
                ↓                         ↓
        ┌──────────────┐          ┌──────────────┐
        │ Text Loader  │          │ User Query   │
        └──────┬───────┘          └──────┬───────┘
               ↓                         ↓
        ┌──────────────┐          ┌──────────────┐
        │   Chunker    │          │   Embedding  │
        └──────┬───────┘          │     Model    │
               ↓                  └──────┬───────┘
        ┌──────────────┐                 │
        │  Embedding   │                 │
        │     Model    │                 │
        └──────┬───────┘                 │
               ↓                         │
        ┌────────────────────────────────┐
        │            ChromaDB            │
        │                                │
        │  Documents + Embeddings        │
        │  + Metadata                    │
        └───────────────┬────────────────┘
                        ↓
                Similarity Search
                        ↓
                Ranked Results
                        ↓
                 Terminal Output
```

---

# 🔄 How It Works

## 1. Indexing

The user provides a directory containing text documents:

```text
documents/
├── python.txt
├── databases.txt
├── networking.txt
├── machine-learning.txt
└── operating-systems.txt
```

The application:

```text
Documents
    ↓
Read text
    ↓
Split into chunks
    ↓
Generate embeddings
    ↓
Store vectors in ChromaDB
```

Each chunk becomes something conceptually similar to:

```text
{
  text: "TCP is a connection-oriented protocol...",
  embedding: [0.12, -0.43, 0.82, ...],
  metadata: {
    source: "networking.txt",
    chunkIndex: 4
  }
}
```

---

## 2. Searching

The user enters:

```bash
vec search "How do computers communicate?"
```

The query goes through the same embedding model:

```text
"How do computers communicate?"
              ↓
        Embedding Model
              ↓
     [0.14, -0.39, 0.79, ...]
```

ChromaDB compares this vector against the stored vectors and returns the closest matches.

```text
Query Vector
      │
      ↓
┌─────────────┐
│   ChromaDB  │
└──────┬──────┘
       │
       ├── Result 1 → similarity: 0.89
       ├── Result 2 → similarity: 0.84
       ├── Result 3 → similarity: 0.79
       └── Result 4 → similarity: 0.71
```

The results are displayed in the terminal.

---

# ✨ Features

### 📚 Document Indexing

Index a directory of text documents.

```bash
vec index ./documents
```

---

### 🔎 Semantic Search

Search using natural language rather than exact keywords.

```bash
vec search "how does a computer communicate over a network"
```

---

### 🔢 Top-K Retrieval

Control how many results are returned.

```bash
vec search "how does TCP work" --top-k 5
```

---

### 📊 Similarity Playground

Compare the semantic similarity between two pieces of text.

```bash
vec similarity "car" "automobile"
```

Example:

```text
Text 1: car
Text 2: automobile

Similarity: 0.82
```

You can experiment with:

```text
car ↔ automobile
king ↔ queen
python ↔ programming
python ↔ snake
car ↔ banana
```

---

### 🎚️ Similarity Threshold

Only return results above a specified similarity threshold.

```bash
vec search "quantum physics" --threshold 0.75
```

This helps explore the difference between:

> "This is the closest result."

and:

> "This result is actually relevant."

---

### 🧩 Chunking Experiments

Experiment with different chunk sizes.

```text
50 tokens
100 tokens
250 tokens
500 tokens
```

Then compare how chunk size affects search results.

---

### 🧠 Embedding Model Experiments

The project should make it easy to switch embedding models.

For example:

```text
Embedding Model A
       ↓
     Chroma
       ↓
    Search

Embedding Model B
       ↓
     Chroma
       ↓
    Search
```

Use the same documents and queries to compare retrieval quality.

---

### 📈 Vector Store Statistics

Display information about the current index.

```bash
vec stats
```

Example:

```text
Vector Search Laboratory
────────────────────────────

Documents:        12
Chunks:           184
Embedding Model:  all-MiniLM-L6-v2
Dimensions:       384
Distance Metric:  cosine
```

---

### 🔍 Document Inspection

Inspect how a document was divided into chunks.

```bash
vec inspect ./documents/networking.txt
```

Example:

```text
Document: networking.txt

Chunks: 8

────────────────────────

Chunk 1
TCP/IP is a collection of communication protocols...

Chunk 2
TCP provides reliable transmission...

Chunk 3
IP is responsible for addressing...
```

This makes it easier to understand how chunking affects retrieval.

---

# 🖥️ CLI

The project will eventually support commands such as:

```bash
# Index documents
vec index ./documents

# Search
vec search "how does TCP work"

# Search with top-k
vec search "how does TCP work" --top-k 5

# Search with threshold
vec search "database indexing" --threshold 0.75

# Compare two texts
vec similarity "car" "automobile"

# Inspect chunks
vec inspect ./documents/networking.txt

# Show vector store information
vec stats

# Show available embedding models
vec models

# Clear the vector database
vec clear
```

---

# 🧱 Technology Stack

The project will be built using JavaScript.

### Core

- **Node.js** — runtime
- **JavaScript** — application language
- **ChromaDB** — vector database
- **Embedding model** — converts text into vectors
- **CLI** — terminal interface

Possible supporting libraries:

```text
Node.js
├── CLI argument parser
├── File system utilities
├── Text chunking utilities
├── Embedding model client/library
└── ChromaDB client
```

The exact libraries can be chosen during implementation.

---

# 🧠 Concepts This Project Teaches

The main purpose of the project is learning, not building a production search engine.

By completing it, you should understand:

### Embeddings

```text
Text
 ↓
Embedding Model
 ↓
Vector
```

Why does:

```text
"car"
```

produce a vector that is relatively close to:

```text
"automobile"
```

while being farther from:

```text
"banana"
```

---

### Vector Dimensions

Understand concepts such as:

```text
384-dimensional vector
768-dimensional vector
1024-dimensional vector
```

and why the embedding model determines the vector dimension.

---

### Similarity

Learn how vectors can be compared using similarity/distance metrics such as:

```text
Cosine similarity
Euclidean distance
Dot product
```

---

### Semantic Search

Understand why:

```text
"How does a vehicle work?"
```

can retrieve information containing:

```text
"Automobiles use an engine to generate..."
```

even when the exact words don't match.

---

### Chunking

Understand how:

```text
Document
   ↓
Chunks
   ↓
Embeddings
   ↓
Vector Database
```

affects retrieval quality.

---

### Top-K Retrieval

Understand why searching for:

```text
top-k = 3
```

is different from:

```text
top-k = 10
```

and how retrieval ranking works.

---

### Similarity Thresholds

Understand why the nearest vector isn't necessarily a relevant vector.

---

### Vector Databases

Learn what ChromaDB actually does and what it **doesn't** do.

The embedding model creates the semantic representation.

ChromaDB stores and retrieves those representations.

---

# 🧪 Experiments

The project should be treated as a **vector-search laboratory**.

Some experiments to perform:

### Experiment 1 — Synonyms

```text
car
automobile
vehicle
```

Compare their similarity scores.

---

### Experiment 2 — Unrelated Concepts

```text
car
banana
quantum physics
football
```

Observe the differences.

---

### Experiment 3 — Sentence Similarity

```text
"The cat is sleeping on the sofa."

vs

"A cat is resting on a couch."
```

Compare their similarity.

---

### Experiment 4 — Chunk Size

Run the same queries using:

```text
50-token chunks
100-token chunks
250-token chunks
500-token chunks
```

Compare retrieval results.

---

### Experiment 5 — Top-K

Compare:

```text
top-k = 1
top-k = 3
top-k = 5
top-k = 10
```

---

### Experiment 6 — Embedding Models

Use multiple embedding models and compare their search results.

---

# 🚫 What This Project Does NOT Include

To keep the learning focused, the first version intentionally does **not** include:

- ❌ LLM integration
- ❌ Chatbot
- ❌ RAG generation
- ❌ OpenAI LLM API
- ❌ Groq LLM API
- ❌ Frontend
- ❌ Web UI
- ❌ LangChain
- ❌ LlamaIndex

The goal is to understand **vector search before adding generation**.

---

# 🗺️ Development Roadmap

## Phase 1 — Basic CLI

- [ ] Create Node.js project
- [ ] Build CLI
- [ ] Read text files
- [ ] Add basic commands

## Phase 2 — Chunking

- [ ] Implement basic chunking
- [ ] Add configurable chunk size
- [ ] Add document/chunk metadata
- [ ] Build `inspect` command

## Phase 3 — Embeddings

- [ ] Integrate an embedding model
- [ ] Generate embeddings
- [ ] Understand vector dimensions
- [ ] Add embedding model configuration

## Phase 4 — ChromaDB

- [ ] Connect to ChromaDB
- [ ] Store documents
- [ ] Store embeddings
- [ ] Store metadata
- [ ] Implement similarity search

## Phase 5 — Search

- [ ] Implement query embeddings
- [ ] Implement top-k retrieval
- [ ] Display similarity scores
- [ ] Add similarity threshold

## Phase 6 — Experiments

- [ ] Build similarity comparison
- [ ] Compare chunk sizes
- [ ] Compare embedding models
- [ ] Compare distance metrics where supported
- [ ] Document observations

## Phase 7 — Polish

- [ ] Add `stats`
- [ ] Add `models`
- [ ] Add `clear`
- [ ] Improve terminal output
- [ ] Add error handling
- [ ] Add tests

---

# 🔮 Future

Once the vector-search engine is well understood, it can become the foundation for a RAG system.

The future architecture could become:

```text
                 VECTOR SEARCH
                      │
                      ↓
                 Retrieved
                   Context
                      │
                      ↓
                     LLM
                      │
                      ↓
                    Answer
```

But **LLM integration is intentionally a future phase**.

The first goal is simple:

> **Understand vectors. Understand embeddings. Understand similarity. Understand retrieval.**

Once those concepts are solid, RAG becomes much easier to understand.

---

# 💡 Philosophy

This project is not about hiding complexity behind frameworks.

It's about asking questions like:

> Why did this document rank first?

> Why did this query retrieve this chunk?

> What happens when I change the chunk size?

> What happens when I change the embedding model?

> Why are these two sentences close in vector space?

> What does the similarity score actually mean?

> Why can the search return an irrelevant result?

The more experiments you perform, the better your intuition for embeddings and vector search will become.

---

## 🚀 Final Goal

Build a small CLI tool that can take:

```text
documents
```

and turn them into:

```text
embeddings
```

stored in:

```text
ChromaDB
```

and answer:

```text
"Which pieces of my data are semantically closest to this query?"
```

**No LLM required.**

Just vectors, similarity, retrieval, and experimentation.

---

## 📌 Project Status

🚧 **Learning Project — In Development**

Built with **JavaScript + Node.js + ChromaDB**.
