
public class Ex_1 {
   public static void main(String[] args) {

    int i = 0;
    int j = 0;
   
    try {
    int k = i/j;
 
    }
   
    catch(ArithmeticException e) {
     System.out.println(e);
     
    }
   
  
    
    try {
    int[] n = new int[2];
    n[3]=4;

    } 
    catch (Exception e) {
    
    	e.printStackTrace();
   }
    }}