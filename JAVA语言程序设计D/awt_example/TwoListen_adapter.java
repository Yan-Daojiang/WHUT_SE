import java.awt.*;
import java.awt.event.*;

//TwoListen类继承自MouseAdapter,MouseAdapter实现了
//MouseListener接口,但MouseAdapter中所有方法都为空
public class TwoListen_adapter extends MouseAdapter{
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
}