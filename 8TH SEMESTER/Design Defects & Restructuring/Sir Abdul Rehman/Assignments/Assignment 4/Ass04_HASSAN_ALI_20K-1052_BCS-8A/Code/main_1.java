import java.util.ArrayList;
import java.util.List;

// Factory Pattern

// Employee interface
interface Employee {
    void displayInfo();
    double calculateSalary(int hoursWorked);
}

// Concrete implementations of employees
class FullTimeEmployee implements Employee {
    private String name;
    private String position;
    private double hourlyRate;

    public FullTimeEmployee(String name, String position, double hourlyRate) {
        this.name = name;
        this.position = position;
        this.hourlyRate = hourlyRate;
    }

    public void displayInfo() {
        System.out.println("Name: " + name);
        System.out.println("Position: " + position);
        System.out.println("Hourly Rate: $" + hourlyRate);
    }

    public double calculateSalary(int hoursWorked) {
        return hoursWorked * hourlyRate;
    }
}

class PartTimeEmployee implements Employee {
    private String name;
    private String position;
    private double hourlyRate;

    public PartTimeEmployee(String name, String position, double hourlyRate) {
        this.name = name;
        this.position = position;
        this.hourlyRate = hourlyRate;
    }

    public void displayInfo() {
        System.out.println("Name: " + name);
        System.out.println("Position: " + position);
        System.out.println("Hourly Rate: $" + hourlyRate);
    }

    public double calculateSalary(int hoursWorked) {
        return hoursWorked * hourlyRate;
    }
}

// Factory to create different types of employees
class EmployeeFactory {
    public static Employee createEmployee(String type, String name, String position, double hourlyRate) {
        switch (type) {
            case "FullTime":
                return new FullTimeEmployee(name, position, hourlyRate);
            case "PartTime":
                return new PartTimeEmployee(name, position, hourlyRate);
            default:
                throw new IllegalArgumentException("Invalid employee type: " + type);
        }
    }
}

// Attendance tracking class
class AttendanceTracker {
    public void trackAttendance(Employee employee, int hoursWorked) {
        System.out.println(employee.getClass().getSimpleName() + " " + employee.calculateSalary(hoursWorked));
    }
}

public class main_1 {
    public static void main(String[] args) {
        // Create employees using the factory
        Employee fullTimeEmployee = EmployeeFactory.createEmployee("FullTime", "John Doe", "Manager", 30.0);
        Employee partTimeEmployee = EmployeeFactory.createEmployee("PartTime", "Jane Smith", "Clerk", 15.0);

        // Display employee information
        System.out.println("Full-Time Employee Information:");
        fullTimeEmployee.displayInfo();

        System.out.println("\nPart-Time Employee Information:");
        partTimeEmployee.displayInfo();

        // Track attendance and calculate salary
        AttendanceTracker tracker = new AttendanceTracker();
        tracker.trackAttendance(fullTimeEmployee, 40); // Full-time employee worked 40 hours
        tracker.trackAttendance(partTimeEmployee, 20); // Part-time employee worked 20 hours
    }
}
