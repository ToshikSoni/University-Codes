class Animal {
	public void move() {};
}
class Bird extends Animal {
	public void move() {
		System.out.println("Bird Fly.");
	}
}
class Fish extends Animal {
	public void move() {
		System.out.println("Fish Swim.");
	}
}
public class midterm2 {
	public static void main(String[] args) {
		Animal b = new Bird();
		Animal f = new Fish();
		b.move();
		f.move();
	}
}