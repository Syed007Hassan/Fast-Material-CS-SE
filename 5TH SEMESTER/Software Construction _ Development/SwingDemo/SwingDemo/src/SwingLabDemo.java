import java.awt.MouseInfo;
import java.awt.Point;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseEvent;

import javax.swing.*;  

public class SwingLabDemo extends JFrame implements ActionListener{
	
	JFrame f;
	JLabel lbl;
	JTextField txtFld;
	JButton btn;
	
	public SwingLabDemo() {
		f=new JFrame();
		
		lbl = new JLabel("Name: ");
		lbl.setBounds(100,100,40, 40);
		f.add(lbl);
		txtFld = new JTextField();
		txtFld.setBounds(150, 100, 200, 30);
		f.add(txtFld);
		btn = new JButton("Click Me to remove the name!");
		btn.setBounds(200,180,250, 60);
		f.add(btn);
//		
//		btn.addActionListener(this);
		
		f.setLayout(null);
		
		f.setSize(500,500);
		
		f.setVisible(true);
		
		
		btn.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				txtFld.setText("hassan");
				
			}
		});
		
	}
	
	public static void main(String[] args) {
		
		SwingLabDemo demo = new SwingLabDemo();
		
	}
	


}
