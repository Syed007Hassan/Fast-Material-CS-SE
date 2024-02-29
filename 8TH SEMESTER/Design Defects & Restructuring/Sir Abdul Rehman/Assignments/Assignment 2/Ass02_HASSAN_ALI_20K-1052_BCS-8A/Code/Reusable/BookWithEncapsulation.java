package DDR.assignment2.Reusable;

class Customer {
  boolean hasLicense;
  boolean hasPaidFees;
  boolean hasBookedCar;

  Customer() {
    hasLicense = true;
    hasPaidFees = true;
    hasBookedCar = false;
  }

  boolean canBook(Car car) {
    return hasLicense && hasPaidFees && !car.isBooked;
  }

  void book(Car car) {
    if (canBook(car)) {
      hasBookedCar = true;
      car.isBooked = true;
    }
  }
}

class Car {
  boolean isBooked;
}

class CarBooking {

  // Encapsulation: The internal state of the Customer and Car classes is hidden
  // from the CarBooking class.

  void bookCar(Customer customer, Car car) {
    customer.book(car);
    System.out.println("Car booked: " + car.isBooked);
  }
}

public class BookWithEncapsulation {
  public static void main(String[] args) {
    Customer customer = new Customer();
    Car car = new Car();
    CarBooking carBooking = new CarBooking();
    carBooking.bookCar(customer, car);
  }
}
