******************************
    Author : townboy
    Submit time : 2012-11-04 17:04:54
    Judge Status : Accepted
    HDOJ Runid : 7082884
    Problem id : 2363
    Exe.time : 62MS
    Exe.memory : 372K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<queue>
#include<iostream>
#include<vector>
#include<stdlib.h>
#define INF 0x7fffffff

using namespace std;

int cmp(const void *a,const void *b)
{
    return *(int*)a-*(int*)b;
}

struct node 
{
    int v;
    int len; 
};
struct node ru;

int now,so[110],up,down,minn;
int n,hei[110],diff,dis[110],hash[110];
vector<node>q[110]; 
vector<int>ans;

void chu()
{
    int i;
    for(i=1;i<=n;i++)
    {
        q[i].clear(); 
    }    
    ans.clear();
} 

void add(int u,int v,int len)
{
    ru.len=len;
    ru.v=v;
    q[u].push_back(ru);
    ru.v=u;
    q[v].push_back(ru); 
} 

void spfa()
{
    int tem,i,size,v;
    queue<int>que;

    for(i=1;i<=n;i++)
    {
        dis[i]=INF;
    }
    dis[1]=hei[1];
    que.push(1);
    memset(hash,0,sizeof(hash));
    
    while(!que.empty())
    {
        tem=que.front();
        que.pop();
        hash[tem]=0;
    
        size=q[tem].size();
        for(i=0;i<size;i++)
        {
            v=q[tem][i].v;
            
            if(hei[v] < now)
            {
                continue;
            }
            if(dis[v] > max(dis[tem],hei[v]))
            {
                dis[v]=max(dis[tem],hei[v]);
                if(0 == hash[v])
                {
                    hash[v]=1;
                    que.push(v);
                }    
            }
        }        
    }
}

void debug()
{
    int i,size=ans.size();
    for(i=0;i<size;i++)
    {    
        printf("%d ",ans[i]);
    }
    printf("\n");
}

void lenspfa()
{
    int len,i,size,v,tem;
    queue<int>que;

    memset(hash,0,sizeof(hash));
    for(i=1;i<=n;i++)
    {
        dis[i]=INF;
    }
    dis[1]=0;
    que.push(1);
    
    while(!que.empty())
    {
        tem=que.front();
        que.pop();
        hash[tem]=0;
        
        size=q[tem].size();
        for(i=0;i<size;i++)
        {
            v=q[tem][i].v;
            len=q[tem][i].len;
            if(hei[v] < down || hei[v] > up)
            {
                continue;
            }
            if(dis[v] > dis[tem]+len)
            {
                dis[v]=dis[tem]+len;
                if(0 == hash[v])
                {
                    hash[v]=1;
                    que.push(v);
                }
            }
        }
    }
    minn=min(minn,dis[n]);
}

int main()
{
    int u,v,len,i,cas,f,m,size;
    scanf("%d",&cas);
    for(i=0;i<cas;i++)
    {
        scanf("%d%d",&n,&m);
        chu();
        for(f=1;f<=n;f++)
        {
            scanf("%d",&hei[f]); 
            so[f]=hei[f];
        } 
        for(f=0;f<m;f++)
        {
            scanf("%d%d%d",&u,&v,&len);
            add(u,v,len); 
        } 
        
        qsort(&so[1],n,sizeof(so[0]),cmp);
        
        diff=INF;
        so[0]=-1;
        for(f=1;f<=n;f++)
        {
            now=so[f];
            if(so[f] == so[f-1])
            {
                continue;
            }
            if(now > hei[1] || now > hei[n])
            {
                break;    
            }
            
            spfa();
            if(INF == dis[n])
            {    
                break;
            }
            if(diff > dis[n]-now)
            {
                diff=dis[n]-now;
                ans.clear();
                ans.push_back(now);
            }
            else if(diff == dis[n]-now)
            {
                ans.push_back(now);        
            }
        }
    
        minn=INF;
        size=ans.size();
        for(f=0;f<size;f++)
        {
            down=ans[f];
            up=down+diff;
            lenspfa();
        }
        
        printf("%d %d\n",diff,minn);
    } 
    return 0; 
} 