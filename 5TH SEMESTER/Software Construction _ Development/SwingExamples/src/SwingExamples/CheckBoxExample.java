package SwingExamples;

import javax.swing.*;  
import java.awt.event.*;  

public class CheckBoxExample extends JFrame implements ActionListener{  
    JLabel l;  
    JCheckBox cb1,cb2,cb3;  
    JButton b;  
    CheckBoxExample(){  
        l=new JLabel("Food Ordering System");  
        l.setBounds(50,50,300,20);  
        
        cb1=new JCheckBox("Pizza @ 100");  
        cb1.setBounds(100,100,150,20);  
        
        cb2=new JCheckBox("Burger @ 30");  
        cb2.setBounds(100,150,150,20);  
        
        cb3=new JCheckBox("Tea @ 10");  
        cb3.setBounds(100,200,150,20);  
        
        b=new JButton("Order");  
        b.setBounds(100,250,80,30);  
        b.addActionListener(this);  
        
        add(l);add(cb1);add(cb2);add(cb3);add(b);  
        
        setSize(400,400);  
        setLayout(null);  
        setVisible(true);  
        setDefaultCloseOperation(EXIT_ON_CLOSE);  
    }  
    
    
    public void actionPerformed(ActionEvent e){  
        float amount=0;  
        String msg="";  
        if(cb1.isSelected()){  
            amount+=100;  
            msg="Pizza: 100\n";  
        }  
        if(cb2.isSelected()){  
            amount+=30;  
            msg+="Burger: 30\n";  
        }  
        if(cb3.isSelected()){  
            amount+=10;  
            msg+="Tea: 10\n";  
        }  
        msg+="-----------------\n";  
        JOptionPane.showMessageDialog(this,msg+"Total: "+amount);  
        JOptionPane.showMessageDialog(b,"dfgfdg");
    }  
    
    public static void main(String[] args) {  
        new CheckBoxExample();  
    }  
}  