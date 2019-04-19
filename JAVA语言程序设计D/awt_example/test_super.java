class A{ 
 protected int x; 
 A(){x=5;}
 }

class B extends A
 { protected int x;  
   B(){ x=8;}
   void show(){
    System.out.println("this x is "+x);
    System.out.println("super x is "+super.x);
 }
}
public class test_super
  {    public static void main(String args[])   
    {  B b1=new B();   
       b1.show();}  
 } 