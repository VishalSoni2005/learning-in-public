# Deep Learning Practical 5 — Complete Theory, Code Explanation, and Viva Preparation

## 1. Practical Overview

**Title:** CBOW (Continuous Bag of Words) using a neural network

**Objective:** Implement a CBOW neural network that learns word-context relationships from a text corpus, trains on context-target pairs, and predicts a word from given context words.

The notebook uses:
- Python and NumPy for text processing and numerical operations.
- TensorFlow/Keras for building and training the neural network.
- Matplotlib for plotting training loss and accuracy.
- A small sample text to train the CBOW model.

The model predicts a target word using the words surrounding it.

## 2. Prerequisite Theory

### 2.1 Natural Language Processing (NLP)

Natural Language Processing is a branch of Artificial Intelligence that enables computers to process, analyze, and understand human language.

Examples:
- Chatbots and virtual assistants
- Machine translation
- Sentiment analysis
- Text summarization
- Next-word prediction
- Search engines

Computers cannot directly process words such as `"apple"` or `"learning"` as numerical mathematical inputs. Text is therefore converted into numerical representations. This is called **text vectorization**.

### 2.2 Corpus, Token, and Vocabulary

| Term | Meaning | Example |
|---|---|---|
| Corpus | Collection of text used for training | Several sentences |
| Token | Individual text unit, usually a word | `"learning"` |
| Tokenization | Splitting text into tokens | `"Deep learning"` → `["Deep", "learning"]` |
| Vocabulary | Set of unique tokens | `["deep", "learning"]` |
| Vocabulary size | Number of unique tokens | `V = 2` |

The notebook's sample text is:

```text
The quick brown fox jumps over the lazy dog.
The fox is quick and the dog is lazy.
Machine learning is a part of artificial intelligence.
Deep learning is a part of machine learning.
Artificial intelligence is changing the world.
```

After lowercasing and splitting, the notebook initially obtains 40 word tokens. After punctuation removal and deduplication for the vocabulary, it obtains 20 unique words.

- Total tokens: 40
- Unique words: 20

A word may appear many times in the corpus but only once in the vocabulary.

### 2.3 Deep Learning

Deep Learning is a subset of Machine Learning that uses neural networks with layers of interconnected mathematical units called neurons.

A neuron receives numerical inputs, calculates a weighted sum, applies an activation function, and produces an output.

\[
z = \sum_{i=1}^{n} w_i x_i + b
\]

\[
a = f(z)
\]

Where:
- \(x_i\): input values
- \(w_i\): learned weights
- \(b\): bias
- \(f\): activation function
- \(a\): neuron output

During training, the network adjusts its weights and biases to reduce prediction errors.

### 2.4 Word2Vec

Word2Vec is a family of neural-network-based methods used to learn dense vector representations of words, commonly called **word embeddings**.

It has two main architectures:

**CBOW — Continuous Bag of Words**
- Uses surrounding context words to predict the target word.
- Example: context words → target word.

**Skip-gram**
- Uses the target word to predict surrounding context words.
- Example: target word → context words.

| CBOW | Skip-gram |
|---|---|
| Context → Target | Target → Context |
| Predicts one target from multiple context words | Predicts surrounding words from one target |
| Often efficient for frequent words | Often useful for learning representations of less frequent words |

The practical implements CBOW, not Skip-gram.

**Important distinction:** This is a simplified CBOW implementation with an averaged context vector and a dense neural network. It demonstrates the core learning idea, but does not implement every detail of the original Word2Vec algorithm.

## 3. One-Hot Encoding

A neural network cannot directly use text words as input. One simple method to represent words numerically is **one-hot encoding**.

Suppose the vocabulary is:

```python
vocab = ["cat", "dog", "fox", "quick", "the"]
```

Each word gets an index:

| Word | Index | One-hot vector |
|---|---:|---|
| cat | 0 | `[1, 0, 0, 0, 0]` |
| dog | 1 | `[0, 1, 0, 0, 0]` |
| fox | 2 | `[0, 0, 1, 0, 0]` |
| quick | 3 | `[0, 0, 0, 1, 0]` |
| the | 4 | `[0, 0, 0, 0, 1]` |

Each vector contains a `1` at the word's index and `0` everywhere else.

\[
\text{One-hot vector dimension} = V
\]

In this practical, the vocabulary size is 20, so an individual word's one-hot vector has 20 elements.

