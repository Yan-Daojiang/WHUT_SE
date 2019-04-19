import java.awt.*;

public class LabelExample
{  public static void main(String args[]){
   
    Frame f=new Frame("Label example");
    f.setLayout(new GridLayout(3,1,30,30));
    Label l1=new Label("Hello,this is Label1");
    Label l2=new Label("Hello,this is Label2");
    Label l3=new Label("Hello,this is Label3");
    f.add(l1);
    f.add(l2);
    f.add(l3);
    f.setSize(500,400);
    f.setVisible(true);
    }

 }
