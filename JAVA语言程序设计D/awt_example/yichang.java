import java.lang.*;
public class yichang{
public static void main(String args[ ]){
   int i=0;
   String vds[ ]={"0","zero","null"};
   while(i<4)
   {
     try{System.out.println(vds[i]);}
     catch(ArrayIndexOutOfBoundsException e)
     {System.out.println("Re-setting index Value");
                                          i = -1;}
     catch(Exception e){System.out.println(e.toString());}
     finally{System.out.println("This is always printed");}
     i++;}
}
}
