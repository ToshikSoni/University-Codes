public class a1q16 {
	public static class Calculator {
		public static int powerInt(int num1, int num2) {
			int power = 1;
			for (int i = 1; i <= num2; i++)
				power = power * num1;
			return power;
		}

		public static double powerDouble(double num1, int num2) {
			double power = 1;
			for (int i = 1; i <= num2; i++)
				power *= num1;
			return power;
		}
	}

	public static void main(String args[]) {
		System.out.println("powerInt: " + Calculator.powerInt(5, 3));
		System.out.println("powerDouble: " + Calculator.powerDouble(5.3, 2));
	}
}
