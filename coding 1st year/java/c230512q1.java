import java.sql.*;
import java.util.Scanner;

public class c230512q1 {
    public static void main(String[] args) {
        try {
            Class.forName("com.mysql.jdbc.Driver");
            Connection conn = DriverManager.getConnection("jdbc:mysql://127.0.0.1:3306/toshik", "root", "Qazplm@123");
            Statement stmt = conn.createStatement();
            Scanner sc = new Scanner(System.in);
            stmt.executeUpdate("create table employees(ecode int,ename varchar(20),age int,salary int);");
            PreparedStatement ps = conn.prepareStatement("insert into employees values(?,?,?,?);");
            System.out.println("Enter ecode: ");
            int i = sc.nextInt();
            System.out.println("Enter ename: ");
            String n = sc.next();
            System.out.println("Enter age: ");
            int a = sc.nextInt();
            System.out.println("Enter salary: ");
            int s = sc.nextInt();
            ps.setInt(1, i);
            ps.setString(2, n);
            ps.setInt(3, a);
            ps.setInt(4, s);
            ResultSet rs = ps.executeQuery("select * from employees where age>27;");
            while (rs.next())
                System.out.println("Ecode: " + rs.getInt(1) + "\tEname: " + rs.getString(2) + "\tAge: " + rs.getInt(3)
                        + "\tSalary: " + rs.getInt(4));
            System.out.print("Enter ecode to delete row: ");
            i = sc.nextInt();
            stmt.executeUpdate("delete from employee where ecode=" + i + ";");
            System.out.print("Enter ecode to update: ");
            i = sc.nextInt();
            System.out.print("Enter salary to update: ");
            s = sc.nextInt();
            stmt.executeUpdate("update table set salary=" + s + " where ecode=" + i + ";");
            stmt.close();
            sc.close();
            conn.close();
        } catch (Exception e) {
            System.err.println("Error: " + e.getMessage());
        }
    }
}
