******************************
    Author : townboy
    Submit time : 2014-05-16 19:44:11
    Judge Status : Accepted
    HDOJ Runid : 10751612
    Problem id : 3452
    Exe.time : 46MS
    Exe.memory : 352K
    https://github.com/townboy
******************************


#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N = 1005;
const int INF = 99999999;

struct node
{
    int v,next,cap;
}edge[5000];

int n,s,t,cnt,head[N],in[N];


void addedge(int u,int v,int w)
{
    edge[cnt].v = v;
    edge[cnt].cap = w;
    edge[cnt].next = head[u];
    head[u] = cnt++;
    edge[cnt].v = u;
    edge[cnt].cap = w;
    edge[cnt].next = head[v];
    head[v] = cnt++;
}

void init()
{
    t = n + 1;
    cnt = 0;
    memset(head,-1,sizeof(head));
    memset(in,0,sizeof(in));
}


void read(int &ret)
{
    char c;
    do
    {
        c = getchar();
    }
    while(c<'0'||c>'9');
    ret = c - '0';
    while((c=getchar())>='0'&&c<='9')
        ret = ret*10 + c - '0';
}

void input()
{
    int c = n-1;
    int u,v,w;
    while(c--)
    {
        read(u);
        read(v);
        read(w);
        in[u]++;
        in[v]++;
        addedge(u,v,w);
    }
    for(int i = 1; i <= n; i++)
    {
        if(i==s)
            continue;
        if(in[i]==1)
            addedge(i,t,INF);
    }
}

int SAP(int s,int t,int n)
{
    int pre[N],dis[N],gap[N],cur[N];
    int u,v,f;
    int aug = -1;
    int maxflow = 0;

    for(int i = 0; i <= n; i++)
        cur[i] = head[i];
    memset(dis,0,sizeof(dis));
    memset(gap,0,sizeof(gap));
    u = pre[s] = s;
    gap[0] = n;
    while(dis[s] < n)
    {
loop:
        for(int & i = cur[u]; i+1; i = edge[i].next)
        {
            v = edge[i].v;
            f = edge[i].cap;
            if(f&&dis[u]==dis[v]+1)
            {
                if(aug==-1||aug>f)
                    aug = f;
                pre[v] = u;
                u = v;
                if(v==t)
                {
                    maxflow += aug;
                    for(u = pre[u]; v!=s; v = u, u = pre[u])
                    {
                        edge[cur[u]].cap -= aug;
                        edge[cur[u]^1].cap += aug;
                    }
                    aug = -1;
                }
                goto loop;
            }
        }
        int mindis = n;
        for(int i = head[u]; i+1; i = edge[i].next)
        {
            v = edge[i].v;
            if(edge[i].cap&&mindis>dis[v])
            {
                cur[u] = i;
                mindis = dis[v];
            }
        }
        if(--gap[dis[u]]==0)
            break;
        gap[dis[u] = mindis+1]++;
        u = pre[u];
    }
    return maxflow;
}

int main()
{
    while(scanf("%d%d",&n,&s))
    {
        if(!n&&!s)
            break;
        init();
        input();
        cout<<SAP(s,t,t)<<endl;
    }
    return 0;
}
