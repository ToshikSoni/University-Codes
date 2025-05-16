import java.util.Scanner;

public class a1q14 {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter size of array: ");
		int size = sc.nextInt(), a = 0, a1 = 0, b = 0, b1 = 0;
		int[] arr;
		arr = new int[size];
		System.out.println("Enter elements of array: ");
		for (int i = 0; i < size; i++)
			arr[i] = sc.nextInt();
		sc.close();
		if (arr[0] < arr[size - 1]) {
			a = arr[0];
			a1 = arr[0];
			b = arr[0];
			b1 = arr[0];
		}
		else {
			a = arr[size - 1];
			a1 = arr[size - 1];
			b = arr[size - 1];
			b1 = arr[size - 1];
		}
		for (int i = 0; i < size; i++)
			if (a < arr[i]) {
				a = arr[i];
				a1 = arr[i];
			}
		if (arr[0] < arr[size - 1])
			a = arr[0];
		else if (arr[0] == arr[size - 1]) {
			a = arr[0];
			a--;
		}
		else
			a = arr[size - 1];
		for (int i = 0; i < size; i++)
			if (a < arr[i])
				if (arr[i] != a1)
					a = arr[i];
		for (int i = 0; i < size; i++)
			if (b > arr[i]) {
				b = arr[i];
				b1 = arr[i];
			}
		if (arr[0] < arr[size - 1])
			b = arr[size - 1];
		else if (arr[0] == arr[size - 1]) {
			b = arr[0];
			b++;
		}
		else
			b = arr[0];
		for (int i = 0; i < size; i++)
			if (b > arr[i])
				if (arr[i] != b1)
					b = arr[i];
		System.out.println("The largest number is: " + a1 + "\nAnd the second largest number is: "
				+ a + "\n\nThe smallest number is: " + b1 + "\nAnd the second smallest number is: "
				+ b);
	}
}
