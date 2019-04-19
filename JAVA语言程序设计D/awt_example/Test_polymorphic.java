class Person{ 
  private String name;
  private int age;
  public void setName(String name)
    {	this.name = name;	}
  public String getName()           {	return name;}  
  public void setAge(int age)
     {	this.age = age;	}
  public int getAge(){	return age;	}	
  public String getInfo()
    {	return "Name: " + name + "\tAge: " + age;}
  public  void    setschool(  String  school ){}
}

class Student extends Person
{  private String school;
   public void setSchool(String school){	this.school = school;	}  
   public String getSchool(){	return school;	}
   public String getInfo()
   {return super.getInfo() + "\tSchool: " + school; 	}

}

class Tp
{
   public void tp_gi(Person px)
   {
     System.out.println(px.getInfo());
   }
}


public class Test_polymorphic
 {
    public static void main(String[] args)
    {	Person p1 = new Student();
     // p1.setSchool("WHU");
	p1.setName("÷‹∞«∆§");
        p1.setAge(120);
        System.out.println(p1.getInfo());
        
        Person p2 = new Person();
      //  p2.setSchool("WHU");
        p2.setName("÷‹∞«∆§");
        p2.setAge(120);
        System.out.println(p2.getInfo());

        Student p3 = new Student();
        p3.setSchool("WHU");
	p3.setName("÷‹∞«∆§");
        p3.setAge(120);
	System.out.println(p3.getInfo());

        Student p4=(Student)p1;
        p4.setSchool("WHU");
	p4.setName("÷‹∞«∆§");
        p4.setAge(120);
        System.out.println(p4.getInfo());
         
        System.out.println();
        
        Tp tp1=new Tp();
        tp1.tp_gi(p1);
        tp1.tp_gi(p2);
        tp1.tp_gi(p3);
        tp1.tp_gi(p4);

        System.out.println();

        System.out.println(p1.getInfo());
        

   }
 }