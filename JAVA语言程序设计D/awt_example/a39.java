import java.awt.*;

class a39{
           Frame f;
           Choice c;
           Label lab;

           public static void main(String args[]){
            a39 ex=new a39();
            ex.go();
           }

           public void go(){
             f=new Frame();
             f.setLayout(new FlowLayout());
             lab=new Label("Please input you select:");
             f.add(lab);
             c=new Choice();
             c.addItem("First item");
             c.addItem("Second item");
             c.addItem("Third item");

             f.add(c);

             f.setSize(200,100);
             f.setVisible(true);
         }}

   


