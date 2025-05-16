
// Create a Java program that searches for a specific word in a file and displays the line number(s) where it occurs.
// (File name should be given by user at runtime)
import java.io.BufferedReader;
import java.io.FileReader;
import java.util.ArrayList;
import java.util.Scanner;

public class a2q1 {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter file name: ");
        String filename = sc.nextLine();
        System.out.print("Enter word to search: ");
        String word = sc.nextLine(), line;
        sc.close();
        String file = filename + ".txt";
        int lineNumber = 1;
        ArrayList<Integer> lineNumbers = new ArrayList<>();
        try {
            BufferedReader br = new BufferedReader(new FileReader(file));
            while ((line = br.readLine()) != null) {
                if (line.contains(word))
                    lineNumbers.add(lineNumber);
                lineNumber++;
            }
            br.close();
        } catch (Exception e) {
            System.out.println(e);
        }
        if (lineNumbers.isEmpty())
            System.out.println("Word not found in file.");
        else {
            System.out.print("Word found in line(s): ");
            for (int temp : lineNumbers)
                System.out.println(temp + " ");
        }
    }
}