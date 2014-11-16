******************************
    Author : townboy
    Submit time : 2012-08-23 19:31:03
    Judge Status : Accepted
    HDOJ Runid : 6640785
    Problem id : 4396
    Exe.time : 921MS
    Exe.memory : 7180K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<queue>
#include<memory.h>
#include<iostream>
#define INF 10000000
using namespace std;

int dis[5100][110],size;
int n,m,s,t,k;

int first[5100],next[210000],ll[210000],id[210000];
int hash[5100][110];

void chu()
{
    int i,f;
    for(i=1;i<=n;i++)
    {
        for(f=0;f<=100;f++)
        {
            dis[i][f]=INF;        
        }
    }
    size=0;
    memset(first,-1,sizeof(first));
}

struct node 
{
    int id;
    int c;
};
struct node tem,ru;

void add(int u,int v,int l)
{
    next[size]=first[u];
    first[u]=size;
    id[size]=v;
    ll[size]=l;
    size++;        

    next[size]=first[v];
    first[v]=size;
    id[size]=u;
    ll[size]=l;
    size++;        
}

int spfa()
{
    int i,minn,zan;
    int nc,nid,nval;
    
    dis[s][0]=0;
    queue<node>q;
    ru.id=s;
    ru.c=0;
    memset(hash,0,sizeof(hash));
    q.push(ru);
    
    while(!q.empty())
    {
        tem=q.front();
        q.pop();
        hash[tem.id][tem.c]=0;
        if(k+20 == tem.c)
        {
            continue;
        }
        
        zan=first[tem.id];
        while(-1 != zan)
        {
            nval=dis[tem.id][tem.c]+ll[zan];
            nc=tem.c+1;
            nid=id[zan];        
            if(dis[nid][nc] > nval)
            {
                dis[nid][nc]=nval;
                if(0 == hash[nid][nc])
                {
                    ru.id=nid;
                    ru.c=nc;
                    q.push(ru);
                    hash[nid][nc]=1;
                }    
            }
            zan=next[zan];
        }    
    }    
    
    minn=INF;
    for(i=k;i<=100;i++)
    {
        minn=min(minn,dis[t][i]);
    }
    
    return minn;
}

void debug()
{
    int i,f;
    for(i=1;i<=n;i++)
    {
        for(f=0;f<=k+1;f++)
        printf("%d ",dis[i][f]);
        printf("\n");
    }
}

inline void in(int &num)
{
     char in=getchar();
     while(in<'0'||in>'9'){
           in=getchar();
     }
     num=in-'0';
     in=getchar();
     while(in>='0'&&in<='9'){
           num*=10; num+=in-'0';
           in=getchar();
     }
}

int main()
{
    int ans,u,v,l,i,mu;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        chu();
        for(i=0;i<m;i++)
        {
            in(u);
            in(v);
            in(l);
            add(u,v,l);
        }
        scanf("%d%d%d",&s,&t,&mu);
        k=mu/10;
        if(0 != mu%10)
        {
            k++;
        }
        ans=spfa();
        if(INF == ans)
        {
            printf("-1\n");
        }
        else
        {
            printf("%d\n",ans);
        }
    }
    return 0;
}