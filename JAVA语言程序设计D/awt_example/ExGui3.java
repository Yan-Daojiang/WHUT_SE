import java.awt.*;
public class ExGui3{
  private Frame f;
  private Panel p;
  private Button bw,bc;
  private Button bfile,bhelp;



  public static void main(String args[]){
   ExGui3 gui=new ExGui3();
   gui.go();
   }

   public void go(){
    f=new Frame("Gui Example");
    
    bw=new Button("West");
    bc=new Button("Work space region");
    
    f.add(bw,"West");
    f.add(bc,"Center");
    p=new Panel();
    f.add(p,"North");

    bfile=new Button("File");
    bhelp=new Button("Help");

    p.add(bfile);
    p.add(bhelp);

    f.pack();
    f.setVisible(true);
   }
  }
 