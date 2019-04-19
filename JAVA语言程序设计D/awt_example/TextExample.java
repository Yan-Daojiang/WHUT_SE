import java.awt.*;
import java.awt.event.*;

public class TextExample implements ActionListener,TextListener  
{
  Frame f;
  TextField tf1;
  TextArea ta1,ta2;

  public static void main(String args[]){
   TextExample te=new TextExample();
   te.go();
   }
  
  public void go(){
   f=new Frame("Text Example");
   f.setLayout(new FlowLayout());

   tf1=new TextField("Init",20);
   //注册监听程序
   tf1.addActionListener(this);
   tf1.addTextListener(this);
   
   ta1=new TextArea("Initial text",4,30);
   ta1.addTextListener(this);
   ta2=new TextArea("Only horizontal scrollbar",4,30,TextArea.SCROLLBARS_HORIZONTAL_ONLY);

   f.add(tf1); 
   f.add(ta1); 
   f.add(ta2); 
   
    f.setSize(400,500);
    f.setVisible(true);
}

//实现ActionListener接口中的方法
public void actionPerformed(ActionEvent e){
 
 ta2.append("\nActionPerformed");
}


public void textValueChanged(TextEvent e){
 ta2.append("\n TextValueChanged");
}
}
 

