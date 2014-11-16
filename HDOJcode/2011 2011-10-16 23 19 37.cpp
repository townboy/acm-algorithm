******************************
    Author : townboy
    Submit time : 2011-10-16 23:19:37
    Judge Status : Accepted
    HDOJ Runid : 4769543
    Problem id : 2011
    Exe.time : 0MS
    Exe.memory : 200K
    https://github.com/townboy
******************************


#include<stdio.h>
void main()
{
    int num,n,i,a;
    float sum;
scanf("%d",&num);
for(i=0;i<num;i++)
{sum=0;
scanf("%d",&n);
for(a=1;a<=n;a++)
{
if(a%2==0)
sum=sum-(float)1/a;
else
sum=sum+(float)1/a; 
}
printf("%.2f\n",sum);
}
}