import java.util.Scanner;
public class midterm3 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter two numbers: ");
		int a = sc.nextInt(), b = sc.nextInt(), temp = 0;
		sc.close();
		while (b != 0) {
			temp = b;
			b = a % b;
			a = temp;
		}
		System.out.println("GCD is: " + a);
	}
}