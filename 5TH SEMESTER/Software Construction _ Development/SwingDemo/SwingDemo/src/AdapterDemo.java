import java.awt.*;
import java.awt.event.*;


public class AdapterDemo extends Frame{
	
	String msg = "hello";
	
	public AdapterDemo() {
		addMouseWheelListener(new MyMouseAdapter(this));
		//addMouseListener(new MyMouseAdapter(this));
		addMouseMotionListener(new MyMouseAdapter(this));
		addWindowListener(new MyWindowAdapter());
		
	}
	
	public void paint(Graphics g) {
		g.drawString(msg, 40, 80);
		
	}
	
	public static void main(String[] args) {
		AdapterDemo appwin = new AdapterDemo();
		appwin.setSize(new Dimension(300,300));
		appwin.setTitle("Keyboard Events Demo");
		appwin.setVisible(true);
	}
	
	class MyMouseAdapter extends MouseAdapter {
		AdapterDemo adapterDemo;
		
		public MyMouseAdapter(AdapterDemo adptDm) {
			adapterDemo = adptDm;
		}
		
		public void mouseClicked(MouseEvent me) {
			adapterDemo.msg = "Mouse Clicked";
			adapterDemo.repaint();
		}
		
		public void mouseMoved(MouseEvent me) {
			adapterDemo.msg = "Mouse Moved";
			adapterDemo.repaint();
		}
		
		public void mouseDragged(MouseEvent me) {
			adapterDemo.msg = "Mouse Dragged";
			adapterDemo.repaint();
		}
		
		public void mouseWheelMoved(MouseWheelEvent me) {
			adapterDemo.msg = "Mouse Wheel Moved";
			adapterDemo.repaint();
		}
		
	}
	
	class MyWindowAdapter extends WindowAdapter {
		public void windowClosing (WindowEvent we) {
			System.exit(0);
		}
	}
}
