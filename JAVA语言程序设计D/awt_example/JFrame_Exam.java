//JFrame_Exam.java 使用JFrame创建窗口
import java.awt.*;
import javax.swing.*;
public class JFrame_Exam extends JFrame{
  public static void main(String args[]){
   JFrame_Exam mainJFrame=new JFrame_Exam();
   mainJFrame.setTitle("JFrame框架示例！");
   mainJFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); 
   mainJFrame.setSize(300,300);
   mainJFrame.setLocationRelativeTo(null);
   mainJFrame.getContentPane().setLayout(new FlowLayout());
   mainJFrame.getContentPane().setBackground(Color.green);
   JLabel lb1=new JLabel("大家好，我是一个标签！");
   JButton btn=new JButton("按钮");  
   mainJFrame.getContentPane().add(lb1);
   mainJFrame.getContentPane().add(btn);
   mainJFrame.setVisible(true);
   }
}