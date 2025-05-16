public class testtttttt {
	public static void main(String[] args) {
		try {
			int[] arr = new int[10];
			for (int i = 0; i < 10; i++)
				arr[i] = i;
			arr[10] = 0;
		} catch (Exception e) {
			System.out.print(e);
		}
	}
}