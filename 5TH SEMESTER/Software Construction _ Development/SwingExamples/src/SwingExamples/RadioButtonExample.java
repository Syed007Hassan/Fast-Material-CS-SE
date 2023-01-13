package SwingExamples;

import javax.swing.*;    
import java.awt.event.*; 

class RadioButtonExample extends JFrame implements ActionListener{    
		JRadioButton rb1,rb2;    
		JButton b;
		JPanel jp;
		
		RadioButtonExample(){
			
			jp= new JPanel();
			jp.setBounds(200, 200,100,100);
			
			rb1=new JRadioButton("Cat");    
			rb1.setBounds(60,50,70,30);      
			
			rb2=new JRadioButton("Dog");    
			rb2.setBounds(60,100,70,30);    
			
			ButtonGroup bg=new ButtonGroup();    
			bg.add(rb1);bg.add(rb2);    
			
			b=new JButton("click");
			b.setBounds(100,150,80,30);    
			b.addActionListener(this);    
			
			jp.add(rb1); jp.add(rb2); jp.add(b);
			
			add(jp);    
			
			setSize(300,300);    
			setLayout(null);    
			setVisible(true);    
		
		}
		
		public void actionPerformed(ActionEvent e){    
			if(rb1.isSelected()){    
				JOptionPane.showMessageDialog(this,"Cat.");    
			}    
			if(rb2.isSelected()){    
				JOptionPane.showMessageDialog(this,"Dog.");    
			}    
		}    
		
	public static void main(String args[]){    
		new RadioButtonExample();    
	}
	
}