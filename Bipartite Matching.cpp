// 二分图的几个常用模型
// 最小顶点覆盖  等于最大匹配数
// DAG上的最小路径覆盖 等于顶点个数减去最大匹配数
// 最大独立集 等于 顶点个数减去最大匹配数


//Hungarian algorithm
int map[maxn][maxn],match[maxn],mk[maxn];
int a,b;

int dfs(int x){
　　for(int i=0;i<b;i++){
　　 	if((1 == map[x][i]) && (0 == mk[i])){ 
			mk[i]=1;
　　		int t = match[i];
　　		match[i]=x;
　　		if((-1 == t) || (1 == dfs(t)))
		　　	return 1;
　　		match[i]=t; 
　　	}
　　}
　　return 0;
}

int xyl(){
	int ans=0;
　　for(int i=0;i<a;i++){
		memset(mk,0,sizeof(mk));
		if(1 == dfs(i))
			ans++;
　　}
　　return ans;
}

void init(){
 	memset(map,0,sizeof(map));
	for(int i=0;i<b;i++)
　　	match[i]=-1;
}

//hopcroft-karp算法
vector<int>G[3100];
int cx[3100],cy[3100],disx[3100],disy[3100];
int n, m;

// X部从0-n-1 , Y部从0-m-1

bool bfs() {
	bool flag = false;
	queue<int> q;
    memset(disx,0,sizeof(disx));
    memset(disy,0,sizeof(disy));
    for(int i = 0;i < nn; i++)
		if (-1 == cx[i])
			q.push(i);

    while ( !q.empty() ) {
        int i = q.front();
		q.pop();
		int size = G[i].size();
	    for(int f = 0 ;f < size; f++) {
			int v = G[i][f];
			if(0 == disy[v]) {
                disy[v] = disx[i] + 1;
               	if (-1 != cy[v]) {
                    disx[cy[v]] = disy[v] + 1;
					q.push(cy[v]);
				} 
		        else
					flag = true;
			}
		}
    }
    return flag;
}

int dfs(int x) {
	int size = G[x].size();
    for(int i = 0;i < size; i++) {
		int v = G[x][i];
		if (disy[v] == disx[x]+1) {
	        disy[v]=0;
		    if (-1 == cy[v] || 1 == dfs(cy[v]) ) {
				cy[v] = x;
				cx[x] = v;
			    return true;
			}
		}
	}
    return false;
}

int hopcroft_karp() { 
	int ans = 0 ,i;
	memset(cx,-1,sizeof(cx));
	memset(cy,-1,sizeof(cy));
    while(true == bfs())
        for(i = 0;i < nn;i++)
			if(-1 == cx[i] && true == dfs(i))
				ans++;
	return ans;
}

//KM二分图带权匹配 O(v^3)
#include<stdio.h>
#include<iostream>
#include<memory.h>
#define maxn 305
#define INF 0x7fffffff
using namespace std;

int W[maxn][maxn],S[maxn],T[maxn];
int lx[maxn],ly[maxn];
int mat[maxn],n,slack[maxn];

int match(int u)
{
	int i,diff;
	S[u]=1;
	for(i=1;i<=n;i++)
	{
		if(1 == T[i])	continue;
		diff=lx[u]+ly[i]-W[u][i];
		if(0 == diff)
		{
			T[i]=1;
			if(0 == mat[i] || 1 == match(mat[i]))
			{
				mat[i]=u;
				return 1;
			}
		}
		else
			slack[i]=min(slack[i],diff);
	}
	return 0;
}

void update()
{
	int i,tem=INF;
	for(i=1;i<=n;i++)
		if(0 == T[i])
			tem=min(tem,slack[i]);
	for(i=1;i<=n;i++)
	{
		if(1 == S[i])	lx[i]-=tem;
		if(1 == T[i])	ly[i]+=tem;
		else	slack[i]-=tem;
	}
}

int KM()
{
	int i,f,ans=0;
	for(i=1;i<=n;i++)	lx[i]=-INF;
	memset(ly,0,sizeof(ly));
	memset(mat,0,sizeof(mat));
	for(i=1;i<=n;i++)
		for(f=1;f<=n;f++)
			lx[i]=max(lx[i],W[i][f]);
	for(i=1;i<=n;i++)
	{
		memset(slack,0x3f,sizeof(slack));
		while(1)
		{
			memset(S,0,sizeof(S));
			memset(T,0,sizeof(T));
			if(1 == match(i))	break;
			update();
		}
	}
	for(i=1;i<=n;i++)
		ans+=lx[i]+ly[i];
	return ans;
}


