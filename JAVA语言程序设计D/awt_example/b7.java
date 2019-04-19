 import java.awt.*;
    import java.awt.event.*;
    import java.lang.*;


    public  class b7 implements   ItemListener{
      Frame f;
      Panel p;
      Checkbox wealth,wit;
      TextField tf;
      boolean tag_wth,tag_wit;

      public static void main(String args[]){
        b7 ex=new b7();
        ex.go();
      }
        public void go(){
        f=new Frame("Checkbox Test");
        p=new Panel();
        wealth=new Checkbox("Wealth");
        wit=new Checkbox("Wit");
        tf=new TextField("The man is poor and foolish! ");
        tag_wth=false;
        tag_wit=false;

        f.add(p,"Center");
        f.add(tf,"South");
        p.add(wealth);
        p.add(wit);

        wealth.addItemListener(this);
        wit.addItemListener(this);

        f.setSize(300,150);
        f.setVisible(true);
       }

       public void itemStateChanged(ItemEvent e){
        if(e.getStateChange()==ItemEvent.SELECTED){
           if (e.getSource().equals(wealth)){tag_wth=true;}
           if (e.getSource().equals(wit)){tag_wit=true;}                    }
        if(e.getStateChange()==ItemEvent.DESELECTED){
           if (e.getSource()==wealth){tag_wth=false;}
           if (e.getSource()==wit){tag_wit=false;}
          }

        if (tag_wth && tag_wit) {tf.setText("The man is rich and clever!");}
        if (tag_wth && !tag_wit) {tf.setText("The man is rich and foolish!");}
        if (!tag_wth && tag_wit) {tf.setText("The man is poor and clever!");}
        if (!tag_wth && !tag_wit) {tf.setText("The man is poor and foolish!");}
       }
}






