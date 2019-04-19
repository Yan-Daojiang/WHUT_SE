

public class ThrowsException{
  public static void main(String args[]){
     try{
          ShowException();
         }
     catch(Exception e)
    { System.out.println("这是只在ShowException()中声明，并在main()方法中捕获的异常："+e);}
     }
   
   
   public static void ShowException() throws Exception{
        Object x=new Integer(0);
        System.out.println((String)x); 
  }
  }