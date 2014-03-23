// 类似二分匹配写法 


#include<stdio.h>
#include<memory.h>
#define maxn 310

int xlike[maxn][maxn],ylike[maxn][maxn];
int xrank[maxn][maxn],yrank[maxn][maxn];
int xmat[maxn],ymat[maxn],n;

void find(int x,int y)
{
	int tx;
	if(-1 == ymat[y])
	{
		xmat[x]=y;
		ymat[y]=x;
		return ;
	}
	tx=ymat[y];
	if(yrank[y][x] < yrank[y][tx])
	{
		xmat[x]=y;
		ymat[y]=x;
		find(tx,xlike[tx][xrank[tx][y]+1]);
	}
	else
	{
		find(x,xlike[x][xrank[x][y]+1]);
	}
}

void stable_match()
{
	int i;
	memset(xmat,-1,sizeof(xmat));
	memset(ymat,-1,sizeof(ymat));
	for(i=1;i<=n;i++)
	{
		find(i,xlike[i][1]);
	}
}


// 队列写法 

struct node 
{
	int x;
	int y;
};
struct node tem;
queue<node>que;

void find(int x,int y)
{
	int tx;
	if(-1 == ymat[y])
	{
		xmat[x]=y;
		ymat[y]=x;
		return ;
	}
	tx=ymat[y];
	if(yrank[y][x] < yrank[y][tx])
	{
		xmat[x]=y;
		ymat[y]=x;
		tem.x=tx;
		tem.y=xlike[tx][xrank[tx][y]+1];
		que.push(tem);
	}
	else
	{
		tem.x=x;
		tem.y=xlike[x][xrank[x][y]+1];
		que.push(tem);
	}
}

void stable_match()
{
	int i;
	memset(xmat,-1,sizeof(xmat));
	memset(ymat,-1,sizeof(ymat));
	for(i=1;i<=n;i++)
	{
		tem.x=i;
		tem.y=xlike[i][1];
		que.push(tem);
	}
	while(!que.empty())
	{
		tem=que.front();
		que.pop();
		find(tem.x,tem.y);
	}
}

