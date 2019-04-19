import java.awt.*;
public class M{
  private Frame f;
  private Button b1,b2,b3;


  public static void main(String args[]){
   M mf=new M();
   mf.go();
   }

   public void go(){
    f=new Frame("Flow Layout");
    f.setLayout(new FlowLayout());
    b1=new Button("OK");
    b2=new Button("Open");
    b3=new Button("Close");


    f.add(b1);
    f.add(b2);
    f.add(b3);
    f.setSize(200,100);
    f.setVisible(true);
   }
  }
 