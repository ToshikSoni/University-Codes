import java.util.Scanner;

public class Topic4_b {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter size of array: ");
		int size = sc.nextInt(), a = 0;
		int[] arr;
		arr = new int[size];
		System.out.println("Enter elements of array:");
		for (int i = 0; i < size; i++) {
			arr[i] = sc.nextInt();
		}
		System.out.println("Enter number to search");
		int num = sc.nextInt();
		sc.close();
		for (int i = 0; i < size; i++) {
			if (num == arr[i]) {
				System.out.println("Number found at index: " + i);
				a = 1;
			}
		}
		if (a == 0)
			System.out.println(-1);
	}
}
