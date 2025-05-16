public class class200423q1 {
	public static boolean isVowel(char c) {
		switch (c) {
			case 'a':
			case 'e':
			case 'i':
			case 'o':
			case 'u':
			case 'A':
			case 'E':
			case 'I':
			case 'O':
			case 'U':
				return true;
			default:
				return false;
		}
	}
	public static String sort(String s)
	{
		
		return s;
	}
	public static String make(String s0, String s1) {
		String temp = "";
		if (s0.length() > s1.length()) {
			for (int i = 0; i < s0.length(); i++) {
				temp += s0.charAt(i);
				if (i < s1.length())
					temp += s1.charAt(i);
			}
		}
		else if (s0.length() == s1.length()) {
			for (int i = 0; i < s0.length(); i++) {
				temp += s0.charAt(i);
				temp += s1.charAt(i);
			}
		}
		else
			temp = make(s1, s0);
		return temp;
	}

	public static void main(String args[]) {
		String s1 = "A2BCXY", s2 = "X1YeZ", s3 = "";
		s3 = make(s1, s2);

		System.out.println(s3);
	}
}