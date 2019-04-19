import java.awt.Graphics;
import java.applet.*;

public class HwLoop extends Applet{
 AudioClip sound;

 public void init(){
  sound=getAudioClip(getDocumentBase(),"me.mp3");
  }

public void paint(Graphics g){
  g.drawString("Audio Test!",50,50);
}

public void start(){
  sound.loop();
}

public void stop(){
 sound.stop();
}
}