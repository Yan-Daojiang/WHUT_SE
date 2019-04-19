import java.lang.Math;
public class point{
int x, y;

public point(){x=0;y=0;}
public point(int a,int b){x=a;y=b;}
public point(double ruo,double cida)
  {x=(int)(ruo*Math.cos(cida));
   y=(int)(ruo*Math.sin(cida));}

public static void main(String args[ ]){
point p1,p2,p3;
p1=new point();
p2=new point(20,40);
p3=new point(100.0,Math.PI/4);
System.out.println("p1 is");
System.out.println(p1.x+","+p1.y);
System.out.println("p2 is ");
System.out.println(p2.x+","+p2.y);
System.out.println("p3 is");
System.out.println(p3.x+","+p3.y);
}
}

