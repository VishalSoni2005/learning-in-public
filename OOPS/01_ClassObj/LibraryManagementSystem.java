import java.util.ArrayList;

class Book {
  // class attibutes
    private String bookId;
    private String title;
    private String author;
    private Boolean isAvailable;

    // Unparameterized constructor
    Book() {
        this.bookId = "NA";
        this.author = "NA";
        this.title = "NA";
        this.isAvailable = true;
    }

    // Parameterized constructor
    Book(String bookId, String title, String author) {
        this.bookId = bookId;
        this.title = title;
        this.author = author;
        this.isAvailable = true;
    }

    // Getters
    public String getBookId() {
        return this.bookId;
    }

    public String getBookTitle() {
        return this.title;
    }

    public String getBookAuthor() {
        return this.author;
    }

    public Boolean getBookisAvailablity() {
        return this.isAvailable;
    }

    // Setter
    public void setBookAvailablity(Boolean setStatus) {
        this.isAvailable = setStatus;
    }
}

class Library {
    private ArrayList<Book> bookList;

    Library() {
        this.bookList = new ArrayList<Book>();
    }

    public Boolean addBook(Book book) {
        if (book.getBookId() == null || book.getBookId().equals("NA")) {
            return false;
        }
        bookList.add(book);
        return true;
    }

    public void displayAvailableBooks() {
        if (bookList.isEmpty()) {
            System.out.println("The library is currently empty.");
            return;
        }

        System.out.println("\n--- Available Books ---");
        for (Book book : bookList) {
            if (book.getBookisAvailablity()) {
                System.out.println("ID: " + book.getBookId() + " | Title: " + book.getBookTitle() + " | Author: " + book.getBookAuthor());
            }
        }
    }

    public void borrowBook(String bookId) {
        for (Book book : bookList) {
            if (book.getBookId().equals(bookId)) {
                if (book.getBookisAvailablity()) {
                    book.setBookAvailablity(false);
                    System.out.println("Success: You checked out '" + book.getBookTitle() + "'");
                    return;
                } else {
                    System.out.println("Sorry, '" + book.getBookTitle() + "' is currently checked out.");
                    return;
                }
            }
        }
        System.out.println("Book with ID " + bookId + " not found.");
    }

    // Return Book Method
    public void returnBook(String bookId) {
        for (Book book : bookList) {
            if (book.getBookId().equals(bookId)) {
                book.setBookAvailablity(true);
                System.out.println("Success: '" + book.getBookTitle() + "' has been returned.");
                return;
            }
        }
        System.out.println("Book not found.");
    }
}

public class LibraryManagementSystem {
    public static void main(String[] args) {
        // 1. Instantiate Library
        Library myLibrary = new Library();

        // 2. Create and add books
        Book b1 = new Book("B001", "The Hobbit", "J.R.R. Tolkien");
        Book b2 = new Book("B002", "1984", "George Orwell");
        Book b3 = new Book("B003", "Clean Code", "Robert C. Martin");

        myLibrary.addBook(b1);
        myLibrary.addBook(b2);
        myLibrary.addBook(b3);

        // 3. Display initial available books
        myLibrary.displayAvailableBooks();

        // 4. Try borrowing a book
        System.out.println("\nTrying to borrow 1984...");
        myLibrary.borrowBook("B002");

        // Try borrowing it again to test availability check
        System.out.println("\nTrying to borrow 1984 again...");
        myLibrary.borrowBook("B002");

        // 5. Display books again (1984 should be missing)
        myLibrary.displayAvailableBooks();

        // 6. Return the book and check inventory again
        System.out.println("\nReturning 1984...");
        myLibrary.returnBook("B002");

        myLibrary.displayAvailableBooks();
    }
}
