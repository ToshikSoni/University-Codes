import java.io.*;
import java.util.*;

public class Topic8_c {
	public static void main(String[] args) {
		try {
			BufferedReader reader = new BufferedReader(new FileReader("input.txt"));
			ArrayList<String> words = new ArrayList<>();
			String line;
			while ((line = reader.readLine()) != null) {
				String[] lineWords = line.toLowerCase().split(" ");
				for (String word : lineWords)
					words.add(word);
			}
			reader.close();
			Collections.sort(words);
			FileWriter writer = new FileWriter("output.txt");
			String currentWord = "";
			int currentCount = 0;
			for (String word : words)
				if (word.equals(currentWord))
					currentCount++;
				else {
					if (!currentWord.isEmpty())
						writer.write(currentWord + ": " + currentCount + "\n");
					currentWord = word;
					currentCount = 1;
				}
			if (!currentWord.isEmpty())
				writer.write(currentWord + ": " + currentCount + "\n");
			writer.close();
			System.out.println("Word counts written to output file.");
		} catch (IOException e) {
			System.err.println("Error reading or writing file: " + e.getMessage());
		}
	}
}