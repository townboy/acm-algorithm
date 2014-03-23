//次小生成树
// lemma：次小生成树 必定可以由最小生成树中的一条边替换原有生成树中的一条边的得到。所以枚举新加入（u，v），替换掉生成树上u到v路径上最长边。

//做法：prim中顺便求出maxlen[][]数组。

struct Prim
{
	int n,ans,maxlen[maxn][maxn];
	int G[maxn][maxn],use[maxn][maxn];
	void init(int _n){
		n=_n;
		memset(use,0,sizeof(use));
		memset(G,0x3f,sizeof(G));
	}
	void add(int u,int v,int len){
		G[u][v]=len;
		G[v][u]=len;
	}
	void solve(){
		int i,f;
		int dist[maxn],id,hash[maxn],pre[maxn];
		memset(dist,0x3f,sizeof(dist));
		memset(maxlen,0,sizeof(maxlen));
		memset(hash,0,sizeof(hash));
		ans=0;
		dist[1]=0;
		pre[1]=0;
		for(i=0;i<n;i++)
		{
			id=-1;
			for(f=1;f<=n;f++)
			{
				if(1 == hash[f])	continue;
				if(-1==id || dist[f]<dist[id])
					id=f;
			}
			use[pre[id]][id]=use[id][pre[id]]=1;
			ans+=dist[id];
			for(f=1;f<=n;f++)
			{
				if(G[id][f] >= dist[f])	continue;
				dist[f]=G[id][f];
				pre[f]=id;
			}
			for(f=1;f<=n;f++)
			{
				if(0 == hash[f])	continue;
				maxlen[id][f]=max(maxlen[f][pre[id]],G[id][pre[id]]);
				maxlen[f][id]=maxlen[id][f];
			}
			hash[id]=1;
		}
	}
	int unique(){
		int i,f;
		for(i=1;i<=n;i++)
			for(f=1;f<=n;f++)
			{
				if(INF==G[i][f] || 1==use[i][f])	continue;
				if(maxlen[i][f] == G[i][f])
					return -1;
			}
		return ans;
	}
};


/*
最优比例生成树
设x[i]等于1或0, 表示边e[i]是否属于生成树.
则我们所求的比率 r = ∑(benifit[i] * x[i]) / ∑(cost[i] * x[i]), 0≤i<m.
为了使 r 最大, 设计一个子问题---> 让 z = ∑(benifit[i] * x[i]) - l * ∑(cost[i] * x[i]) = ∑(d[i] * x[i])最大 (d[i] = benifit[i] - l * cost[i]) , 并记为z(l). 我们可以兴高采烈地把z(l)看做以d为边权的最大生成树的总权值.
然后明确两个性质:
　1.  z单调递减
　　证明: 因为cost为正数, 所以z随l的减小而增大.
　2.  z( max(r) ) = 0
　　证明: 若z( max(r) ) < 0, ∑(benifit[i] * x[i]) - max(r) * ∑(cost[i] * x[i]) < 0, 可化为 max(r) < max(r). 矛盾;
　　        若z( max(r) ) >= 0, 根据性质1, 当z = 0 时r最大. 
到了这个地步, 七窍全已打通, 喜欢二分的上二分, 喜欢Dinkelbach的就Dinkelbach.
*/

struct MST
{
	int n,hash[maxn];
	double len[maxn][maxn],d[maxn][maxn],dist[maxn];
	void init(int _n){
		n=_n;
	}
	void c_init(double l){
		int i,f;
		memset(hash,0,sizeof(hash));
		for(i=1;i<=n;i++)
		{
			dist[i]=100000000;
			for(f=1;f<=n;f++)
				d[i][f]=cost[i][f]-l*len[i][f];
		}
	}
	double check(double l){
		double ans=0;
		int i,f,id;
		c_init(l);
		dist[1]=0;
		for(i=0;i<n;i++)
		{	
			id=-1;
			for(f=1;f<=n;f++)
			{
				if(1 == hash[f])	continue;
				if(-1==id || dist[f]<dist[id])
					id=f;
			}
			ans+=dist[id];
			for(f=1;f<=n;f++)
				dist[f]=min(dist[f],d[id][f]);
			hash[id]=1;
		}
		return ans;
	}
	double bsearch(){
		double mid,l=0,r=1000000;
		while(r-l > 1e-5)
		{
			mid=(l+r)/2;
			if(check(mid) > 0)	l=mid;
			else	r=mid;
		}
		return mid;
	}
};


