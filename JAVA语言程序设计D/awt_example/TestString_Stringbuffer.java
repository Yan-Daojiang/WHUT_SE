import java.lang.*;
public class TestString_StringBuffer{
   public static void main(String args[]){
        String tempstr =new String( "abcdefghijklmnopqrstuvwxyz");
        int times = 5000;
        long lstart1 = System.currentTimeMillis();
        String str = "";
        for (int i = 0; i < times; i++) {
            str += tempstr;
        }
        long lend1 = System.currentTimeMillis();
        long s_time = (lend1 - lstart1);
        System.out.println(s_time);

 


        long lstart2 = System.currentTimeMillis();
        StringBuffer sb = new StringBuffer();
        for (int i = 0; i <times; i++) {
            sb.append(tempstr);
        }
        long lend2 = System.currentTimeMillis();
        long sb_time = (lend2 - lstart2);
        System.out.println(sb_time);

    }
}