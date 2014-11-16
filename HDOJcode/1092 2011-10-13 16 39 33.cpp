******************************
    Author : townboy
    Submit time : 2011-10-13 16:39:33
    Judge Status : Accepted
    HDOJ Runid : 4749551
    Problem id : 1092
    Exe.time : 0MS
    Exe.memory : 208K
    https://github.com/townboy
******************************


#include<stdio.h>
void main()
{
    int n,a,b,i;
while(scanf("%d",&n),n)
{
    b=0;
    for(i=0;i<n;i++)
    {scanf("%d",&a);
    b=b+a;}
    printf("%d\n",b);
}
}
