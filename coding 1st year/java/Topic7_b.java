import testpackage.foundation;

public class Topic7_b {
	public static void main(String[] args) {
		foundation f = new foundation();
		System.out.println("Value of Var1 can't be accessed as it is private."
				+ "\nValue of Var2 can't be accessed as it is default."
				+ "\nValue of Var3 can't be accessed as it is protected."
				+ "\nValue of public Var4: " + f.Var4);
	}
}