package SwingExamples;

import java.awt.*;
import java.awt.event.*;

import javax.swing.*;
// Class Cardlayout is extending the JFrame and implementing the interface of ActionListener
@SuppressWarnings("serial")
public class Cardlayout extends JFrame implements ActionListener {

    CardLayout cd;

   JButton jb1, jb2, jb3;

   Container con;

   Cardlayout()

   {
// using the method in order to get the content

	 con = getContentPane();
// Initializing the object "cd” of CardLayout class with horizontal and vertical spaces as 70 and 50 respectively

	 cd = new CardLayout(50, 50);
// setting of the layout using the setLayout method

	 con.setLayout(cd);
// Initialising the object "jb1" of the above JButton class.

	 jb1 = new JButton(new ImageIcon("button-859346_1280.png"));
// Initialising the object "jb2" of the above JButton class.

	 jb2 = new JButton(new ImageIcon("button-859346_1280.png"));
// Initialising the object "jb3" of the above JButton class.

	 jb3 = new JButton(new ImageIcon("button-859346_1280.png"));
// Using this Keyword in order to refers to the current object.
// Adding of Jbutton "jb1" on JFrame using the methods of ActionListener

	 jb1.addActionListener(this);
// Adding of Jbutton "jb2" on JFrame.

	 jb2.addActionListener(this);
// Adding of Jbutton "jb3" on JFrame.

	 jb3.addActionListener(this);
// Adding of the above buttons to the container one by one
// Adding the JButton "jb1" using add method
   
	 
	 con.add("a", jb1);
// Adding the JButton "jb2" similar to the above

	 con.add("b", jb2);
// Adding the JButton "jb3" in the container

	 con.add("c", jb3);
	 

	 JButton likeButton=new JButton(new ImageIcon("like.png")); 
	  likeButton.setBounds(10,200,20,20);
	  likeButton.setLayout(cd);
	   con.add(likeButton); 
	 
}
   
   
   

   public void actionPerformed(ActionEvent e){
	   
// using next method to call the next card

	   cd.next(con);
}
// Main Method of Java class from where the execution starts
public static void main(String[] args)
{
// Creating Object of CardLayout class.

	Cardlayout cl1 = new Cardlayout();
// Setting the title of JFrame

	cl1. setTitle("Browse Album");
// Setting the size of JFrame.

	cl1.setSize(300, 300);
// Setting the resizable value of JFrame.

	cl1.setResizable(false);
// Setting the visibility of JFrame.

	cl1.setVisible(true);
// Function to set default operation of JFrame.

	cl1.setDefaultCloseOperation(EXIT_ON_CLOSE);
}
}
