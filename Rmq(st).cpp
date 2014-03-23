int dp[10000][30],n;

void st()
{
	int k,m,i,f;
	k=(int)(log((double)n)/log(2.0));
	for(f=1;f<=k;f++)
	{
		for(i=1;i+(1<<j)-1 <= n;i++)
		{
			m=i+(1<<(j-1));
			dp[i][f]=maxx(dp[i][f-1],dp[m][f-1]);		
		}
	}
}

int rmq(int a,int b)
{
	int k=(int)(log((double)(b-a+1))/log(2.0));
	return maxx(dp[a][k],dp[b-(1<<k)+1][k];
}
