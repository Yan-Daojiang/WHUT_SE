

public class ThrowsException{
  public static void main(String args[]){
     try{
          ShowException();
         }
     catch(Exception e)
    { System.out.println("����ֻ��ShowException()������������main()�����в�����쳣��"+e);}
     }
   
   
   public static void ShowException() throws Exception{
        Object x=new Integer(0);
        System.out.println((String)x); 
  }
  }