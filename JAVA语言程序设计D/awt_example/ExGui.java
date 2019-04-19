import java.awt.*;
public class ExGui{
  private Frame f;
  private Button b1;
  private Button b2;


  public static void main(String args[]){
   ExGui that=new ExGui();
   that.go();
   }

   public void go(){
    f=new Frame("GUI example");
    f.setLayout(new FlowLayout());
    b1=new Button("Press me");
    b2=new Button("Don't press Me");

    f.add(b1);
    f.add(b2);
    f.pack();
    f.setVisible(true);
   }
  }
 