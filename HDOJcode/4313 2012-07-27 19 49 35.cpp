******************************
    Author : townboy
    Submit time : 2012-07-27 19:49:35
    Judge Status : Accepted
    HDOJ Runid : 6354819
    Problem id : 4313
    Exe.time : 109MS
    Exe.memory : 2260K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

struct node 
{
    int u;
    int v;
    int len;
};
struct node que[110000];

int hash[110000],set[110000],n; 

int cmp(const void*a,const void*b)
{
    return (*(struct node *)b).len-(*(struct node *)a).len;
}

int find(int x)
{
    return set[x]==x?x:set[x]=find(set[x]);
}

void merge(int a,int b)
{
    if(1 == hash[a])
    {
        set[b]=a;
        return ;
    }
    set[a]=b;
}

void chu()
{
    int i;
    memset(hash,0,sizeof(hash));
    for(i=0;i<n;i++)
    {
        set[i]=i;
    }
}

int main()
{
    __int64 tot,ans;
    int uu,vv,i,f,num,x,k;
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        scanf("%d%d",&n,&k);
        chu();
        tot=0;
        for(f=0;f<n-1;f++)
        {
            scanf("%d%d%d",&que[f].u,&que[f].v,&que[f].len);
            tot+=que[f].len;
        }
        qsort(que,n-1,sizeof(que[0]),cmp);
        for(f=0;f<k;f++)
        {
            scanf("%d",&x);
            hash[x]=1;
        }
        ans=0;
        for(f=0;f<n-1;f++)
        {

            uu=find(que[f].u);
            vv=find(que[f].v);
            if(2 == hash[vv]+hash[uu])
            {
                continue;
            }
            ans+=que[f].len;
            merge(uu,vv);
        }
        printf("%I64d\n",tot-ans);
    }
    return 0;
}
