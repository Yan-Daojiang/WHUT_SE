      import java.awt.*;
      import java.awt.event.*;

      public class b9 extends MouseAdapter{
         Frame f;
         Panel p;
         PopupMenu pm;

         public static void main(String args[ ]){
            b9 ex=new b9();
            ex.go();
           }

         public void go(){

           f=new Frame("PopupMenu Test");
           p=new Panel();
           pm=new PopupMenu();

           f.add(p,"Center");

           pm.add(new MenuItem("New"));
           pm.add(new MenuItem("Load"));
           pm.add(new MenuItem("Save"));
           pm.add(new MenuItem("Save as"));

           f.add(pm);
           p.addMouseListener(this);
           f.setSize(300,300);
           f.setVisible(true);
           }
         public void mouseClicked(MouseEvent e){pm.show(p,e.getX(),e.getY());}
      }







