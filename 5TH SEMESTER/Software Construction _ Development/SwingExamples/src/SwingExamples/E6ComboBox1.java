package SwingExamples;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.*;    

public class E6ComboBox1 {
	JFrame f;    
	
	E6ComboBox1(){    
	    f=new JFrame("ComboBox Example");	
	    String country[]={"Pakistan","Australia","U.S.A","England","New Zealand"};
	    JComboBox cb=new JComboBox(country);
	    
	    JComboBox jBox = new JComboBox(country);
	    
	    
	    cb.setBounds(50, 50,100,20);
	    jBox.setBounds(50,100,100,20);
	    
	    f.add(cb);
	    f.add(jBox);
	    f.setLayout(null);
	    f.setSize(400,500);
	    f.setVisible(true);
	    
	    
	    jBox.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				if (jBox.getSelectedItem() == "Pakistan") {
					System.out.println("selected");
				}
				
			}
		});
	}
	
	public static void main(String[] args) {    
	    new E6ComboBox1();         
	}  
	
	
}
