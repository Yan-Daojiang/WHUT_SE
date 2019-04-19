import java.awt.*;
public class MyFlow{
  private Frame f;
  private Button b1,b2,b3;


  public static void main(String args[]){
   MyFlow mf=new MyFlow();
   mf.go();
   }

   public void go(){
    f=new Frame("Flow Layout");
    f.setLayout(new FlowLayout());
    b1=new Button("Hello!");
    b2=new Button("Hello World!");
    b3=new Button("Hello Java World!");


    f.add(b1);
    f.add(b2);
    f.add(b3);
    f.setSize(200,100);
    f.setVisible(true);
   }
  }
 