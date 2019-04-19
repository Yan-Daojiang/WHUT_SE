import java.io.*;
public class fib{
 public int f(int n){
   
   if(n == 1)   {return 1;}
   else if(n==2){return 1;}
   else{  
         return f(n-1)+f(n-2);
        } 		
}
public static void main(String args[]){
  int nx;
  fib object_fib = new fib();    
  InputStreamReader ir;
   BufferedReader in;
   ir=new InputStreamReader(System.in);
   in=new BufferedReader(ir);
   System.out.println("Input nx is:");
   String s=in.readLine();
   nx=Integer.parseInt(s);
  int result = object_fib.f(nx);				
  System.out.println(result);
 }	
}
