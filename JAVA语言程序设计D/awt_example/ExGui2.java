import java.awt.*;
public class ExGui2{
  private Frame f;
  private Button be,bw,bn,bs,bc;


  public static void main(String args[]){
   ExGui2 that=new ExGui2();
   that.go();
   }

   public void go(){
    f=new Frame("Border Layout");
    
    be=new Button("East");
    bs=new Button("South");
    bw=new Button("West");
    bn=new Button("North");
    bc=new Button("Center");


    f.add(be,"East");
    f.add(bs,"South");
    f.add(bw,"West");
    f.add(bn,"North");
    f.add(bc,"Center");

    f.setSize(350,200);
    f.setVisible(true);
   }
  }
 