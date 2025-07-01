# 🚀 Compiler vs Interpreted vs JIT Languages

## 🔧 Compiler Language

Languages like **C**, **C++**, and **Go** are **compiled languages**.

### ✅ What happens?

The entire source code is **converted into machine (binary) code at once** by a **compiler** before execution. The result is an **executable file**.

### 🌀 Process

Source Code (.c) → [Compiler like gcc] → Machine Code (a.out / .exe) → Run

gcc hello.c # Compilation step
./a.out # Executable binary runs

## 🐍 Interpreted Language

Languages like Python, JavaScript, and Ruby are interpreted languages.

✅ What happens?
Code is executed line by line by an interpreter and runs immediately without compiling.

Source Code (.py) → [Interpreter] → Line-by-line Execution

## ⚡ Just-In-Time (JIT) Language

Languages like Java, C#, and modern JavaScript engines (e.g., Chrome's V8) use JIT compilation.

✅ What happens?
JIT compiles parts of the code on-the-fly during runtime, combining the benefits of both compilation and interpretation.

Source Code → [Interpreter + JIT Compiler] → Optimized Machine Code → Execution

javac Hello.java # Compile to bytecode
java Hello # JVM executes using JIT

| Feature          | Compiler Language (C)     | Interpreted Language (Python) | JIT Language (Java)         |
| ---------------- | ------------------------- | ----------------------------- | --------------------------- |
| Translation      | All at once before run    | Line-by-line during run       | Compiled during runtime     |
| Execution Speed  | Fast                      | Slower                        | Faster than interpreted     |
| Debugging        | After compilation         | Real-time (easier)            | Moderate                    |
| Compilation Step | Required                  | Not needed                    | Partial (runtime)           |
| Portability      | Platform-dependent binary | Platform-independent          | Platform-independent via VM |
| Examples         | C, C++, Go                | Python, JavaScript, Ruby      | Java, C#, Kotlin            |
