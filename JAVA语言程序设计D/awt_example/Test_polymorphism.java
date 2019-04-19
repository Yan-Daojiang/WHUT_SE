import person_student.*;


class Tp
{
   public void tp_gi(Person px)
   {
     System.out.println(px.getInfo());
   }
}

public class Test_polymorphism
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