**Limitation:** One-hot vectors are sparse and do not directly express semantic similarity. For example, `"cat"` and `"dog"` have the same distance from each other as `"cat"` and `"artificial"` in a basic one-hot representation.

The practical averages multiple context-word vectors to construct the CBOW input.

## 4. CBOW Architecture

Consider this sentence:

> The quick brown fox jumps over the lazy dog.

Suppose the target word is `"brown"` and the context window size is 2.

- Left context: `"The"`, `"quick"`
- Target: `"brown"`
- Right context: `"fox"`, `"jumps"`

The CBOW model uses the four context words to predict `"brown"`.

### Architecture flow

```text
Context words
(The, quick, fox, jumps)
          |
          v
Average context vectors
          |
          v
Hidden Dense layer
50 neurons, ReLU
          |
          v
Output Dense layer
20 neurons, softmax
          |
          v
Predicted target word
```

The expected target is `"brown"` because that is the word selected from the original sentence. The model may predict another word if it has not learned the relationship accurately.

### 4.1 Context Window Size

In the notebook:

```python
window_size = 2
```

This means two words on the left and two words on the right of the target.

\[
\text{Context words} = 2 \times \text{window size} = 4
\]

For a sequence containing \(N\) tokens:

\[
\text{Training examples} = N - 2w
\]

where \(w\) is the window size, assuming one continuous token sequence and no sentence-boundary handling.

For this practical:

\[
40 - (2 \times 2) = 36
\]

So, the expected number of training examples is 36.

### 4.2 Why Is It Called a “Bag of Words”?

The model averages context vectors rather than preserving their order. The words `"quick"` and `"fox"` contribute to the representation, but their individual positions are not explicitly represented.

For example, these sets have the same averaged representation:

```text
["quick", "fox"]
["fox", "quick"]
```

That is the meaning of “bag of words” in CBOW.

## 5. Neural Network Mathematics

The model contains an input representation, a hidden dense layer, and an output dense layer.

### 5.1 Input Vector

Each context word contributes to a vector of vocabulary size 20. The four context vectors are added and averaged.

\[
\mathbf{x} = \frac{1}{4}\sum_{i=1}^{4}\mathbf{v}_i
\]

Here, \(\mathbf{v}_i\) represents the one-hot vector of a context word. The resulting input vector has 20 elements.

### 5.2 Hidden Layer

The model uses 50 neurons with the ReLU activation function.

\[
\mathbf{h} = \operatorname{ReLU}(\mathbf{x}W_1 + \mathbf{b}_1)
\]

- Input: 20 values
- Hidden layer: 50 values
- Weight matrix \(W_1\): \(20 \times 50\)

ReLU is defined as:

\[
\operatorname{ReLU}(z) = \max(0,z)
\]

It outputs zero for negative inputs and returns positive inputs unchanged. It introduces nonlinearity into the model.

### 5.3 Output Layer

The second dense layer contains 20 neurons, one for each vocabulary word.

\[
\mathbf{z} = \mathbf{h}W_2 + \mathbf{b}_2
\]

The output layer applies softmax:

\[
P(y=i) = \frac{e^{z_i}}{\sum_{j=1}^{V}e^{z_j}}
\]

Softmax converts output scores into probabilities that sum to 1.

Example probabilities (illustrative only):

| Candidate word | Example probability |
|---|---:|
| brown | 0.62 |
| fox | 0.12 |
| quick | 0.10 |
| dog | 0.06 |
| Other words combined | 0.10 |
| Total | 1.00 |

The model predicts the word with the highest probability:

\[
\hat{y} = \arg\max_i P(y=i)
\]

## 6. Loss Function, Optimizer, and Training

### 6.1 Loss Function

A loss function measures how far the model's prediction is from the correct target.

The code uses:

```python
loss='categorical_crossentropy'
```

Categorical cross-entropy is suitable for multiclass classification when target labels are one-hot encoded.

\[
L = -\sum_{i=1}^{V} y_i \log(p_i)
\]

Where:
- \(y_i\): correct target's one-hot value
- \(p_i\): probability predicted for word \(i\)
- \(V\): vocabulary size

If the correct target is `"brown"`, the loss penalizes the model when it assigns a low probability to `"brown"`.

Generally, lower loss indicates better predictions on the evaluated examples.

### 6.2 Optimizer

The code uses:

