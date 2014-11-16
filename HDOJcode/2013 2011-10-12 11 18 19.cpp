******************************
    Author : townboy
    Submit time : 2011-10-12 11:18:19
    Judge Status : Accepted
    HDOJ Runid : 4741679
    Problem id : 2013
    Exe.time : 0MS
    Exe.memory : 208K
    https://github.com/townboy
******************************


#include<stdio.h>
int main()
{
    int i,sum,n;
while(scanf("%d",&n)!=EOF)
{
    sum=1;
    for(i=0;i<n-1;i++)
{
    sum=(sum+1)*2;
}
printf("%d\n",sum);
}
return 0;
}