//CardLayout_Exam.java CardLayout布局管理器的应用
import java.awt.*;
import javax.swing.*;
import java.awt.event.*;


public class GridLayout_Exam extends JFrame 
      implements MouseListener{
  
  static JPanel pnl=new JPanel();
  static JTextField text=new JTextField("");
  static String[] name={"1","2","3","*","4","5","6","/",
       "7","8","9","+","0",".","-","=","CE","+/-"};
  static String flag="read_op1";
  //flag有四种状态："read_op1","read_op2","read_pmmd","read_is"
  static boolean point_flag=false;
  static double op1;
  static double op2;
  static String pmmd;
  static double result;
  public JButton btn1;
  public JButton btn2;
  public JButton btn3;
  public JButton btn4;
  public JButton btn5;
  public JButton btn6;
  public JButton btn7;
  public JButton btn8;
  public JButton btn9;
  public JButton btn0;
  public JButton btn_plus;
  public JButton btn_minus;
  public JButton btn_mul;
  public JButton btn_divide;
  public JButton btn_point;
  public JButton btn_is;
  public JButton btn_clear;
  public JButton btn_sign;


  public static void main(String args[]){
   GridLayout_Exam mainJFrame=new GridLayout_Exam();
                           //mainJFrame为顶层容器
   mainJFrame.setTitle("GridLayout Example");
   mainJFrame.setResizable(false); //窗口大小不可变
   mainJFrame.setSize(250,300);
   mainJFrame.setLocationRelativeTo(null); //使窗口位于桌面的中央
   Container container=mainJFrame.getContentPane(); 
                             //container为中间层的容器
   container.setLayout(null); //使container的缺省布局管理器无效
   container.add(pnl);
   container.add(text);
   mainJFrame.setVisible(true);

   text.setBounds(20,10,200,30);
            //使文本框位于（20,10）处，文本框大小为200*30
   text.setBackground(Color.yellow);
   text.setHorizontalAlignment(JTextField.RIGHT); 

   GridLayout grid=new GridLayout(5,3);
   pnl.setLayout(grid);
   pnl.setBounds(20,45,200,200);
           //使容器pn1位于（20,45）处，大小为200*200

   mainJFrame.go();
  }

  public void go(){   

    btn1 =new JButton(name[0]);
    btn1.setSize(20,20);
    btn1.setMargin(new Insets(4,4,4,4));
      //Insets(int,   int,   int,   int):指定的上、下、左、右四个空白宽度
      // public void setMargin(Insets m):设置按钮边框和标签之间的空白    
    pnl.add(btn1);
    btn1.addMouseListener(this);



    btn2 =new JButton(name[1]);
    btn2.setSize(20,20);
    btn2.setMargin(new Insets(4,4,4,4));
    pnl.add(btn2);
    btn2.addMouseListener(this);

    btn3 =new JButton(name[2]);
    btn3.setSize(20,20);
    btn3.setMargin(new Insets(4,4,4,4));
    pnl.add(btn3);
    btn3.addMouseListener(this);

    btn_mul=new JButton(name[3]);
    btn_mul.setSize(20,20);
    btn_mul.setMargin(new Insets(4,4,4,4));
    pnl.add(btn_mul);
    btn_mul.addMouseListener(this);

    btn4=new JButton(name[4]);
    btn4.setSize(20,20);
    btn4.setMargin(new Insets(4,4,4,4));
    pnl.add(btn4);
    btn4.addMouseListener(this);

    btn5=new JButton(name[5]);
    btn5.setSize(20,20);
    btn5.setMargin(new Insets(4,4,4,4));
    pnl.add(btn5);
    btn5.addMouseListener(this);

    btn6=new JButton(name[6]);
    btn6.setSize(20,20);
    btn6.setMargin(new Insets(4,4,4,4));
    pnl.add(btn6);
    btn6.addMouseListener(this);

    btn_divide=new JButton(name[7]);
    btn_divide.setSize(20,20);
    btn_divide.setMargin(new Insets(4,4,4,4));
    pnl.add(btn_divide);
    btn_divide.addMouseListener(this);

    btn7=new JButton(name[8]);
    btn7.setSize(20,20);
    btn7.setMargin(new Insets(4,4,4,4));
    pnl.add(btn7);
    btn7.addMouseListener(this);

    btn8=new JButton(name[9]);
    btn8.setSize(20,20);
    btn8.setMargin(new Insets(4,4,4,4));
    pnl.add(btn8);
    btn8.addMouseListener(this);

    btn9=new JButton(name[10]);
    btn9.setSize(20,20);
    btn9.setMargin(new Insets(4,4,4,4));
    pnl.add(btn9);
    btn9.addMouseListener(this);

    btn_plus=new JButton(name[11]);
    btn_plus.setSize(20,20);
    btn_plus.setMargin(new Insets(4,4,4,4));
    pnl.add(btn_plus);
    btn_plus.addMouseListener(this);

    btn0=new JButton(name[12]);
    btn0.setSize(20,20);
    btn0.setMargin(new Insets(4,4,4,4));
    pnl.add(btn0);
    btn0.addMouseListener(this);

    btn_point=new JButton(name[13]);
    btn_point.setSize(20,20);
    btn_point.setMargin(new Insets(4,4,4,4));
    pnl.add(btn_point);
    btn_point.addMouseListener(this);

    btn_minus=new JButton(name[14]);
    btn_minus.setSize(20,20);
    btn_minus.setMargin(new Insets(4,4,4,4));
    pnl.add(btn_minus);
    btn_minus.addMouseListener(this);

    btn_is=new JButton(name[15]);
    btn_is.setSize(20,20);
    btn_is.setMargin(new Insets(4,4,4,4));
    pnl.add(btn_is);
    btn_is.addMouseListener(this);
   
    btn_clear=new JButton(name[16]);
    btn_clear.setSize(20,20);
    btn_clear.setMargin(new Insets(4,4,4,4));
    pnl.add(btn_clear);
    btn_clear.addMouseListener(this);

    btn_sign=new JButton(name[17]);
    btn_sign.setSize(20,20);
    btn_sign.setMargin(new Insets(4,4,4,4));
    pnl.add(btn_sign);
    btn_sign.addMouseListener(this);
 }
 
   
   public void mousePressed(MouseEvent e) {  }
   public void mouseReleased(MouseEvent e) {  }
   public void mouseEntered(MouseEvent e) {  }
   public void mouseExited(MouseEvent e) {  }


   public void mouseClicked(MouseEvent e) { 
     if (flag=="read_op1"||flag=="read_op2"){ 
     if(e.getSource()==btn1){text.setText(text.getText()+"1");}
     if(e.getSource()==btn2){text.setText(text.getText()+"2");}
     if(e.getSource()==btn3){text.setText(text.getText()+"3");}
     if(e.getSource()==btn4){text.setText(text.getText()+"4");}
     if(e.getSource()==btn5){text.setText(text.getText()+"5");}
     if(e.getSource()==btn6){text.setText(text.getText()+"6");}
     if(e.getSource()==btn7){text.setText(text.getText()+"7");}
     if(e.getSource()==btn8){text.setText(text.getText()+"8");}
     if(e.getSource()==btn9){text.setText(text.getText()+"9");}
     if(e.getSource()==btn0){text.setText(text.getText()+"0");}
     if(e.getSource()==btn_point && (!point_flag))
      {text.setText(text.getText()+".");
       point_flag=true;}
     if(e.getSource()==btn_sign){
      if(text.getText().charAt(0)=='-')
        {text.setText(text.getText().substring(1));} 
      else
        {text.setText("-"+text.getText());}    
      } 
     }

   if (flag=="read_op1"){ 
     if(e.getSource()==btn_plus)
     {flag="read_pmmd";
      pmmd="+";
      op1=Double.parseDouble(text.getText());
      text.setText("");
      flag="read_op2";
      point_flag=false;

      btn_plus.setEnabled(false);
      btn_minus.setEnabled(false);
      btn_mul.setEnabled(false);
      btn_divide.setEnabled(false);
     }

     if(e.getSource()==btn_minus)
     {flag="read_pmmd";
      pmmd="-";
      op1=Double.parseDouble(text.getText());
      text.setText("");
      flag="read_op2";
      point_flag=false;

      btn_plus.setEnabled(false);
      btn_minus.setEnabled(false);
      btn_mul.setEnabled(false);
      btn_divide.setEnabled(false);
     }
 
     if(e.getSource()==btn_mul)
     {flag="read_pmmd";
      pmmd="*";
      op1=Double.parseDouble(text.getText());
      text.setText("");
      flag="read_op2";
      point_flag=false;

      btn_plus.setEnabled(false);
      btn_minus.setEnabled(false);
      btn_mul.setEnabled(false);
      btn_divide.setEnabled(false);
     }
    }

     if(e.getSource()==btn_divide)
     {flag="read_pmmd";
      pmmd="/";
      op1=Double.parseDouble(text.getText());
      text.setText("");
      flag="read_op2";
      point_flag=false;

      btn_plus.setEnabled(false);
      btn_minus.setEnabled(false);
      btn_mul.setEnabled(false);
      btn_divide.setEnabled(false);
     }

    if(e.getSource()==btn_is && flag=="read_op2")
     {flag="read_op1";
      op2=Double.parseDouble(text.getText());
      switch(pmmd){
      case "+":
       result=op1+op2;
       break;
      case "-":
       result=op1-op2;
       break;
      case "*":
       result=op1*op2;
       break;
      case "/":
       result=op1/op2;
       break;
      }
      text.setText(" "+result);
      btn0.setEnabled(false);
      btn1.setEnabled(false);
      btn2.setEnabled(false);
      btn3.setEnabled(false);
      btn4.setEnabled(false);
      btn5.setEnabled(false);
      btn6.setEnabled(false);
      btn7.setEnabled(false);
      btn8.setEnabled(false);
      btn9.setEnabled(false);
      btn_plus.setEnabled(false);
      btn_minus.setEnabled(false);
      btn_mul.setEnabled(false);
      btn_divide.setEnabled(false);
      btn_point.setEnabled(false);
      btn_sign.setEnabled(false);
      btn_plus.setEnabled(false);
      btn_is.setEnabled(false);
     }   

   if(e.getSource()==btn_clear){
    text.setText("");
    flag="read_op1";  
    point_flag=false;
    btn0.setEnabled(true);
      btn1.setEnabled(true);
      btn2.setEnabled(true);
      btn3.setEnabled(true);
      btn4.setEnabled(true);
      btn5.setEnabled(true);
      btn6.setEnabled(true);
      btn7.setEnabled(true);
      btn8.setEnabled(true);
      btn9.setEnabled(true);
      btn_plus.setEnabled(true);
      btn_minus.setEnabled(true);
      btn_mul.setEnabled(true);
      btn_divide.setEnabled(true);
      btn_point.setEnabled(true);
      btn_sign.setEnabled(true);
      btn_plus.setEnabled(true);
      btn_is.setEnabled(true);
    }
  
  
  
  }

}
   