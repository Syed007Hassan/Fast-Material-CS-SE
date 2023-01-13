import java.util.Scanner;


class InvalidCharacter extends Exception{
	
  static char cc;	
 
  public InvalidCharacter(char x) {
	  cc = x;
	   
}
 
	public String toString() {
		return "Other than alphabet:  " +  cc;
	} 
	
}

public class Task2 {
	public static void main(String[] args) {
	
		InvalidCharacter iv = new InvalidCharacter('z');
		
        try{
			
			Scanner sc = new Scanner(System.in);
			System.out.print("Enter the string: ");
			String a = sc.nextLine();
			
			for(int i=0;i<a.length();i++){
			  
				char c = a.charAt(i);
				
	          if( (c != 'a' && c != 'z') || (c != 'A' && c != 'Z')){
					c = a.charAt(i+1);
					throw new InvalidCharacter(c);
				}
				
				if(c == 'A' || c == 'B'){
					throw new Exception("A or B typed");
				}
				
				if(c >= 'a' && c <= 'z'){
					throw new Exception("Small case letter");
				}
				
			
				else{
					
					throw new Exception("Some random error occurred");
				}
			}
			
		}
		
		catch(Exception e){
		System.out.println(e);
		}

	}

}
