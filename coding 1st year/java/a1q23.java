import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class a1q23 {
	public static void main(String[] args) {
		try {
			FileWriter fout = new FileWriter("file.txt");
			String txt = "Hi hello";
			fout.write(txt);
			fout.close();
			FileReader fin = new FileReader("file.txt");
			FileWriter fout1 = new FileWriter("file1.txt");
			int i;
			while ((i = fin.read()) != -1)
				fout1.write((char) i);
			fout1.close();
			fin.close();
		} catch (FileNotFoundException e) {
			System.out.println(e);
		} catch (IOException e) {
			System.out.println(e);
		}
	}
}
