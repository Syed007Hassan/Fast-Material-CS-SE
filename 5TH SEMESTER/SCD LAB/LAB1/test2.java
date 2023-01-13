import java.lang.reflect.Field;
import java.util.Scanner;

class Teacher{
  private String name;
  private int age;
  private String institute;

  String field;
  String courseName;
  String designation;

  Scanner input = new Scanner(System.in);

  void setName(){
    System.out.print("Enter the name");
    name = input.nextLine();
   }

   String getName(){
    
    return name;
   }

   void setAge(){
    System.out.print("Enter the age");
    age = input.nextInt();
   }

   int getAge(){
    
    return age;
   }

   void setInstName(){
    System.out.print("Enter the Intitution name: ");
    institute = input.nextLine();
    institute = input.nextLine();
   }

   String getInstName(){
    
    return institute;
   }

   void setField(){
    System.out.print("Enter the Field name: ");
    field = input.nextLine();
   }

   String getField(){
    
    return field;
   }

   void setCourseName(){
    System.out.print("Enter the Course name: ");
    courseName = input.nextLine();
   }

   String getCourseName(){
    
    return courseName;
   }

   void setDesignation(){
    System.out.print("Enter the Designation name: ");
    designation = input.nextLine();
   }

   String getDesignation(){
    
    return designation;
   }


}


class HumanitiesTeacher extends Teacher{


}



class MathsTeacher extends Teacher {



}


class ScienceTeacher extends Teacher{
    
}


public class test2 {
    public static void main(String[] args) {
    	
        Teacher t = new Teacher();
        HumanitiesTeacher ht = new HumanitiesTeacher();
        ScienceTeacher st = new ScienceTeacher();
        MathsTeacher mt = new MathsTeacher();

        System.out.println("Humanities Teacher");
        ht.setName();
        ht.setAge();
        ht.setInstName();
        ht.setField();
        ht.setCourseName();
        ht.setDesignation();

        // System.out.println("Science Teacher");
        // st.setName();
        // st.setAge();
        // st.setInstName();
        // st.setField();
        // st.setCourseName();
        // st.setDesignation();

        // System.out.println("Maths Teacher");
        // mt.setName();
        // mt.setAge();
        // mt.setInstName();
        // mt.setField();
        // mt.setCourseName();
        // mt.setDesignation();


        System.out.println("Name: " + ht.getName() );
        System.out.println("AGE: " + ht.getAge());
        System.out.println("INSTITUTION: " + ht.getInstName());
        System.out.println("FIELD: " + ht.getField());
        System.out.println("COURSE NAME: " + ht.getCourseName());
        System.out.println("DESIGNATION: " + ht.getDesignation()); 
        

	}
}
