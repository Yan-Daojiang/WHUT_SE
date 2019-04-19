import java.lang.Math;
class point2d{
 int x, y;
 public point2d(int a,int b){x=a;y=b;}
 public double distance(){return Math.sqrt(x*x+y*y);}
}

public class point3d extends point2d{
  int z;
  
  public  point3d(int a,int b,int c){
   super(a,b);
   z=c;
  }

  public double distance()
   {return Math.sqrt(x*x+y*y+z*z);}

  public static void main(String args[ ]){
   point2d p2d=new point2d(3,4);
   System.out.println("The 2d distance is:"+p2d.distance());
   point3d p3d=new point3d(3,4,12);
   System.out.println("The 3d distance is:"+p3d.distance());
  }
 }
