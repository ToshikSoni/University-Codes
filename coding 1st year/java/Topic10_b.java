import java.sql.*;

public class Topic10_b {
    public static void main(String[] args) {
        try {
            Class.forName("com.mysql.jdbc.Driver");
            Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/toshik", "root", "Qazplm@123");
            Statement stmt = conn.createStatement();
            stmt.executeUpdate(
                    "CREATE TABLE IF NOT EXISTS student (rollno int(4) PRIMARY KEY, studentname VARCHAR(20) NOT NULL, standard VARCHAR(2) NOT NULL, date_of_birth DATE, fees float(9,2));");
            String insertQuery = "INSERT INTO student VALUES (1, 'John Doe', '10', '2003-01-01', 10000.00);";
            stmt.executeUpdate(insertQuery);
            String updateQuery = "UPDATE student SET fees = 15000.00 WHERE rollno = 1;";
            stmt.executeUpdate(updateQuery);
            String deleteQuery = "DELETE FROM student WHERE rollno = 2;";
            stmt.executeUpdate(deleteQuery);
            ResultSet rs = stmt.executeQuery("SELECT * FROM student");
            while (rs.next()) {
                int rollno = rs.getInt("rollno");zzzzzx
                String studentname = rs.getString("studentname");
                String standard = rs.getString("standard");
                Date dateOfBirth = rs.getDate("date_of_birth");
                double fees = rs.getDouble("fees");
                System.out.println(rollno + ", " + studentname + ", " + standard + ", " + dateOfBirth + ", " + fees);
            }
            rs.close();
            stmt.close();
            conn.close();
        } catch (Exception e) {
            System.err.println("Error: " + e.getMessage());
        }
    }
}
