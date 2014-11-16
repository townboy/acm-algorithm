******************************
    Author : townboy
    Submit time : 2012-09-17 23:21:24
    Judge Status : Accepted
    HDOJ Runid : 6786246
    Problem id : 2489
    Exe.time : 0MS
    Exe.memory : 256K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>
#include<stdlib.h>
#define INF 0x7fffffff

int map[20][20],n,k;
int dian[20],ans[20];
int select[20],set[20],ji; 
double minn;

struct node 
{
    int u;
    int v;
    int len; 
}; 
struct node que[500]; 

int cmp(const void *a,const void *b)
{
    return (*(struct node *)a).len-(*(struct node *)b).len; 
} 

void chu()
{
    int i; 
    for(i=1;i<=n;i++)
    {
        set[i]=i; 
    } 
} 

int find(int x)
{
    return x==set[x]?x:set[x]=find(set[x]);
}

void merge(int a,int b)
{
    set[a]=b;
}

int check()
{
    int i;
    for(i=1;i<=n;i++)
    {
        if(ans[i] > select[i])
        {
            return 0;
        }
        if(ans[i] < select[i])
        {
            return 1;
        }
    }
}

void debug()
{
    int i;
    for(i=0;i<ji;i++)
    {
        printf("%d %d %d\n",que[i].u,que[i].v,que[i].len);
    }
    printf("\n");
}

void solve()
{
    double now;
    int u,v,i,se=0,sv=0,bian=0; 
    chu(); 
    for(i=0;;i++)
    {
        if(0 == select[que[i].u] || 0 == select[que[i].v])
        {
            continue;
        }    
        u=find(que[i].u);    
        v=find(que[i].v);
        if(u == v)
        {
            continue;
        }
        bian++;
        merge(u,v);
        se+=que[i].len;
        if(k-1 == bian)
        {
            break;
        }
    }
    for(i=1;i<=n;i++)
    {
        if(1 == select[i])
        {
            sv+=dian[i];
        }
    }
    now=(double)se/sv;
    if(now == minn)
    {
        if(0 == check())
        {
            return ;    
        }
        for(i=1;i<=n;i++)
        {
            ans[i]=select[i];
        }    
    }
    if(now < minn)
    {
        for(i=1;i<=n;i++)
        {
            ans[i]=select[i];
        }    
        minn=now;
    }
} 

void dfs(int id,int sum)
{
    if(sum == k)
    {    
        solve();
        return ; 
    }    
    if(id == n+1)
    {
        return ; 
    } 
    select[id]=1; 
    dfs(id+1,sum+1); 
    select[id]=0;
    dfs(id+1,sum); 
} 

int main()
{
    int len,i,f,flag;
    while(scanf("%d%d",&n,&k),n+k)
    {
        minn=INF;
        memset(select,0,sizeof(select)); 
        for(i=1;i<=n;i++)
        {
            scanf("%d",&dian[i]);
        }
        ji=0; 
        for(i=1;i<=n;i++)
        {
            for(f=1;f<=n;f++)
            {
                scanf("%d",&len);
                if(i <= f)
                {
                    continue;
                }
                que[ji].u=i;
                que[ji].v=f;
                que[ji].len=len; 
                ji++; 
            }
        }
        qsort(que,ji,sizeof(que[0]),cmp); 
        dfs(1,0); 
        flag=0;
        for(i=1;i<=n;i++)
        {
            if(0 == ans[i])
            {
                continue;
            }
            if(1 == flag)
            {
                printf(" ");            
            }
            flag=1;
            printf("%d",i);
        }
        printf("\n");
    }
    return 0;
}