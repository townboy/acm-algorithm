******************************
    Author : townboy
    Submit time : 2011-10-23 14:12:12
    Judge Status : Accepted
    HDOJ Runid : 4808090
    Problem id : 2012
    Exe.time : 0MS
    Exe.memory : 212K
    https://github.com/townboy
******************************


#include<stdio.h>
void main()
{
   int x,y,n,flag,a;
   while(scanf("%d%d",&x,&y),!(x==0&&y==0))
   {    
       flag=1;
       for(n=x;n<=y;n++)
       {    

             
            for(a=2;a<(n*n+n+41);a++)
            {
                if((n*n+n+41)%a==0)
                {
                    flag=0;
                    break;
            
                }
            
            }      
            if(flag==0)
                break;

       } 
       if(flag==0)
           printf("Sorry\n");
       else
           printf("OK\n");
   
   
   }

}
