import java.util.Scanner;

public class Task1 {

	public static void main(String[] args) throws Exception {
		
		try{
			
			Scanner sc = new Scanner(System.in);
			System.out.print("Enter the string: ");
			String a = sc.nextLine();
			
			for(int i=0;i<a.length();i++){
			  
				char c = a.charAt(i);
				
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
