import java.util.Scanner;

public class Topic4_a {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter size of array: ");
		int size = sc.nextInt(), max, min;
		int[] arr;
		arr = new int[size];
		System.out.println("Enter elements of array:");
		for (int i = 0; i < size; i++) {
			arr[i] = sc.nextInt();
		}
		sc.close();
		max = arr[0];
		for (int i = 0; i < size; i++) {
			if (max < arr[i])
				max = arr[i];
		}
		min = arr[0];
		for (int i = 0; i < size; i++) {
			if (min > arr[i])
				min = arr[i];
		}
		System.out.print("Smallest element in array is: " + min
				+ "\nAnd the largest element in array is: " + max);
	}
}
