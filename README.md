# 🐍 Python Mastery Roadmap — 1 Week Intensive (3 hrs/day)

**Goal:** Build rock-solid Python fundamentals — syntax, conditional flow, functions, data structures, and OOP — before starting your **Trainee Decision Scientist** role at **Mu Sigma**. This is Week 1 of your 4-month prep window; once this base is clean, you move on to NumPy, Pandas, SQL, and stats/ML.

---

## 📊 Progress Tracker

| Day | Topic | Status |
|-----|-------|--------|
| 1 | Syntax, Variables & Data Types | ⬜ |
| 2 | Conditional Flow & Operators | ⬜ |
| 3 | Loops, Comprehensions & Strings | ⬜ |
| 4 | Functions & Scope | ⬜ |
| 5 | Data Structures Deep Dive | ⬜ |
| 6 | OOP Part 1 — Classes & Objects | ⬜ |
| 7 | OOP Part 2 + Exceptions + Mini Project | ⬜ |

> Tip: Change ⬜ to ✅ as you finish each day. Commit this file daily to a GitHub repo — it doubles as proof of consistency you can mention in interviews/appraisals.

---

## 🧭 How to Use This Roadmap

Each day = **3 focused hours**, split into 3 blocks:

| Block | Duration | Purpose |
|-------|----------|---------|
| 1. Concept Study | 60 min | Read/watch, take notes in your own words |
| 2. Hands-on Coding | 90 min | Type every example yourself — no copy-paste |
| 3. Practice & Recall | 30 min | Solve problems without looking at notes |

**Rules for the week:**
- Code in a Jupyter Notebook or VS Code — you'll use both at Mu Sigma.
- Keep a `notes.md` and a `practice.py` file per day in your repo.
- No tutorial-watching without typing code alongside it.
- End each day by writing 3 lines: *what I learned, what confused me, what I'll revisit.*

