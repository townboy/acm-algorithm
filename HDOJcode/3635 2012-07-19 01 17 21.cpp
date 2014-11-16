******************************
    Author : townboy
    Submit time : 2012-07-19 01:17:21
    Judge Status : Accepted
    HDOJ Runid : 6259001
    Problem id : 3635
    Exe.time : 406MS
    Exe.memory : 284K
    https://github.com/townboy
******************************


#include<stdio.h>

int n,set[11000],d[11000],path;

void chu()
{
    int i;
    for(i=1;i<=n;i++)
    {
        set[i]=i;
        d[i]=1;
    }
}

int find(int x)
{
    path=0;
    while(x != set[x])
    {
        x=set[x];
        path++;    
    }
    return x;
}

void merge(int u,int v)
{
    set[u]=v;
    d[v]+=d[u];
}

int main()
{
    int num,i,f,m,u,v,id;
    char ch[10];
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        printf("Case %d:\n",i+1);
        scanf("%d%d",&n,&m);
        chu();
        for(f=0;f<m;f++)
        {
            scanf("%s",ch);
            if('T' == ch[0])
            {
                scanf("%d%d",&u,&v);    
                merge(find(u),find(v));
            }
            else
            {
                scanf("%d",&id);    
                id=find(id);
                printf("%d %d %d\n",id,d[id],path);
            }    
        }
    }
    return 0;
}