public class Topic6_a {
	static class Animal {
		public void eat() {
			System.out.println("Animal eat.\n");
		}

		public void sleep() {
			System.out.println("Animal sleep.\n");
		}
	}

	static class Bird extends Animal {
		public void eat() {
			System.out.println("Bird Eat.\n");
		}

		public void sleep() {
			System.out.println("Bird sleep.\n");
		}

		public void fly() {
			System.out.println("Bird fly.\n");
		}
	}

	public static void main(String args[]) {
		Animal a = new Animal();
		Bird b = new Bird();
		a.eat();
		a.sleep();
		b.eat();
		b.sleep();
		b.fly();
	}
}