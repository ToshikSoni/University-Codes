import java.util.Scanner;

public class aaq1 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt(), a = 0;
		int K = sc.nextInt();
		int[] A = new int[n];
		for (int i = 0; i < n; i++) {
			A[i] = sc.nextInt();
		}
		sc.close();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i != j)
					if (A[i] + A[j] == K)
						a = 1;
			}
		}
		if (a == 1)
			System.out.println("YES");
		else
			System.out.println("NO");
	}
}
