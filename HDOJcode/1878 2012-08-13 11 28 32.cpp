******************************
    Author : townboy
    Submit time : 2012-08-13 11:28:32
    Judge Status : Accepted
    HDOJ Runid : 6536886
    Problem id : 1878
    Exe.time : 31MS
    Exe.memory : 256K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>

int n,set[1100],du[1100];

void chu()
{
    int i;
    for(i=1;i<=n;i++)
    {
        set[i]=i;
    }
    memset(du,0,sizeof(du));
}

void merge(int a,int b)
{
    set[a]=b;
}

int find(int x)
{
    return x==set[x]?x:set[x]=find(set[x]);
}

int check()
{
    int i,flag=0;
    for(i=1;i<=n;i++)
    {
        if(i == set[i])
        {
            if(1 == flag)
            {
                return 0;
            }
            flag=1;
        }
        if(1 == (1&du[i]))
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int i,u,v,m;
//    freopen("D:\\in.txt","r",stdin);
    while(scanf("%d",&n),n)
    {
        chu();
        scanf("%d",&m);
        for(i=0;i<m;i++)
        {
            scanf("%d%d",&u,&v);
            du[u]++;
            du[v]++;            
            merge(find(u),find(v));
        }
        if(1 == check())
        {
            printf("1\n");
        }
        else
        {
            printf("0\n");
        }
    }
    return 0;
}