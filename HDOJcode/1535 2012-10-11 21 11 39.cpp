******************************
    Author : townboy
    Submit time : 2012-10-11 21:11:39
    Judge Status : Accepted
    HDOJ Runid : 6906235
    Problem id : 1535
    Exe.time : 718MS
    Exe.memory : 44720K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<queue>
#include<vector>
#include<memory.h>
#define INF 0x7fffffff
using namespace std;

struct node
{
    int v;
    int len;
};
struct node ru;

int road[1100000][3],s;
int n,m,hash[1100000],dis[1100000];
vector<node>q[1100000];

void chu()
{
    int i;
    for(i=1;i<=n;i++)
    {
        q[i].clear();
        dis[i]=INF;
    }    
    memset(hash,0,sizeof(hash));
}

void add(int u,int v,int len)
{
    ru.len=len;
    ru.v=v;
    q[u].push_back(ru);
}

void spfa()
{
    int i,tem,size,len,v;
    queue<int>que;
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
            v=q[tem][i].v;
            len=q[tem][i].len;
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
}

int main()
{
    int i,f,num,u,v,len,ans,g;
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        scanf("%d%d",&n,&m);
        chu();
        for(f=0;f<m;f++)
        {
            for(g=0;g<3;g++)
            {
                scanf("%d",&road[f][g]);
            }
            add(road[f][0],road[f][1],road[f][2]);
        }
        ans=0;
        s=1;
        spfa();
        for(f=2;f<=n;f++)
        {
            ans+=dis[f];
        }
        chu();
        for(f=0;f<m;f++)
        {
            add(road[f][1],road[f][0],road[f][2]);
        }
        spfa();
        for(f=2;f<=n;f++)
        {
            ans+=dis[f];
        }
        printf("%d\n",ans);        
    }
    return 0;
}