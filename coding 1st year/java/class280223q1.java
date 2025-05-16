class X {
	int i;

	public X(int i) {
		this.i = i--;
	}
}


class Y extends X {
	public Y(int i) {
		super(i++);
		System.out.print(i);
	}
}


public class class280223q1 {
	public static void main(String args[]) {
		Y a = new Y(26);
	}
}
