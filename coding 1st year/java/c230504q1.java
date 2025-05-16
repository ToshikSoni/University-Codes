import java.sql.*;

public class c230504q1 {
    public static void main(String args[]) {
        try {
            Class.forName("com.mysql.jdbc.Driver");
            DriverManager.registerDriver(new com.mysql.jdbc.Driver());
            Connection con = DriverManager.getConnection("jdbc:mysql://localhost:3306/kuku", "root", "Qazplm@123");
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
    }
}