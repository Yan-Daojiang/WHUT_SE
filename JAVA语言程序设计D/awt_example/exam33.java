public class exam33{
 int count;
 void exam33(){count=10;}
 public void change_int(int x){x++;this.count=x;}

 public static void main(String args[])
 {int c=30;
  exam33 test_obj=new exam33();
  System.out.println("count="+test_obj.count);
  test_obj.change_int(c);
  System.out.println("count="+test_obj.count);
  System.out.println("c=  "+c);}
}