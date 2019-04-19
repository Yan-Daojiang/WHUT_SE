import java.awt.*;
public class a37{
  private Frame f;
  private Button be,bn,bs,bc;

  public static void main(String args[ ]){
   a37 ex=new a37();
   ex.go();
  }

  public void go(){
    f=new Frame("Border Layout Test");
    be=new Button("East");
    bs=new Button("South");
    bn=new Button("North");
    bc=new Button("Center");

    f.add(be,"East");
    f.add(bs,"South");
    f.add(bn,"North");
    f.add(bc,"Center");

    f.setSize(300,200);
    f.setVisible(true);}
} 

