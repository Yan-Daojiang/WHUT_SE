public class StrCopy{
   public static void main(String args[]){
     String s1=new String();
     char data[]={'a','b','c','d','e','f'};
     s1=String.copyValueOf(data);
     System.out.println("s1="+s1);
     s1=String.copyValueOf(data,2,3);
     System.out.println("s1="+s1);
     s1.getChars(1,2,data,0);
  
     System.out.println("data="+String.copyValueOf(data));
     data=s1.toCharArray();
     System.out.println("data="+String.copyValueOf(data));
     String s2=new String();
     String s3=new String();
     s2=s1.substring(0);
     System.out.println("s2="+s2);
     s3=s1.substring(1,2);
     System.out.println("s3="+s3);
  }
}