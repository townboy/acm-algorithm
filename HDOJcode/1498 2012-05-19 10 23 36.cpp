******************************
    Author : townboy
    Submit time : 2012-05-19 10:23:36
    Judge Status : Accepted
    HDOJ Runid : 5964502
    Problem id : 1498
    Exe.time : 46MS
    Exe.memory : 288K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>

int mk[110],map[110][110],color[110][110],match[110],n,flag;

void chu(int x)
{
    int i,f;
    memset(map,0,sizeof(map));

    for(i=0;i<=n;i++)
    {
        match[i]=-1;
    }

    for(i=0;i<n;i++)
    {
        for(f=0;f<n;f++)
        {
            if(color[i][f] == x)
            {
                map[i][f]=1;
            }
        }
    }
}

int dfs(int x)
{
    int i,t;
    for(i=0;i<n;i++)
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

int xyl()
{
    int max=0,i;
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

int main()
{
    int i,f,k,res;
//    freopen("D:\\in.txt","r",stdin);
    while(scanf("%d%d",&n,&k),!(0 == n && 0 == k))
    {
        flag=0;
        for(i=0;i<n;i++)
        {
            for(f=0;f<n;f++)
            {
                scanf("%d",&color[i][f]);
            }
        }

        for(i=1;i<=50;i++)
        {
            chu(i);
            res=xyl();
        
            if(res > k)
            {
                if(1 == flag)
                {
                    printf(" %d",i);
                }
                else
                {
                    flag=1;
                    printf("%d",i);
                }
            }
        }
        if(0 == flag)
        {
            printf("-1");
        }
        printf("\n");
    }
    return 0;
}