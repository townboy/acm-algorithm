******************************
    Author : townboy
    Submit time : 2012-10-15 23:47:38
    Judge Status : Accepted
    HDOJ Runid : 6926590
    Problem id : 3311
    Exe.time : 187MS
    Exe.memory : 7784K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>
#include<vector>
#include<queue>
#include<iostream>
#define INF 1000000000

using namespace std;

struct node 
{
    int v;
    int len;
};
struct node ru;

int n,m,p,M;
int val[1100];
vector<node>q[1100];
int dis[1100][900],flag[1100],hash[1100][900];

struct xx
{
    int id;
    int sta;
};
struct xx zan,tem;

void add(int u,int v,int len)
{    
    ru.len=len;
    ru.v=u;
    q[v].push_back(ru);
    ru.v=v;
    q[u].push_back(ru);
}

void chu()
{
    int i,f;
    for(i=0;i<=n+m;i++)
    {
        q[i].clear();
        for(f=0;f<=M;f++)
        {
            dis[i][f]=INF;
        }
    }
    memset(flag,0,sizeof(flag));
    memset(hash,0,sizeof(hash));
}

void steiner()
{
    int id,sta,i,st,mask,v,newsta,size,len;
    queue<xx>que;
    for(i=0;i<=n;i++)
    {
        zan.id=i;
        zan.sta=flag[i];
        dis[i][flag[i]]=0;
        hash[i][flag[i]]=1;
        que.push(zan);
    }
    while(!que.empty())
    {
        tem=que.front();
        que.pop();
        id=tem.id;
        sta=tem.sta;
        hash[id][sta]=0;
        
        st=M^sta;
        for(mask=st;mask;mask=(st&(mask-1)))
        {
            newsta=mask;
            if(0 != flag[id])
            {
                newsta=(mask|flag[id]);                    
            }
            if(dis[id][newsta|sta] > dis[id][sta]+dis[id][newsta])
            {
                dis[id][newsta|sta]=dis[id][sta]+dis[id][newsta];
                if(0 == hash[id][newsta|sta])
                {
                    hash[id][newsta|sta]=1;
                    zan.id=id;
                    zan.sta=(newsta|sta);
                    que.push(zan);
                }
            }
        }
        size=q[id].size();
        for(i=0;i<size;i++)
        {
            v=q[id][i].v;
            len=q[id][i].len;
            newsta=sta;
            if(0 != flag[v])
            {
                newsta=(newsta|flag[v]);
            }
            if(dis[v][newsta] > dis[id][sta]+len)
            {    
                dis[v][newsta]=dis[id][sta]+len;
                if(0 == hash[v][newsta])
                {
                    hash[v][newsta]=1;
                    zan.id=v;
                    zan.sta=newsta;
                    que.push(zan);        
                }    
            }
        }
    }
}

void debug()
{
    int i,f;
    for(i=0;i<=n;i++)
    {
            printf("%d ",dis[i][M]);
    }    
    printf("\n");
}

int main()
{
    int i,u,v,len,ans;
    while(scanf("%d%d%d",&n,&m,&p)!=EOF)
    {
        M=(1<<(n+1))-1;
        chu();

        for(i=1;i<=n+m;i++)
        {
            scanf("%d",&val[i]);
            add(0,i,val[i]);
        }
        for(i=0;i<=n;i++)
        {
            flag[i]=(1<<i);
        }
        for(i=0;i<p;i++)
        {
            scanf("%d%d%d",&u,&v,&len);            
            add(u,v,len);
        }
        steiner();
        ans=INF;
        for(i=0;i<=n;i++)
        {
            ans=min(ans,dis[i][M]);
        }
        printf("%d\n",ans);
    }    
    return 0;
}