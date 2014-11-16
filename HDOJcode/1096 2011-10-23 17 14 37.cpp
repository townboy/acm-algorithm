******************************
    Author : townboy
    Submit time : 2011-10-23 17:14:37
    Judge Status : Accepted
    HDOJ Runid : 4809228
    Problem id : 1096
    Exe.time : 0MS
    Exe.memory : 184K
    https://github.com/townboy
******************************


#include<stdio.h>
int main (void)
{
    int num,x,y,i,f,sum;
scanf("%d",&num);
       sum=0;
       scanf("%d",&x);
       for(f=0;f<x;f++)
       { 
       scanf("%d",&y);
       sum=sum+y;
       }
       printf("%d\n",sum);

 



    for(i=1;i<num;i++)
    {
        sum=0;
         scanf("%d",&x);
       for(f=0;f<x;f++)
       { 
       scanf("%d",&y);
       sum=sum+y;
       
       }
    
       printf("\n%d\n",sum);
    }


 return 0;

}