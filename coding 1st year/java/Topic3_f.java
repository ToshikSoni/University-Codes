import java.util.Scanner;
public class Topic3_f {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter number: ");
		int num = sc.nextInt(), t1 = 0, t2 = 0, t3 = num;
		sc.close();
		while (num != 0) {
			t1 = num % 10;
			t2 = t2 * 10 + t1;
			num = num / 10;
		}
		if (t3 == t2)
			System.out.println("It is palindrome number.");
		else
			System.out.println("It is not palindrome number.");
	}
}