import java.util.Scanner;
public class Topic3_a {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter gender(press m for male and press f for female): ");
        char g = sc.next().charAt(0);
        System.out.print("Enter age: ");
        int age = sc.nextInt();
        sc.close();
        if (g == 'M' || g == 'm') {
            if (age >= 1 && age <= 60)
                System.out.println("Interest is: 9.2%");
            else if (age >= 60 && age <= 120)
                System.out.println("Interest is: 8.3%");
            else
                System.out.println("Enter a valid age.");
        }
        else if (g == 'F' || g == 'f') {
            if (age >= 1 && age <= 58)
                System.out.println("Interest is: 8.2%");
            else if (age >= 59 && age <= 120)
                System.out.println("Interest is: 7.6%");
            else
                System.out.println("Enter a valid age.");
        }
        else
            System.out.println("Enter valid gender.");
    }
}