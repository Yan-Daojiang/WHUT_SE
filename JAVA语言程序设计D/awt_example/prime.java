public class prime{ public boolean zhis(int n,int i){
  if(i==n){return true;} 
  if(n % i == 0){return false;}   
  return zhis(n,i+1);		 
  } 
 public static void main(String args[]){
   int k; 
   prime p=new prime(); 
   for(k=100;k<=200;k++) 
   {if (p.zhis(k,2)){System.out.println(k);}
  } 
 }	
}