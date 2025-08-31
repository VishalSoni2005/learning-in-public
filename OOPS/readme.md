# 🚀 Switching from C++ → Java (OOP + Collections)

This guide is designed for a **C++ programmer** who wants to transition into **Java OOP** quickly and effectively, especially for placements and interviews.

---

## 🔑 Roadmap

### 1. Core Basics (Syntax Differences from C++)

- Hello World, class structure (`public static void main`).
- Data Types (no unsigned in Java).
- Input/Output (`Scanner`, `BufferedReader`).
- Arrays as objects (`int[] arr = new int[5];`).

👉 **Task:** Convert a simple C++ `for loop array sum` into Java.

---

### 2. Classes & Objects

- Class & Object creation (`new` keyword required).
- Constructors (default, parameterized).
- `this` keyword.
- Access Modifiers (`public`, `private`, `protected`, default).

👉 **Task:** Implement a `Car` class with fields, constructor, and a display method.

---

### 3. Inheritance & Polymorphism

- Inheritance using `extends`.
- Single & Multilevel inheritance.
- Method Overriding (`@Override`).
- Polymorphism: Overloading (compile-time) vs Overriding (runtime).

👉 **Task:** Make `Animal → Dog` hierarchy with overridden `speak()` method.

---

### 4. Abstraction & Encapsulation

- Encapsulation: private fields + getters/setters.
- Abstraction: Abstract classes & Interfaces.
- Interfaces = pure virtual classes (but stronger).

👉 **Task:** Implement `Shape` as an abstract class, `Circle` and `Square` as subclasses.

---

### 5. Special Java Features (vs C++)

- Garbage Collection (no destructors).
- `final` keyword (like const, but also prevents inheritance/overriding).
- Static keyword (variables, methods, blocks).
- Inner classes.
- Packages & Imports (like namespaces).

---

### 6. Object Class (Universal Parent)

Every class extends `Object` by default.

- Important methods: `toString()`, `equals()`, `hashCode()`, `clone()`, `finalize()`.

👉 **Task:** Override `toString()` in your class.

---

### 7. Exception Handling

- `try-catch-finally`.
- `throw`, `throws`.
- Custom exceptions (`extends Exception`).

👉 **Task:** Create a `BankAccount` class that throws an exception if balance < 0.

---

### 8. Java Collections Framework (STL Equivalent)

| **C++ STL**      | **Java Equivalent**      |
| ---------------- | ------------------------ |
| `vector`         | `ArrayList`              |
| `list`           | `LinkedList`             |
| `deque`          | `ArrayDeque`             |
| `stack`          | `Stack` / `Deque`        |
| `queue`          | `Queue`, `PriorityQueue` |
| `priority_queue` | `PriorityQueue`          |
| `set`            | `HashSet`, `TreeSet`     |
| `map`            | `HashMap`, `TreeMap`     |
| `unordered_map`  | `HashMap`                |
| `unordered_set`  | `HashSet`                |

Also:

- Iterators (`for-each`, `Iterator`).
- Generics (`ArrayList<Integer>`).
- `Collections` utility class (sorting, reversing).

👉 **Task:** Convert a C++ program using `vector + map` into Java using `ArrayList + HashMap`.

---

### 9. Advanced OOP & Interview Must-Know

- Abstract class vs Interface.
- Overloading vs Overriding.
- Shallow vs Deep copy (`clone()`).
- Immutability (`String`).
- Singleton Pattern.
- SOLID principles.

---

### 10. Java Extras for Placements

- Strings & `StringBuilder`.
- Enums.
- Annotations (`@Override`).
- Multithreading basics (`Thread`, `Runnable`).
- Streams API (Java 8).

---

## 📅 2-Week Curated Plan

- **Day 1–2:** Java syntax, input/output, classes/objects.
- **Day 3–4:** Constructors, `this`, `static`, `final`.
- **Day 5–6:** Inheritance, polymorphism, interfaces.
- **Day 7:** Abstraction, encapsulation.
- **Day 8:** Exception handling.
- **Day 9–10:** Collections (ArrayList, HashMap, LinkedList, Queue).
- **Day 11:** Object class methods, immutability, `StringBuilder`.
- **Day 12:** Singleton + Factory pattern.
- **Day 13:** Solve OOP coding problems in Java.
- **Day 14:** Revise + mock interviews.

---

# 💪 Final Challenge (Master OOP + Collections)

**Problem:** Design a **Mini Library Management System** in Java.

### Requirements

1. `Book` class with `id`, `title`, `author`, `isIssued`.
2. `Member` class with `id`, `name`, `issuedBooks`.
3. `Library` class that:
   - Stores all books (`HashMap<Integer, Book>`).
   - Stores all members (`HashMap<Integer, Member>`).
   - Allows adding new books/members.
   - Allows issuing & returning books.
   - Throws custom exception if:
     - Book is already issued.
     - Book not found.
     - Member not found.

### Skeleton Solution (Java)

```java
import java.util.*;

class Book {
    int id;
    String title;
    String author;
    boolean isIssued;

    Book(int id, String title, String author) {
        this.id = id;
        this.title = title;
        this.author = author;
        this.isIssued = false;
    }

    @Override
    public String toString() {
        return id + ": " + title + " by " + author + (isIssued ? " (Issued)" : " (Available)");
    }
}

class Member {
    int id;
    String name;
    List<Book> issuedBooks = new ArrayList<>();

    Member(int id, String name) {
        this.id = id;
        this.name = name;
    }
}

class LibraryException extends Exception {
    LibraryException(String message) {
        super(message);
    }
}

class Library {
    Map<Integer, Book> books = new HashMap<>();
    Map<Integer, Member> members = new HashMap<>();

    void addBook(Book b) { books.put(b.id, b); }
    void addMember(Member m) { members.put(m.id, m); }

    void issueBook(int bookId, int memberId) throws LibraryException {
        if (!books.containsKey(bookId)) throw new LibraryException("Book not found");
        if (!members.containsKey(memberId)) throw new LibraryException("Member not found");

        Book b = books.get(bookId);
        if (b.isIssued) throw new LibraryException("Book already issued");

        b.isIssued = true;
        members.get(memberId).issuedBooks.add(b);
    }

    void returnBook(int bookId, int memberId) throws LibraryException {
        if (!books.containsKey(bookId)) throw new LibraryException("Book not found");
        if (!members.containsKey(memberId)) throw new LibraryException("Member not found");

        Book b = books.get(bookId);
        Member m = members.get(memberId);

        if (!b.isIssued || !m.issuedBooks.contains(b)) throw new LibraryException("Book not issued to this member");

        b.isIssued = false;
        m.issuedBooks.remove(b);
    }

    void showBooks() { books.values().forEach(System.out::println); }
}

public class Main {
    public static void main(String[] args) {
        try {
            Library lib = new Library();
            lib.addBook(new Book(1, "1984", "Orwell"));
            lib.addBook(new Book(2, "Clean Code", "Martin"));

            lib.addMember(new Member(101, "Vishal"));

            lib.issueBook(1, 101);
            lib.showBooks();

            lib.returnBook(1, 101);
            lib.showBooks();
        } catch (LibraryException e) {
            System.out.println("Error: " + e.getMessage());
        }
    }
}
```

✅ This challenge tests:

- **Classes, Objects, Encapsulation** (Book, Member, Library).
- **Inheritance/Polymorphism** (could extend with different types of books/members).
- **Collections Framework** (`HashMap`, `ArrayList`).
- **Exception Handling** (custom exception).
- **Overriding `toString()`**.

Master this, and you’ll be confident with **Java OOP + Collections** 💯
