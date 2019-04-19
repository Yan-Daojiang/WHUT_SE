import java.awt.*;
import java.awt.event.*;
import java.applet.Applet;

public class HwMouse extends Applet implements MouseListener{
 int mouseX=25;
 int mouseY=25;

 public void init(){
  addMouseListener(this);
}
 
public void paint(Graphics g){
  g.drawString("Hello World!",mouseX,mouseY);
 }

public void mousePressed(MouseEvent evt){
 mouseX=evt.getX();
 mouseY=evt.getY();
 repaint();
}

public void mouseClicked(MouseEvent e){}
public void mouseEntered(MouseEvent e){}
public void mouseExited(MouseEvent e){}
public void mouseReleased(MouseEvent e){}
}
