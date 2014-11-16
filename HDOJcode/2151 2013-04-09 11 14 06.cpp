******************************
    Author : townboy
    Submit time : 2013-04-09 11:14:06
    Judge Status : Accepted
    HDOJ Runid : 8036551
    Problem id : 2151
    Exe.time : 0MS
    Exe.memory : 304K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>

int sum[110][110];
int n,pos,t,aim;

int fun()
{
    int i,f;
    memset(sum,0,sizeof(sum));
    sum[0][pos]=1;
    for(i=1;i<=t;i++)
        for(f=1;f<=n;f++)
            sum[i][f]=sum[i-1][f-1]+sum[i-1][f+1];
    return sum[t][aim];
}

int main()
{
    while(scanf("%d%d%d%d",&n,&pos,&t,&aim)!=EOF)
        printf("%d\n",fun());
    return 0;
}