class Juzh{
 int[][] data=new int[10][10];
 int[][] result=new int[10][10];

 public void plus(Juzh jz){
  int i,j;
  for(i=0;i<10;i++){
    for(j=0;j<10;j++){
     result[i][j]=data[i][j]+jz.data[i][j];
    }}
 }

 public void out_Juzh(){
   int i,j;
   for(i=0;i<10;i++){
    for(j=0;j<10;j++){
     System.out.print(data[i][j]+"  ");
    }
    System.out.println();    
  }
 }
  

 public Juzh(){
  int i,j;
  for(i=0;i<10;i++){
    for(j=0;j<10;j++){
     data[i][j]=(int)(Math.random()*100);
    }}
 }

 public Juzh(Juzh jz){
  int i,j;
  for(i=0;i<10;i++){
    for(j=0;j<10;j++){
     data[i][j]=jz.result[i][j];
    }}
 }

}

public class calcu_jz{
 public static void main(String []args)
 {Juzh jz1,jz2,result_of_plus;
  jz1=new Juzh();
  jz2=new Juzh();
  jz1.plus(jz2);
  result_of_plus=new Juzh(jz1);
  System.out.println("jz1 is:");
  jz1.out_Juzh();
  System.out.println("jz2 is:");
  jz2.out_Juzh();
  System.out.println("jz1+jz2 is:");
  result_of_plus.out_Juzh();
  }
}

  
  
         

