public class a32{
 public static void main(String args[])
 {String str="This is a string!";
  int len, i , �ܺ�;
  len=str.length();
  �ܺ�=0;
  for (i=0; i<len; i++)
  {if (str.substring(i,i+1).equals("s")){�ܺ�++;}}
  System.out.println("�ܺ�= "+�ܺ�); 
 }
}

