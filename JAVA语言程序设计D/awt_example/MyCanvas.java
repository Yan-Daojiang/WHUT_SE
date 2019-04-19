import java.awt.*;
import java.awt.event.*;
import java.util.*;

public class MyCanvas implements KeyListener,MouseListener
{
  Canvas c;
  TextField t;
  Frame f;
  String s="";

  public static void main(String args[]){
    MyCanvas  mc=new MyCanvas();
    mc.go();
   }

    public void go(){
    Frame f=new Frame("Canvas");
    t=new TextField();
    c=new Canvas();
    f.add("South",t);
    f.add("Center",c);
    f.setSize(500,400);
    c.addMouseListener(this);
    c.addKeyListener(this);
    f.setVisible(true);
    }

  //ʵ��KeyListener�ӿ��еķ���
  public void keyTyped(KeyEvent ev){
   t.setText("keyTyped");
   s+=ev.getKeyChar();

    //���û�������ַ�д��������
    c.getGraphics().drawString(s,0,20);
   }

   public void keyPressed(KeyEvent ev){}

   public void keyReleased(KeyEvent ev){
    t.setText("keyReleased");
   }

  //ʵ��MouseListener�ӿ��еķ���
  public void mouseClicked(MouseEvent ev){
   t.setText("mouseClicked");  //ǿ�ƻ�����ȡ���뽹��
   c.requestFocus();
  }
 
  public void mousePressed(MouseEvent ev){
   t.setText("mousePressed"); 
   c.getGraphics().setColor(Color.orange);             
   c.getGraphics().drawLine(0, 0, ev.getX(), ev.getY()); 
  }


public void mouseReleased(MouseEvent ev){
   t.setText("mouseReleased"); 
  }

public void mouseEntered(MouseEvent ev){
   t.setText("mouseEntered"); 
  }

public void mouseExited(MouseEvent ev){
   t.setText("mouseExited"); 
  }
 }
