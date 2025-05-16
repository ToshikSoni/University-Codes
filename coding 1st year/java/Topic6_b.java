public class Topic6_b {
	static class Shape {
		public void draw() {
			System.out.println("Drawing Shape\n");
		}

		public void erase() {
			System.out.println("Erasing Shape\n");
		}
	}
	static class Circle extends Shape {
		public void draw() {
			System.out.println("Drawing Circle\n");
		}

		public void erase() {
			System.out.println("Erasing Circle\n");
		}
	}
	static class Triangle extends Shape {
		public void draw() {
			System.out.println("Drawing Triangle\n");
		}

		public void erase() {
			System.out.println("Erasing Triangle\n");
		}
	}
	static class Square extends Shape {
		public void draw() {
			System.out.println("Drawing Square\n");
		}

		public void erase() {
			System.out.println("Erasing Square\n");
		}
	}

	public static void main(String[] args) {
		Shape c = new Circle();
		Shape t = new Triangle();
		Shape s = new Square();
		c.draw();
		c.erase();
		t.draw();
		t.draw();
		s.draw();
		s.erase();
	}
}
