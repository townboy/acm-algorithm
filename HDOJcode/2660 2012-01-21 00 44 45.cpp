******************************
    Author : townboy
    Submit time : 2012-01-21 00:44:45
    Judge Status : Accepted
    HDOJ Runid : 5281881
    Problem id : 2660
    Exe.time : 15MS
    Exe.memory : 176K
    https://github.com/townboy
******************************


#include<stdio.h>
int wei[30],val[30],maxw,res,n,k;
void dfs(int x,int s,int v,int w)
{
    if(w>maxw)
    {
        return ;
    }
     if(s==k+1)
    {
        return ;
    }
    if(x==n)
    {
        return ;
    }
    if(s==k)
    {
        if(v>res)
        {
            res=v;
        }
        return ;
    }
    dfs(x+1,s,v,w);
    dfs(x+1,s+1,v+val[x],w+wei[x]);
}
int main(void)
{
    int i,f,num;
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        res=0;
        scanf("%d%d",&n,&k);
        for(f=0;f<n;f++)
        {
            scanf("%d%d",&val[f],&wei[f]);
        } 
        scanf("%d",&maxw);
        dfs(0,0,0,0);
        printf("%d\n",res);
    }
    return 0;
}