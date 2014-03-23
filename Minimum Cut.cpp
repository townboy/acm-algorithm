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

//ƽ��ͼ��С��
/*��ƽ��ͼת���ɶ�żͼ,ÿһ��ƽ�潨��һ����,ԭͼ�е�һ���߽����������ڶ���ı�.
����Դ����������������,��Դ�������,��ƽ��ֳ�s*��t*,��s*��t*�����·������.
֤�����ݶ�żͼ�е�����һ������Ӧԭͼ�е�һ���.
Dijkstra���spfa��ʱ���������ܶ�.
*/
