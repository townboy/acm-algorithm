// 顶点下标是从1 - n

int gap[maxn],dis[maxn],pre[maxn],cur[maxn];
int size,n,head[maxn];

struct Node{
	int c,v,next;
	Node(){}
	Node(int _v,int _c,int _next):v(_v),c(_c),next(_next){}
}E[maxe];

int sap(int s,int t) {
	memset(dis,0,sizeof(dis));
	memset(gap,0,sizeof(gap));
	for(int i=1;i<=n;i++)	cur[i] = head[i];
	int u = pre[s] = s,maxflow = 0,aug = -1;
	gap[0] = n;
	while(dis[s] < n) {
loop:		for(int &i = cur[u]; i != -1; i = E[i].next) {
			int v = E[i].v;
			if(E[i].c && dis[u] == dis[v] + 1) {
				if(aug==-1 || aug>E[i].c)	aug=E[i].c;
				pre[v] = u;
				u = v;
				if(v == t) {
					maxflow += aug;
					for(u = pre[u];v != s;v = u,u = pre[u]) {
						E[cur[u]].c -= aug;
						E[cur[u]^1].c += aug;
					}
					aug = -1;
				}
				goto loop;
			}
		}
		int mindis = n;
		for(int i = head[u]; i != -1 ; i = E[i].next) {
			int v = E[i].v;
			if(E[i].c && mindis > dis[v]) {
				cur[u] = i;
				mindis = dis[v];
			}
		}
		if( (--gap[dis[u]]) == 0)	break;
		gap[ dis[u] = mindis+1 ] ++;
		u = pre[u];
	}
	return maxflow;
}

void add(int u,int v,int c,int cc = 0) {
	E[size] = Node(v,c,head[u]);
	head[u] = size++;
	E[size] = Node(u,cc,head[v]);
	head[v] = size++;
}
void init(){
	memset(head,-1,sizeof(head));
	size=0;
}

/*
1. 无源汇求可行流
算法：
按上述方法构造新网络(分离必要弧，附加源汇)
求附加源x到附加汇y的最大流
若x的出弧或y的入弧都满，则有解，将必要弧合并回原图；否则，无解。
2. 有源汇求最大/最小流
算法：
往t到s添加一条下界b,上界c的流量，用无源汇的方法来判是否存在可行流，如果存在，等价于s到t之间存在一个流量大于等于b小于等于c的可行流。
最大流二分判定b（上界 +oo），最小流二分判定c(下界 -oo)。
*/



// ISAP
// 下标必须是1到n


#include<stdio.h>
#include<memory.h>
#include<queue>
#include<iostream>
#define maxn 1000
#define maxe 2100000
#define INF 0x3f3f3f3f

using namespace std;

int n,m,s,t;
int size,net[maxn];
int gap[maxn];//gap优化 
int dist[maxn];//距离标号 
int pre[maxn];//前驱 
int curedge[maxn];//当前弧 
int hash[maxn];

struct node
{
    int v,next;
    int cap;
    int flow;
};
struct node edge[maxe];

void init()
{
    size=0;
    memset(net,-1,sizeof(net));
}

void add(int u,int v,int cap)
{
    edge[size].v = v;
    edge[size].cap = cap;
    edge[size].flow = 0;
    edge[size].next = net[u];
    net[u] = size;
    ++size;

    edge[size].v = u;
    edge[size].cap = 0;
    edge[size].flow = 0;
    edge[size].next = net[v];
    net[v] = size;
    ++size;
}

struct node2 
{
    int id,dis;
    friend bool operator < (node2 a,node2 b){
        return a.dis > b.dis;
    }
};
struct node2 tem,ru;

