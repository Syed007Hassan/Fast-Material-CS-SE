package Composing_Method;

// public class Extract_Method {
 
//     public String name = "Hero";
//     public double amount  = 100;

//     public void printFlag(){
//         System.out.println("Print Flag");
//     }

//     public double getAmount(){
//         return amount;
//     }

       // Code fragment that is grouped together 
    // public void printAll() {
    //     printFlag();
        
    //     // Print details.
    //     System.out.println("name: " + name);
    //     System.out.println("amount: " + getAmount());
    // }

// }

public class Extract_Method {
 
    public String name = "Hero";
    public double amount  = 100;

    public void printFlag(){
        System.out.println("Print Flag");
    }

    public double getAmount(){
        return amount;
    }

    // Extract Method (Composing Method)
    // Move code to new function and call this function
    public void printAll() {
        printFlag();
        
        printDetails(getAmount());
    }

    public void printDetails(double amountt){
        // Print details.
        System.out.println("name: " + name);
        System.out.println("amount: " + amountt);
    }

}
