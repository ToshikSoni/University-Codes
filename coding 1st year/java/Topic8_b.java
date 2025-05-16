import java.io.*;

public class Topic8_b {
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
		} catch (Exception e) {
			System.out.println(e);
		}
	}
}
