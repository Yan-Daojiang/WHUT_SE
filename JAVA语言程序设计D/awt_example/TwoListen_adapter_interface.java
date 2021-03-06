import java.awt.*;
import java.awt.event.*;

//TwoListen类继承自MouseAdapter,MouseAdapter实现了
//MouseListener接口,但MouseAdapter中所有方法都为空
//同时，TwoListen类还实现了MouseMoutionListener接口
public class TwoListen_adapter_interface extends 
    MouseAdapter implements MouseMotionListener 
{
  private Frame f;
  private TextField tf;

  public static void main(String args[]){
   TwoListen two=new TwoListen();
   two.go();
   }
  
  public void go(){
   f=new Frame("Two listeners example");
   f.add(new Label("Click and drag the mouse"),"North"); 
   tf=new TextField(30);
   f.add(tf,"South");

   //注册监听程序
    f.addMouseMotionListener(this);
   //向事件处理程序（实现了“事件监听”功能的程序，本例中为
   //this.mouseMoved（）、this.mouseDragged()方法）注册
   //MouseMotion事件，以便在f上发生了MouseMotion事件后，
   //this.mouseMoved（）、this.mouseDragged()方法可以处理这些事件
 
    f.addMouseListener(this);

    f.setSize(300,300);
    f.setVisible(true);
   }

//实现MouseListener接口中感兴趣的方法
public void mouseEntered(MouseEvent e){
 String s="the mouse entered";
 tf.setText(s);
}


public void mouseExited(MouseEvent e){
String s="the mouse has left the building";
 tf.setText(s);
}


//实现MouseMotionListener接口中的方法
  public void mouseDragged(MouseEvent e){
   String s="Mouse dragging:X="+e.getX()+"Y="+e.getY();
   tf.setText(s);
   }

  public void mouseMoved(MouseEvent e){}
}




