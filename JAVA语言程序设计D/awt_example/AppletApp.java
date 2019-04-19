import java.awt.*;
import java.awt.event.*;
import java.applet.Applet;

public class AppletApp extends Applet{

 public static void main(String args[]){
  Frame frame=new Frame("Application");
  AppletApp app=new AppletApp();
  frame.add("Center",app);
  frame.setSize(200,200);
  frame.validate();
  frame.setVisible(true);
  frame.addWindowListener(new WindowControl(app));

  app.init();
  app.start();
}
 
public void paint(Graphics g){
  g.drawString("Hello World!",25,25);
 }

public void destroy(){
 System.exit(0);
 }
}

class WindowControl extends WindowAdapter{
 Applet c;
 public WindowControl(Applet c){
  this.c=c;
 }

 public void windowClosing(WindowEvent e){
  c.destroy();
}
}