import java.awt.*;
import java.awt.event.*;

public class MenuExample extends Frame
    implements ItemListener,ActionListener{
 
 TextField tf;
 public MenuExample(){
  super("Menu Example");
  setSize(300,200);
}

 public void init(){
 //建立菜单栏
 MenuBar mb=new MenuBar();
 setMenuBar(mb);

 //建立File菜单
 Menu m1=new Menu("File");
 m1.add(new MenuItem("Open..."));
 MenuItem mi1=new MenuItem("Save");
 mi1.setEnabled(false);
 m1.add(mi1);
 m1.add("Close");
 m1.addSeparator();//加分界线
 m1.add("Exit");

 //注册监听程序
 m1.addActionListener(this);
 mb.add(m1);
 
 //建立Option菜单
 Menu m2=new Menu("Option");
 m2.add("Font...");

 //建立子菜单
 Menu ms=new Menu("Color...");
 ms.add("ForeGround");
 ms.add("BackGround");
 ms.addActionListener(this);
 m2.add(ms);

 m2.addSeparator();
 CheckboxMenuItem cm=new CheckboxMenuItem("Always on Top");
 cm.addItemListener(this);
 m2.add(cm);

 m2.addActionListener(this);
 mb.add(m2);

 //建立Help菜单
 Menu h=new Menu("Help");
 h.add("about...");

 h.addActionListener(this);
 mb.setHelpMenu(h);

 tf=new TextField();
 add("South",tf);
}

 static public void main(String args[]){
   MenuExample me=new MenuExample();
   me.init();
   me.setVisible(true);
 }

  //实现ItemListener接口中的方法
  public void itemStateChanged(ItemEvent e){
    tf.setText("ItemStateChanged");
  }


  //实现ActionListener接口中的方法
  public void actionPerformed(ActionEvent e){
   tf.setText(e.getActionCommand());
   if(e.getActionCommand()=="Exit"){
        System.exit(0);
}}}

 