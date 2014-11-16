******************************
    Author : townboy
    Submit time : 2012-09-18 14:42:56
    Judge Status : Accepted
    HDOJ Runid : 6788630
    Problem id : 2818
    Exe.time : 171MS
    Exe.memory : 604K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>

int p;
int set[31000],nn[31000],path[31000];

void chu()
{
    int i;
    memset(path,0,sizeof(path));
    for(i=0;i<=30000;i++)
    {
        set[i]=i;
        nn[i]=1;
    }
}

int find(int x)
{
    while(set[x] != x)
    {
        x=set[x];
    }
    return x;
}

int query(int x)
{
    int sum=0,old=x;
    while(set[x] != x)
    {
        sum+=path[x];
        x=set[x];
    }
    path[old]=sum;
    set[old]=x;
    return sum;    
}

void merge(int a,int b)
{
    set[a]=b;
    path[a]=nn[b];
    nn[b]+=nn[a];
}

int main()
{
    char ch[10];
    int i,u,v,uu,vv;
    while(scanf("%d",&p)!=EOF)
    {
        chu();
        for(i=0;i<p;i++)
        {
            scanf("%s",ch);
            if('M' == ch[0])
            {
                scanf("%d%d",&u,&v);
                uu=find(u);
                vv=find(v);
                if(uu == vv)
                {
                    continue;
                }
                merge(uu,vv);
            }
            else
            {
                scanf("%d",&u);
                printf("%d\n",query(u));
            }
        }        
    }
    return 0;
}