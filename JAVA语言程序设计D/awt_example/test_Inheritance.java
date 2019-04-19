   class Employee
   {
   protected String name;
   protected String hireDate;
   protected String dateOfBirth;
   protected String  jobTitle;
   protected int grade;
   protected String department;
   public String getName(){return name;}
   public String getHireDate(){return hireDate;}
   }

   class Manager extends Employee{
    private int stocks;
    public void setStocks(int s)    {  stocks=s; }
    public void show()
    {   System.out.println(super.name+"¡¯s stocks is "+stocks); }
      }
    
    public class test_Inheritance{    
    
      public static void main(String args[])    { 
      Manager m=new Manager();  
      m.setStocks(100000);   
      m.name="John"; 
      m.show();} 
     }