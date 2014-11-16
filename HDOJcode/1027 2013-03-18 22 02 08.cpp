******************************
    Author : townboy
    Submit time : 2013-03-18 22:02:08
    Judge Status : Accepted
    HDOJ Runid : 7803728
    Problem id : 1027
    Exe.time : 703MS
    Exe.memory : 276K
    https://github.com/townboy
******************************


#include<stdio.h>

int hash[1100];
int ans[1100];
int n,m;
int sum;

void dfs(int pos)
{
    int i;
    if(n+1 == pos)
    {    
        sum++;
        return ;
    }
    for(i=1;i<=n;i++)
    {
        if(sum == m)
            return ;
        if(0 == hash[i])
        {
            hash[i]=1;
            ans[pos]=i;
            dfs(pos+1);
            hash[i]=0;
        }
    }
}

int main()
{
    int i;
    while(scanf("%d%d",&n,&m)!=EOF)
    {    
        sum=0;
        dfs(1);
        printf("%d",ans[1]);
        for(i=2;i<=n;i++)
            printf(" %d",ans[i]);
        printf("\n");
    }
    return 0;
}