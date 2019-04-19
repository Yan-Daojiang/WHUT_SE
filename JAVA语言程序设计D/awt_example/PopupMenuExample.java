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
  //ע���������
  b.addActionListener(this);
  f.add(b,"Center");

 //��������ʽ�˵�
 pm=new PopupMenu("Popup");
 //����˵���
 pm.add(new MenuItem("New"));
 pm.add(new MenuItem("Load"));
 pm.add(new MenuItem("Save"));
 pm.add(new MenuItem("Save as..."));
 f.add(pm);
 f.setSize(200,200);
 f.setVisible(true);
}


  //ʵ��ActionListener�ӿ��еķ���
  public void actionPerformed(ActionEvent e){
   //�԰�ťb��λ��Ϊ�ο�ԭ�㣬��(10,10)����ʾ����ʽ�˵�
  pm.show(b,10,10);
}}

 