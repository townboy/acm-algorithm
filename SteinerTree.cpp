// 证明 一个最小连通状态是一棵树 可以由最短树链和同根子树的合并 更新而来



#include<stdio.h>
#include<memory.h>
#include<vector>
#include<queue>
#include<math.h>
#define INF 10000000
using namespace std;

int dis[210][10],flag[210],hash[210][10];
int M,n,k;			// M 全连通状态  k 需连通点数  
					// 顶点为 1-n 
struct edge
{
	int v;
	int len;
};
struct edge edge_ru;

vector<edge>q[210];

struct node 
{
	int id;
	int sta;
};
struct node ru,tem;

void chu()
{
	int i,f;
	memset(hash,0,sizeof(hash));
	memset(flag,0,sizeof(flag));
	for(i=1;i<=n;i++)
	{
		for(f=0;f<=M;f++)
		{
			dis[i][f]=INF;
		}
		q[i].clear();
	}
}

void add(int u,int v,int len) 
{
	edge_ru.len=len;
	edge_ru.v=v;
	q[u].push_back(edge_ru);
	edge_ru.v=u;
	q[v].push_back(edge_ru);	
}

void flag_init()				// 初始化 flag 标记数组 
{
	int i,id;
	M=(1<<k)-1;
	for(i=0;i<k;i++)
	{
		scanf("%d",&id);
		flag[id]=(1<<i);
	} 
}

void steiner()
{
	int i,id,sta,newsta,st,mask,size,v,len;
	queue<node>que;
	
	for(i=1;i<=n;i++)
	{
		if(0 != flag[i])
		{
			ru.sta=flag[i];
			ru.id=i;
			hash[i][flag[i]]=1;
			dis[i][flag[i]]=0;
			que.push(ru);
		}
	}
	
	while(!que.empty())
	{
		tem=que.front();
		que.pop();
		id=tem.id;
		sta=tem.sta;
		hash[id][sta]=0;
		
		st=M^sta;					//更新子树合并 
		for(mask=st;mask;mask=st&(mask-1))
		{
			newsta=mask;
			if(0 != flag[id])
			{
				newsta=mask|flag[id];	
			}
			if(dis[id][sta|newsta] > dis[id][sta]+dis[id][newsta])
			{
				dis[id][sta|newsta]=dis[id][sta]+dis[id][newsta];	
				if(0 == hash[id][sta|newsta])
				{
					hash[id][sta|newsta]=1;
					ru.id=id;
					ru.sta=newsta|sta;
					que.push(ru);
				}
			}
		}
		
		size=q[id].size();
		for(i=0;i<size;i++)			// 更新树链 
		{
			v=q[id][i].v;
			len=q[id][i].len;
			newsta=sta;
			if(0 != flag[v])
			{	
				newsta=sta|flag[v];
			}
			if(dis[v][newsta] > dis[id][sta]+len)
			{
				dis[v][newsta]=dis[id][sta]+len;
				if(0 == hash[v][newsta])
				{
					hash[v][newsta]=1;
					ru.id=v;
					ru.sta=newsta;
					que.push(ru);
				}
			}
		}
	}	
}

