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
 //�����˵���
 MenuBar mb=new MenuBar();
 setMenuBar(mb);

 //����File�˵�
 Menu m1=new Menu("File");
 m1.add(new MenuItem("Open..."));
 MenuItem mi1=new MenuItem("Save");
 mi1.setEnabled(false);
 m1.add(mi1);
 m1.add("Close");
 m1.addSeparator();//�ӷֽ���
 m1.add("Exit");

 //ע���������
 m1.addActionListener(this);
 mb.add(m1);
 
 //����Option�˵�
 Menu m2=new Menu("Option");
 m2.add("Font...");

 //�����Ӳ˵�
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

 //����Help�˵�
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

  //ʵ��ItemListener�ӿ��еķ���
  public void itemStateChanged(ItemEvent e){
    tf.setText("ItemStateChanged");
  }


  //ʵ��ActionListener�ӿ��еķ���
  public void actionPerformed(ActionEvent e){
   tf.setText(e.getActionCommand());
   if(e.getActionCommand()=="Exit"){
        System.exit(0);
}}}

 