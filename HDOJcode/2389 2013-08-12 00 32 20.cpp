******************************
    Author : townboy
    Submit time : 2013-08-12 00:32:20
    Judge Status : Accepted
    HDOJ Runid : 8910237
    Problem id : 2389
    Exe.time : 1390MS
    Exe.memory : 141636K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<memory.h>
#include<algorithm>
#include<vector>

using namespace std;
#define INF 0x3f3f3f3f
#define maxn 6500
#define maxe 20000000

int guest[3100][3];
int umb[3100][2];
int tt ,nn ,mm;

void read() {
    cin >> tt;
    cin >> nn;
    for(int i = 0 ;i < nn;i++)
        for(int f = 0 ;f < 3;f++)
            scanf("%d",&guest[i][f]);
    cin >> mm;
    for(int i = 0 ;i < mm;i++)
        for(int f = 0 ;f < 2;f++)
            scanf("%d",&umb[i][f]);
}

int gap[maxn],dis[maxn],pre[maxn],cur[maxn];
int size,n,head[maxn];

struct Node{
    int next;
    short c,v;
    Node(){}
    Node(int _v,int _c,int _next):v(_v),c(_c),next(_next){}
}E[maxe];

int sap(int s,int t) {
    memset(dis,0,sizeof(dis));
    memset(gap,0,sizeof(gap));
    for(int i=1;i<=n;i++)    cur[i] = head[i];
    int u = pre[s] = s,maxflow = 0,aug = -1;
    gap[0] = n;
    while(dis[s] < n) {
loop:        for(int &i = cur[u]; i != -1; i = E[i].next) {
            int v = E[i].v;
            if(E[i].c && dis[u] == dis[v] + 1) {
                if(aug==-1 || aug>E[i].c)    aug=E[i].c;
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
        if( (--gap[dis[u]]) == 0)    break;
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
void init(){
    memset(head,-1,sizeof(head));
    size=0;
}

int solve() {
    n = nn+mm+2;
    int s = n-1;
    int t = n;
    init();
    for(int i = 0 ;i < nn;i++) {
        for(int f = 0;f < mm;f++) {
            int dis = (guest[i][0] - umb[f][0])*(guest[i][0] - umb[f][0]) + (guest[i][1] - umb[f][1])*(guest[i][1] - umb[f][1]);
            if(tt * tt * guest[i][2] * guest[i][2] >= dis)
                add(1+i,nn+1+f,1);
        }
    }
    for(int i = 1;i <= nn;i++)
        add(s,i,1);
    for(int i = nn+1;i <= nn+mm;i++)
        add(i,t,1);
    return sap(s,t);
}

int main() {
    int cas;
    cin >> cas;
    for(int i = 0 ;i < cas;i++) {
        read();
        printf("Scenario #%d:\n",i+1);
        cout << solve() << endl << endl;
    }
    return 0;
}
