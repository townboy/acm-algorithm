//图的最大独立集等于补图的最大团
int map[55][55],vis[55],dp[55];
int tmax,n;

void dfs(int id,int cnt) {
	int tvis[55],able=0;
	for(int i = id+1; i<=n ;i++)
		if(1 == vis[i])
			able++;	

	if(0 == able) {
		if(cnt > tmax)
			tmax = cnt;
		return ;		
	}
	if(able + cnt <= tmax)
		return ;

	for(int i = 1;i <= n; i++)
		tvis[i]=vis[i];	

	for(int i = id+1; i <= n; i++) {
		if(0 == tvis[i])
			continue;
		if(cnt + dp[i] <= tmax)
			continue;

		for(int f=i+1;f<=n;f++)
			vis[f]=tvis[f]&map[i][f];
		dfs(i,cnt+1);		
	}
}

int max_clique() {
	tmax=1;
	dp[n]=1;
	for(int i = n-1; i>=1; i--) {
		for(int f=1;f<=n;f++)
			vis[f]=map[i][f];
		dfs(i,1);
		dp[i]=tmax;
		if(n == tmax)
			return tmax;
	}
	return tmax;
}
