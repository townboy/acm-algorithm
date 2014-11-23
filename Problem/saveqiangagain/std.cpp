#include <stdio.h>
#include <iostream>
#include <memory.h>
#include <queue>
#include <algorithm>

using namespace std;

#define maxn 19000
#define maxe 1000000
char map[20][20];

int turn(int tt, int x,int y, int kind) {
	return tt * 450 + kind * 225 + 15 * x + y + 1;
}

int sx, sy, ex, ey;

void read() {
	for(int i = 0 ;i < 15; i++)
		scanf("%s", map[i]);
	for(int i = 0 ;i < 15;i ++)
		for(int f = 0 ;f < 15; f++)
			if('S' == map[i][f])
				sx = i, sy = f;
			else if('T' == map[i][f])
				ex = i, ey = f;
}

int gap[maxn],dis[maxn],pre[maxn],cur[maxn];
int size,n,head[maxn];

struct Node{
	int c,v,next;
	Node(){}
	Node(int _v,int _c,int _next):v(_v),c(_c),next(_next){}
}E[maxe];

int sap(int s,int t) {
	memset(dis,0,sizeof(dis));
	memset(gap,0,sizeof(gap));
	for(int i=1;i<=n;i++)	cur[i] = head[i];
	int u = pre[s] = s,maxflow = 0,aug = -1;
	gap[0] = n;
	while(dis[s] < n) {
loop:		for(int &i = cur[u]; i != -1; i = E[i].next) {
			int v = E[i].v;
			if(E[i].c && dis[u] == dis[v] + 1) {
				if(aug==-1 || aug>E[i].c)	aug=E[i].c;
				pre[v] = u;
				u = v;
				if(v == t) {
					maxflow += aug;
					for(u = pre[u];v != s;v = u,u = pre[u]) {
						E[cur[u]].c -= aug;
						E[cur[u]^1].c += aug;
					}
					aug = -1;
				}
				goto loop;
			}
		}
		int mindis = n;
		for(int i = head[u]; i != -1 ; i = E[i].next) {
			int v = E[i].v;
			if(E[i].c && mindis > dis[v]) {
				cur[u] = i;
				mindis = dis[v];
			}
		}
		if( (--gap[dis[u]]) == 0)	break;
		gap[ dis[u] = mindis+1 ] ++;
		u = pre[u];
	}
	return maxflow;
}

void add(int u,int v,int c,int cc = 0) {
	E[size] = Node(v,c,head[u]);
	head[u] = size++;
	E[size] = Node(u,cc,head[v]);
	head[v] = size++;
}

void init() {
	memset(head,-1,sizeof(head));
	size=0;
}

int dir[8][2] = {0, 1, 0, -1, 1, 0, -1, 0, 1, 1, 1 ,-1, -1, 1, -1, -1};

bool valid(int x) {
	if(x < 0 || x > 14)
		return false;
	return true;
}

#define tt 40

int fun() {
	init();
	n = 450 * 41 + 1;
	int s = turn(0, sx, sy, 1);
	int t = n;

	for(int i = 0 ;i <= tt; i++)
		for(int f = 0 ;f < 15;f++)
			for(int g = 0;g < 15;g ++)
				if('#' != map[f][g])
					add(turn(i, f, g, 0) ,turn(i ,f ,g, 1), 1);
	for(int i = 0; i < tt;i ++)
		for(int f = 0 ;f < 15; f++)
			for(int g = 0;g < 15; g++)
				for(int h = 0; h < 8; h++) {
					int tox = f + dir[h][0];
					int toy = g + dir[h][1];
					if(false == valid(tox) || false == valid(toy))
						continue;
					add(turn(i ,f ,g, 1) ,turn(i + 1, tox, toy ,0), 1);
				}
	
	for(int i = 0 ;i <= tt;i ++)
		add(turn(i, ex, ey, 1), t, 1);
	return sap(s, t);
}

void debug() {
	for(int i = 0 ;i < 15;i ++)
		puts(map[i]);
	cout << "end" << endl;
}

int main() {
	freopen("in", "r", stdin); 
	freopen("out", "w", stdout);
	int a, b;
	while(scanf("%d%d", &a ,&b) != EOF) {
		read();
		cout << fun() << endl;
	}
	return 0;
}
