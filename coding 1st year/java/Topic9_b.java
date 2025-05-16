import java.util.Scanner;

public class Topic9_b {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter string: ");
        String s = sc.next(), temp = "";
        System.out.print("Enter number: ");
        int n = sc.nextInt();
        for (int i = n-1; i < s.length(); i++)
            temp += s.charAt(i);
        for (int i = 0; i < n; i++)
            System.out.print(temp);
        sc.close();
    }
}
