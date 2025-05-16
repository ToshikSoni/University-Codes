import java.util.Scanner;

public class a1q11 {
	public static void main(String args[]) {
		char c = 'y';
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter numbers: ");
		int num1 = sc.nextInt(), num2 = sc.nextInt();
		while (c == 'y' | c == 'Y') {
			System.out.print("Select an input(1. Add 2. Subtract): ");
			int input = sc.nextInt();
			switch (input) {
				case 1:
					System.out.println("Addition: " + (num1 + num2));
					break;
				case 2:
					System.out.println("Subtraction: " + (num1 - num2));
					break;
				default:
					System.out.println("Enter a valid input.");
					break;
			}
			System.out.println("Do you want to continue(Press y to continue): ");
			c = sc.next().charAt(0);
		}
		sc.close();
	}
}
