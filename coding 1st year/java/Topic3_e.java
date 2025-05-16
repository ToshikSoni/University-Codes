import java.util.Scanner;

public class Topic3_e {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter number: ");
		int num = sc.nextInt(), temp = 0;
		sc.close();
		if (num >= 2) {
			for (int i = 2; i < num; i++) {
				if (num % i == 0) {
					temp = 1;
					break;
				}
				else
					temp = 0;
			}
			if (temp == 0)
				System.out.println("It is a prime number.");
			else
				System.out.println("It is not a prime number.");
		}
		else if (num == 1)
			System.out.println("1 is neither prime nor composite.");
		else
			System.out.println("Enter number greater than 0.");
	}
}