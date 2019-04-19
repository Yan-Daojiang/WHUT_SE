abstract class ab_matrix{
  protected int column;
  protected int line;
  protected int[][] m;

  public void set_matrix(int column,int line,int m[][]){
     this.column=column;   
     this.line=line;  
     this.m=m;
   }
  
  public void out(){
   int i, j;   
   for(i=1;i<=line;i++)
    {for(j=1;j<=column;j++)
      {System.out.print(m[i][j]+"   ");}
       System.out.println();
     }   
  }
   
   abstract int plus(ab_matrix x);  
   abstract int mul_number(int x);
   abstract int mul_matrix(ab_matrix x);   
} 

class matrix extends ab_matrix{
   matrix(int line,int column){
   int i,j;
   this.column=column;   
   this.line=line;  
   m=new int[line+1][column+1];
   for(i=1;i<=line;i++)
    {for(j=1;j<=column;j++)
      {m[i][j]=(int)(Math.random()*10+1); }
     }
   }

   matrix(int column,int line,int m[][]){
     this.column=column;   
     this.line=line;  
     this.m=m;
   }

   public int plus(ab_matrix x)
   {
      int i,j;
      if (x.line!=this.line || x.column!=this.column){return 0;}  
      for(i=1;i<=line;i++)
      {for(j=1;j<=column;j++)
        {m[i][j]+=x.m[i][j]; }
       }
      return 1;
   } 

    
    public int mul_number(int x)
   {
      int i,j;
      for(i=1;i<=line;i++)
      {for(j=1;j<=column;j++)
        {m[i][j]*=x;  }
       }
      return 1;
   } 

   
   public int mul_matrix(ab_matrix x){
      matrix t=new matrix(line,x.column); 
      int i,j,k;
      if (this.column!=x.line){return 0;}  
      for(i=1;i<=t.line;i++)
      {for(j=1;j<=t.column;j++)
        {t.m[i][j]=0;
         for (k=1;k<=this.column;k++)
          {t.m[i][j]=t.m[i][j]+m[i][k]*x.m[k][j];}
        }
       }
      this.line=t.line;
      this.column=t.column;
      this.m=t.m;
      return 1;
   }    
}

public class test_ab{
 public static void main(String args[])
  {    
    int ma1[][]={{0,0,0,0},{0,2,-1,3},{0,5,0,1},{0,-2,1,-1}};
    int mb1[][]={{0,0,0,0},{0,-3,2,3},{0,5,1,0},{0,2,1,-1}};
    int ma2[][]={{0,0,0,0},{0,2,-1,3},{0,5,0,1},{0,-2,1,-1}};
    int mb2[][]={{0,0,0,0},{0,-3,2,3},{0,5,1,0},{0,2,1,-1}};
    int ma3[][]={{0,0,0,0},{0,2,-1,3},{0,5,0,1},{0,-2,1,-1}};
    int mb3[][]={{0,0,0,0},{0,-3,2,3},{0,5,1,0},{0,2,1,-1}};
    matrix a=new matrix(3,3,ma1);
    matrix b=new matrix(3,3,mb1);

    System.out.println("Matrix a is:");
    a.out();
    System.out.println("Matrix b is:");
    b.out();
    System.out.println("a+b is:");
    a.plus(b);
    a.out();
    
    a.set_matrix(3,3,ma2);
    b.set_matrix(3,3,mb2);
    b.mul_number(-1);
    
    a.plus(b);
    System.out.println("a-b is:");
    a.out();
    
    a.set_matrix(3,3,ma3);
    b.set_matrix(3,3,mb3);
    System.out.println("a*b is:");
    a.mul_matrix(b);
    a.out();
    
  }
}

