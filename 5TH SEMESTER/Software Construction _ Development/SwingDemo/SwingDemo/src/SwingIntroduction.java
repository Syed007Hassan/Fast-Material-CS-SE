import java.awt.LayoutManager;
import java.awt.dnd.MouseDragGestureRecognizer;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPasswordField;
import javax.swing.JTextField;

public class SwingIntroduction {

	private static final LayoutManager MouseDragGestureRecognizer = null;

	public static void main(String[] args) {

		JFrame frame=new JFrame("Login Screen"); //Line 1

		JLabel label = new JLabel();//Line 2

		label.setBounds(20,150, 200,50);  //Line 3

		final JPasswordField value = new JPasswordField();//Line 4

		value.setBounds(100,75,100,30);

		JLabel userNameLabel=new JLabel("User Name:");//Line 5

		userNameLabel.setBounds(20,20, 80,30);

		JLabel paswordLabel=new JLabel("Password:");//Line 6

		paswordLabel.setBounds(20,75, 80,30);

		JButton loginButton = new JButton("Login Here");//Line 7

		loginButton.setBounds(100,120, 80,30);

		final JTextField text = new JTextField();//Line 8

		text.setBounds(100,20, 100,30);

		frame.add(value);   //Line 9

		frame.add(userNameLabel); //Line 9

		frame.add(label); //Line 9

		frame.add(paswordLabel); //Line 9

		frame.add(loginButton); //Line 9

		frame.add(text);  //Line 9

		frame.setSize(300,300);

		frame.setLayout(null);    //Line 10

		frame.setVisible(true);     //Line 11

		loginButton.addActionListener(new ActionListener() {  //Line 12

			public void actionPerformed(ActionEvent e) {

				String userNameDisplay = "You are " + text.getText();//Line 13

				label.setText(userNameDisplay);     //Line 14
}
});
}
}