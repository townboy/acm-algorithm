//以下是对于定根的情况，对于不定根的情况，在超级根向所有可做根的节点加上一条边权//极大的边，在最后的结果中减去即可。

struct edge {
	int u,v;
	int val;
};
struct edge e[M];

int pre[N],vis[N],id[N];
int val[N];
int dmst(int r,int n,int m) {
	int u, v, res=0, cnt, k, tv;
	while(true) {
		memset(id,-1,sizeof(id));
		memset(vis,-1,sizeof(vis));
		for(int i=1;i<=n;i++) 
			val[i]=INF;

		val[r]=0;
		for(int i=0;i<m;i++) {
			u=e[i].u;
			v=e[i].v;
			if(u == v) 
				continue;
			if(val[v] > e[i].val) {
				val[v] = e[i].val;
				pre[v] = u;
			}
		}
		for(int i=1;i<=n;i++)
			if(INF == val[i]) 
				return -1;

		cnt = 0;
		int f;
		for(int i=1; i <= n; i++) {
			res += val[i];
			for(f=i ; f!=r ; f=pre[f]) {
				if(vis[f]==i || -1!=id[f]) 
					break;
				vis[f]=i;
			}
			if(f != r && -1 == id[f]) {
				cnt ++;
				id[f]=cnt;
				for(k = pre[f]; k != f ;k = pre[k])
					id[k] = cnt;
			}
		}
		if(0 == cnt)
			break;

		for(int i=1;i<=n;i++) {
			if(-1 == id[i])  {
				cnt++;
				id[i]=cnt;
			}
		}

		for(int i=0;i<m;i++) {
			tv=e[i].v;
			e[i].u=id[e[i].u];
			e[i].v=id[e[i].v];
			if(e[i].u != e[i].v)
				e[i].val-=val[tv];
		}
		n = cnt;
		r = id[r];
	}
	return res;
}
