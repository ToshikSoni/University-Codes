public class Topic3_b {
	public static void main(String args[]) {
		int temp = args.length;
		if (temp == 0)
			System.out.println("No Values");
		else
			for (int i = 0; i < temp; i++) {
				System.out.print(args[i]);
				if (i != temp - 1)
					System.out.print(", ");
			}
	}
}
