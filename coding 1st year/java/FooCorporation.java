public class FooCorporation {
	public static void calculatePay(double pay, int hours) {
		double totalPay = 0;
		int ohours = 0;
		if (pay < 8)
			System.out.println("Error: Base pay is less than minimum wage.");
		else if (hours > 60)
			System.out.println("Error: Hours worked is greater than maximum hours allowed.");
		else {
			if (hours <= 40)
				totalPay = pay * hours;
			else {
				ohours = hours - 40;
				totalPay = (40 * pay) + ((pay * 1.5) * ohours);
			}
			System.out.println("Total pay: " + totalPay);
		}
	}

	public static void main(String[] args) {
		calculatePay(7.50, 35);
		calculatePay(8.20, 47);
		calculatePay(10.00, 73);
	}
}
