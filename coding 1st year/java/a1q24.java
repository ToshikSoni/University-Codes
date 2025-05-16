import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;

public class a1q24 {
	public static void main(String[] args) {
		try {
			FileReader fr = new FileReader("input.txt");
			String hi = "";
			int k;
			while ((k = fr.read()) != -1)
				hi = hi + (char) k;
			String[] arr = hi.split(" ");
			Arrays.sort(arr);
			FileWriter fw = new FileWriter("output.txt");
			int count = 0;
			for (int i = 0; i < arr.length; i++) {
				for (int j = 0; j < arr.length; j++) {
					if (arr[i] == arr[j]) {
						if (i != j) {
							System.out.println("in count: " + arr[i] + " " + arr[j]);
							count++;
						}
					}
				}
				fw.write(arr[i] + " " + count + '\n');
				count = 0;
			}
			fr.close();
			fw.close();
		} catch (FileNotFoundException e) {
			System.out.println(e);
		} catch (IOException e) {
			System.out.println(e);
		}
	}
}
