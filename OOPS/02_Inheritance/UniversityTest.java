//! Static class can be called without creating an object of the class.
//! Final method cannot be overridden by subclasses.

class person {
  String name;
  int age;

  person(String name, int age) {
    this.name = name;
    this.age = age;
  }

  void displayInfo() {
    System.out.println("Name: " + name);
    System.out.println("Age: " + age);
  }

  void work() {
    System.out.println(name + " is working.");
  }

  static void showrole() {
    System.out.println("Person is a human being.");
  }

  final void uniqueid() {
    System.out.println("This is a unique ID method and cannot be overridden.");
  }
}

class student extends person {
  int rollNo;
  String course;

  student(String name, int age, int rollNo, String course) {
    super(name, age);
    this.rollNo = rollNo;
    this.course = course;
  }

  void work() {
    super.work();
    System.out.println(name + " is studying " + course + ".");

  }

  void displayInfo() {
    super.displayInfo();
    System.out.println("Roll No: " + rollNo);
    System.out.println("Course: " + course);
  }

  void study() {
    System.out.println(name + " is studying.");
  }

  static void showrole() {
    System.out.println("Student is a learner.");
  }

}

class professor extends person {
  String department;
  double salary;

  professor(String name, int age, String department, double salary) {
    super(name, age);
    this.department = department;
    this.salary = salary;
  }

  void work() {
    super.work();
    System.out.println(name + " is teaching in the " + department + " department.");
  }

  void displayInfo() {
    super.displayInfo();
    System.out.println("Department: " + department);
    System.out.println("Salary: ₹" + salary);
  }

  void teach() {
    System.out.println(name + " is teaching.");
  }

  static void showrole() {
    System.out.println("Professor is an educator.");
  }
}

public class UniversityTest {
  public static void main(String[] args) {
    System.out.println("--- Student Details ---");

    person p = new person("Vishal", 22);
    p.displayInfo();
    p.work();
    person.showrole();
    p.uniqueid();
    System.out.println();
    System.out.println();

    student s = new student("Aman", 20, 101, "Computer Science");
    s.displayInfo();
    s.work();
    s.study();
    student.showrole();
    s.uniqueid();
    System.out.println();
    System.out.println();

    System.out.println("--- Professor Details ---");
    professor prof = new professor("Dr. Sharma", 45, "Mathematics", 75000.0);
    prof.displayInfo();
    prof.work();
    prof.teach();
    professor.showrole();
    prof.uniqueid();
    System.out.println();

  }
}