void bfs()
{
    priority_queue<node2>que;
    int i,u,dis;
    memset(dist,0x3f,sizeof(dist));
    memset(hash,0,sizeof(hash));
    tem.id=t;
    tem.dis=0;
    que.push(tem);
    while(!que.empty())
    {
        tem=que.top(),que.pop();
        u=tem.id,dis=tem.dis;
        if(1 == hash[u])    continue;
        dist[u]=dis;
        hash[u]=1;
        for(i=net[u];i!=-1;i=edge[i].next)
        {
            if(0 == edge[i].cap)    continue;
            if(1 == hash[edge[i].v])    continue;
            ru.id=edge[i].v,ru.dis=dis+1;
            que.push(ru);
        }
    }
    for(i=0;i<=n;i++)
        gap[min(n+1,dist[i])]++;
}

int isap()
{
    int curflow,u,temp,neck,i;
    int maxflow;
    memset(gap,0,sizeof(gap));
    memset(pre,-1,sizeof(pre));
    memset(dist,0,sizeof(dist));
    for(i=1;i<=n;i++) 
        curedge[i]=net[i];//将当前弧初始话成邻接表的第一条边 
    gap[0]=n;
    maxflow=0;
    u=s;
    while(dist[s] < n)
    {
        if(u==t)
        {        //找到一条增广路 
            curflow=INF;
            for(i=s;i!=t;i=edge[curedge[i]].v)    //沿着增广路找到最小增广流量 
                if(curflow > edge[curedge[i]].cap)
                {
                    neck=i;
                    curflow=edge[curedge[i]].cap;
                }
            for(i=s;i!=t;i=edge[curedge[i]].v)
            {    //更新 
                temp=curedge[i];
                edge[temp].cap-=curflow;
                edge[temp].flow+=curflow;
                temp^=1;
                edge[temp].cap+=curflow;
                edge[temp].flow-=curflow;
            }
            maxflow+=curflow;
            u=neck;//下次直接从关键边的u开始新一轮的增广 
        }
        for(i=curedge[u];i!=-1;i=edge[i].next)//找到一条允许弧 
            if(edge[i].cap>0 && dist[u]==dist[edge[i].v]+1)	break;
        if(i!=-1)    //如果找到 将u指向v 
        {
            curedge[u]=i;
            pre[edge[i].v]=u;
            u=edge[i].v;
        }
        else
        {        //找不到 
            if(0 == --gap[dist[u]])	break;//出现断层
            curedge[u] = net[u];//把当前弧重新设为邻接表中满足要求的第一条弧
            for(temp=n,i=net[u];i!=-1;i=edge[i].next)
                if(edge[i].cap > 0)
                    temp=temp<dist[edge[i].v]?temp:dist[edge[i].v];
            dist[u]=temp+1;//将这个点的距离标号设为由它出发的所有弧的终点的距离标号的最小值加1
            gap[dist[u]]++;
            if(u != s)
                u=pre[u];
        }
    }
    return maxflow;
}


// 最小费用流
////////////////////O（VE^2）
//  如果要求最大费用的话 只需在加边的时候加-的边  输出时输出-ans即可


int net[maxn],size,maxflow,mincost;
int n,dist[maxn],pre[maxn],pe[maxn];
bool hash[maxn];
queue<int>q;
	
struct xx{
	int v,next;
	int cap;
	int cost;
	xx(){}
	xx(int _v,int _next,int _cap,int _cost)
	:v(_v),next(_next),cap(_cap),cost(_cost){}
};
struct xx edge[maxe];

void init(){
	size=0;
	memset(net,-1,sizeof(net));
}

void add(int u,int v,int cap,int cost)
{
	edge[size] = xx(v,net[u],cap,cost);
	net[u]=size++;
	edge[size] = xx(u,net[v],0,-cost);
	net[v]=size++;
}

int spfa(int s,int t)
{
	while(!q.empty())	q.pop();
	memset(hash,0,sizeof(hash));
	memset(pre,-1,sizeof(pre));
	for(int i=1;i<=n;i++)	dist[i]=INF;
	dist[s]=0;
	hash[s]=1;
	q.push(s);
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		hash[u]=0;
		for(int i=net[u];i!=-1;i=edge[i].next)
		{
			int v=edge[i].v;
			if(edge[i].cap && dist[v]>dist[u]+edge[i].cost)
			{
				dist[v]=dist[u]+edge[i].cost;
				pre[v]=u; 
				pe[v]=i;
				if(0 == hash[v]){
					hash[v]=1;
					q.push(v);
				}
			}
		}
	}
	if(-1 == pre[t]) 
		return 0;
	return 1;
}

