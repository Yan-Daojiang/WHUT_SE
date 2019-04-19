import java.awt.*;
import java.awt.event.*;

public class CheckboxGroupExample extends 
    WindowAdapter implements ItemListener 
{
  private Frame f;
  Panel p;
  CheckboxGroup cbg;
  Checkbox one,two,three;
  TextField tf;

  public static void main(String args[]){
   CheckboxGroupExample ce=new CheckboxGroupExample();
   ce.go();
   }
  
  public void go(){
   f=new Frame("CheckboxGroup Example");
   p=new Panel();

   cbg=new CheckboxGroup();
   one=new Checkbox("One",cbg,false);
   two=new Checkbox("Two",cbg,false);
   three=new Checkbox("three",cbg,true);

   //ע���������
   one.addItemListener(this);
   two.addItemListener(this);
   three.addItemListener(this);

   p.add(one); 
   p.add(two); 
   p.add(three); 

   f.add(p,"Center");
   tf=new TextField("Three selected");
   f.add(tf,"South");

   //ע���������
    
    f.addWindowListener(this);

    f.setSize(300,150);
    f.setVisible(true);
   }

//ʵ��ItemListener�ӿ��е�itemStateChanged����
public void itemStateChanged(ItemEvent e){
 
 String st;

 
  st=e.getItem()+"  selected ";
  tf.setText(st);  
}

//����WindowAdapter���е�windorClosing()����
 public void windowClosing(WindowEvent e){
   System.exit(0);
}
}
 

