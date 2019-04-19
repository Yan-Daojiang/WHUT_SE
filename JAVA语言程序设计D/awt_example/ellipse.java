
      
      public class ellipse {
        public final double PI=3;
        public double short_Axis;
        public double long_Axis;
        protected ellipse(double sA, double lA){
            short_Axis=sA;
            long_Axis=lA;
        }
        public double get_area(){return PI*short_Axis*long_Axis;}
        public double get_girth(){return 2*PI*long_Axis+4*                                    (short_Axis-long_Axis);}
        public static void main(String[] args){
          ellipse e1=new ellipse(15.0,20.0);
          ellipse e2=new ellipse(8.0,10.0);
          System.out.println("e1.area="+e1.get_area());
          System.out.println("e1.girth="+e1.get_girth());
          System.out.println("e2.area="+e2.get_area());
          System.out.println("e2.girth="+e2.get_girth());
        }
      }  