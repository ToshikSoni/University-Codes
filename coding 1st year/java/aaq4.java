public class aaq4 {
	public static int fastest(int[] arr) {
		int temp = arr[0], ind = 0;
		for (int i = 0; i < arr.length; i++)
			if (temp > arr[i]) {
				temp = arr[i];
				ind = i;
			}
		return ind;
	}
	public static int fast(int[] arr) {
		int f = arr[fastest(arr)], temp = arr[0], ind = 0;
		for (int i = 0; i < arr.length; i++)
			if (temp > arr[i]) {
				temp = arr[i];
				if (temp == f) {
					temp = arr[i - 1];
				}
				ind = i;
			}
		return ind;
	}

	public static void main(String[] args) {
		String[] names = {"Elena", "Thomas", "Hamilton", "Suzie", "Phil", "Matt", "Alex", "Emma",
				"John", "James", "Jane", "Emily", "Daniel", "Neda", "Aaron", "Kate"};
		int[] times =
				{341, 273, 278, 329, 445, 402, 388, 275, 243, 334, 412, 393, 299, 343, 317, 265};
		System.out.println("Fastest runner: " + names[fastest(times)] + ", time taken: "
				+ times[fastest(times)] + "\nSecond fastest runner: " + names[fast(times)]
				+ ", time taken: " + times[fast(times)]);
	}
}
