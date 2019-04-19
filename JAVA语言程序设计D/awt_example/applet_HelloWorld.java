import java.awt.Graphics;
import java.applet.Applet;

public class applet_HelloWord extends Applet{
 String hw_text;
 public void init(){
  hw_text="Hello World";
}
 
public void paint(Graphics g){
  g.drawString(hw_text,25,25);
 }
}