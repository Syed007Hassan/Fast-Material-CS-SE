package DDR.assignment2.Reusable;

interface Student {
  void register();
}

class Undergraduate implements Student {
  public void register() {
    System.out.println("Registered for Undergraduate courses");
  }
}

class Graduate implements Student {
  public void register() {
    System.out.println("Registered for Graduate courses");
  }
}

class PhD implements Student {
  public void register() {
    System.out.println("Registered for PhD courses");
  }
}

class CourseRegistration {

  // This method is using encapsulation that varies therefore it is reusable

  public void register(Student student) {
    student.register();
  }
}

public class RegisterWithEncapsulation {

  public static void main(String[] args) {
    Student student = new Undergraduate();
    CourseRegistration courseRegistration = new CourseRegistration();
    courseRegistration.register(student);
  }

}
