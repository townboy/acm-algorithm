******************************
    Author : townboy
    Submit time : 2012-09-17 20:46:37
    Judge Status : Accepted
    HDOJ Runid : 6784693
    Problem id : 3938
    Exe.time : 843MS
    Exe.memory : 1080K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<stdlib.h>

__int64 ans[11000];
int n,m,q;
int set[11000],nn[11000];

void chu()
{
    int i;
    for(i=1;i<=n;i++)
    {
        nn[i]=1;
        set[i]=i;
    }
}

int find(int x)
{
    return x==set[x]?x:set[x]=find(set[x]);    
}

void merge(int a,int b)
{
    set[b]=a;
    nn[a]+=nn[b];
}

struct node 
{
    int u;
    int v;
    int len;
};
struct node que[51000];

int cmp(const void *a,const void *b)
{
    return (*(struct node *)a).len-(*(struct node *)b).len;
}

struct xx
{
    int id;
    int l;
};
struct xx query[11000];

int cmp2(const void *a,const void *b)
{
    return (*(struct xx *)a).l-(*(struct xx *)b).l;
}

void solve()
{
    __int64 sum;
    int u,v;
    int f,i,start=0;
    for(i=0;i<q;i++)
    {
        for(;;start++)
        {
            if(m == start)
            {
                break;
            }
            if(que[start].len > query[i].l)
            {
                break;
            }
            u=find(que[start].u);
            v=find(que[start].v);
            if(u == v)
            {
                continue;
            }
            merge(u,v);
        }
        sum=0;
        for(f=1;f<=n;f++)
        {
            if(f != set[f])
            {
                continue;
            }
            sum+=((__int64)nn[f]-1)*(__int64)nn[f]/2;
        }
        ans[query[i].id]=sum;                
    }
}

void debug()
{
    int i;
    for(i=0;i<q;i++)
    {
        printf("%d %d\n",query[i].id,query[i].l);
    }
}

int main()
{
    int i,l;
    while(scanf("%d%d%d",&n,&m,&q)!=EOF)
    {
        chu();
        for(i=0;i<m;i++)
        {
            scanf("%d%d%d",&que[i].u,&que[i].v,&que[i].len);
        }
        qsort(que,m,sizeof(que[0]),cmp);
        for(i=0;i<q;i++)
        {
            scanf("%d",&l);
            query[i].id=i;
            query[i].l=l;
        }
        qsort(query,q,sizeof(query[0]),cmp2);
        solve();
        for(i=0;i<q;i++)
        {
            printf("%d\n",ans[i]);
        }
    }
    return 0;
}