### 🛠️ Day 0 — Setup (30 min, do this before Day 1)
- [ ] Install [Python 3.12+](https://www.python.org/downloads/)
- [ ] Install [VS Code](https://code.visualstudio.com/) + Python extension
- [ ] Install [Anaconda](https://www.anaconda.com/download) or `pip install jupyter` (Jupyter is standard in DS roles)
- [ ] Create a virtual environment: `python -m venv venv`
- [ ] Create a GitHub repo called `python-mastery-week1`

---

## Day 1 — Syntax, Variables & Data Types

**Topics:** indentation rules, comments, variables & naming conventions, `print()`/`input()`, data types (`int`, `float`, `str`, `bool`, `complex`), type casting, `type()`, f-strings, PEP 8 basics.

**Resources:**
- [Python Official Docs — Intro](https://docs.python.org/3/tutorial/introduction.html)
- [Corey Schafer — Python Basics (YouTube)](https://www.youtube.com/watch?v=YYXdXT2l-Gg)
- [W3Schools Python Syntax](https://www.w3schools.com/python/python_syntax.asp)

**Practice:**
- [ ] [W3Schools Variables Exercises](https://www.w3schools.com/python/python_variables_exercises.asp)
- [ ] [HackerRank — Python Basics track](https://www.hackerrank.com/domains/python)
- [ ] Write a script that takes name, age, height as input and prints a formatted f-string bio.

**Checklist:**
- [ ] I can explain the difference between `=` and `==`
- [ ] I can explain mutable vs immutable types with an example
- [ ] I wrote 10+ small snippets without errors

---

## Day 2 — Conditional Flow & Operators

**Topics:** arithmetic/comparison/logical/bitwise/assignment operators, `if / elif / else`, nested conditionals, ternary expressions, `and/or/not`, truthy vs falsy values, `match-case` (Python 3.10+).

**Resources:**
- [Real Python — Conditional Statements](https://realpython.com/python-conditional-statements/)
- [Python Docs — More Control Flow](https://docs.python.org/3/tutorial/controlflow.html)
- [Programiz — if...else](https://www.programiz.com/python-programming/if-elif-else)

**Practice:**
- [ ] [HackerRank — Conditional Statements](https://www.hackerrank.com/challenges/py-if-else/problem)
- [ ] [Exercism Python Track](https://exercism.org/tracks/python) (do 3 conditional-flow exercises)
- [ ] Build a simple grading system (marks → grade) using `if/elif/else`, then rewrite it using `match-case`.

**Checklist:**
- [ ] I understand short-circuit evaluation
- [ ] I can write a one-line ternary expression
- [ ] I solved 5+ conditional logic problems unaided

---

## Day 3 — Loops, Comprehensions & Strings

**Topics:** `for` loop, `while` loop, `range()`, `break/continue/pass`, nested loops, list/dict/set comprehensions, string methods (`split`, `join`, `strip`, `format`, slicing), string immutability.

**Resources:**
- [Real Python — for Loops](https://realpython.com/python-for-loop/)
- [Real Python — List Comprehensions](https://realpython.com/list-comprehension-python/)
- [Corey Schafer — String Methods (YouTube)](https://www.youtube.com/watch?v=k9TUPpGqYTo)

**Practice:**
- [ ] [HackerRank — Loops](https://www.hackerrank.com/challenges/python-loops/problem)
- [ ] [LeetCode Easy — String problems](https://leetcode.com/problemset/?difficulty=EASY&topicSlugs=string)
- [ ] Print a pattern (pyramid of stars) using nested loops
- [ ] Convert a `for` loop that builds a list into a one-line list comprehension

**Checklist:**
- [ ] I can write a list comprehension with a condition (`[x for x in range(10) if x%2==0]`)
- [ ] I know when to use `while` vs `for`
- [ ] I can manipulate strings without looking up syntax

---

## Day 4 — Functions & Scope

**Topics:** `def`, parameters vs arguments, default/keyword/positional args, `*args`/`**kwargs`, return values, `lambda`, recursion, local vs global scope, `global`/`nonlocal`, docstrings, built-in functions (`map`, `filter`, `zip`, `enumerate`).

**Resources:**
- [Real Python — Defining Functions](https://realpython.com/defining-your-own-python-function/)
- [Python Docs — More on Defining Functions](https://docs.python.org/3/tutorial/controlflow.html#more-on-defining-functions)
- [Corey Schafer — *args and **kwargs (YouTube)](https://www.youtube.com/watch?v=gZB_ENJD34E)

**Practice:**
- [ ] [HackerRank — Functions](https://www.hackerrank.com/domains/python?filters%5Bsubdomains%5D%5B%5D=py-functionals)
- [ ] Write a recursive function (factorial or Fibonacci)
- [ ] Write a function using `*args`/`**kwargs` that accepts any number of numeric inputs and returns their sum and average
- [ ] Practice `map()`, `filter()`, and `lambda` on a list of numbers

**Checklist:**
- [ ] I can explain the difference between `*args` and `**kwargs`
- [ ] I can write a recursive function and trace its call stack
- [ ] I understand variable scope without printing to debug it

---

## Day 5 — Data Structures Deep Dive

**Topics:** lists (methods, slicing, sorting, nested lists), tuples (immutability, unpacking), dictionaries (methods, `.items()/.keys()/.values()`, nested dicts), sets (union/intersection/difference), choosing the right structure, basic file I/O (`open`, `read`, `write`, `with`).

**Resources:**
- [Python Docs — Data Structures](https://docs.python.org/3/tutorial/datastructures.html)
- [Real Python — Dictionaries](https://realpython.com/python-dicts/)
- [Corey Schafer — Sets (YouTube)](https://www.youtube.com/watch?v=sBvaPopWOmQ)

**Practice:**
- [ ] [HackerRank — Data Structures](https://www.hackerrank.com/domains/data-structures)
- [ ] Build a small "student database" using a list of dictionaries; write functions to add, search, and update records
- [ ] Read a `.txt` file and count word frequency using a dictionary
- [ ] [Exercism — Sets & Dicts exercises](https://exercism.org/tracks/python)

**Checklist:**
- [ ] I know when to use a tuple vs a list vs a set
- [ ] I can iterate over a dictionary and modify values conditionally
- [ ] I can read/write a file using a `with` block

---

## Day 6 — OOP Part 1: Classes & Objects

**Topics:** classes vs objects, `__init__`, `self`, instance vs class variables, methods, `__str__`/`__repr__`, encapsulation basics (public/protected/private via `_`/`__`), property decorators (`@property`).

**Resources:**
- [Real Python — OOP in Python 3](https://realpython.com/python3-object-oriented-programming/)
- [Corey Schafer — OOP Playlist (YouTube)](https://www.youtube.com/watch?v=ZDa-Z5JzLYM)
- [Python Docs — Classes](https://docs.python.org/3/tutorial/classes.html)

**Practice:**
- [ ] Build a `BankAccount` class with `deposit()`, `withdraw()`, and balance encapsulation
- [ ] Build a `Student` class with instance variables, a class variable (e.g., `school_name`), and a custom `__str__`
- [ ] [HackerRank — Classes](https://www.hackerrank.com/domains/python?filters%5Bsubdomains%5D%5B%5D=py-classes)

**Checklist:**
- [ ] I can explain `self` to someone who's never coded
- [ ] I know the difference between instance and class variables
- [ ] I used `@property` at least once

---

## Day 7 — OOP Part 2, Exceptions, Modules & Mini Project

**Topics:** inheritance (single & multiple), `super()`, method overriding, polymorphism, abstraction (`abc` module), magic/dunder methods (`__eq__`, `__len__`, `__add__`), `try/except/else/finally`, custom exceptions, importing modules & packages, intro to `pip` and virtual environments.

**Resources:**
- [Real Python — Inheritance and Composition](https://realpython.com/inheritance-composition-python/)
- [Real Python — Python Exceptions](https://realpython.com/python-exceptions/)
- [Corey Schafer — Custom Exceptions (YouTube)](https://www.youtube.com/watch?v=NIWwJbo-9_8)

**Practice:**
- [ ] Extend Day 6's `Student` class into `GraduateStudent` using inheritance and `super()`
- [ ] Add a custom exception (e.g., `InsufficientBalanceError`) to your `BankAccount` class from Day 6
- [ ] [HackerRank — Exceptions](https://www.hackerrank.com/challenges/exceptions/problem)

### 🎯 Mini Project (last 90 min of the week)
Build a **command-line Contact Book** that combines everything from the week:
- OOP: a `Contact` class and a `ContactBook` class
- Data structures: store contacts in a list of objects / dict
- File I/O: save/load contacts from a `.json` or `.txt` file
- Exception handling: handle invalid input, duplicate entries, missing contacts
- Functions: add, delete, search, update, list-all

Push this to your GitHub repo — it's a clean, demonstrable artifact of Week 1.

**Checklist:**
- [ ] I can explain polymorphism with a real example
- [ ] I can raise and catch a custom exception
- [ ] My mini project runs end-to-end without crashing

---

## 🚀 What's Next (Weeks 2+, aligned to Decision Scientist prep)

Once this base is solid, move toward the data science stack:
1. **NumPy** — arrays, broadcasting, vectorized operations
2. **Pandas** — DataFrames, groupby, merging, cleaning data
3. **Matplotlib / Seaborn** — data visualization
4. **SQL** — joins, aggregations, window functions (Mu Sigma is analytics-heavy)
5. **Statistics fundamentals** — descriptive stats, probability, hypothesis testing
6. **Intro to ML** — scikit-learn basics (regression, classification)

**General extra practice platforms:** [LeetCode](https://leetcode.com/), [HackerRank](https://www.hackerrank.com/), [Exercism](https://exercism.org/), [CodeWars](https://www.codewars.com/), [freeCodeCamp Python Course](https://www.freecodecamp.org/learn/scientific-computing-with-python/).

---

*Roadmap created for a 1-week, 3 hrs/day intensive Python foundation sprint. Stay consistent — the base you build this week is what everything else at Mu Sigma will sit on.*
