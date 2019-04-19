import java.awt.*;
import javax.swing.*;
import java.awt.event.*;
public class KeyAndMouse_Exam extends JFrame implements KeyListener{
  static KeyAndMouse_Exam mainJFrame=new KeyAndMouse_Exam();
  static JTextField tf=new JTextField(15);
  static JTextArea ta1=new JTextArea(7,22);
  
  static JTextField tf1=new JTextField(20);
  static JTextArea ta2=new JTextArea("",7,22);
  static JButton btn=new JButton("拖动我");
  static int px,py,ox,oy,offx,offy,x,y;

  static JPanel mainpan=new JPanel();
  static JPanel pan1=new JPanel();
  static JPanel pan2=new JPanel();
  static JPanel pan3=new JPanel();

  static  CardLayout card =new CardLayout(10,10);
  static JButton but1=new JButton("键盘事件类");
  static JButton but2=new JButton("鼠标事件类");

  public static void main(String args[]){
   mainJFrame.setTitle("键盘和鼠标事件类综合应用");
   mainJFrame.setResizable(false);
   mainJFrame.setLocationRelativeTo(null);
   mainJFrame.setSize(300,230);
   Container container=mainJFrame.getContentPane();
   container.setLayout(new BorderLayout(10,10));
   container.setBackground(Color.lightGray);

   mainpan.setBounds(20,20,300,230);
   mainpan.setLayout(card);
   pan1.setBounds(20,20,230,220);
   pan1.setFont(new Font("Helvetica",Font.BOLD,20));
   pan1.setBackground(Color.green);
   JLabel tlbl1=new JLabel("键盘事件类应用");
   tlbl1.setBounds(20,20,60,20);
   pan1.add(tlbl1);
   tf.setBounds(60,20,60,20);
   pan1.add(tf);
   tf.addKeyListener(mainJFrame);
   
   ta1.setEnabled(false);
   JScrollPane scrollPane1=new JScrollPane(ta1);
   scrollPane1.setVerticalScrollBarPolicy(JScrollPane.VERTICAL_SCROLLBAR_ALWAYS);
   pan1.add(scrollPane1);
   mainpan.add(pan1,"t1");

   pan2.setBounds(20,20,230,220);
   pan2.setFont(new Font("Helvetica",Font.BOLD,20));
   pan2.setBackground(Color.yellow);
   JLabel tlbl2=new JLabel("鼠标事件类应用");
   tlbl2.setBounds(20,20,60,20);
   pan2.add(tlbl2);

   btn.setBounds(90,20,90,20);
   pan2.add(btn);

   ta2.setEnabled(false);
   //ta2.setCaretPosition(ta1.getDocument().getLength());
   JScrollPane scrollPane2=new JScrollPane(ta2);
   scrollPane2.setVerticalScrollBarPolicy(JScrollPane.VERTICAL_SCROLLBAR_ALWAYS);
   pan2.add(scrollPane2);

   btn.addMouseMotionListener(new MyBtnMouseMotionList());
   btn.addMouseListener(new MyBtnMouseList());


   mainpan.add(pan2,"t2");
   card.show(mainpan,"t1");
   pan3.setLayout(new GridLayout(1,2));
   pan3.setBounds(20,200,230,20);
   but1.addActionListener(new MyPageBtnListener());
   but2.addActionListener(new MyPageBtnListener());
   pan3.add(but1);
   pan3.add(but2);

   container.add("North",mainpan);
   container.add("South",pan3);
   mainJFrame.setVisible(true);
}

public void keyPressed(KeyEvent e){
  if (e.isActionKey()) ta1.append("你按的是Action键\n");
  else ta1.setText("KeyEvent事件发生，你按的是 ["+e.getKeyChar()+"] 键\n");
}
 
public void keyReleased(KeyEvent e){
   ta1.append("你现在放开了按键\n");
 }

public void keyTyped(KeyEvent e){
  String input=tf.getText()+e.getKeyChar();
  if(e.getKeyChar()=='\n')ta1.setText(input);
}



static class MyBtnMouseList extends MouseAdapter{
 public void mousePressed(MouseEvent e){
  px=e.getX();
  py=e.getY();
  ox=btn.getLocation().x;
  oy=btn.getLocation().y;
 }
}



static class MyBtnMouseMotionList extends MouseMotionAdapter{
 public void mouseDragged(MouseEvent e){
  offx=px-ox;
  offy=py-oy;
  x=e.getX()-offx;
  y=e.getY()-offy;
  String position="命令按钮放在("+x+","+y+")的位置\n";
  ta2.append(position);
  btn.setLocation(x,y);
  ox=x;
  oy=y;
 }
}

static class MyPageBtnListener implements ActionListener{
  public void actionPerformed(ActionEvent e)
    {
      JButton butt=(JButton)e.getSource();
      if(butt==but1) card.first(mainpan);
      else card.last(mainpan);

    }
   }
  }










