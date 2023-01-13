package SwingExamples;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.*;
import javax.swing.*;  

public class PracticeExample {



	public static void main(String[] args) {
	
		JFrame frame = new JFrame("Student Registration");
		frame.setSize(350,350);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		JPanel jPanel = new JPanel();
		frame.add(jPanel);
		
		placeComponents(jPanel);
		frame.setVisible(true);
		
	   frame.setLayout(new CardLayout());
	
	}

	protected static int lcount=0;
	protected static int dcount=0;

	private static void placeComponents(JPanel jPanel) {
		
		jPanel.setLayout(null);
		final int c=0;
		
		JLabel fJLabel = new JLabel("First Name");
		fJLabel.setBounds(10,20,80,25);
		jPanel.add(fJLabel);
		
		JLabel lJLabel = new JLabel("Last Name");
		lJLabel.setBounds(10,50,100,25);
		jPanel.add(lJLabel);
		
		JLabel eJLabel = new JLabel("Email");
		eJLabel.setBounds(10,80,80,25);
		jPanel.add(eJLabel);
		
		JLabel pJLabel = new JLabel("Phone No");
		pJLabel.setBounds(10,110,80,25);
		jPanel.add(pJLabel);
		
		JTextField fJTextField = new JTextField(20);
		fJTextField.setBounds(100,50,165,25);
		jPanel.add(fJTextField);
		
		JTextField lJTextField = new JTextField(20);
		lJTextField.setBounds(100,20,165,25);
		jPanel.add(lJTextField);
		
		JTextField eJTextField = new JTextField(20);
		eJTextField.setBounds(100,80,165,25);
		jPanel.add(eJTextField);
		
		JTextField pJTextField = new JTextField(20);
		pJTextField.setBounds(100,110,165,25);
		jPanel.add(pJTextField);
		
		JButton logButton = new JButton("Login");
		logButton.setBounds(10,160,80,25);
		jPanel.add(logButton);
		

		JButton registerButton = new JButton("Register");
		registerButton.setBounds(100,160,80,25);
		jPanel.add(registerButton);
		
		
		JButton likeButton=new JButton(new ImageIcon("like.png")); 
	    likeButton.setBounds(10,200,20,20);
	    jPanel.add(likeButton);
	    

		JButton dislikeButton=new JButton(new ImageIcon("dislike.png")); 
	    dislikeButton.setBounds(50,200,20,20);
	    jPanel.add(dislikeButton);
	    
	    JLabel likeJLabel = new JLabel("like");
	    likeJLabel.setBounds(10,250,100,25);
	    jPanel.add(likeJLabel);
	    
	    JLabel dislikeJLabel = new JLabel("dislike");
	    dislikeJLabel.setBounds(100,250,100,25);
	    jPanel.add(dislikeJLabel);
		
		logButton.addActionListener( new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
			
			 String fname =  fJTextField.getText();
			 String lname = lJTextField.getText();
			 String email =  eJTextField.getText();	
			 String phone =  pJTextField.getText();	
			 
			 JOptionPane.showMessageDialog(logButton, 
				"First name : " + fname + "\n" + 
				"Last name : " + lname + "\n" +
				"Email : " + email + "\n" +
				"Phone : " + phone + "\n" 
					 );
			}
			
	    
		});
		
		likeButton.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
		
			++lcount;
			
				
				likeJLabel.setText(" like: " + lcount);
				
			}
		});
		
		
		dislikeButton.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				++dcount;
				dislikeJLabel.setText("dislike: " + dcount);
				
			}
		});
		
	   
	}

}
