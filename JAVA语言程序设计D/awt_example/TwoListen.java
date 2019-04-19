import java.awt.*;
import java.awt.event.*;

//TwoListen��ͬʱʵ��MouseMotionListener
//��MouseListener�����ӿ�
public class TwoListen implements MouseMotionListener,MouseListener{
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

   //ע���������
    f.addMouseMotionListener(this);
   //���¼��������ʵ���ˡ��¼����������ܵĳ��򣬱�����Ϊ
   //this.mouseMoved������this.mouseDragged()������ע��
   //MouseMotion�¼����Ա���f�Ϸ�����MouseMotion�¼���
   //this.mouseMoved������this.mouseDragged()�������Դ�����Щ�¼�
    f.addMouseListener(this);

    f.setSize(300,300);
    f.setVisible(true);
   }


//ʵ��MouseMotionListener�ӿ��еķ���
public void mouseDragged(MouseEvent e){
   String s="Mouse dragging:X="+e.getX()+"Y="+e.getY();
   tf.setText(s);
   }

public void mouseMoved(MouseEvent e){}

//ʵ��MouseListener�ӿ��еķ���
public void mouseClicked(MouseEvent e){}


public void mouseEntered(MouseEvent e){
 String s="the mouse entered";
 tf.setText(s);
}


public void mouseExited(MouseEvent e){
String s="the mouse has left the building";
 tf.setText(s);
}

public void mousePressed(MouseEvent e){}
  
public void mouseReleased(MouseEvent e){}
}