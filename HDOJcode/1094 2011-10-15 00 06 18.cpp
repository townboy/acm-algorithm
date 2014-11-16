******************************
    Author : townboy
    Submit time : 2011-10-15 00:06:18
    Judge Status : Accepted
    HDOJ Runid : 4758045
    Problem id : 1094
    Exe.time : 0MS
    Exe.memory : 184K
    https://github.com/townboy
******************************


#include<stdio.h>
void main()
{
    int a,b,n,sum;
while(scanf("%d",&n)!=EOF)
{sum=0;
for(a=0;a<n;a++)
{
scanf("%d",&b);
sum=sum+b;}
printf("%d\n",sum);
}
}
