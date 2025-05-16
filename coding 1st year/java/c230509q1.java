import java.sql.*;

public class c230509q1 {
    public static void main(String[] args) {
        try {
            // Step 1: Loading the drivers
            Class.forName("com.mysql.jdbc.Driver");
            DriverManager.registerDriver(new com.mysql.jdbc.Driver());
            // Step 2: Establish a connection
            Connection con = DriverManager.getConnection("jdbc:mysql://localhost:3306/toshik", "root", "Qazplm@123");
            // Step 3: Creating a statement
            Statement stmt = con.createStatement();
            // Step 4: Executing a statement(executeQuery or executeUpdate)
            ResultSet rs = stmt.executeQuery("select * from detail");
            while (rs.next()) {
                System.out.println(rs.getInt(1) + "\t" + rs.getString(2) + "\t" + rs.getString(3) + "\t"
                        + rs.getDate(4) + "\t" + rs.getDouble(5));
            }
            // Step 5: Closing connection
            con.close();
            // execution javac -classpath .;"jar path" FileName.java
            // same for execution
        } catch (Exception e) {
            System.out.println(e);
        }
    }
}