******************************
    Author : townboy
    Submit time : 2012-05-17 21:25:37
    Judge Status : Accepted
    HDOJ Runid : 5959057
    Problem id : 1150
    Exe.time : 0MS
    Exe.memory : 240K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>

int a,b,map[110][110],match[110],mk[110];

int dfs(int x)
{
    int i,t;
    for(i=0;i<b;i++)
    {
        if((1 == map[x][i])&&(0 == mk[i]))
        {
            mk[i]=1;
            t=match[i];
            match[i]=x;
            if((-1 == t)||(1 == dfs(t)))
            {
                return 1;
            }
            match[i]=t;
        }
    }
    return 0;
}

void chu()
{
    int i;
    memset(map,0,sizeof(map));
    for(i=0;i<b;i++)
    {
        match[i]=-1;
    }
}

int xyl()
{
    int i,max=0;
    for(i=0;i<a;i++)
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
    int res,k,i,s,e,x;
//    freopen("D:\\in.txt","r",stdin);
    while(scanf("%d",&a),a)
    {
        scanf("%d%d",&b,&k);

        chu();

        for(i=0;i<k;i++)
        {
            scanf("%d%d%d",&x,&s,&e);
            if((0 == s)||(0 == e))
            {
                continue;
            }
            map[s][e]=1;
        }
        res=xyl();
        printf("%d\n",res);
    }
    return 0;
}