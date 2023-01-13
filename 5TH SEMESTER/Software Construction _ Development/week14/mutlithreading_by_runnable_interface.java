import java.util.*;
import java.io.*;
import java.util.Scanner;

public class mutlithreading_by_runnable_interface implements Runnable  {
	
	public static int m ;
	public static int c ;
	public static int v ;
	public static int g;
	public static int h;
	public static int velocity ;
	public static int a_1 ;
	public static int a_2 ;
	public static int a_3 ;
	public static int a_4 ;
	public static int total_energy ;
	
	 public static void main(String args[]){ 
		
		 Scanner s = new Scanner(System.in);
		 Runnable r1=new Runnable(){  
			    public void run(){  
			    	  System.out.println("Enter the Mass m of object");
		                 m = s.nextInt();
		                 System.out.println("Enter the Velocity V of object");
						  v=s.nextInt();
						  System.out.println("Enter the Gravitaional Accelaration G of object");
						  g=s.nextInt();
						  System.out.println("Enter the Gravitaional Height h of object");
						  h=s.nextInt();
						  
			 }
		        } ;
			  
		 
		        Runnable r2=new Runnable(){  
				    public void run(){ 
				    	velocity=v*v;
				    	 System.out.println("Thread 2 is calculating v*v_____________"+velocity);
				    	
				    }
			        } ;
		 

			        Runnable r3=new Runnable(){  
					    public void run(){  
					    	a_1=m*velocity;
					    	 System.out.println("Thread 3 is calculating m*v*v_____________"+a_1);
					    	
					    	
					    	
					    }
				        } ; 

				        Runnable r4=new Runnable(){  
						    public void run(){  
						    	a_2=(int) (0.5*a_1);
						    	System.out.println("thread 4 is calculating 1/2 mv*2_____________"+a_2);
						    	
						    }
					        } ; 
					        Runnable r5=new Runnable(){  
							    public void run(){  
							    	a_3=m*g;
							    	System.out.println("thread 5 is calculating m*g_____________"+a_3);
							    	
							    }
						        } ; 
						        
						        
						        Runnable r6=new Runnable(){  
								    public void run(){  
								    	a_4=h*a_3;
								    	System.out.println("thread 6 is calculating h*m*g_____________"+a_4);
								    	
								    }
							        } ; 
							        
							        Runnable r7=new Runnable(){  
									    public void run(){  
									    total_energy=a_4+a_2;
					 System.out.println("thread 7 is calculating Total Energy (  Kinectic + Potential )_____________"+total_energy);
									    	
					   }
							   } ; 
				        
				        
				        
				        
				        Thread t1=new Thread(r1); 
				        Thread t2=new Thread(r2);  
				        Thread t3=new Thread(r3);
				        Thread t4=new Thread(r4);
				        Thread t5=new Thread(r5);
				        Thread t6=new Thread(r6);
				        Thread t7=new Thread(r7);
				        
				        
				        try {
				            t1.start(); 
							t1.join();
							if( !t1.isAlive()) {
					            t2.start();
					            t3.start();
					            t4.start();
					            t5.start();
					            t6.start();
					            t7.start();
					        }
						} catch (InterruptedException e) {
							// TODO Auto-generated catch block
							e.printStackTrace();
						}
				        
				      
				   
				        
	 }

	@Override
	public void run() {
		// TODO Auto-generated method stub
		
	}
	 }
	
	
	
	