```python
optimizer='adam'
```

Adam is an optimization algorithm that updates model parameters using gradient information. It adapts the effective learning rates of individual parameters based on estimates of gradients and squared gradients.

Its purpose is to reduce loss during training.

### 6.3 Epoch

An epoch is one complete pass through the training dataset.

```python
epochs=300
```

This means the model is trained for up to 300 epochs. An epoch does not mean one word or one training example.

### 6.4 Batch Size

The code uses:

```python
batch_size=16
```

A batch is a group of training examples processed together before a gradient update.

With 36 training examples, Keras ordinarily processes batches of 16, 16, and 4 per epoch, resulting in three batch updates per epoch.

### 6.5 Accuracy

The code uses:

```python
metrics=['accuracy']
```

Accuracy measures the proportion of examples for which the predicted class matches the correct class.

\[
\text{Accuracy} = \frac{\text{Correct predictions}}{\text{Total predictions}}
\]

Accuracy is useful for tracking progress, but it is not the same as loss. Loss can improve even when accuracy does not change immediately.

## 7. Complete Code Explanation, Cell by Cell

### Cell 1 — Import Libraries

```python
import numpy as np
import string
import tensorflow as tf
import matplotlib.pyplot as plt

from tensorflow.keras.models import Sequential
from tensorflow.keras.layers import Dense
from tensorflow.keras.utils import to_categorical
from numpy.linalg import norm
```

| Code | Purpose |
|---|---|
| `numpy as np` | Creates arrays and performs numerical operations. |
| `string` | Provides punctuation characters such as `.`, `,`, and `!`. |
| `tensorflow as tf` | Imports the TensorFlow framework. |
| `matplotlib.pyplot as plt` | Creates graphs. |
| `Sequential` | Builds a neural network by stacking layers. |
| `Dense` | Creates a fully connected neural network layer. |
| `to_categorical` | Converts integer class labels into one-hot encoded labels. |
| `norm` | Calculates vector norms; it is not used in the shown notebook. |

**Viva point:** TensorFlow is the deep learning framework, Keras provides the high-level model-building interface, and NumPy handles numerical operations.

### Cell 2 — Sample Text and Tokenization

```python
text = """
The quick brown fox jumps over the lazy dog.
The fox is quick and the dog is lazy.
Machine learning is a part of artificial intelligence.
Deep learning is a part of machine learning.
Artificial intelligence is changing the world.
"""

words = text.lower().split()

print("Total words:", len(words))
print("Words:")
print(words)
```

`text.lower()` converts all text to lowercase.

Example:

```text
"Artificial Intelligence" → "artificial intelligence"
```

`split()` splits a string on whitespace by default.

```python
"the quick brown fox".split()
```

Output:

```python
['the', 'quick', 'brown', 'fox']
```

The printed total is 40 because the notebook's text contains 40 whitespace-separated tokens, including punctuation attached to some words.

### Cell 3 — Remove Punctuation

```python
import string

words = [
    word.strip(string.punctuation)
    for word in words
]

words = [word for word in words if word]

print("Cleaned words:")
print(words)
```

For example:

```python
word = "dog."
word.strip(string.punctuation)
```

Output:

```python
'dog'
```

`strip()` removes punctuation characters from the beginning and end of a string. It does not remove punctuation from the middle of a word.

The second list comprehension removes empty strings:

```python
words = [word for word in words if word]
```

This means retain a word only if it is nonempty.

**Why clean text?** Without cleaning, `"dog"` and `"dog."` might be treated as two separate vocabulary entries.

### Cell 4 — Create Vocabulary and Word Indexes

```python
vocab = sorted(set(words))

vocab_size = len(vocab)

word_to_index = {word: i for i, word in enumerate(vocab)}

index_to_word = {i: word for i, word in enumerate(vocab)}

print("Vocabulary Size:", vocab_size)
print("\nVocabulary:")
print(vocab)
```

`set(words)` removes duplicates. `sorted()` sorts the unique vocabulary alphabetically.

`enumerate()` associates each word with an index:

```python
list(enumerate(["cat", "dog", "fox"]))
```

Output:

```python
[(0, 'cat'), (1, 'dog'), (2, 'fox')]
```

The dictionaries map words to numbers and numbers back to words:

```python
word_to_index = {
    word: i for i, word in enumerate(vocab)
}
```

