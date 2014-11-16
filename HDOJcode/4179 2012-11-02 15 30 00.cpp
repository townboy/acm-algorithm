******************************
    Author : townboy
    Submit time : 2012-11-02 15:30:00
    Judge Status : Accepted
    HDOJ Runid : 7065385
    Problem id : 4179
    Exe.time : 828MS
    Exe.memory : 2264K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>
#include<vector>
#include<queue>
#include<math.h>
#define INF 0x7fffffff
using namespace std;

int n,m,s,t,aimd;
int loc[11000][3],hash[11000][2];
double dis[11000][2];

struct node 
{
    int v;
    double len;
    int d;
};
struct node ru;

vector<node>q[11000];

void chu()
{
    int i,f;
    for(i=1;i<=n;i++)
    {
        q[i].clear();        
        for(f=0;f<2;f++)
        {
            dis[i][f]=INF;
        }
    }
    memset(hash,0,sizeof(hash));
}

void add(int u,int v)
{
    int i,d;
    double sum=0;
    for(i=0;i<3;i++)
    {
        sum+=(loc[u][i]-loc[v][i])*(loc[u][i]-loc[v][i]);
    }
    ru.len=sqrt((double)sum);
    
    sum=0;
    for(i=0;i<2;i++)
    {
        sum+=(loc[u][i]-loc[v][i])*(loc[u][i]-loc[v][i]);
    }
    d=(int)(100*(loc[v][2]-loc[u][2])/sqrt((double)sum));
    ru.v=v;
    ru.d=max(0,d);
    q[u].push_back(ru);
    
    ru.d=max(0,-d);
    ru.v=u;
    q[v].push_back(ru);
}

void spfa()
{
    double len;
    int i,id,d,flag,size,v; 
    int newflag;
    queue<int>que;
    
    que.push(s);
    que.push(0);
    dis[s][0]=0;
    while(!que.empty())
    {
        id=que.front();
        que.pop();
        flag=que.front();
        que.pop();
        size=q[id].size();
        hash[id][flag]=0;
        
        for(i=0;i<size;i++)
        {        
            if(q[id][i].d > aimd)
            {
                continue;
            }
            d=q[id][i].d;
            v=q[id][i].v;
            len=q[id][i].len;
            if(1 == flag)
            {
                if(dis[v][1] > dis[id][1]+len)
                {
                    dis[v][1]=dis[id][1]+len;
                    if(0 == hash[v][1])
                    {
                        hash[v][1]=1;
                        que.push(v);
                        que.push(1);
                    }    
                }    
            }
            else
            {
                newflag = aimd==d ? 1:0;
                if(dis[v][newflag] > dis[id][0]+len)
                {
                    dis[v][newflag] = dis[id][0]+len;    
                    if(0 == hash[v][newflag])
                    {
                        hash[v][newflag]=1;
                        que.push(v);
                        que.push(newflag);
                    }
                }
            }
        }        
    }
}

int main()
{
    int i,f,u,v;
    
    while(scanf("%d%d",&n,&m),n+m)
    {
        chu();
        for(i=1;i<=n;i++)
        {
            scanf("%d%d%d",&loc[i][0],&loc[i][1],&loc[i][2]);
        }
        for(i=0;i<m;i++)
        {
            scanf("%d%d",&u,&v);
            add(u,v);
        }
        scanf("%d%d%d",&s,&t,&aimd);
        spfa();
        if(INF == dis[t][1])
        {
            printf("None\n");
            continue;
        }
        printf("%.1lf\n",dis[t][1]);
    }
    return 0;
}