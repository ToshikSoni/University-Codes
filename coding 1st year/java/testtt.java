import java.sql.*;

public class testtt {
	public static void main(String[] args) {
		String dbURL = "jdbc:mysql://localhost:3306/mydatabase";
		String username = "root";
		String password = "mypassword";
		try (Connection conn = DriverManager.getConnection(dbURL, username, password)) {
			Statement stmt = conn.createStatement();
			String query = "SELECT customer_name, order_date, product_name, quantity " +
					"FROM customers " +
					"JOIN orders ON customers.customer_id = orders.customer_id " +
					"JOIN order_items ON orders.order_id = order_items.order_id " +
					"JOIN products ON order_items.product_id = products.product_id";
			ResultSet rs = stmt.executeQuery(query);
			ResultSetMetaData rsmd = rs.getMetaData();
			int numColumns = rsmd.getColumnCount();
			for (int i = 1; i <= numColumns; i++)
				System.out.print(rsmd.getColumnName(i) + "\t");
			System.out.println();
			while (rs.next()) {
				for (int i = 1; i <= numColumns; i++)
					System.out.print(rs.getString(i) + "\t");
				System.out.println();
			}
			rs.close();
			stmt.close();
		} catch (SQLException e) {
			System.out.println("SQLException: " + e.getMessage());
			System.out.println("SQLState: " + e.getSQLState());
			System.out.println("VendorError: " + e.getErrorCode());
		}
	}
}