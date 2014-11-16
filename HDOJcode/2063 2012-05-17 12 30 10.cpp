******************************
    Author : townboy
    Submit time : 2012-05-17 12:30:10
    Judge Status : Accepted
    HDOJ Runid : 5956328
    Problem id : 2063
    Exe.time : 15MS
    Exe.memory : 1604K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>

int mk[600],match[600],x,y,map[600][600];

void chu()
{
    int i;
    for(i=0;i<=y;i++)
    {
        match[i] = -1;
    }
    memset(map,0,sizeof(map));
}

int dfs(int x)
{
    int i,t;
    for(i=1;i<=y;i++)
    {
        if((1 == map[x][i]) && (0 ==mk[i]))
        {
            mk[i] = 1;
            t=match[i];
            match[i]=x;
            if( (-1 == t) || (1 == dfs(t)))
            {
                return 1;
            }
            match[i]=t;
        }
    }
    return 0;
}

int xyl()
{
    int max=0,i;
    for(i=1;i<=x;i++)
    {
        memset(mk,0,sizeof(mk));
        if(1 == dfs(i))
        {
            max++;
        }
    }
    return max;
}

int main()
{
    int n,i,res,s,e;
//    freopen("D:\\in.txt","r",stdin);
    while(scanf("%d",&n),n)
    {
        scanf("%d%d",&x,&y);
    
        chu();
        for(i=0;i<n;i++)
        {
            scanf("%d%d",&s,&e);
            map[s][e]=1;
        }

        res=xyl();
        printf("%d\n",res);
    }
    return 0;
}