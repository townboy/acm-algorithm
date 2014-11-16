//（回溯搜解）
// 只能解对称性建图
struct TwoSAT {
	int n;
	vector<int> G[maxn << 1];
	bool mark[maxn << 1];
	int S[maxn << 1], c;

	bool dfs(int x) {
		if(true == mark[x^1])
			return false;
		if(true == mark[x])
			return true;
		mark[x] = true;
		S[c++] = x;
		for(int i = 0 ;i < G[x].size(); i++) 
			if(false == dfs(G[x][i]))
				return false;
		return true;
	}

	void init(int n) {
		this->n = n;
		for(int i = 0 ;i < n*2 ;i++)
			G[i].clear();
		memset(mark,false,sizeof(mark));
	}

	void add_clause(int x ,int y) {
		G[x].push_back(y^1);
		G[y].push_back(x^1);
	}

	bool solve() {
		for(int i = 0 ;i < n*2 ;i+=2) {
			if(false == mark[i] && false == mark[i+1]) {
				c = 0;
				if(false == dfs(i)) {
					while(c > 0) 
						mark[S[--c]] = false;
					if(false == dfs(i+1))
						return false;
				}
			}
		}
		return true;
	}
};


// 强联通建图
#include<stack>
#include<queue>
#include<stdio.h>
#include<memory.h>
#include<iostream>
#define maxn 3000
#define maxe 2100000
#define W 0
#define R 1
#define B 2

using namespace std;

int scc,Dindex,n,size,m;				// 顶点序号是 0 - n-1 
int belong[maxn],instack[maxn],dfn[maxn],low[maxn],first[maxn];
stack<int>q;
int opp[maxn],group,deg[maxn],col[maxn];

struct xx 
{
	int u;
	int v;
};
struct xx mat[maxe];

struct node 
{
	int v;
	int next;
};
struct node edge[maxe];

void add(int u,int v)
{
	edge[size].v=v;
	edge[size].next=first[u];
	first[u]=size++;
}

void tarjan(int x)
{	
	int tem,i;
	dfn[x]=low[x]=++Dindex;
	instack[x]=1;
	q.push(x);
	
	tem=first[x];
	while(-1 != tem)
	{
		i=edge[tem].v;
		if(0 == dfn[i])
		{
			tarjan(i);
			low[x]=min(low[i],low[x]);
		}
		else if(1==instack[i] && dfn[i]<low[x])
		{
			low[x]=dfn[i];
		}
		tem=edge[tem].next;
	}
	if(low[x] == dfn[x])
	{
		scc++;
		while(1)
		{
			i=q.top();
			q.pop();
			instack[i]=0;
			belong[i]=scc;
			if(i == x)
			{
				break;
			}
		}
	}
}

void chu()
{
	Dindex=scc=size=0;
	memset(instack,0,sizeof(instack));
	memset(dfn,0,sizeof(dfn));
	memset(first,-1,sizeof(first));
	while(!q.empty())
	{
		q.pop();
	}
}

void slove()
{
	int i;
	for(i=0;i<n;i++)
	{
		if(0 == dfn[i])
		{
			tarjan(i);
		}
	}
}

int check()
{
	int i;
	for(i=0;i<group;i++)
	{
		opp[belong[i<<1]]=belong[i<<1|1];
		opp[belong[i<<1|1]]=belong[i<<1];
		if(belong[i<<1] == belong[i<<1|1])
		{
			return 0;
		}	
	}
	return 1;
}

void print()
{
	int i,flag=0;
	for(i=0;i<n;i++)
	{
		if(R == col[belong[i]])
		{
			if(1 == flag)
			{
				printf(" ");		
			}
			flag=1;
			printf("%d",i);
		}
	}
}

void topo()
{
	int v,i,tem;
	queue<int>zero;
	memset(col,W,sizeof(col));	
	for(i=1;i<=scc;i++)
	{
		if(0 == deg[i])
		{
			zero.push(i);
		}
	}
	while(!zero.empty())
	{
		tem=zero.front();
		zero.pop();
		if(0 == col[tem])
		{
			col[tem]=R;
			col[opp[tem]]=B;
		}	
		tem=first[tem];
		while(-1 != tem)
		{
			v=edge[tem].v;
			deg[v]--;
			if(0 == deg[v])
			{
				zero.push(v);
			}
			tem=edge[tem].next;
		}	
	}
}

void build()
{
	int i,n,v,u;
	chu();
	memset(deg,0,sizeof(deg));
	for(i=0;i<m;i++)
	{
		u=belong[mat[i].u];
		v=belong[mat[i].v];
		if(u == opp[v] || v == opp[u])
		{
			continue;	
		}
		add(opp[u],v);
		add(opp[v],u);
		deg[u]++;
		deg[v]++;
	}
}

int main()
{
	return 0;
}


