//Abstract class defining the template method
abstract class ReportGenerator {
 // Template method defining the algorithm for generating a report
 public final void generateReport() {
     // Common steps for generating a report
     System.out.println("Generating report header...");
     generateTitle();
     generateEmployeeList();
     generateBody();
     generateFooter();
 }

 // Hook methods to be implemented by subclasses
 protected abstract void generateTitle();
 protected abstract void generateEmployeeList();
 protected abstract void generateBody();
 protected abstract void generateFooter();
}

//Concrete subclass implementing the template method for generating Attendance Report
class AttendanceReportGenerator extends ReportGenerator {
 // Concrete implementation of hook methods for Attendance Report
 @Override
 protected void generateTitle() {
     System.out.println("Attendance Report");
 }

 @Override
 protected void generateEmployeeList() {
     System.out.println("Employee List for Attendance Report:");
     // Code to retrieve and print employee list
 }

 @Override
 protected void generateBody() {
     System.out.println("Generating attendance data...");
     // Code to generate attendance data and print
 }

 @Override
 protected void generateFooter() {
     System.out.println("Attendance report generated successfully.");
 }
}

//Concrete subclass implementing the template method for Performance Report
class PerformanceReportGenerator extends ReportGenerator {
 // Concrete implementation of hook methods for Performance Report
 @Override
 protected void generateTitle() {
     System.out.println("Performance Report");
 }

 @Override
 protected void generateEmployeeList() {
     System.out.println("Employee List for Performance Report:");
     // Code to retrieve and print employee list
 }

 @Override
 protected void generateBody() {
     System.out.println("Generating performance data...");
     // Code to generate performance data and print
 }

 @Override
 protected void generateFooter() {
     System.out.println("Performance report generated successfully.");
 }
}

//Concrete subclass implementing the template method for Payroll Report
class PayrollReportGenerator extends ReportGenerator {
 // Concrete implementation of hook methods for Payroll Report
 @Override
 protected void generateTitle() {
     System.out.println("Payroll Report");
 }

 @Override
 protected void generateEmployeeList() {
     System.out.println("Employee List for Payroll Report:");
     // Code to retrieve and print employee list
 }

 @Override
 protected void generateBody() {
     System.out.println("Generating payroll data...");
     // Code to generate payroll data and print
 }

 @Override
 protected void generateFooter() {
     System.out.println("Payroll report generated successfully.");
 }
}

//Client code
public class main_4 {
 public static void main(String[] args) {
     // Generate Attendance Report
     System.out.println("Generating Attendance Report:");
     AttendanceReportGenerator attendanceReportGenerator = new AttendanceReportGenerator();
     attendanceReportGenerator.generateReport();
     System.out.println();

     // Generate Performance Report
     System.out.println("Generating Performance Report:");
     PerformanceReportGenerator performanceReportGenerator = new PerformanceReportGenerator();
     performanceReportGenerator.generateReport();
     System.out.println();

     // Generate Payroll Report
     System.out.println("Generating Payroll Report:");
     PayrollReportGenerator payrollReportGenerator = new PayrollReportGenerator();
     payrollReportGenerator.generateReport();
 }
}

