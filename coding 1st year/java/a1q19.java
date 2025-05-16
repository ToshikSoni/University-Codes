public class a1q19 {
	abstract static class GeneralBank {
		abstract double getSavingInterestRate();

		abstract double getFixedInterestRate();
	}
	static class ICICIBank extends GeneralBank {
		double getSavingInterestRate() {
			return 4;
		}

		double getFixedInterestRate() {
			return 8.5;
		}
	}
	static class KotMBank extends GeneralBank {
		double getSavingInterestRate() {
			return 6;
		}

		double getFixedInterestRate() {
			return 9;
		}
	}

	public static void main(String[] args) {
		ICICIBank i = new ICICIBank();
		KotMBank k = new KotMBank();
		GeneralBank gi = new ICICIBank();
		GeneralBank gk = new KotMBank();
		System.out.println("Savings interest of ICICI Bank through ICICI Bank object: "
				+ i.getSavingInterestRate());
		System.out.println("Fixed interest of ICICI Bank through ICICI Bank object: "
				+ i.getFixedInterestRate());
		System.out.println("Savings interest of KotM Bank through KotM Bank object: "
				+ k.getSavingInterestRate());
		System.out.println("Fixed interest of KotM Bank through KotM Bank object: "
				+ k.getFixedInterestRate());
		System.out.println("Savings interest of ICICI Bank through General Bank object: "
				+ gi.getSavingInterestRate());
		System.out.println("Fixed interest of ICICI Bank through General Bank object: "
				+ gi.getFixedInterestRate());
		System.out.println("Savings interest of KotM Bank through General Bank object: "
				+ gk.getSavingInterestRate());
		System.out.println("Fixed interest of KotM Bank through General Bank object: "
				+ gk.getFixedInterestRate());
	}
}
