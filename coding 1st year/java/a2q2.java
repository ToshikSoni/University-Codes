import java.util.Scanner;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;

public class a2q2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String directoryPath = "C:\\Users\\tsoni\\OneDrive\\Desktop\\coding\\java";
        String fileExtension = ".txt";
        System.out.print("Enter word to search: ");
        String keyword = sc.nextLine();
        File directory = new File(directoryPath);
        if (!directory.isDirectory())
            System.out.println("The specified directory path is not a directory.");
        else {
            File[] files = directory.listFiles();
            for (File file : files)
                if (file.getName().endsWith(fileExtension))
                    try (BufferedReader reader = new BufferedReader(new FileReader(file))) {
                        String line;
                        int lineNumber = 0;
                        while ((line = reader.readLine()) != null) {
                            lineNumber++;
                            if (line.contains(keyword))
                                System.out.println("\n" + file + " - line " + lineNumber + ": " + line);
                        }
                    } catch (Exception e) {
                        System.out.println("Error reading file: " + e.getMessage());
                    }
        }
        sc.close();
    }
}