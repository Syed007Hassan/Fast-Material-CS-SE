package LayoutExamples;
//import statement  
import java.awt.*;    
import javax.swing.*;    
 
public class FlowLayoutExample {    
	JFrame frameObj;  
	
	//constructor    
	FlowLayoutExample() {    
		 // creating a frame object  
		 frameObj = new JFrame();    
		     
		  // creating the buttons  
		 JButton b1 = new JButton("1");    
		 JButton b2 = new JButton("2");    
		 JButton b3 = new JButton("3");    
		 JButton b4 = new JButton("4");    
		 JButton b5 = new JButton("5");  
		 JButton b6 = new JButton("6");    
		 JButton b7 = new JButton("7");    
		 JButton b8 = new JButton("8");    
		 JButton b9 = new JButton("9");    
		 JButton b10 = new JButton("10");    
		 
		      
		 // adding the buttons to frame        
		 frameObj.add(b1); frameObj.add(b2); frameObj.add(b3); frameObj.add(b4);      
		 frameObj.add(b5); frameObj.add(b6);  frameObj.add(b7);  frameObj.add(b8);    
		 frameObj.add(b9);  frameObj.add(b10);      
		 
		 //align left/right, hgap, vgap
		 //frameObj.setLayout(new FlowLayout(FlowLayout.LEFT, 20, 25));
		 
		 //align only
		 //frameObj.setLayout(new FlowLayout(FlowLayout.LEFT));
		 
		 //no align, 5 hgap by default
		 frameObj.setLayout(new FlowLayout());
		     
		   
		 frameObj.setSize(300, 300);    
		 frameObj.setVisible(true);    
	}    
	//main method  
	public static void main(String argvs[]) {    
		new FlowLayoutExample();    
	}    
}  