
class MyException extends Exception{
	
	public int a;

	public MyException(int a) {
		this.a = a;
	}
	
@Override

   public String toString() {
	return "MyException [a=" + a + "]";
   }

}

public class customexception {
public static void main(String[] args) {
		try {
			throw new MyException(3);
		} catch (MyException e) {
			System.out.println(e);
		}}}
