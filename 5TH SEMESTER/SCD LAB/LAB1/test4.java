
class Person{

   private String name;
   private String occupation;

   Person(){
    
   }

   public void Draw(){
    System.out.println("A person can draw in many ways");
   }

   void setName(String n){
       name = n;
   }

   String getName(){
    return name;
   }

   void setOccupation(String occ){
    occupation = occ;
   }

   String getOccupation(){
    return occupation;
   }


}


class Artist extends Person{

   Artist(){
   }

   public void Draw(){
    System.out.println("An artist can draw with a paint brush.");
   }


}


class Gunman extends Person{

  Gunman(){
  }

  public void Draw(){

    System.out.println("A gunman draws a gun to shoot");
  }

}

public class test4 {
    public static void main(String[] args) {

        Person p = new Person();
        Artist a = new Artist();
        Gunman g = new Gunman();


        p.Draw();
        a.setName("Hassan");
        a.setOccupation("Artist");

        g.setName("Ali");
        g.setOccupation("Gunman");

        
        System.out.println("Name: " + a.getName());
        System.out.println("Occupation: " + a.getOccupation());
        a.Draw();

        System.out.println("Name: " + g.getName());
        System.out.println("Occupation: " + g.getOccupation());
        g.Draw();

    }
}