```python
index_to_word = {
    i: word for i, word in enumerate(vocab)
}
```

For example, if `"brown"` has index 3:

```python
word_to_index["brown"]  # 3
index_to_word[3]        # "brown"
```

The exact index depends on the sorted vocabulary.

### Cell 5 — Generate Training Examples

This is the **most important cell** because it converts text into the examples used to train CBOW.

```python
window_size = 2

X = []
y = []

for i in range(window_size, len(words) - window_size):

    context_words = (
        words[i-window_size:i] +
        words[i+1:i+window_size+1]
    )

    target_word = words[i]

    context_vector = np.zeros(vocab_size)

    for word in context_words:
        context_vector[word_to_index[word]] += 1

    context_vector = context_vector / len(context_words)

    target_index = word_to_index[target_word]

    X.append(context_vector)
    y.append(target_index)

X = np.array(X)
y = np.array(y)

y = to_categorical(y, num_classes=vocab_size)

print("Input shape:", X.shape)
print("Target shape:", y.shape)
```

**Part A — Initialize lists**

```python
X = []
y = []
```

- `X` stores input context vectors.
- `y` stores correct target words as integer indices initially.

**Part B — Slide the window**

```python
for i in range(window_size, len(words) - window_size):
```

With a window size of 2, the loop begins at index 2 and stops before the final two tokens. Each target therefore has two tokens on its left and two on its right.

**Part C — Extract context words**

```python
context_words = (
    words[i-window_size:i] +
    words[i+1:i+window_size+1]
)
```

For:

```python
words = ["the", "quick", "brown", "fox", "jumps"]
```

At index `i = 2`, the target is `"brown"`.

```python
words[0:2]  # ['the', 'quick']
words[3:5]  # ['fox', 'jumps']
```

Combined context:

```python
['the', 'quick', 'fox', 'jumps']
```

The right-side slice skips the target word so the answer is not included in the input.

**Part D — Create the context vector**

```python
context_vector = np.zeros(vocab_size)
```

For a vocabulary of 20 words, this creates a vector of 20 zeros.

```python
for word in context_words:
    context_vector[word_to_index[word]] += 1
```

Each context word increments the value at its vocabulary index.

**Part E — Average the vector**

```python
context_vector = context_vector / len(context_words)
```

With four context words, each of four distinct words contributes `0.25` at its index.

**Part F — Store the target**

```python
target_index = word_to_index[target_word]

X.append(context_vector)
y.append(target_index)
```

The context vector is the input; the target word's integer index is the correct answer.

**Part G — Convert lists to arrays**

```python
X = np.array(X)
y = np.array(y)
```

**Part H — One-hot encode the target**

```python
y = to_categorical(y, num_classes=vocab_size)
```

Each target becomes a 20-element vector with one value equal to 1 and all other values equal to 0.

Expected shapes:

```text
Input shape:  (36, 20)
Target shape: (36, 20)
```

Interpretation:
- 36 training examples
- 20 input features per example
- 20 possible target classes

### Cell 6 — Display Training Examples

```python
print("Number of training examples:", len(X))

for i in range(min(5, len(X))):
    print("\nExample", i + 1)
    print("Input vector:", X[i])
    print("Target word:", index_to_word[np.argmax(y[i])])
```

`min(5, len(X))` prints no more than five examples.

`np.argmax(y[i])` finds the index of the largest value in the one-hot target vector.

```python
target = [0, 0, 1, 0, 0]
np.argmax(target)
```

Output:

```text
2
```

`index_to_word[2]` then retrieves the actual target word.

### Cell 7 — Build and Compile the Model

```python
model = Sequential([
    Dense(50, input_shape=(vocab_size,), activation='relu'),
    Dense(vocab_size, activation='softmax')
])

model.compile(
    optimizer='adam',
    loss='categorical_crossentropy',
    metrics=['accuracy']
)

model.summary()
```

**First layer**

```python
Dense(50, input_shape=(vocab_size,), activation='relu')
```

- 50 neurons
- 20 input features
- ReLU activation
- Learns combinations of context features

**Second layer**

```python
Dense(vocab_size, activation='softmax')
```

- 20 output neurons
- One output for each vocabulary word
- Softmax produces a probability distribution

**Model compilation**

This configures the optimizer, loss function, and performance metric.

The notebook reports 2,070 trainable parameters:

