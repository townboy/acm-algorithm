******************************
    Author : townboy
    Submit time : 2011-10-19 22:53:54
    Judge Status : Accepted
    HDOJ Runid : 4784596
    Problem id : 2022
    Exe.time : 0MS
    Exe.memory : 188K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<math.h>
void main()
{  
  int m,n,a[50][50],f,g,max,e;
    while(scanf("%d%d",&m,&n)!=EOF)
    {
       for(f=0;f<m;f++)
       {   
       
       for(g=0;g<n;g++)
       {
       scanf("%d",&a[f][g]);
       }
       }
    
       
       max=abs(a[0][0]);
       for(f=0;f<m;f++)
       {   
       
       for(g=0;g<n;g++)
       {
       if(max<abs(a[f][g]))
             max=abs(a[f][g]);
       }
       
       
       }
    
       e=0;
       for(f=0;f<m;f++)
       {   
       
       for(g=0;g<n;g++)
       {
       if(max==abs(a[f][g]))
       {     printf("%d %d %d\n",f+1,g+1,a[f][g]);
             e=1;
             break;
       }   
       }
       if(e==1)
       break;

       
       
       }
    

    
    

     
    
    
    
    
    }
}

