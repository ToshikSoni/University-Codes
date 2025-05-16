import java.util.Scanner;

public class a1q22 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter size of array: ");
		int size = sc.nextInt();
		int[] arr = new int[size];
		System.out.println("\nEnter elements in array:");
		for (int i = 0; i < size; i++)
			arr[i] = sc.nextInt();
		try {
			System.out.print("\nEnter index of element: ");
			int index = sc.nextInt();
			System.out.println("Element is: " + arr[index]);
		} catch (ArrayIndexOutOfBoundsException e) {
			System.out.println(e);
		}
		sc.close();
	}
}
