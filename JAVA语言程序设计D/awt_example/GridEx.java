import java.awt.*;
public class GridEx{
  private Frame f;
  private Button b1,b2,b3,b4,b5,b6;


  public static void main(String args[]){
   GridEx that=new GridEx();
   that.go();
   }

   public void go(){
    f=new Frame("Grid Layout Example");
    f.setLayout(new GridLayout(3,2));
    
    b1=new Button("b1");
    b2=new Button("b2");
    b3=new Button("b3");
    b4=new Button("b4");
    b5=new Button("b5");
    b6=new Button("b6");

    f.add(b1);
    f.add(b2);
    f.add(b3);
    f.add(b4);
    f.add(b5);
    f.add(b6);

    f.pack();
    f.setVisible(true);
   }
  }
 