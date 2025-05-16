import java.sql.*;

public class Topic10_a {
    public static void main(String[] args) {
        try {
            Class.forName("com.mysql.jdbc.Driver");
            DriverManager.registerDriver(new com.mysql.jdbc.Driver());
            Connection con = DriverManager.getConnection("jdbc:mysql://localhost:3306/toshik", "root", "Qazplm@123");
            System.out.println("Connection Established successfully");
            con.close();
        } catch (Exception e) {
            System.out.println("Connection could not be established: " + e);
        }
    }
}