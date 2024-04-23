//Employee class representing employee information
class Employee {
 private String name;
 private String position;
 private double hourlyRate;

 public Employee(String name, String position, double hourlyRate) {
     this.name = name;
     this.position = position;
     this.hourlyRate = hourlyRate;
 }

 public String getName() {
     return name;
 }

 public String getPosition() {
     return position;
 }

 public double getHourlyRate() {
     return hourlyRate;
 }
}

//AttendanceTracker class for tracking employee attendance
class AttendanceTracker {
 public void recordAttendance(String employeeId, int hoursWorked) {
     // Logic to record attendance
     System.out.println("Attendance recorded for employee ID: " + employeeId);
 }
}

//SalaryCalculator class for calculating employee salaries
class SalaryCalculator {
 public double calculateSalary(double hourlyRate, int hoursWorked) {
     return hourlyRate * hoursWorked;
 }
}

//ReportingSystem class for generating reports
class ReportingSystem {
 public void generateReport(String reportType) {
     // Logic to generate reports
     System.out.println("Generating " + reportType + " report...");
 }
}

//HRFacade class acting as a facade for HR managers
class HRFacade {
 private AttendanceTracker attendanceTracker;
 private SalaryCalculator salaryCalculator;
 private ReportingSystem reportingSystem;

 public HRFacade() {
     this.attendanceTracker = new AttendanceTracker();
     this.salaryCalculator = new SalaryCalculator();
     this.reportingSystem = new ReportingSystem();
 }

 public void recordAttendance(String employeeId, int hoursWorked) {
     attendanceTracker.recordAttendance(employeeId, hoursWorked);
 }

 public double calculateSalary(double hourlyRate, int hoursWorked) {
     return salaryCalculator.calculateSalary(hourlyRate, hoursWorked);
 }

 public void generateReport(String reportType) {
     reportingSystem.generateReport(reportType);
 }
}

//Client code
public class main_3 {
 public static void main(String[] args) {
     HRFacade hrFacade = new HRFacade();

     // HR managers can use the facade to interact with the subsystems
     hrFacade.recordAttendance("EMP001", 8);
     double salary = hrFacade.calculateSalary(30.0, 40);
     System.out.println("Calculated salary: $" + salary);
     hrFacade.generateReport("Attendance");
 }
}
