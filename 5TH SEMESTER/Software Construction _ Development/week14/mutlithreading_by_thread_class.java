import java.util.*;
import java.io.*;
import java.util.Scanner;

                                    /// calulation of algebric formulas

class Thread_1 extends Thread
{

	  int i,j;
	  Thread_1(int x,int y)
	  {
		  
		  i=x;
		  j=y;
	  }

	public void run()
	{
		System.out.println("THREAD 1___"+(i-j)*(i+j));  // a² – b² = (a-b)(a+b)
	
		
	}
	 
	}
	
	class Thread_2 extends Thread
	{
		
		int i,j;
		
		Thread_2(int x,int y)
		{
			i=x;
			j=y;
			
		}
		public void run()
		{
			System.out.println("THREAD 2___"+(i*i)+2*i*j+(j*j));         // (a+b)² = a² + 2ab + b²
			
			
		}
	}
	
	class Thread_3 extends Thread
	{
		
		int i,j,k;
		
		Thread_3(int x,int y,int z)
		{
			i=x;
			j=y;
			k=z;
		}
		public void run()
		{
			System.out.println("THREAD 3___"+(i*i)+2*i*j+(j*j)+(k*k)+(2*i*k)+2*j*k);  // (a+b+c)² = a²+b²+c²+2ab+2ac+2bc.
			
			
		}
	}
	
	class Thread_4 extends Thread
	{
		
		int i,j;
		
		Thread_4(int x,int y)
		{
			i=x;
			j=y;
			
		}
		public void run()
		{
			System.out.println("THREAD 4___"+(i*j)*2+2*i*j);    // a² + b² = (a-b)² +2ab.
			
			
		}
	}
	
	
	class Thread_5 extends Thread
	{
		
		int i,j;
		
		Thread_5(int x,int y)
		{
			i=x;
			j=y;
			
		}
		public void run()
		{
			System.out.println("THREAD 5___"+(i-j)*(i*i+i*j+j*j));  //  a³-b³ = (a-b) (a² + ab + b²)
			
			
		}
	}
	

	class Thread_6 extends Thread
	{
		
		int i,j;
		
		Thread_6(int x,int y)
		{
			i=x;
			j=y;
			
		}
		public void run()
		{
			System.out.println("THREAD 6___"+(i-j)*(i*i-i*j+j*j));  //a³+b³ = (a+b) (a² – ab + b²)
			
			
		}
	}

public class mutlithreading_by_thread_class{
	
	  public static void main(String[] args)
	  {
		  Scanner s = new Scanner(System.in);
		     int a;
		     int b;
		      int c;
		      System.out.println("Enter the value of a");
				a=s.nextInt();
				System.out.println("Enter the value of b");
				b=s.nextInt();
				System.out.println("Enter the value of c");
				c=s.nextInt();
				
		     
		  
		  
		  
		  Thread_1 t1=new Thread_1(a,b);
		  Thread_2 t2=new Thread_2(a,b);
		  Thread_3 t3=new Thread_3(a,b,c);
		  Thread_4 t4=new Thread_4(a,b);
		  Thread_5 t5=new Thread_5(a,b);
		  Thread_6 t6=new Thread_6(a,b);
		  t1.start();
		  t2.start();
		  t3.start();
		  t4.start();
		  t5.start();
		  t6.start();
		  
		  
		  
	  }
	

	
}



