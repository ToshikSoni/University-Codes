import java.util.Scanner;

public class a1q15 {
	public static class Box {
		private double width, height, depth;

		public Box(double w, double h, double d) {
			width = w;
			height = h;
			depth = d;
		}

		public double volume() {
			return (depth * width * height);
		}
	}

	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter width, height, depth: ");
		double w = sc.nextDouble(), h = sc.nextDouble(), d = sc.nextDouble();
		Box a = new Box(w, h, d);
		System.out.print("The volume is: " + a.volume());
		sc.close();
	}
}
