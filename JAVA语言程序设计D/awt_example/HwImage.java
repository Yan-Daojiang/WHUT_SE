import java.awt.*;
import java.applet.Applet;

public class HwImage extends Applet{
 Image one;

 public void init(){
  one=getImage(getDocumentBase(),"one.gif");
  }

public void paint(Graphics g){
  g.drawImage(one,25,25,this);
  g.drawString("Hello,one!",25,25);
}
}
