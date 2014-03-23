/*LCA 爬坡法
预处理出每个节点的深度和父节点，然后u和v中较深的一个点先爬到和另外一点同一深度，然后从两个点开始同时往上爬。
*/

// LCA tarjan离线	

vector<int>G[maxn];
vector<pair<int,int> >Q[maxn];		// first 是 询问的序号 second是另外一个点
int set[maxn],ancestor[maxn];
int ans[maxn];
bool vis[maxn];

void INIT() {
    for(int i = 1;i <= n;i++) {
        set[i]=i;
        G[i].clear();
        Q[i].clear();    
    }
    memset(vis,false,sizeof(vis));
}

int find(int x) {
    return x==set[x]?x:set[x]=find(set[x]);
}

void merge(int a,int b) {
    set[a] = b;
}

void lca(int x,int fa) {
    ancestor[x] = x;
    int size = G[x].size();

    for(int i = 0;i < size; i++) {
        int v = G[x][i];
        if(v == fa)
            continue;
        lca(v,x);
        merge(find(v),find(x));
        ancestor[find(x)] = x;
    }
    vis[x] = true;
    size = Q[x].size();
    for(int i = 0;i < size;i++) {
        int id = Q[x][i].first;
        int v = Q[x][i].second;
        if(true == vis[v])
            ans[id] = ancestor[find(v)];
    }
}

//倍增lca

struct LCA {
	int ancestors[10010][20];
	int depth[10010], dis[10010];
	int n;
	vector<int> G[10010] , Dis[10010];  

	int find(int u, int v) {  
		if (depth[u] < depth[v])
			swap(u, v);
		for (int i = 19; i >= 0 ; i--) {  
			if (depth[ancestors[u][i]] >= depth[v] ) {  
				u = ancestors[u][i];  
				if (depth[u] == depth[v])
				  break;	
			}
		}
		if (u == v)
			return u;

		for (int i = 19; i >= 0 ; i--) {
			if (ancestors[u][i] != ancestors[v][i]) {
				u = ancestors[u][i];   
				v = ancestors[v][i];  
			}
		}
		return ancestors[u][0];  
	}

	void dfs(int rt, int fa) {
		int size = G[rt].size();
		for (int i = 0 ; i < size; i++) {
			int son = G[rt][i];
			if(son == fa)
				continue;
			depth[son] = depth[rt] + 1;
			dis[son] = dis[rt] + Dis[rt][i];
			ancestors[son][0] = rt;
			dfs(son, rt);
		}
	}

	void init() {
		depth[1] = 0;
		dis[1] = 0;
		ancestors[1][0] = 1;
		dfs(1 ,-1);
		for (int i = 1; i < 20 ; i++)
			for (int f = 1 ; f <= n ; f++)
				ancestors[f][i] = ancestors[ancestors[f][i - 1]][i - 1];  
	}

	void chu(int _n) {
		n = _n;
		for(int i = 1;i <= n;i++) {
			G[i].clear();
			Dis[i].clear();
		}
	}

	void add_edge(int u,int v,int dis = 1) {
		G[u].push_back(v);
		Dis[u].push_back(dis);
		G[v].push_back(u);
		Dis[v].push_back(dis);
	}
};


