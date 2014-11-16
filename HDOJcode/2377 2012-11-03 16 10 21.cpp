******************************
    Author : townboy
    Submit time : 2012-11-03 16:10:21
    Judge Status : Accepted
    HDOJ Runid : 7073382
    Problem id : 2377
    Exe.time : 250MS
    Exe.memory : 1684K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<queue>
#include<vector>
#include<memory.h>
#include<iostream>
#define INF 0x7fffffff

using namespace std;

vector<int>q[20000];
int n,yin[21000],bus[21000],map[21000];
vector<int>aim;
int dis[21000],maxx[21000],hash[21000],ji;

void chu()
{
    int i;
    for(i=1;i<=n;i++)
    {
        q[i].clear();
    }
    memset(yin,-1,sizeof(yin));
    memset(maxx,0,sizeof(maxx));
    memset(bus,0,sizeof(bus));
    memset(map,0,sizeof(map));
    aim.clear();
    ji=0;
}

void spfa(int s)
{
    int i,size,tem,v;
    queue<int>que;
    
    for(i=1;i<=n;i++)
    {
        dis[i]=INF;
    }
    memset(hash,0,sizeof(hash));
    
    que.push(s);
    dis[s]=0;
    
    while(!que.empty())
    {
        tem=que.front();
        que.pop();
        hash[tem]=0;
        size=q[tem].size();
        for(i=0;i<size;i++)
        {
            v=q[tem][i];
            if(dis[v] > dis[tem]+1)
            {
                dis[v]=dis[tem]+1;
                if(0 == hash[v])
                {
                    hash[v]=1;
                    que.push(v);
                }
            }
        }
    }
    for(i=1;i<=n;i++)
    {
        maxx[i]=max(maxx[i],dis[i]);
    }
}

int name(int x)
{
    if(0 == map[x])
    {
        ji++;
        map[x]=ji;
        return ji;
    }
    return map[x];
}

int main()
{
    int c,p,k,i,cas,f,g,m,ans,size,flag;
    scanf("%d",&cas);
    for(i=0;i<cas;i++)
    {
        scanf("%d%d",&n,&m);
        chu();
        for(f=1;f<=n;f++)
        {
            scanf("%d",&k);
            yin[name(k)]=k;            
            scanf("%d",&c);
            for(g=0;g<c;g++)
            {
                scanf("%d",&p);
                q[name(k)].push_back(name(p));
            }
        }
        for(f=0;f<m;f++)
        {
            scanf("%d",&k);
            for(g=0;g<k;g++)
            {
                scanf("%d",&p);
                if(0 == bus[name(p)])
                {
                    bus[name(p)]=1;
                    aim.push_back(name(p));
                }
            }
        }
        size=aim.size();
        for(f=0;f<size;f++)
        {
            spfa(aim[f]);
        }
        ans=0;
        maxx[0]=INF;
        for(f=1;f<=n;f++)
        {
            if(maxx[f] < maxx[ans])
            {
                ans=f;
            }
            else if((maxx[f] == maxx[ans]) && (yin[f] < yin[ans]))
            {
                ans=f;
            }    
        }
        printf("%d %d\n",maxx[ans]+1,yin[ans]);
    }
    return 0;
}