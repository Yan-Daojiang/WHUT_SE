import java.io.*;
public class TestString{
   public static void main(String args[]){
     StringC s=new StringC("cool","java");

     System.out.println(s);
     
   
    }
}
class StringC{
     String s1;
     String s2;

     StringC(String str1,String str2){
  
      s1=str1;
      s2=str2;
     
     }


     public String toString(){
      return s1+s2;
  }
}