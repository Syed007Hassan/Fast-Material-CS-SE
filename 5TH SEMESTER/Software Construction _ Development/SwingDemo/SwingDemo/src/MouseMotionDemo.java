import java.awt.Color;
import java.awt.Frame;
import java.awt.Graphics;
import java.awt.MouseInfo;
import java.awt.Point;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.event.MouseMotionListener;
import java.awt.event.WindowAdapter;

import javax.swing.JFrame;
import javax.swing.JLabel;

public class MouseMotionDemo extends JFrame implements MouseMotionListener, MouseListener{
	JFrame fr;
	JLabel lbl;
	
	public MouseMotionDemo () {
		fr = new JFrame();
		lbl = new JLabel("Label!!");
		lbl.setBounds(250, 250, 100, 20);
		
		fr.add(lbl);
		
		fr.addMouseMotionListener(this);
		
		fr.addWindowListener(new MyWindowAdapter());
		fr.setSize(500, 500);
		fr.setLayout(null);
		fr.setVisible(true);
		
		
		
	}
	
	
	public static void main(String[] args) {
		MouseMotionDemo mDemo = new MouseMotionDemo();

	}

	@Override
	public void mouseDragged(MouseEvent e) {
//		Graphics g=getGraphics();  
//	    g.setColor(Color.BLUE);  
//	    g.fillOval(e.getX(),e.getY(),20,20);  
		
	}

	@Override
	public void mouseMoved(MouseEvent e) {
		Point p = MouseInfo.getPointerInfo().getLocation();
		
		lbl.setText(p.x + "," + p.y);
		lbl.setBounds(p.x, p.y, 100, 20);
		
		
	}
	
	class MyWindowAdapter extends WindowAdapter{
		public void windowClosing () {
			System.exit(0);
		}
	}

	@Override
	public void mouseClicked(MouseEvent e) {
		// TODO Auto-generated method stub
		
	}


	@Override
	public void mousePressed(MouseEvent e) {
		// TODO Auto-generated method stub
		
	}


	@Override
	public void mouseReleased(MouseEvent e) {
		// TODO Auto-generated method stub
		
	}


	@Override
	public void mouseEntered(MouseEvent e) {
		// TODO Auto-generated method stub
		
	}


	@Override
	public void mouseExited(MouseEvent e) {
		// TODO Auto-generated method stub
		
	}

}
