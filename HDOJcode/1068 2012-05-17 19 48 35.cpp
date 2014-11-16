******************************
    Author : townboy
    Submit time : 2012-05-17 19:48:35
    Judge Status : Accepted
    HDOJ Runid : 5958316
    Problem id : 1068
    Exe.time : 1968MS
    Exe.memory : 1604K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>

int map[600][600],n,match[600],mk[600];

int dfs(int x)
{
    int i,t;
    for(i=0;i<n;i++)
    {
        if((1 == map[x][i]) && (0 == mk[i]))
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

int xyl()
{
    int i,max=0;
    for(i=0;i<n;i++)
    {
        memset(mk,0,sizeof(mk));
        if(1 == dfs(i))
        {
            max++;
        }
    }
    return max;
}

void chu()
{
    int i;
    memset(map,0,sizeof(map));
    for(i=0;i<n;i++)
    {
        match[i]=-1;
    }
}

int main()
{
    int num,s,e,i,f,res;
//    freopen("D:\\in.txt","r",stdin);
    while(scanf("%d",&n)!=EOF)
    {
        chu();
        
        for(i=0;i<n;i++)
        {
            scanf("%d: (%d)",&s,&num);
            for(f=0;f<num;f++)
            {
                scanf("%d",&e);
                map[s][e]=1;
            }
        }
        res=xyl();
        printf("%d\n",n-res/2);
    }
    return 0;
}