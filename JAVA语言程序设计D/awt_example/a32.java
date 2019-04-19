public class a32{
 public static void main(String args[])
 {String str="This is a string!";
  int len, i , 总和;
  len=str.length();
  总和=0;
  for (i=0; i<len; i++)
  {if (str.substring(i,i+1).equals("s")){总和++;}}
  System.out.println("总和= "+总和); 
 }
}

