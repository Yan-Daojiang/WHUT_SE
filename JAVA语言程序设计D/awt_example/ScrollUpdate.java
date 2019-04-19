import java.sql.*;
class ScrollUpdate{
  public static void main(String[] args){
   try{
     Class.forName("sun.jdbc.odbc.JdbcOdbcDriver");
     String url="jdbc:odbc:Store";
     Connection conn=DriverManager.getConnection(url);
     Statement stmt=conn.createStatement( 
       ResultSet.TYPE_SCROLL_SENSITIVE,ResultSet.CONCUR_UPDATABLE);
       ResultSet rs=stmt.executeQuery("SELECT ID,senderName,"+
       "State FROM Package WHERE ID<20");
       rs.last();
       rs.updateString("senderName","Nora");
       rs.updateRow();
       rs.previous();
       rs.updateString("State","Damaged");
       rs.cancelRowUpdates();
       rs.updateString("State","On the way");
       rs.updateRow();
       rs.close();
       stmt.close();
      conn.close();
    } catch(Exception e){  System.err.println(e.getMessage());     }
 }
}
