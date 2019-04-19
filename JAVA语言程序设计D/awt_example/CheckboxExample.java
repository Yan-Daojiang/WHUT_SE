import java.awt.*;
import java.awt.event.*;

public class CheckboxExample extends 
    WindowAdapter implements ItemListener 
{
  private Frame f;
  Panel p;
  Checkbox one,two,three;
  TextField tf;

  public static void main(String args[]){
   CheckboxExample ce=new CheckboxExample();
   ce.go();
   }
  
  public void go(){
   f=new Frame("Checkbox Example");
   p=new Panel();

   one=new Checkbox("One");
   two=new Checkbox("Two");
   three=new Checkbox("three");

   //注册监听程序
   one.addItemListener(this);
   two.addItemListener(this);
   three.addItemListener(this);

   p.add(one); 
   p.add(two); 
   p.add(three); 

   f.add(p,"Center");
   tf=new TextField();
   f.add(tf,"South");

   //注册监听程序
    
    f.addWindowListener(this);

    f.setSize(300,150);
    f.setVisible(true);
   }

//实现ItemListener接口中的itemStateChanged方法
public void itemStateChanged(ItemEvent e){
 String state="deselected";
 String st;

 if(e.getStateChange()==ItemEvent.SELECTED){
  state="selected";
  }
  st=e.getItem()+"  "+state;
  tf.setText(st);  
}

//覆盖WindowAdapter类中的windorClosing()方法
 public void windowClosing(WindowEvent e){
   System.exit(0);
}
}
 

