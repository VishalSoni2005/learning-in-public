# Python Mastery Roadmap → ML / Agentic AI / Deep Learning / FastAPI

Ranked by leverage: master Tier 0–1 before touching any domain library. Skipping ahead is why most people can copy-paste PyTorch/FastAPI code but can't debug it.

---

## Tier 0 — Non-Negotiable Foundations
*You cannot proceed without these. No exceptions.*

- [ ] **Syntax core**: variables, data types, operators, `if/elif/else`, `for`/`while`, `break`/`continue`/`else` on loops
- [ ] **Data structures**: list, tuple, dict, set — methods, slicing, comprehensions (list/dict/set), unpacking (`a, *b, c = x`)
- [ ] **Strings**: formatting (f-strings), common methods, encoding basics
- [ ] **Functions**: positional/keyword args, defaults, `*args`/`**kwargs`, return values, scope (LEGB rule)
- [ ] **Exception handling**: `try/except/else/finally`, exception hierarchy, catching specific vs bare `except`, raising custom exceptions, `raise from`
- [ ] **OOP fundamentals**:
  - Classes, `__init__`, `self`, instance vs class attributes
  - Inheritance, method overriding, `super()`
  - Encapsulation (`_protected`, `__private` name mangling), abstraction
  - Polymorphism, duck typing
  - Dunder/magic methods: `__str__`, `__repr__`, `__eq__`, `__len__`, `__iter__`, `__call__`
  - `@classmethod`, `@staticmethod`, `@property`
- [ ] **Modules & environment**: imports, packages, `pip`, virtual environments (`venv`), `requirements.txt`

**Why first:** every ML traceback, every FastAPI 500 error, every agent framework bug ultimately surfaces as a Python exception or an OOP misunderstanding (wrong `self`, mutable default arg, broken inheritance).

---

## Tier 1 — Core Professional Skills
*This is what separates "knows Python" from "professional Python developer."*

- [ ] **Memory model**: mutable vs immutable types, `is` vs `==`, object references, shallow vs deep copy, garbage collection basics, reference counting
- [ ] **Iterators & generators**: `__iter__`/`__next__`, `yield`, generator expressions, `itertools` (chain, groupby, product, etc.)
- [ ] **Decorators**: functions as first-class objects, closures, writing your own decorators, `functools.wraps`, decorators with arguments
- [ ] **Context managers**: `with` statement, `__enter__`/`__exit__`, `contextlib.contextmanager`
- [ ] **Type hints**: `typing` module, `Optional`, `Union`, `Callable`, generics; run `mypy` at least once
- [ ] **Concurrency model** (critical — this *is* how FastAPI and agent frameworks work internally):
  - The GIL and what it actually restricts
  - `threading` vs `multiprocessing` vs `asyncio` — when to use which
  - `async`/`await`, the event loop, coroutines, `asyncio.gather`
- [ ] **Dataclasses & Enum**: `@dataclass`, `Enum`, `auto()`
- [ ] **Functional tools**: `map`, `filter`, `reduce`, `functools.lru_cache`, `functools.partial`

**Why this tier matters for your goals:** FastAPI is async-native. Agentic AI frameworks (LangChain/LangGraph) lean heavily on async, generators (streaming tokens), and decorators (tool registration). Skipping this tier means you'll copy async code without understanding why it breaks.

---

## Tier 2 — Advanced Internals & Engineering Discipline
*Needed to write production-grade code, debug real systems, and read library source.*

- [ ] **Testing**: `pytest` (fixtures, parametrize, mocking with `unittest.mock`), basic TDD habit
- [ ] **Logging**: `logging` module (vs scattering `print` everywhere)
- [ ] **Debugging & profiling**: `pdb`/`breakpoint()`, `cProfile`, reading tracebacks fluently
- [ ] **Abstract Base Classes (ABCs)**: `abc` module, enforcing interfaces
- [ ] **Descriptors**: how `@property` actually works under the hood (deepens OOP understanding)
- [ ] **Design patterns in Python**: Singleton, Factory, Strategy, Observer — as they actually appear in real codebases, not textbook UML
- [ ] **Regex**: `re` module — pattern matching, groups, `search` vs `match` vs `findall`
- [ ] **HTTP & data interchange**: `requests`/`httpx`, JSON serialization, working with REST APIs
- [ ] **Config management**: `.env` files, `pydantic-settings` (this bridges directly into FastAPI)
- [ ] **Packaging**: `pyproject.toml`, building your own installable package, basics of `poetry`/`uv`

---

## Tier 3 — Domain Gateways (your actual destinations)
*Once Tier 0–2 are solid, these become fast to pick up — because you're learning a library's API, not fighting Python itself.*

**→ FastAPI / Backend**
- [ ] Pydantic models (v2) — validation, serialization
- [ ] Path/query/body params, dependency injection (`Depends`)
- [ ] Async endpoints, background tasks, middleware
- [ ] Auth: OAuth2, JWT
- [ ] SQLAlchemy (ORM) + async DB drivers, Alembic migrations

**→ Data Science / ML**
- [ ] NumPy (vectorization — understand *why* it's fast, ties back to Tier 1 memory model)
- [ ] Pandas (DataFrame ops, merging, groupby)
- [ ] Matplotlib/Seaborn for visualization
- [ ] scikit-learn: pipelines, model training/evaluation workflow

**→ Deep Learning**
- [ ] PyTorch (preferred for research/agentic work) or TensorFlow — tensors, autograd, `nn.Module`, training loops
- [ ] Understanding `nn.Module` deeply requires your OOP fundamentals (it's inheritance + `__call__` + state management)

**→ Agentic AI**
- [ ] LLM API basics (function/tool calling, structured outputs)
- [ ] LangChain / LangGraph — built on decorators, async, and generators (streaming)
- [ ] Vector databases & embeddings (conceptual + one library like FAISS/Chroma)
- [ ] Prompt orchestration patterns, agent loops, memory/state management

---

## Tier 4 — Good to Know / Polish
*High-value but not blocking. Pick up opportunistically.*

- [ ] Metaclasses (rarely needed day-to-day, but explains "magic" frameworks do)
- [ ] `asyncio` internals — event loop deep dive, writing custom awaitables
- [ ] Performance: Cython/C extensions, when Python isn't enough
- [ ] Docker (containerizing FastAPI/ML apps)
- [ ] Git workflows, CI/CD basics
- [ ] Security: input sanitization, secrets management, dependency vulnerability scanning
- [ ] Contributing to an open-source Python project

---

### Suggested sequencing
1. Tier 0 → build 3–4 small CLI projects using OOP + exception handling (e.g., a bank account simulator, an inventory system)
2. Tier 1 → build one project using `async`/generators (e.g., an async web scraper)
3. Tier 2 → add tests, logging, and packaging to an existing project
4. Tier 3 → split into parallel tracks based on which domain excites you most; FastAPI + a basic ML model deployed behind an API is a great capstone that touches everything
5. Tier 4 → absorb as needed while working on real projects
