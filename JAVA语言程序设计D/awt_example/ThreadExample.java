     class SimpleRunnable implements Runnable{
     protected String message;
     protected int iterations;

     public  SimpleRunnable(String msg,int iter){                 
        message =msg;
        iterations=iter;        
      }
     
     public void run(){
        for (int i=0;i<iterations;i+=1){
           System.out.println(message);  
           try{  Thread.sleep(100);}
           catch(InterruptedException e){System.out.println(e); }
        } } } 
    
        public class ThreadExample{
         public static void main(String args[]){
         Thread t1,t2;
       
         t1=new Thread(new SimpleRunnable("Thread 1",3));
         t2=new Thread(new SimpleRunnable("Thread 2",6));
         System.out.println("T1  p  is:"+ t1.getPriority());
         System.out.println("T2  p  is:"+ t2.getPriority());
         t2.setPriority(7);
         System.out.println("T2 after set p is:"+t2.getPriority());
         //t2.yield();
         System.out.println("T2 after set p is:"+t2.getPriority());
         t1.start();
         t2.start();
         }
        }





