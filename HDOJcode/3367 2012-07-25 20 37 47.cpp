******************************
    Author : townboy
    Submit time : 2012-07-25 20:37:47
    Judge Status : Accepted
    HDOJ Runid : 6330022
    Problem id : 3367
    Exe.time : 281MS
    Exe.memory : 1536K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

int n,set[11000],flag[11000];

void chu()
{
    int i;
    for(i=0;i<n;i++)
    {
        set[i]=i;
    }
    memset(flag,0,sizeof(flag));
}

struct node 
{
    int u;
    int v;
    int len;
};
struct node que[110000];

int cmp(const void*a,const void*b)
{
    return (*(struct node*)b).len-(*(struct node*)a).len;
}

int find(int x)
{
    return x==set[x]?x:set[x]=find(set[x]);
}

void merge(int a,int b)
{
    set[a]=b;
}

int main()
{
    int uu,vv;
    int ans,m,i;
    while(scanf("%d%d",&n,&m),0 != n+m)
    {
        chu();
        ans=0;
        for(i=0;i<m;i++)
        {
            scanf("%d%d%d",&que[i].u,&que[i].v,&que[i].len);
        }
        qsort(que,m,sizeof(que[0]),cmp);
        for(i=0;i<m;i++)
        {
            uu=find(que[i].u);
            vv=find(que[i].v);
            if(uu != vv)
            {
                if(0 == flag[uu]||0 == flag[vv])
                {
                    merge(uu,vv);
                    if(1 == flag[uu]+flag[vv])
                    {
                        flag[find(uu)]=1;
                    }
                    ans+=que[i].len;                    
                }
            }
            else
            {
                if(1 != flag[uu])
                {
                    flag[uu]=1;
                    ans+=que[i].len;                
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}