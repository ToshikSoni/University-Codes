import java.util.*;

public class aaq2 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter number of days: ");
		int N = sc.nextInt(), rating = 0, consecutiveDays = 0;
		int[] workload = new int[N];
		System.out.println("Enter workload hours: ");
		for (int i = 0; i < N; i++)
			workload[i] = sc.nextInt();
		sc.close();
		for (int i = 0; i < N; i++) {
			if (workload[i] > 6) {
				consecutiveDays++;
				if (rating < consecutiveDays)
					rating = consecutiveDays;
			}
			else
				consecutiveDays = 0;
		}
		System.out.println("The rating is: " + rating);
	}
}
