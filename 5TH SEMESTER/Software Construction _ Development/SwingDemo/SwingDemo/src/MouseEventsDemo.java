import java.awt.*;
import java.awt.event.*;

public class MouseEventsDemo extends Frame implements MouseListener, MouseMotionListener {
	String msg = "";
	int mouseX = 0, mouseY = 0;
	
	public MouseEventsDemo() {
		addMouseListener(this);
		addMouseMotionListener(this);
		addWindowListener(new MyWindowAdapter());
	}

	@Override
	public void mouseDragged(MouseEvent e) {
		// mouse dragged
		mouseX = e.getX();
		mouseY = e.getY();
		msg = "*" + "mouse at " + mouseX + ", " + mouseY;
		repaint();
	}

	@Override
	public void mouseMoved(MouseEvent e) {
		// mouse moved
		msg = "Moving mouse at " + e.getX() + ", " + e.getY();
		repaint();
		
	}
	
	@Override
	public void mouseReleased1(MouseEvent e) {
		// TODO Auto-generated method stub
		super.mouseReleased(e);
	}

	@Override
	public void mouseClicked(MouseEvent e) {
		// mouse clicked
		msg = msg + " -- click received";
		repaint();
		
	}

	@Override
	public void mousePressed(MouseEvent e) {
		// mouse button pressed
		mouseX = e.getX();
		mouseY = e.getY();
		msg = "Button Down";
		repaint();
	}

	@Override
//	public void mouseReleased(MouseEvent e) {
//		// mouse button released
//		mouseX = e.getX();
//		mouseY = e.getY();
//		msg = "Button Released";
//		repaint();
//		
//	}

	@Override
	public void mouseEntered(MouseEvent e) {
		// mouse entered
		mouseX = 100;
		mouseY = 100;
		msg = "Mouse Entered";
		repaint();
		
	}

	@Override
	public void mouseExited(MouseEvent e) {
		// mouse exited
		mouseX = 100;
		mouseY = 100;
		msg = "Mouse Exited";
		repaint();
	}
	
	public void paint(Graphics g) {
		g.drawString(msg, mouseX, mouseY);
	}
	
	public static void main(String args[]) {
		MouseEventsDemo appwin = new MouseEventsDemo();
		appwin.setSize(new Dimension(300,300));
		appwin.setTitle("Mouse Events Demo");
		appwin.setVisible(true);
	}
}

class MyWindowAdapter extends WindowAdapter {
	public void windowClosing (WindowEvent we) {
		System.exit(0);
	}
}