| Layer | Calculation | Parameters |
|---|---|---:|
| Hidden layer | \(20 \times 50 + 50\) biases | 1,050 |
| Output layer | \(50 \times 20 + 20\) biases | 1,020 |
| **Total** | \(1,050 + 1,020\) | **2,070** |

Biases are trainable parameters, just like weights.

### Cell 8 — Train the Model

```python
history = model.fit(
    X, y, epochs=300, batch_size=16, verbose=1
)
```

- `X`: input context vectors
- `y`: correct target labels
- `epochs=300`: up to 300 complete passes through the training data
- `batch_size=16`: up to 16 examples per batch
- `verbose=1`: display training progress
- `history`: stores metrics for each epoch

During training, the model:
1. Takes a context vector as input.
2. Computes hidden-layer activations.
3. Produces output probabilities.
4. Calculates categorical cross-entropy loss.
5. Uses backpropagation to calculate gradients.
6. Uses Adam to update weights.
7. Repeats over the dataset and epochs.

### Cell 9 — Plot Loss and Accuracy

```python
import matplotlib.pyplot as plt

plt.figure(figsize=(8, 5))
plt.plot(history.history['loss'])
plt.xlabel("Epoch")
plt.ylabel("Loss")
plt.title("CBOW Training Loss")
plt.show()

plt.figure(figsize=(8, 5))
plt.plot(history.history['accuracy'])
plt.xlabel("Epoch")
plt.ylabel("Accuracy")
plt.title("CBOW Training Accuracy")
plt.show()
```

`history.history['loss']` stores the loss at each epoch. `history.history['accuracy']` stores training accuracy.

Interpretation:
- Decreasing loss generally indicates that the model is learning the training examples.
- Increasing accuracy generally indicates that more training targets are being predicted correctly.
- Neither curve alone proves generalization to unseen text. A separate validation or test dataset is needed for that.

### Cell 10 — Create the Prediction Function

```python
def predict_word(context_words):

    context_vector = np.zeros(vocab_size)

    for word in context_words:
        if word in word_to_index:
            context_vector[word_to_index[word]] += 1

    context_vector = context_vector / len(context_words)

    prediction = model.predict(
        np.array([context_vector]),
        verbose=0
    )

    predicted_index = np.argmax(prediction)

    return index_to_word[predicted_index]
```

This function accepts context words and returns the vocabulary word with the highest predicted probability.

Steps:
1. Create a zero vector of vocabulary size.
2. Convert recognized context words into vocabulary-indexed counts.
3. Average the vector.
4. Pass the vector into the trained model.
5. Find the output class with the largest probability.
6. Convert the predicted index back into a word.

`np.array([context_vector])` adds a batch dimension. Keras expects a batch of examples even when predicting for just one example.

**Implementation detail:** This version checks whether a word exists in the vocabulary to avoid a `KeyError`. For robust handling, the function should also reject empty contexts and define how unknown words affect the averaging denominator.

### Cell 11 — Test the Prediction

```python
context = ["fox", "and", "the", "is"]

predicted_word = predict_word(context)

print("Context words:", context)
print("Predicted word:", predicted_word)
```

The model processes the supplied context and selects the most probable word from the vocabulary.

The PDF shows `"quick"` as the predicted word for this example. Because the corpus is tiny, this is a demonstration rather than a reliable language prediction. Different random initialization or training runs may produce a different answer.

## 8. Complete Practical Workflow

```text
Sample text corpus
        ↓
Lowercase and tokenize
        ↓
Remove punctuation
        ↓
Build vocabulary and indexes
        ↓
Generate context-target pairs
        ↓
Average context vectors
        ↓
One-hot encode target words
        ↓
Build Dense neural network
        ↓
Compile with Adam and cross-entropy
        ↓
Train for 300 epochs
        ↓
Plot loss and accuracy
        ↓
Predict a word from context
```

**Sequence to memorize:** Text → Tokens → Vocabulary → Context vectors → Neural network → Training → Prediction.

## 9. Important Limitations

