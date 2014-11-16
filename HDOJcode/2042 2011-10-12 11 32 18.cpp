******************************
    Author : townboy
    Submit time : 2011-10-12 11:32:18
    Judge Status : Accepted
    HDOJ Runid : 4741751
    Problem id : 2042
    Exe.time : 0MS
    Exe.memory : 208K
    https://github.com/townboy
******************************


#include<stdio.h>
int main()
{
    int i,sum,num,a,n;
    scanf("%d",&num);
for (a=0;a<num;a++)
{
    sum=3;
    scanf("%d",&n);
    for(i=0;i<n;i++)
{
    sum=(sum-1)*2;
}
printf("%d\n",sum);
}
return 0;
}