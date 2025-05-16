import java.util.Scanner;

public class Topic3_c {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("Enter a month number (1-12): ");
        int monthNumber = input.nextInt();
        input.close();
        String monthName = getMonthName(monthNumber);
        System.out.println("The month is " + monthName);
    }

    public static String getMonthName(int monthNumber) {
        switch (monthNumber) {
            case 1:
                return "January";
            case 2:
                return "February";
            case 3:
                return "March";
            case 4:
                return "April";
            case 5:
                return "May";
            case 6:
                return "June";
            case 7:
                return "July";
            case 8:
                return "August";
            case 9:
                return "September";
            case 10:
                return "October";
            case 11:
                return "November";
            case 12:
                return "December";
            default:
                return "Invalid month number";
        }
    }
}