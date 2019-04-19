interface  ICalC{
  int add(int a, int b); 
  int substract(int a, int b); 
 }

class Person{ 
  private ICalC mytool; 
  public void setCalCulator(ICalC tool)  
  {   this.mytool=tool;    }   
  public void calculate()    { 
      System.out.println(mytool.add(12,13));  
      System.out.println(mytool.substract(13,12)); 
  }}

class CalCulator implements ICalC{
 public int add(int a, int b) { return a+b; }
 public int substract(int a, int b)  { return a-b; }}
 
public class Interface_Test { 
  public static void main(String args[]) 
  {  Person  p=new Person();  
     p.setCalCulator(new CalCulator());  
     p.calculate(); }
}