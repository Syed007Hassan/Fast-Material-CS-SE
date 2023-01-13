package SwingExamples;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

import javax.swing.*;

public class E9OptionPanes extends WindowAdapter{
	JFrame f;  
	E9OptionPanes(){  
	    f=new JFrame();
	    f.addWindowListener(this);
	    f.setDefaultCloseOperation(JFrame.DO_NOTHING_ON_CLOSE);
	    
	    f.setSize(400,400);  
	    f.setLayout(null);  
	    f.setVisible(true);
	    String name=JOptionPane.showInputDialog(f,"Enter Name");
	}
	
	public void windowClosing(WindowEvent e) {  
	    int a=JOptionPane.showConfirmDialog(f,"Are you sure you want to exit?");  
		
	    if(a==JOptionPane.YES_OPTION){  
		    f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);  
		}
	}
	
	
	public static void main(String[] args) {  
	    new  E9OptionPanes();  
	}  
}
