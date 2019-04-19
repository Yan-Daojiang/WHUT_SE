      public class ThreadTest  extends Thread{
      String threadName;
      public   ThreadTest(String s){
       System.out.println("Making  thread:"+s);
       threadName=s;
      }
      public void  run(){
       for(int i=0;i<3;i++){
        System.out.println("Running thread number="+ threadName);
        try{Thread.sleep((int)(Math.random()*1000));}
        catch(InterruptedException ex)
         {System.err.println(ex.toString()); }
          }
        }
      public static void main(String[] args){
      ThreadTest thread1=new ThreadTest("Tom");
      ThreadTest thread2=new ThreadTest("Jack");
      thread1.start();
      thread2.start();
      System.out.println("End of main");
     }
   }

