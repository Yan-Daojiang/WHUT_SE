public class dim_test{	
 public static void main(String args[])	{ 
  char[] s ={'A','B','C','D'};	    
  for (int i=0; i<s.length; i++ )     {	System.out.print(s[i]+"  ");  }      
      System.out.println();      int [][] dd;	
      dd=new int[][]{{1,2},{1,2,3},{1,2,3}};	
    	    for(int i=0;i<dd.length;i++)	 
             {for(int j=0;j<dd[i].length;j++)	   
        	{System.out.print(dd[i][j]+"  "); }	
                System.out.println();	    }	
}}