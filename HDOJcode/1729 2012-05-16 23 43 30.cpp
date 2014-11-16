******************************
    Author : townboy
    Submit time : 2012-05-16 23:43:30
    Judge Status : Accepted
    HDOJ Runid : 5954934
    Problem id : 1729
    Exe.time : 0MS
    Exe.memory : 208K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<math.h>

int tem;

int dfs(__int64 x)
{
    int i;
    if(x*(x+1) >= tem)
    {
        return tem-x;
    }
    for(i=sqrt(tem)+1;;i--)
    {
        if(i*(i+1) < tem)
        {
            tem=i;
            break;
        }
    }
    return dfs(x);
}

int main()
{
    int n,ans,i,x,ji;
    ji=0;
    while(scanf("%d",&n),n)
    {
        ji++;
        ans=0;
        for(i=0;i<n;i++)
        {
            scanf("%d%d",&tem,&x);
            if(0 == x)
            {
                continue;
            }
            ans=(ans^dfs(x));
                        
        }
        if(0 == ans)
        {
            printf("Case %d:\nNo\n",ji);
        }
        else
        {
            printf("Case %d:\nYes\n",ji);
        }
    }
    return 0;
}