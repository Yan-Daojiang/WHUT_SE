import java.awt.*;
import java.awt.event.*;

public class ChoiceExample {
  private Frame f;
  Choice c;
  Label l;

  public static void main(String args[]){
   ChoiceExample ce=new ChoiceExample();
   ce.go();
   }
  
  public void go(){
   f=new Frame();
   f.setLayout(new FlowLayout());
   l=new Label("your choice: ");

   f.add(l);
   c=new Choice();
   c.addItem("First");
   c.addItem("Second");
   c.addItem("Third");
   
   f.add(c);
    f.setSize(300,150);
    f.setVisible(true);
   }
}