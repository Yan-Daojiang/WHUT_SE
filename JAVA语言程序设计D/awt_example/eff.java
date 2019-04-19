import java.math.*;
public class eff{ public double f(double x) {return Math.sin(x)-1/x;} 
 public double get_root(double a,double b)
  {  if(Math.abs(a-b)<1e-5){return (a+b)/2;} 
     if(f((a+b)/2)*f(b)>0){return get_root(a,(a+b)/2);}   
     return get_root((a+b)/2,b);  
  } public static void main(String args[])
    { eff p=new eff(); System.out.println(p.get_root(1e-2,Math.PI/2));}	
  }