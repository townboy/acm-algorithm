// Stoer-Wagner algorithm
int vis[N];
int gra[N][N],id[N],dis[N];

int Min_Cut(int n)
{
	int s,t,f;
	int ans=INF,i;
	for(i=0;i<n;i++)	id[i]=i;
	while(n > 1)
	{
		t=1;
		for(i=1;i<n;i++)
		{
			dis[id[i]]=gra[id[0]][id[i]];
			if(dis[id[i]] > dis[id[t]])
				t=i;
		}
		memset(vis,0,sizeof(vis));
		vis[id[0]]=1;
		for(i=0;i<n-2;i++)
		{
			vis[id[t]]=1;
			s=t;
			t=-1;
			for(f=1;f<n;f++)
			{
				if(1 == vis[id[f]])	continue;
				dis[id[f]]+=gra[id[s]][id[f]];
				if(-1 == t || dis[id[f]] > dis[id[t]])
					t=f;
			}
		}
		ans=min(ans,dis[id[t]]);
		for(i=0;i<n;i++)
		{
			gra[id[s]][id[i]]+=gra[id[t]][id[i]];
			gra[id[i]][id[s]]=gra[id[s]][id[i]];
		}
		id[t]=id[--n];
	}
	return ans;
}

//平面图最小割
/*将平面图转化成对偶图,每一个平面建成一个点,原图中的一条边建成连接相邻顶点的边.
对于源汇点在最外侧的情况下,从源汇点连边,将平面分成s*和t*,求s*到t*的最短路径即可.
证明根据对偶图中的任意一个环对应原图中的一个割集.
Dijkstra会比spfa在时间上优良很多.
*/
