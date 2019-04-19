import java.awt.*;
import java.awt.event.*;

public class DialogExample extends WindowAdapter
    implements ActionListener{
 
 Frame f;
 Button b;
 Dialog d;

 static public void main(String args[]){
   DialogExample de=new DialogExample();
   de.go();
 }

 public void go(){
  f=new Frame("Dialog Example");
  b=new Button("Show Dialog");
  b.addActionListener(this);
  f.add("South",b);

  d=new Dialog(f,"Dialog",true);
  d.add("Center",new Label("Hello,I'm a Dialog"));
  d.pack();
  d.addWindowListener(this);
  f.setSize(300,200);
  f.setVisible(true);
}
  public void actionPerformed(ActionEvent e){
    d.setVisible(true);
   }
  public void windowClosing(WindowEvent e){
   d.setVisible(false); 
  }  
}
