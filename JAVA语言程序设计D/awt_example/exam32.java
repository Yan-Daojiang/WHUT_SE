public class exam32{
 public static void main(String args[])
  {String str="This is a string!";
   int len,i,sum;
   len=str.length();
   sum=0;
   for(i=0;i<len;i++)
    {if(str.substring(i,i+1).equals("s")){sum++;}
     System.out.println("sum="+sum);}
   }
}