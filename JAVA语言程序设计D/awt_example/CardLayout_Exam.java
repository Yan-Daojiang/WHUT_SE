//CardLayout_Exam.java CardLayout���ֹ�������Ӧ��
import java.awt.*;
import javax.swing.*;
public class CardLayout_Exam{
  
  static JFrame mainJFrame=new JFrame("CardLayoutʾ����");
  static JPanel pnl1=new JPanel();
  static JPanel pnl2=new JPanel();
  static String[] str={"��һҳ","��һҳ","��һҳ","���ҳ"};
  static CardLayout card=new CardLayout(5,10);
  public static void main(String args[]){
   mainJFrame.setSize(400,400);
   mainJFrame.setResizable(false);
   Container container=mainJFrame.getContentPane();
   container.setBackground(Color.red);
   container.setLayout(null);
   
   pnl1.setLayout(card);
   pnl1.setBounds(10,10,320,160);
   pnl2.setLayout(new GridLayout(1,4));
   pnl2.setBounds(10,180,320,35);
   for(int i=1;i<4;i++){
    String str=new String("��"+i+"ҳ");
    JTextField text=new JTextField("��Ƭ���ֲ���!!"+str,30);
    pnl1.add(text,"t"+i);
   }
   
   card.show(pnl1,"t3");
   for(int i=0;i<str.length;i++){
     JButton b=new JButton(str[i]);
     pnl2.add(b);
   }
   container.add(pnl1);
   container.add(pnl2);
   mainJFrame.setVisible(true);
}}
   