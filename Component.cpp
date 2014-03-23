//点双联通
#define maxn 10010

struct BCC
{
	stack<int>S;
	vector<int>G[maxn],bcc[maxn];
	int n,dfs_clock,bcc_cnt,bccno[maxn],iscut[maxn];
	int dfn[maxn],low[maxn];
	void init(int _n){
		n=_n;
		dfs_clock=bcc_cnt=0;
		memset(dfn,0,sizeof(dfn));
		memset(iscut,0,sizeof(iscut));
		for(int i=1;i<=n;i++)
			G[i].clear();
	}
	void add(int u,int v){
		G[u].push_back(v);
	}
	void dfs(int u,int fa){
		int i,v,size=G[u].size(),x,child=0;
		S.push(u);
		dfn[u]=low[u]=++dfs_clock;
		for(i=0;i<size;i++)
		{
			v=G[u][i];
			if(0 == dfn[v])
			{
				child++;
				dfs(v,u);
				low[u]=min(low[u],low[v]);
				if(low[v] >= dfn[u])
				{
					iscut[u]=1;
					bcc_cnt++;
					bcc[bcc_cnt].clear();
					do{
						x=S.top();S.pop();
						bccno[x]=bcc_cnt;
						bcc[bcc_cnt].push_back(x);
					}while(x != v);
					bcc[bcc_cnt].push_back(u);
				}
			}
			else if(v != fa)
				low[u]=min(low[u],dfn[v]);
		}
		if(-1==fa && 1==child)
			iscut[u]=0;
	}
	void find_bcc(){
		for(int i=1;i<=n;i++)
			if(0 == dfn[i])
			{
				while(!S.empty()) S.pop();
				dfs(i,-1);
			}
	}
};


//边双联通
struct BCC
{
	int n,dfs_clock,bcc_cnt;
	int dfn[maxn],low[maxn],bccno[maxn];
	vector<int>G[maxn];
	stack<int>S;
	void init(int _n){
		dfs_clock=bcc_cnt=0;
		n=_n;
		for(int i=1;i<=n;i++)
			G[i].clear();
		memset(dfn,0,sizeof(dfn));
		while(!S.empty())
			S.pop();
	}
	void dfs(int u,int fa){
		int v,size=G[u].size(),x,flag=1;
		S.push(u);
		dfn[u]=low[u]=++dfs_clock;
		for(int i=0;i<size;i++)
		{
			v=G[u][i];
			if(v == fa && 1==flag)
			{	
				flag=0;
				continue;
			}
			if(0 == dfn[v])
			{
				dfs(v,u);
				low[u]=min(low[u],low[v]);
			}
			else
				low[u]=min(low[u],dfn[v]);
		}
		if(low[u] == dfn[u])
		{
			bcc_cnt++;
			do{
				x=S.top();S.pop();
				bccno[x]=bcc_cnt;
			}while(x != u);
		}
	}
	void add(int u,int v){
		G[u].push_back(v);
	}
	void find_bcc(){
		for(int i=1;i<=n;i++)
			if(0 == dfn[i])
				dfs(i,-1);
	}
};

//强连通 Tarjan Algorithm
//树枝边：深搜树上存在的边。
//反向边：指向节点祖先的边。
//正向边:指向自己的子孙的边，不是树枝边。
//交叉边：指不是直系亲属关系的边。


struct SCC
{
	int n,dfs_clock,scc_cnt;
	int dfn[maxn],low[maxn],sccno[maxn];
	vector<int> G[maxn];
	stack<int> S;
	void init(int _n){
		n=_n;
		for(int i=1;i<=n;i++)
			G[i].clear();
	}
	void add(int u,int v){
		G[u].push_back(v);
	}
	void dfs(int u){
		int i,size=G[u].size(),v,x;
		dfn[u]=low[u]=++dfs_clock;
		S.push(u);
		for(i=0;i<size;i++)
		{
			v=G[u][i];
			if(0 == dfn[v])
			{
				dfs(v);
				low[u]=min(low[v],low[u]);
			}
			else if(0 == sccno[v])
				low[u]=min(low[u],dfn[v]);
		}
		if(low[u] == dfn[u])
		{
			scc_cnt++;
			while(1)
			{
				x=S.top();S.pop();
				sccno[x]=scc_cnt;
				if(u == x)	break;
			}
		}
	}
	void find_scc(){
		memset(dfn,0,sizeof(dfn));
		memset(sccno,0,sizeof(sccno));
		dfs_clock=scc_cnt=0;
		for(int i=1;i<=n;i++)
			if(0 == dfn[i])
				dfs(i);
	}
};



