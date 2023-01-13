
public class Ex_2 {

	public static void main(String[] args) {
		
		try{
			String s = null;
//			System.out.print(s.length());  if this runs first so parent exception runs
			
			int a[] = new int [5];
			a[5] = 0;
		}
		
		
		
		catch(ArrayIndexOutOfBoundsException e){
                 System.out.println("Array Inddex out of bound Exception Occurs");		
		}
		
		catch(Exception e){
			System.out.println("Parent exception occurs");
		}
		
		finally{
			System.out.println("last statement to run");
		}
		
	}

}
