package SwingExamples;

import javax.swing.*;  

public class FirstExample {
	public static void main(String[] args) {  
		JFrame frame = new JFrame("JFrame demo");
		JPanel panel = new JPanel();
		
		JButton jButton = new JButton("hello world");
		jButton.setBounds(80,100,150,50);
		
		JTextField jTextField = new JTextField(" ");
		jTextField.setBounds(120, 100, 150, 150);
		
		panel.add(jButton);
		panel.add(jTextField);
		frame.add(panel);
		frame.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
		frame.setSize(320,240);
		frame.setVisible(true);
		frame.setLayout(null);
		}  
}
