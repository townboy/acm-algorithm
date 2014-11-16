******************************
    Author : townboy
    Submit time : 2011-12-15 21:16:37
    Judge Status : Accepted
    HDOJ Runid : 5169177
    Problem id : 1846
    Exe.time : 0MS
    Exe.memory : 176K
    https://github.com/townboy
******************************


#include<stdio.h>
int main(void)
{
     int num,i,m,n;
     scanf("%d",&num);
     for(i=0;i<num;i++)
     {
         scanf("%d%d",&n,&m);
         if(n%(m+1)==0)
         {
             printf("second\n");
         }
         else
         {
             printf("first\n");
         }

     
     }
return 0;
}