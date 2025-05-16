public class jokee {
	public static void main(String[] args) {
		int a = 10;
		String b = String.valueOf(a);
		String c = Integer.toString(a);
		int d = Integer.parseInt(c);
		int e = Integer.valueOf(c);
		System.out.print(a + " " + b + " " + c + " " + d + " " + e);
	}
}