void mcmf(int s,int t)
{
	maxflow=0;
	mincost=0;
	while(1 == spfa(s,t))
	{
		int aug=INF;
		for(int v=t;v!=s;v=pre[v])
			aug=min(aug,edge[pe[v]].cap);
		maxflow+=aug;
		mincost+=dist[t]*aug;
		for(int v=t;v!=s;v=pre[v]){
			edge[pe[v]].cap-=aug;
			edge[pe[v]^1].cap+=aug;
		}
	}
}


//zkw费用流
struct MaxFlow {
    int size, n;
    int st, en, maxflow, mincost;
    bool vis[maxn];
    int net[maxn], pre[maxn], cur[maxn], dis[maxn];
    queue <int> Q;
    struct EDGE {
        int v, cap, cost, next;
        EDGE(){}
        EDGE(int a, int b, int c, int d) {
            v = a, cap = b, cost = c, next = d;
        }
    }E[maxm<<1];
    void init(int _n) {
        n = _n, size = 0;
        memset(net, -1, sizeof(net));
    }
    void add_edge(int u, int v, int cap, int cost) {
        E[size] = EDGE(v, cap, cost, net[u]);
        net[u] = size++;
        E[size] = EDGE(u, 0, -cost, net[v]);
        net[v] = size++;
    }
    bool adjust() {
        int v, min = inf;
        for(int i = 0; i <= n; i++) {
            if(!vis[i])
                continue;
            for(int j = net[i]; v = E[j].v, j != -1; j = E[j].next)
                if(E[j].cap)
                    if(!vis[v] && dis[v]-dis[i]+E[j].cost < min)
                        min = dis[v] - dis[i] + E[j].cost;
        }
        if(min == inf)
            return false;
        for(int i = 0; i <= n; i++)
            if(vis[i])
                cur[i] = net[i], vis[i] = false, dis[i] += min;
        return true;
    }
    int augment(int i, int flow) {
        if(i == en) {
            mincost += dis[st] * flow;
            maxflow += flow;
            return flow;
        }
        vis[i] = true;
        for(int j = cur[i], v; v = E[j].v, j != -1; j = E[j].next) {
            if(!E[j].cap)
                continue;
            if(vis[v] || dis[v]+E[j].cost != dis[i])
                continue;
            int delta = augment(v, std::min(flow, E[j].cap));
            if(delta) {
                E[j].cap -= delta;
                E[j^1].cap += delta;
                cur[i] = j;
                return delta;
            }
        }
        return 0;
    }
    void spfa() {
        int u, v;
        for(int i = 0; i <= n; i++)
            vis[i] = false, dis[i] = inf;
        dis[st] = 0;
        Q.push(st);
        vis[st] = true;
        while(!Q.empty()) {
            u = Q.front(), Q.pop();
            vis[u] = false;
            for(int i = net[u]; v = E[i].v, i != -1; i = E[i].next) {
                if(!E[i].cap || dis[v] <= dis[u] + E[i].cost)
                    continue;
                dis[v] = dis[u] + E[i].cost;
                if(!vis[v]) {
                    vis[v] = true;
                    Q.push(v);
                }
            }
        }
        for(int i = 0; i <= n; i++)
            dis[i] = dis[en] - dis[i];
    }
    int zkw(int s, int t) {
        st = s, en = t;
        spfa();
        mincost = maxflow = 0;
        for(int i = 0; i <= n; i++)
            vis[i] = false, cur[i] = net[i];
        do {
            while(augment(st, inf))
                memset(vis, false, sizeof(vis));
        }while(adjust());
        return mincost;
    }
};




