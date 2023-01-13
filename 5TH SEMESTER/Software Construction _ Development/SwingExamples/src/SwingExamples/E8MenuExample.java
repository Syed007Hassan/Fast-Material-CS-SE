package SwingExamples;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.*;  

public class E8MenuExample implements ActionListener{
	 JMenu menu, submenu;  
     JMenuItem i1, i2, i3, i4, i5;
     JTextArea ta; 
     
     E8MenuExample(){  
	     JFrame f= new JFrame("Menu and MenuItem Example");  
	     JMenuBar mb=new JMenuBar();  
	     
	     ta=new JTextArea();    
	     ta.setBounds(5,5,300,300); 
	     
	     menu=new JMenu("Menu");  
//	     submenu=new JMenu("Sub Menu");  
	     
	     i1=new JMenuItem("Item 1");
	     i1.addActionListener(this);
	     
	     i2=new JMenuItem("Item 2");  
	     i3=new JMenuItem("Item 3");  
	     i4=new JMenuItem("Item 4");  
	     i5=new JMenuItem("Item 5");  
	     
	     menu.add(i1); menu.add(i2); menu.add(i3);  
	     
//	     submenu.add(i4); submenu.add(i5);  
	     
//	     menu.add(submenu);  
	    
	     mb.add(menu);  
	     
	     f.add(ta);
	     f.setJMenuBar(mb);
	     
	     f.setSize(400,400);  
	     f.setLayout(null);  
	     f.setVisible(true);  
     }
	public static void main(String[] args) {

		new E8MenuExample();

	}
	@Override
	public void actionPerformed(ActionEvent e) {
		if (e.getSource() == i1) {
			ta.paste();
		}
		
	}

}
