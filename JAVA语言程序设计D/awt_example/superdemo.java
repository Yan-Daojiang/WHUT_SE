public class superdemo
 {    public static void main(String args[])
    {  Child c=new Child();  
       c.show();}  }

class Parent{
  public int add(int a, int b)
     { return  a+b; }  }

class Child extends Parent{
   public void show()    { 
 	int iresult=super.add(12,13);  
  	System.out.println(iresult); } }