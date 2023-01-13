//https://github.com/guto-alves/java-how-to-program-11e/tree/master/src/ch23/ex23_11

import java.awt.Color;
import java.awt.Graphics;
import java.awt.Point;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.security.SecureRandom;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import javax.swing.JPanel;

public class w11_ui extends JPanel {
	private Ball[] balls;
	private int counterOfBalls = 0;

	private ExecutorService executorService;

	private enum Direction {
		DOWN, RIGHT, LEFT, UP, DIAGONAL_LEFT_DOWN, DIAGONAL_LEFT_UP, DIAGONAL_RIGHT_DOWN, DIAGONAL_RIGHT_UP
	};

	public w11_ui(int ballsTotal) {
		balls = new Ball[ballsTotal];

		balls[counterOfBalls] = new Ball();

		executorService = Executors.newCachedThreadPool();
		executorService.execute(balls[counterOfBalls]);
		counterOfBalls++;

		addMouseListener(new MouseAdapter() {

			@Override
			public void mousePressed(MouseEvent event) {
				if (counterOfBalls < balls.length) {
					balls[counterOfBalls] = new Ball();

					executorService.execute(balls[counterOfBalls]);
					counterOfBalls++;
				}
			}
		});

		setBackground(Color.WHITE);
	}

	@Override
	public void paintComponent(Graphics g) {
		super.paintComponent(g);

		for (int i = 0; i < counterOfBalls; i++) {
			g.setColor(balls[i].color);
			g.fillOval(balls[i].point.x, balls[i].point.y, 50, 50);
		}
	}

	class Ball implements Runnable {
		private Point point;
		private Color color;

		private final SecureRandom random = new SecureRandom();

		public Ball() {
			color = new Color(random.nextInt(256), random.nextInt(256), random.nextInt(256));
			point = new Point(random.nextInt(300), random.nextInt(300));
		}

		@Override
		public void run() {
			Direction currentDirection = generateDirection();

			try {
				while (true) {
					Direction nextDirection = generateDirection();

					while (nextDirection == currentDirection)
						nextDirection = generateDirection();

					currentDirection = nextDirection;

					do {
						move(currentDirection);
						repaint();
						Thread.sleep(5);

						if (isEdge(currentDirection))
							break;
					} while (true);
				}

			} catch (InterruptedException e) {
				e.printStackTrace();
				Thread.currentThread().interrupt();
			}
		}

		private void move(Direction direction) {
			switch (direction) {
			case DOWN:
				point.y++;
				break;
			case RIGHT:
				point.x++;
				break;
			case UP:
				point.y--;
				break;
			case LEFT:
				point.x--;
				break;
			case DIAGONAL_LEFT_DOWN:
				point.x--;
				point.y++;
				break;
			case DIAGONAL_LEFT_UP:
				point.x++;
				point.y--;
				break;
			case DIAGONAL_RIGHT_DOWN:
				point.x++;
				point.y++;
				break;
			case DIAGONAL_RIGHT_UP:
				point.x--;
				point.y--;
				break;
			}
		}

		private boolean isEdge(Direction direction) {
			switch (direction) {
			case DOWN:
				if (point.y >= 310)
					return true;
				break;
			case RIGHT:
				if (point.x >= 330)
					return true;
				break;
			case UP:
				if (point.y <= 0)
					return true;
				break;
			case LEFT:
				if (point.x <= 0)
					return true;
				break;
			case DIAGONAL_LEFT_DOWN:
				if (point.x <= 0 || point.y >= 310)
					return true;
				break;
			case DIAGONAL_LEFT_UP:
				if (point.x >= 330 || point.y <= 0)
					return true;
				break;
			case DIAGONAL_RIGHT_DOWN:
				if (point.x >= 330 || point.y >= 310)
					return true;
				break;
			case DIAGONAL_RIGHT_UP:
				if (point.x <= 0 || point.y <= 0)
					return true;
				break;
			}

			return false;
		}

		private Direction generateDirection() {
			switch (new SecureRandom().nextInt(8)) {
			case 0:
				return Direction.DOWN;
			case 1:
				return Direction.RIGHT;
			case 2:
				return Direction.UP;
			case 3:
				return Direction.LEFT;
			case 4:
				return Direction.DIAGONAL_LEFT_DOWN;
			case 5:
				return Direction.DIAGONAL_LEFT_UP;
			case 6:
				return Direction.DIAGONAL_RIGHT_DOWN;
			default:
				return Direction.DIAGONAL_RIGHT_UP;
			}
		}
	}
}