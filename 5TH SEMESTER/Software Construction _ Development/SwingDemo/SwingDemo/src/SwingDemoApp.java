import java.awt.*;
import java.awt.event.*;
import javax.swing.*;


public class SwingDemoApp {
	
	
	private JFrame mainFrame;
	private JLabel headerLabel;
	private JLabel statusLabel;
	private JPanel controlPanel;
	
	public SwingDemoApp () {
		prepareGUI();
	}
	private void prepareGUI(){
	      mainFrame = new JFrame("Java SWING Examples");
	      mainFrame.setSize(400,400);
	      mainFrame.setLayout(new GridLayout(3, 1));

	      headerLabel = new JLabel("",JLabel.CENTER );
	      statusLabel = new JLabel("",JLabel.CENTER);        
	      statusLabel.setSize(350,100);
	      
	      mainFrame.addWindowListener(new WindowAdapter() {
	         public void windowClosing(WindowEvent windowEvent){
	            System.exit(0);
	         }        
	      });    
	      controlPanel = new JPanel();
	      controlPanel.setLayout(new FlowLayout());

	      mainFrame.add(headerLabel);
	      mainFrame.add(controlPanel);
	      mainFrame.add(statusLabel);
	      mainFrame.setVisible(true);  
	}
	
	
	private void showEventDemo(){
	      headerLabel.setText("Control in action: Button"); 

	      JButton okButton = new JButton("OK");
	      JButton submitButton = new JButton("Submit");
	      JButton cancelButton = new JButton("Cancel");

	      okButton.setActionCommand("OK");
	      submitButton.setActionCommand("Submit");
	      cancelButton.setActionCommand("Cancel");

	      okButton.addActionListener(new ButtonClickListener()); 
	      submitButton.addActionListener(new ButtonClickListener()); 
	      cancelButton.addActionListener(new ButtonClickListener()); 

	      controlPanel.add(okButton);
	      controlPanel.add(submitButton);
	      controlPanel.add(cancelButton);       

	      mainFrame.setVisible(true);  
	}
	
	private class ButtonClickListener implements ActionListener{
	      public void actionPerformed(ActionEvent e) {
	         String command = e.getActionCommand();  
	         
	         if( command.equals( "OK" ))  {
	            statusLabel.setText("Ok Button clicked.");
	         } else if( command.equals( "Submit" ) )  {
	            statusLabel.setText("Submit Button clicked."); 
	         } else {
	            statusLabel.setText("Cancel Button clicked.");
	         }  	
	      }		
	}
	public static void main(String[] args) {
		
		SwingDemoApp appwin = new SwingDemoApp();
		appwin.showEventDemo();

	}

}
