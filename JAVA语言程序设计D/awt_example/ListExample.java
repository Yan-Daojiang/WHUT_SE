import java.awt.*;
import java.awt.event.*;

public class ListExample extends Frame
    implements ItemListener{
 Panel p;
 TextField tf;
 List theList;
 
 ListExample(String s) {super(s);}

 static public void main(String args[]){
   ListExample le=new ListExample("ListExample");
   le.init();
 }

 public void init(){
  theList=new List(5,false);
  theList.addItem("Monday");
  theList.addItem("Tuesday");
  theList.addItem("Wednesday");
  theList.addItem("Thursday");
  theList.addItem("Friday");
  theList.addItem("Saturday");
  theList.addItem("Sunday");

  //×¢²á¼àÌý³ÌÐò
  theList.addItemListener(this);
  p=new Panel();
  p.add(theList);
  add(p,"Center");
  tf=new TextField();
  add(tf,"South");
  setSize(300,200);
  setVisible(true);
}
  public void itemStateChanged(ItemEvent e){
    tf.setText(theList.getSelectedItem());
}
}
