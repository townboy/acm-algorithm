******************************
    Author : townboy
    Submit time : 2012-01-21 01:19:25
    Judge Status : Accepted
    HDOJ Runid : 5281946
    Problem id : 2616
    Exe.time : 78MS
    Exe.memory : 172K
    https://github.com/townboy
******************************


#include<stdio.h>
int res,n,v[20][2],m,M[20];
void dfs(int x,int s)
{
    int i;
    if(s<=0)
    {
        if(x<res)
        {
            res=x;
        }
        return ;
    }
    if(x==n||x>=res)
    {
        return ;
    }
    for(i=0;i<n;i++)
    {
        if(0==v[i][1])
        {
            v[i][1]=1;
            if(s<=M[i])
            {
                dfs(x+1,s-2*v[i][0]);
            }
            else
            {
                dfs(x+1,s-v[i][0]);
            }
            v[i][1]=0;
        }
    }
}
int main(void)
{
    int i;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
       for(i=0;i<n;i++)
       {
           scanf("%d%d",&v[i][0],&M[i]);
           v[i][1]=0;
       }
       res=20;
       dfs(0,m);
       if(20==res)
       {
           printf("-1\n");
       }
       else
       {
           printf("%d\n",res);
       }
    }
    return 0;
}