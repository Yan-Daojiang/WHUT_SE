//JFrame_Exam.java ʹ��JFrame��������
import java.awt.*;
import javax.swing.*;
public class JFrame_Exam extends JFrame{
  public static void main(String args[]){
   JFrame_Exam mainJFrame=new JFrame_Exam();
   mainJFrame.setTitle("JFrame���ʾ����");
   mainJFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); 
   mainJFrame.setSize(300,300);
   mainJFrame.setLocationRelativeTo(null);
   mainJFrame.getContentPane().setLayout(new FlowLayout());
   mainJFrame.getContentPane().setBackground(Color.green);
   JLabel lb1=new JLabel("��Һã�����һ����ǩ��");
   JButton btn=new JButton("��ť");  
   mainJFrame.getContentPane().add(lb1);
   mainJFrame.getContentPane().add(btn);
   mainJFrame.setVisible(true);
   }
}