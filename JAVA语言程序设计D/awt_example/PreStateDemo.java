import java.sql.*;
class PreStateDemo{
  public static void main(String[] args){
   try{
     Class.forName("sun.jdbc.odbc.JdbcOdbcDriver");
     String url="jdbc:odbc:Store";
     Connection conn=DriverManager.getConnection(url);
     Statement stmt=conn.createStatement();
     String createTablePackage="CREATE TABLE  Package"+
        "(senderName VARCHAR(32),acceptName VARCHAR(32), State INTEGER, ID INTEGER,"+
             "Gender String)";
     System.out.println(createTablePackage);
     stmt.executeUpdate(createTablePackage);
     PreparedStatement insertPackage =conn.prepareStatement(
       "Insert Into Package Values(?,'Simon',?,?,'ÄÐ')");
     String n[]={"Dean","Donald","Eric","Julian","Jeff"};    
     int a[]={22,23,21,20,25};
     int s[]={4000,3800,3800,38500,37500};
     for(int i=0;i<n.length;i++){
       insertPackage.setString(1,n[i]);
        insertPackage.setInt(2,a[i]);
        insertPackage.setInt(3,s[i]);
        insertPackage.executeUpdate();
      }
      stmt.close();
      conn.close();
    } catch(Exception e){  System.err.println(e.getMessage());     }
 }
}
