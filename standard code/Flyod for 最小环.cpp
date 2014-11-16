
int n,map[110][110],ans;
int path[110][110];

void floyd()
{
	int k,i,f;
	for(k=1;k<=n;k++){
		for(i=1;i<k;i++)
			for(f=i+1;f<k;f++)
				ans=min(ans,path[k][i]+path[k][f]+map[i][f]);			
		for(i=1;i<=n;i++)
			for(f=1;f<=n;f++)
				map[i][f]=min(map[i][f],map[i][k]+map[k][f]);
	}
}
