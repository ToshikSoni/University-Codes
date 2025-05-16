import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class nea {
    public static void main(String[] args) {
        String inputFile = "input.txt";     // Path to the input file
        String outputFile = "output.txt";   // Path to the output file

        try {
            // Read the input file
            BufferedReader reader = new BufferedReader(new FileReader(inputFile));
            StringBuilder content = new StringBuilder();
            String line;
            while ((line = reader.readLine()) != null) {
                content.append(line).append("\n");
            }
            reader.close();

            // Reverse the content
            String reversedContent = content.reverse().toString();

            // Write the reversed content to the output file
            BufferedWriter writer = new BufferedWriter(new FileWriter(outputFile));
            writer.write(reversedContent);
            writer.close();

            System.out.println("Content reversed and written to the output file successfully.");
        } catch (IOException e) {
            System.out.println("An error occurred: " + e.getMessage());
            e.printStackTrace();
        }
    }
}
