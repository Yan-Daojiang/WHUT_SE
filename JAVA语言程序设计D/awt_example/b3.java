import java.lang.Math;
public class point_b3{
int x, y;

public  point_b3(int a,int b){x=a;y=b;}

public double distance(){return  Math.sqrt(x*x+y*y);}
public double distance(point_b3 p)
{return Math.sqrt((this.x-p.x)* (this.x-p.x)+(this.y-p.y)* (this.y-p.y));}

public static void main(String args[ ]){
point_b3 p1,p2;
p1=new point_b3(3,4);
p2=new point_b3(4,3);
System.out.println("p1.distance()="+p1.distance());
System.out.println("p2.distance()="+p2.distance());
System.out.println("p1.distance(p2)="+ p1.distance(p2));
System.out.println("p2.distance(p1)="+ p2.distance(p1));
}
}




