  import java.awt.*;
  import java.awt.event.*;
  public   class a38 extends MouseAdapter{
     public  Frame f;
     public  Button b1,b2,b3;
     public  TextField tf;

     public static void main(String args[]){
       a38 ex=new a38();
       ex.go();
     }
     public void go()  {
        f= new Frame("Button Test");
        b1=new Button("SET");
        b2=new Button("CLEAR");
        b3=new Button("EXIT");
        tf=new TextField();

        b1.addMouseListener(this);
        b2.addMouseListener(this);
        b3.addMouseListener(this);

        f.add(b1,"East");
        f.add(b2,"Center");
        f.add(b3,"West");
        f.add(tf,"South");

        f.setSize(300,150);
        f.setVisible(true);
       }

     public void mouseClicked(MouseEvent e){
       if(e.getSource() ==b1){tf.setText("This is a TextField!");}
       if(e.getSource() ==b2){tf.setText("");}
       if(e.getSource() ==b3) {System.exit(0);}
     }
   }


