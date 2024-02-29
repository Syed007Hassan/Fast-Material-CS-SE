package DDR.assignment2.Unusable;

class Student {
  String status;

  public Student(String status) {
    this.status = status;
  }

  public String getStatus() {
    return this.status;
  }
}

class CourseRegistration {

  // This method is not using encapsulation that varies therefore it is not
  // reusable

  public void register(Student student) {
    if (student.getStatus().equals("Undergraduate")) {
      System.out.println("Registered for Undergraduate courses");
    } else if (student.getStatus().equals("Graduate")) {
      System.out.println("Registered for Graduate courses");
    } else if (student.getStatus().equals("PhD")) {
      System.out.println("Registered for PhD courses");
    }
  }
}

public class RegisterWithoutEncapsulation {

  public static void main(String[] args) {
    Student student = new Student("Undergraduate");
    CourseRegistration courseRegistration = new CourseRegistration();
    courseRegistration.register(student);
  }

}
