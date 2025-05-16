public class midterm {
	public static void main(String[] args) {
		int[] arr = new int[10];
		for (int i = 0; i < 10; i++)
			arr[i] = i + 1;
		// a
		int tempe = 0, tempo = 0, count = 0;
		for (int i = 0; i < 10; i++)
			if (arr[i] % 2 == 0) {
				count++;
				tempe += arr[i];
			}
		System.out.println(
				"Number of even numbers: " + count + "\tSum of all even numbers: " + tempe);
		// b
		count = 0;
		for (int i = 0; i < 10; i++)
			if (arr[i] % 2 != 0) {
				count++;
				tempo += arr[i];
			}
		System.out
				.println("Number of odd numbers: " + count + "\tSum of all odd numbers: " + tempo);
		// c
		System.out.println("The difference of sum calculated: " + (tempe - tempo));
	}
}