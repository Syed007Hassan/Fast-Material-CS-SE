package SwingExamples;

import java.awt.*;  
import java.awt.event.ActionEvent;  
import java.awt.event.ActionListener;  
import javax.swing.*;  

public class BrowseAnimals extends JFrame{
	private int currCard = 1;
	private CardLayout layout;
	protected static int lcount1=0;
	protected static int lcount2=0;
	protected static int lcount3=0;
	protected static int dcount1=0;
	protected static int dcount2=0;
	protected static int dcount3=0;
	
	public BrowseAnimals() {
		setTitle("Card Layout Example");
		setSize(420,250);
		
		JPanel panel = new JPanel();
		layout = new CardLayout();
		
		//set layout for your panel
		panel.setLayout(layout);
		
		JPanel panel1 = new JPanel();
		JPanel panel2 = new JPanel();
		JPanel panel3 = new JPanel();
		JPanel panel4 = new JPanel();
		
		//creating labels for each card
//		JButton likeButton=new JButton(new ImageIcon("like.png")); 
		JLabel label1 = new JLabel(new ImageIcon("zebra.png"));
		JLabel label2 = new JLabel(new ImageIcon("panda-bear.png"));
		JLabel label3 = new JLabel(new ImageIcon("hedgehog.png"));
		JLabel likeJLabel = new JLabel("Likes " + lcount1);
		
		JLabel dislikeJLabel = new JLabel("Dislikes " + dcount1);
		
		//placing labels in panel(card)
		panel1.add(label1);
		panel2.add(label2);
		panel3.add(label3);

		
		//adding panels(cards) to the main panel
		panel.add(panel1, "1");
		panel.add(panel2, "2");
		panel.add(panel3, "3");
		
		JPanel buttonPanel = new JPanel();
		
		JButton nextB = new JButton("Next");
		JButton prevB = new JButton("Previous");

		JButton likeButton=new JButton(new ImageIcon("like.png"));
		JButton dislikeButton=new JButton(new ImageIcon("dislike.png")); 
		
		buttonPanel.add(nextB);
		buttonPanel.add(prevB);
		buttonPanel.add(likeButton);
		buttonPanel.add(likeJLabel);
		buttonPanel.add(dislikeButton);
		buttonPanel.add(dislikeJLabel);
		
		
		
		nextB.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				if (currCard < 4) {
					currCard += 1;
					if(currCard == 1) {
						likeJLabel.setText("Likes: " + lcount1);
						dislikeJLabel.setText("Dislikes: " + dcount1);
					}
					if(currCard == 2) {
						likeJLabel.setText("Likes: " + lcount2);
						dislikeJLabel.setText("Dislikes: " + dcount2);
					}
					if(currCard == 3) {
						likeJLabel.setText("Likes: " + lcount3);
						dislikeJLabel.setText("Dislikes: " + dcount3);
					}	
					
					layout.show(panel, "" +currCard);
				}
				
			}
		});
		
		prevB.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				if (currCard > 1) {
					currCard -= 1;
					if(currCard == 1) {
						likeJLabel.setText("Likes: " + lcount1);
						dislikeJLabel.setText("Dislikes: " + dcount1);
					}
					if(currCard == 2) {
						likeJLabel.setText("Likes: " + lcount2);
						dislikeJLabel.setText("Dislikes: " + dcount2);
					}
					if(currCard == 3) {
						likeJLabel.setText("Likes: " + lcount3);
						dislikeJLabel.setText("Dislikes: " + dcount3);
					}
					
					
					
					layout.show(panel, "" +currCard);
				}
				
			}
		});
		
	likeButton.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
		   
				if(currCard == 1) {
					++lcount1;
					likeJLabel.setText("Likes: " + lcount1);
				}
				if(currCard == 2) {
					++lcount2;
					likeJLabel.setText("Likes: " + lcount2);
				}
				if(currCard == 3) {
					++lcount3;
					likeJLabel.setText("Likes: " + lcount3);
				}
				
			
				
			}
		});
	
	
	dislikeButton.addActionListener(new ActionListener() {
		
		@Override
		public void actionPerformed(ActionEvent e) {
			
			if(currCard == 1) {
				++dcount1;
				dislikeJLabel.setText("Dislikes: " + dcount1);
			}
			
			if(currCard == 2) {
				++dcount2;
				dislikeJLabel.setText("Dislikes: " + dcount2);
			}
			
			if(currCard == 2) {
				++dcount3;
				dislikeJLabel.setText("Dislikes: " + dcount3);
			}
		}
	});
		

		getContentPane().add(panel, BorderLayout.NORTH);  
		getContentPane().add(buttonPanel, BorderLayout.SOUTH);  
	}

	public static void main(String[] args) {
		BrowseAnimals ex = new BrowseAnimals();
		ex.setDefaultCloseOperation(EXIT_ON_CLOSE);
		ex.setVisible(true);

	}

}
