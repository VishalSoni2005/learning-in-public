class Car {
  private int carId;
  private String brand;
  private double rentalPricePerDay;

  // Default Constructor
  Car() {
    this.carId = -1;
    this.brand = "Unknown";
    this.rentalPricePerDay = 0.0;
    System.out.println("Default constructor called for Car");
  }

  // Parameterized Constructor
  Car(int carId, String brand, double rentalPricePerDay) {
    this.carId = carId;
    this.brand = brand;
    this.rentalPricePerDay = rentalPricePerDay;
    System.out.println("Parameterized constructor called for Car " + carId);
  }

  // Display method
  public void displayDetails() {
    System.out.println("Car ID: " + carId + ", Brand: " + brand + ", Price/Day: ₹" + rentalPricePerDay);
  }

  // Destructor-like (called before GC clears object)
  @Override
  protected void finalize() throws Throwable {
    System.out.println("Car with ID " + carId + " is being removed from memory...");
  }
}

public class CarRental {
  public static void main(String[] args) {
    // Using default constructor
    Car c1 = new Car();

    // Using parameterized constructor
    Car c2 = new Car(101, "Toyota", 1500);
    Car c3 = new Car(102, "BMW", 3500);

    // Displaying details
    c1.displayDetails();
    c2.displayDetails();
    c3.displayDetails();

    // Make one object eligible for GC
    c2 = null;

    // Request Garbage Collector
    System.gc();

    System.out.println("Main method finished...");
  }
}

/*
 * * * Why is the"destructor"(finalize()) not always showing output?
 * This is because Java’s finalize() is not like C++ destructors.
 * 👉
 * 
 * The JVM (Garbage Collector) decides when or whether to call it.
 * 
 * System.gc() only suggests the JVM to run garbage collection.
 * 
 * The JVM is free to ignore that request.
 * 
 * Even if GC runs, it might not immediately destroy the object, so finalize()
 * may or may not run.
 * 
 * That’s why you see random behavior: sometimes the message prints, sometimes
 * not.
 * *
 */