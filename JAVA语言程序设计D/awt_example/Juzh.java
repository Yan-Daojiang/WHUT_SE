class Juzh{
 data=new int[10][10];
 result=new int[10][10];

 public void plus(Juzh jz){
  int i,j;
  for(i=1;i<=10;i++){
    for(j=1;i<=10;i++){
     result[i][j]=data[i][j]+jz.data[i][j];
    }}
 
 public void out_Juzh(Juzh jz){
   int i,j;
   for(i=1;i<=10;i++){
    for(j=1;i<=10;i++){
     System.out.print(jz.data[i][j]);
    }
    System.out.println();
  }
 
  

 public Juzh(){
  int i,j;
  for(i=1;i<=10;i++){
    for(j=1;i<=10;i++){
     data[i][j]=(int)(Math.Random()*100);
    }}
}

public class calcu_jz{
 public static void mian(String []args)
 {Juzh jz1,jz2;
  jz1.out_Juzh(jz1);
  }
}

  
  
         

