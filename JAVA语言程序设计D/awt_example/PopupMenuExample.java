import java.awt.*;
import java.awt.event.*;

public class PopupMenuExample implements ActionListener{
 
 Frame f;
 Button b;
 PopupMenu pm;

 
 static public void main(String args[]){
   PopupMenuExample pme=new PopupMenuExample();
   pme.init();
 }


 
 public void init(){
  f=new Frame("PopupMenu Example");
  b=new Button("Press me");
  //注册监听程序
  b.addActionListener(this);
  f.add(b,"Center");

 //创建弹出式菜单
 pm=new PopupMenu("Popup");
 //加入菜单项
 pm.add(new MenuItem("New"));
 pm.add(new MenuItem("Load"));
 pm.add(new MenuItem("Save"));
 pm.add(new MenuItem("Save as..."));
 f.add(pm);
 f.setSize(200,200);
 f.setVisible(true);
}


  //实现ActionListener接口中的方法
  public void actionPerformed(ActionEvent e){
   //以按钮b的位置为参考原点，在(10,10)处显示弹出式菜单
  pm.show(b,10,10);
}}

 