1. **Small dataset:** The corpus contains only 40 tokens and 20 unique words. It cannot teach the model broad language patterns.
2. **Sentence boundaries:** The notebook tokenizes the complete text as one sequence, so some training windows may include words from neighboring sentences. A more robust implementation would create windows separately for each sentence.
3. **Bag-of-words limitation:** Averaging context vectors removes positional information.
4. **Training and evaluation:** Training progress is measured on the same examples used to fit the model. There is no separate validation or test dataset.
5. **Word embeddings:** The hidden layer has 50 neurons, but the notebook does not explicitly extract and evaluate a learned embedding matrix as a separate output.
6. **Random initialization:** Results may vary between runs unless random seeds are controlled.
7. **Prediction vocabulary:** The function selects a word from the existing vocabulary and cannot generate a completely new word outside it.

## 10. Viva Questions and Answers

### Q1. What is the aim of Practical 5?
To implement a CBOW neural network that predicts a target word from its surrounding context words.

### Q2. What is CBOW?
Continuous Bag of Words is a Word2Vec architecture that uses surrounding context words to predict the target word.

### Q3. What is the difference between CBOW and Skip-gram?
CBOW predicts the target from context; Skip-gram predicts context words from the target.

### Q4. What is a vocabulary?
The collection of unique tokens identified in the training corpus.

### Q5. Why do we use lowercase conversion?
To avoid treating uppercase and lowercase versions of the same word as separate tokens.

### Q6. Why is punctuation removed?
To reduce unwanted differences between tokens such as `"dog"` and `"dog."`.

### Q7. What is one-hot encoding?
A numerical representation in which one position is 1 and all other positions are 0.

### Q8. What is the context window size in this practical?
2 on each side of the target, giving four context words in total.

### Q9. Why is the number of training examples 36?
There are 40 tokens and a window size of 2, so \(40 - 2 \times 2 = 36\) examples.

### Q10. Why is the input shape `(36, 20)`?
There are 36 examples, each represented by a vector of length 20.

### Q11. Why is the target shape `(36, 20)`?
There are 36 target labels, each one-hot encoded across 20 possible vocabulary classes.

### Q12. Why is ReLU used?
ReLU introduces nonlinearity and returns \(\max(0,x)\).

### Q13. Why is softmax used?
It converts output scores into probabilities across the vocabulary classes.

### Q14. Why use categorical cross-entropy?
It measures prediction error for multiclass classification with one-hot target labels.

### Q15. What is Adam?
An optimizer that adapts parameter updates using estimates of gradients and squared gradients.

### Q16. What is an epoch?
One complete pass through the training dataset.

### Q17. What does `batch_size=16` mean?
The model processes up to 16 training examples per batch before updating its parameters.

### Q18. What is the purpose of `model.summary()`?
It displays model layers, output shapes, and parameter counts.

### Q19. Why plot loss and accuracy?
To observe how training error and classification performance change across epochs.

### Q20. What does `np.argmax()` do?
It returns the index of the largest value, identifying the most probable output class.

### Q21. Why do we need `index_to_word`?
It converts the predicted numerical class index back into a readable word.

### Q22. What is the main limitation of this practical?
The dataset is extremely small, so the trained model demonstrates the method rather than reliable language understanding.

## 11. How to Prepare for the Practical

1. **Understand the objective:** CBOW predicts a target word from surrounding context.
2. **Practice preprocessing:** Write tokenization, punctuation removal, vocabulary, and indexing code without notes.
3. **Master training-data generation:** Understand why the context excludes the target, why vectors are averaged, and why there are 36 examples.
4. **Memorize the architecture:** Input size 20; hidden layer 50 neurons with ReLU; output size 20 with softmax.
5. **Understand training:** Explain Adam, categorical cross-entropy, epochs, batch size, loss, and accuracy.
6. **Run the notebook:** Check shapes, model summary, training graphs, and prediction.
7. **Practice viva questions:** Answer each question aloud in your own words.

## 12. Quick Revision Sheet

| Item | Value |
|---|---|
| Algorithm | CBOW |
| Total tokens | 40 |
| Vocabulary size | 20 |
| Context window | 2 words per side |
| Training examples | 36 |
| Input shape | `(36, 20)` |
| Target shape | `(36, 20)` |
| Hidden layer | 50 neurons, ReLU |
| Output layer | 20 neurons, softmax |
| Optimizer | Adam |
| Loss function | Categorical cross-entropy |
| Epochs | 300 |
| Batch size | 16 |
| Trainable parameters | 2,070 |

## Final Study Recommendation

Focus first on Cells 4–7, especially the context-window logic and neural network architecture. Those cells explain the core of the experiment. Once you understand them, training, plotting, and prediction become much easier to reproduce.
