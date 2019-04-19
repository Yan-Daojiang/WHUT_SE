class ab_matrix{
  protected int c;
  protected int line;
  protected int[][] m;
  ab_matrix(int c,int l){  
   int i,j;
   this.c=c;
   this.line=line;    
   m=new int[100][100];
   for(i=1;i<=c;i++)
    {for(j=1;j<=line;j++)
      {m(i,j)=(int)(Math.random()*100+1);}
     }
   } 
  public void out_this(){
   int i, j;   
   for(i=1;i<=c;i++)
    {for(j=1;j<=line;j++)
      {System.out.print(ab_matrix(j,i)+"   ");}
       System.out.println();
     }  
   System.out.println("行数："+line+"列数："+c); 
  }
   
} 

public class test_ab{
 public static void main(String args[])
  {
    ab_matrix am=new ab_matrix(5,7);
    out_this();
  }
}

}