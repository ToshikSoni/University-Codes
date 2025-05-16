import java.util.Scanner;

public class aaq3 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter size of array: ");
		int n = sc.nextInt();
		int[][] g = new int[n][n];
		System.out.print("Enter elements in array: ");
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				g[i][j] = sc.nextInt();
		sc.close();
		int sum = n * (n * n + 1) / 2;
		boolean ms = true;
		for (int i = 0; i < n; i++) {
			int rsum = 0;
			int csum = 0;
			for (int j = 0; j < n; j++) {
				rsum += g[i][j];
				csum += g[j][i];
			}
			if (rsum != sum || csum != sum) {
				ms = false;
				break;
			}
		}
		int d1 = 0;
		int d2 = 0;
		for (int i = 0; i < n; i++) {
			d1 += g[i][i];
			d2 += g[i][n - i - 1];
		}
		if (d1 != sum || d2 != sum)
			ms = false;
		if (ms)
			System.out.println("The given array is a magic square.");
		else
			System.out.println("The given array is not a magic square.");
	}
}
