import java.lang.Thread;

class Counter extends Thread{
  private int currentValue;

  public Counter(String threadName){
    super(threadName);
    currentValue=0;
    System.out.println(this);
    // System.out.println(Thread.currentThread());
    setPriority(10);
    start();
   } 
  

  public void run(){
    try{
      while(currentValue<5){
        System.out.println(getName()+":"+(currentValue++));
        Thread.sleep(500);
      }
   }catch(InterruptedException e){  System.out.println(getName()+"    interrupted.");   }
    System.out.println("Exit from "+getName()+".");
  }

  public int getValue()  {  return currentValue; }
 }


public class ThreadJoinAndIsAlive{
  public static void main(String args[]){
   Counter cA=new Counter("Counter A");
   Counter cB=new Counter("Counter B");
   System.out.println("!!!!!!!!!!!!!!"+cB.getPriority());
   try{
     System.out.println("Wait for the child threads to finish.");
     cA.join();
     System.out.println("Current thread is:"+Thread.currentThread().getName()+",  "+
        Thread.currentThread().getPriority());
     System.out.println("I  am here 111");
     if (!cA.isAlive())
      System.out.println("Counter A not alive.");
      if (!cB.isAlive())
      System.out.println("Counter B not alive.");
    } catch(InterruptedException e)  { System.out.println("Main Thread interrupted.");  }
   System.out.println("Exit from Main Thread.");
 }
}