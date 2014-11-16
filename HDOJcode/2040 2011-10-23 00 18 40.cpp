******************************
    Author : townboy
    Submit time : 2011-10-23 00:18:40
    Judge Status : Accepted
    HDOJ Runid : 4806143
    Problem id : 2040
    Exe.time : 109MS
    Exe.memory : 184K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<string.h>
void main ()
{    int num,i,a,x1,x2,sum1,sum2,num2;
      scanf("%d",&num);
      for(i=0;i<num;i++)
      {
         scanf("%d%d",&x1,&x2);
         sum1=sum2=0;
         for(a=1;a<x1;a++)
         {
         if(x1%a==0)
         sum1=sum1+a;
         }
         
         for(a=1;a<x2;a++)
         {
         if(x2%a==0)
         sum2=sum2+a;
         }
         num2=0;
         if(sum1==x2)
         num2++;
         if(sum2==x1)
         num2++;
         if(num2==2)
         printf("YES\n");
         else
         printf("NO\n");
    
         
         
      
      
      
      }






}