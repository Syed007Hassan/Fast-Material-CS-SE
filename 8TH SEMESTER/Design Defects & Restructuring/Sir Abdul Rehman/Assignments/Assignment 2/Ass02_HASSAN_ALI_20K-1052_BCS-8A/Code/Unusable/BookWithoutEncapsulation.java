package DDR.assignment2.Unusable;

class Customer {
  public boolean hasLicense;
  public boolean hasPaidFees;
  public boolean hasBookedCar;

  Customer() {
    hasLicense = true;
    hasPaidFees = true;
    hasBookedCar = false;
  }
}

class Car {
  public boolean isBooked;
}

class CarBooking {

  // Encapsulation: The internal state of the Customer and Car classes is not
  // hidden

  void bookCar(Customer customer, Car car) {
    if (customer.hasLicense && customer.hasPaidFees && !car.isBooked) {
      customer.hasBookedCar = true;
      car.isBooked = true;
    }
    System.out.println("Car booked: " + car.isBooked);
  }
}

public class BookWithoutEncapsulation {
  public static void main(String[] args) {
    Customer customer = new Customer();
    Car car = new Car();
    CarBooking carBooking = new CarBooking();
    carBooking.bookCar(customer, car);
  }
}