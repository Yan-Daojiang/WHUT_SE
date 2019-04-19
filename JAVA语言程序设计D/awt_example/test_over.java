class Person
 {String name;  int age;
  Person(String n,int a){name=n;age=a;}
  public String getInfo()
  {return "Name:"+ name + "\t" +"age:"+ age;}
}
class Student extends Person 
{private String school; 
 public void setSchool(String school){	 this.school = school;}
 public String getSchool()
 {return school;}
 Student(String n,int a){super(n,a);}
 protected String getInfo() 
{  
   return "Name:"+ name + "\tAge:"+ age + "\tSchool:" + school;}
 }

public class test_over
 {public static void main(String args[])   
   {
   Student s=new Student("郎能饮",35);
   s.setSchool("武汉理工大学");
   System.out.println(s.getInfo());    
  }
}