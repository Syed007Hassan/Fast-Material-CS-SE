import java.util.Scanner;

class Student{

   private String name;
   private int ID;
   private String depName;
   private int arr[];
   private int total;

   public Student(int size) {
    this.arr = new int[size];
  }

   Scanner input = new Scanner(System.in);

   void setName(){
    System.out.println("Enter the name");
    name = input.nextLine();
   }

   String getName(){
    
    return name;
   }

   void setID(){
    System.out.println("Enter the ID: ");
    ID = input.nextInt();
   }

   int getID(){
    return ID;
   }

   void setDepName(){
    System.out.println("Enter the Dep Name: ");
    depName = input.nextLine();
   }

   String getDepName(){
    return depName;  
   }

   void setPercentage(){
     
    System.out.println("Enter the marks for subjects out of 100: ");
   
    for (int i = 0; i < arr.length; i++) {
        
        System.out.println("Subject : " + (i+1));

        arr[i] = input.nextInt();
        //  arr[i] = x;
        total = total + arr[i];
    }

   }

   float getPercentage(){
    float percent;
    percent = ((total*100)/600);
    return percent;

   }

}


public class test{

    public static void main(String[] args) {
    	
		Student s = new Student(6);

         s.setName();
         s.setDepName();
         s.setID();
         
         s.setPercentage();
        

         System.out.println("NAME: " + s.getName());
         System.out.println("DEP NAME: " + s.getDepName());
         System.out.println("ID: " + s.getID());
         System.out.println("PERCENTAGE: " + s.getPercentage());
	}

}