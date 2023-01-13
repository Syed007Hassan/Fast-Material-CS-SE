package SwingExamples;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.*; 

public class E2Button3 extends JFrame {
	static int x = 100;
	static int y = 40;
	E2Button3() {
		
		JFrame f=new JFrame("Button Example");            
		JButton b=new JButton(new ImageIcon("button-859346_1280.png"));    
		b.setBounds(100,100,x,y);    
		
		f.add(b);    
		
		f.setSize(300,400);    
		f.setLayout(null);    
		f.setVisible(true);    
		f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		
		
		b.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
			
				b.setBounds(100, 100, ++x, ++y);
				
			}
		});
		
		
		
	}
	
	public static void main(String[] args) {    
	    new E2Button3();    
	}    
}
