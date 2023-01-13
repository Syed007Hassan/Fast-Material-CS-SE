///https://github.com/guto-alves/java-how-to-program-11e/tree/master/src/ch23/ex23_11

import javax.swing.JFrame;

public class w11_main {

	public static void main(String[] args) {
		JFrame application = new JFrame("Rebating the Ball");
		application.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

		w11_ui ballsJPanel = new w11_ui(20);
		application.add(ballsJPanel);

		application.setSize(400, 400);
		application.setLocationRelativeTo(null);
		application.setVisible(true);

	}

}
