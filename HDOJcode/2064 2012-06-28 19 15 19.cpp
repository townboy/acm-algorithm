******************************
    Author : townboy
    Submit time : 2012-06-28 19:15:19
    Judge Status : Accepted
    HDOJ Runid : 6106157
    Problem id : 2064
    Exe.time : 0MS
    Exe.memory : 188K
    https://github.com/townboy
******************************


#include<stdio.h>
__int64 f[36];
int main()
{
    int x,i;
    f[1]=2;
    for(i=2;i<=35;i++)
    {
        f[i]=f[i-1]*3+2;    
    }
    while(scanf("%d",&x)!=EOF)
    {
        printf("%I64d\n",f[x]);
    }    
}