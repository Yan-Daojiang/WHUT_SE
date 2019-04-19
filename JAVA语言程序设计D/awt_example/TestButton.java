import java.awt.*;


import java.awt.event.*;

public class TestButton{
  
  public static void main(String args[]){
   
    Frame f=new Frame("Test Button");
    Button b=new Button("Press me");


    b.addActionListener(new ButtonHandler());
    f.add("Center",b);

    f.pack();
    f.setVisible(true);
   }
  }

class ButtonHandler implements ActionListener{
 public void actionPerformed(ActionEvent e){
  System.out.println("Action occurred"); 
}
}