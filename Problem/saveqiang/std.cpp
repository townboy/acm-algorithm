#include <stdio.h>
#include <iostream>
#include <memory.h>
#include <queue>
#include <math.h>
#include <algorithm>

using namespace std;

#define maxn 110

struct MaxMatch {
	int mat[maxn],pre[maxn];
	int block[maxn];
	bool map[maxn][maxn],hash[maxn],in[maxn];
	int n; 
	queue<int>q; 
	void init(int _n) { 
		n = _n; 
		memset(map,false,sizeof(map)); 
		memset(mat,-1,sizeof(mat)); 
	}
	void add(int u,int v){ 
		map[u][v] = map[v][u] = true; 
	}
	void modify(int u,int lca){ 
		int v; 
		while(block[u] != lca)
		{ 
			v = mat[u]; 
			hash[ block[u] ] = hash[ block[v] ] = true; 
			u = pre[v]; 
			if(block[u] != lca) 
				pre[u] = v; 
		} 
	}
	void contract(int u,int v,int start) { 
		int lca,i; 
		memset(hash,false,sizeof(hash)); 
		for(lca = u;;lca = pre[ mat[lca] ])
		{ 
			lca = block[lca];
			hash[lca] = true; 
			if(lca == start) break; 
		} 
		for(lca = v;;lca = pre[ mat[lca] ])
		{ 
			lca = block[lca]; 
			if(hash[lca] == true) break; 
		}
		memset(hash,false,sizeof(hash)); 
		modify(u,lca); 
		modify(v,lca); 
		if(block[u] != lca) pre[u] = v; 
		if(block[v] != lca) pre[v] = u; 
		for(i = 1;i <= n;i ++)
		{ 
			if(true == hash[ block[i] ])
			{ 
				block[i] = lca; 
				if(!in[i])
				{ 
					in[i] = true; 
					q.push(i); 
				}
			}
		}
	}

	void find(int start)
	{
		int now,temp,i;
		memset(in,false,sizeof(in));
		memset(pre,-1,sizeof(pre));
		for(i = 1;i <= n ;i ++)	block[i] = i; 
		while(!q.empty()) q.pop(); 
		q.push(start); 
		in[start] = true; 
		while(!q.empty())
		{ 
			now = q.front(),q.pop(); 
			for(i = 1;i <= n;i ++)
			{ 
				if(map[now][i] == false) continue; 
				if(block[now] == block[i]) continue; 
				if(mat[now] == i) continue; 
				if(i == start || (mat[i] != -1 && pre[mat[i]] != -1))
					contract(now,i,start); 
				else if(pre[i] == -1)
				{ 
					pre[i] = now; 
					if(mat[i] == -1) 
					{ 
						while(i != -1) 
						{ 
							now = pre[i]; 
							temp = mat[now]; 
							mat[now] = i; 
							mat[i] = now; 
							i = temp; 
						} 
						return; 
					} 
					in[ mat[i] ] = true; 
					q.push(mat[i]); 
				} 
			} 
		} 
	}
	int solve() { 
		int i,cnt = 0; 
		for(i=1;i<=n;i++) 
			if(-1 == mat[i]) 
				find(i);
		for(i=1;i<=n;i++) 
			if(-1 != mat[i])
				cnt ++; 
		return cnt; 
	} 
};

MaxMatch townboy;

int pos[maxn][2];
double dis[maxn][maxn];
int n ,m;

vector<double> val;

void debug() {
	int size = val.size();
	for(int i = 0 ;i < size;i++)
		printf("%lf ", val[i]);
	puts("");
}

double cal() {
	val.clear();
	for(int i = 1 ;i <= n;i ++)
		for(int f = i+1; f <= n; f++) {
			dis[i][f] = sqrt((pos[i][0] - pos[f][0]) * (pos[i][0] - pos[f][0]) + (pos[i][1] - pos[f][1]) * (pos[i][1] - pos[f][1]));
			val.push_back(dis[i][f]);
		}
	sort(val.begin(), val.end());

	int l = -1 ,r = val.size() - 1;
	while(l < r - 1) {
		int mid = (l + r) / 2;
		townboy.init(n);
		for(int i = 1 ;i <= n ;i++)
			for(int f = i+1;f <= n;f++)
				if(dis[i][f] < val[mid] + 0.00001)
					townboy.add(i, f);
		int ans = townboy.solve() / 2;
		if(ans >= m)
			r = mid;
		else
			l = mid;
	}
	return val[r];
}

int main() {
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
	while(cin >> n >> m) {
		for(int i = 1;i <= n; i++)
			scanf("%d%d",&pos[i][0] ,&pos[i][1]);
		printf("%.9lf\n", cal());
	}
	return 0;
}
