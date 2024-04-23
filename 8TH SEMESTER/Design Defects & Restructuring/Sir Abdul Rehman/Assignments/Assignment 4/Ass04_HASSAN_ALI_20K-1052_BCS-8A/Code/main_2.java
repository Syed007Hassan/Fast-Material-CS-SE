
//Existing interface for tracking attendance
interface AttendanceSystem {
 void recordAttendance(String employeeId, int hoursWorked);
}

//Biometric attendance system
class BiometricAttendanceSystem {
 void recordAttendanceByBiometric(String biometricId, int hoursWorked) {
     // Logic to record attendance using biometric device
     System.out.println("Attendance recorded via biometric device for employee ID: " + biometricId);
 }
}

//Adapter to integrate the biometric attendance system with the existing interface
class BiometricAttendanceAdapter implements AttendanceSystem {
 private BiometricAttendanceSystem biometricSystem;

 public BiometricAttendanceAdapter(BiometricAttendanceSystem biometricSystem) {
     this.biometricSystem = biometricSystem;
 }

 @Override
 public void recordAttendance(String employeeId, int hoursWorked) {
     // Convert employee ID to biometric ID if necessary
     String biometricId = convertToBiometricId(employeeId);
     // Delegate the call to the biometric system
     biometricSystem.recordAttendanceByBiometric(biometricId, hoursWorked);
 }

 private String convertToBiometricId(String employeeId) {
     // Logic to map employee ID to biometric ID
     return "BIO_" + employeeId;
 }
}

//Manual entry attendance system
class ManualEntryAttendanceSystem {
 void recordAttendanceManually(String employeeId, int hoursWorked) {
     // Logic to manually record attendance
     System.out.println("Attendance recorded manually for employee ID: " + employeeId);
 }
}

//Adapter to integrate the manual entry attendance system with the existing interface
class ManualEntryAttendanceAdapter implements AttendanceSystem {
 private ManualEntryAttendanceSystem manualEntrySystem;

 public ManualEntryAttendanceAdapter(ManualEntryAttendanceSystem manualEntrySystem) {
     this.manualEntrySystem = manualEntrySystem;
 }

 @Override
 public void recordAttendance(String employeeId, int hoursWorked) {
     // Delegate the call to the manual entry system
     manualEntrySystem.recordAttendanceManually(employeeId, hoursWorked);
 }
}

//Client code
public class main_2 {
 public static void main(String[] args) {
     // Biometric attendance adapter
     BiometricAttendanceSystem biometricSystem = new BiometricAttendanceSystem();
     AttendanceSystem biometricAdapter = new BiometricAttendanceAdapter(biometricSystem);
     biometricAdapter.recordAttendance("EMP001", 8);

     // Manual entry attendance adapter
     ManualEntryAttendanceSystem manualEntrySystem = new ManualEntryAttendanceSystem();
     AttendanceSystem manualEntryAdapter = new ManualEntryAttendanceAdapter(manualEntrySystem);
     manualEntryAdapter.recordAttendance("EMP002", 7);
 }
}

