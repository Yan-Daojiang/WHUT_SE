import java.sql.*;
class JdbcOdbcDemo{
  public static void main(String[] args){
   try{
     Class.forName("sun.jdbc.odbc.JdbcOdbcDriver");
     String url="jdbc:odbc:Store";
     Connection conn=DriverManager.getConnection(url);
     Statement stmt=conn.createStatement();
     String createTablePersonnel="CREATE TABLE Personnel"+
        "(Name VARCHAR(32),ID INTEGER,Salary FLOAT, "+"Gender String)";
     System.out.println(createTablePersonnel);
     stmt.executeUpdate(createTablePersonnel);
     stmt.executeUpdate("Insert Into Personnel Values('Tom',12,37000,'ÄÐ')");
     stmt.executeUpdate("Insert Into Personnel Values('Susi',13,37001,'Å®')");
     stmt.executeUpdate("Insert Into Personnel Values('Linda',15,37002,'Å®')");
     String updateString="UPDATE Personnel "+"SET ID=7 "+"WHERE Name LIKE 'Jack' ";
     stmt.executeUpdate(updateString);
     String query="Select ID,Gender,Name From Personnel";
     ResultSet rs =stmt.executeQuery(query);
     while(rs.next())
       {
         String name =rs.getString("Name");
         int id =rs.getInt("ID");
         String gender=rs.getString("Gender");
         System.out.println(name+"\t"+id+"\t"+gender);
      }
      rs.close();
      stmt.close();
      conn.close();
    } catch(Exception e){  System.err.println(e.getMessage());   }
 }
}
