import java.awt.*;
import java.awt.event.*;

public class ButtonExample extends 
    WindowAdapter implements ActionListener 
{
  private Frame f;
  private Button b;
  private TextField tf;
  int tag=0;

  public static void main(String args[]){
   ButtonExample be=new ButtonExample();
   be.go();
   }
  
  public void go(){
   f=new Frame("Button example");
   b=new Button("Sample");
   //注册监听程序
   b.addActionListener(this);
   f.add(b,"South"); 
   tf=new TextField();
   f.add(tf,"Center");

   //注册监听程序
    
    f.addWindowListener(this);

    f.setSize(300,150);
    f.setVisible(true);
   }

//实现ActionListener接口中的actionPerformed方法
public void actionPerformed(ActionEvent e){
 String s1="You have pressed the Button!";
 String s2="You do another time!";

 if(tag==0){
  tf.setText(s1);
  tag=1;
  }
  else{
  tf.setText(s2);
  tag=0;
  }
}

//覆盖WindowAdapter类中的windorClosing()方法
 public void windowClosing(WindowEvent e){
   System.exit(0);
}
}
 

