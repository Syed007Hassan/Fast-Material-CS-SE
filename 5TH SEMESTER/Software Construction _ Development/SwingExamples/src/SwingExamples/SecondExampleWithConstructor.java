package SwingExamples;

import javax.swing.*;  

public class SecondExampleWithConstructor {
	JFrame f;  
	SecondExampleWithConstructor(){  
		f=new JFrame();//creating instance of JFrame  
		          
		JButton b=new JButton("click");//creating instance of JButton  
		b.setBounds(130,100,100, 40);  
		          
		f.add(b);//adding button in JFrame  
		          
		f.setSize(400,500);//400 width and 500 height  
		f.setLayout(null);//using no layout managers  
		f.setVisible(true);//making the frame visible  
	}	
	
	public static void main(String[] args) {  
			new SecondExampleWithConstructor();  
		}
}
