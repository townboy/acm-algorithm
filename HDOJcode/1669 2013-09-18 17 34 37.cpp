******************************
    Author : townboy
    Submit time : 2013-09-18 17:34:37
    Judge Status : Accepted
    HDOJ Runid : 9191863
    Problem id : 1669
    Exe.time : 546MS
    Exe.memory : 8320K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<memory.h>
#include<vector>

using namespace std;

int nn ,m;
vector<int> G[1100];

#define maxn 2000
#define maxe 2000000

void read() {
    char ch[20], t;
    for(int i = 0 ;i < nn;i++) {
        scanf("%s",ch);
        t = getchar();
        G[i].clear();
        while(t != '\n') {
            int v;
            cin >> v;
            G[i].push_back(v);
            t = getchar();
        }
    }
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

bool check(int mid) {
    init();
    n = nn + m + 2;
    int s = n-1, t = n;
    for(int i = 0 ;i < nn; i++) {
        int size = G[i].size();
        for(int f = 0 ;f < size;f ++)
            add(i+1,nn+G[i][f]+1,1);
    }
    for(int i = 1;i <= nn;i++)
        add(s,i,1);
    for(int i = nn+1;i <= nn+m ;i++)
        add(i,t,mid);
    if(nn == sap(s,t))
        return true;
    return false;
}

int solve() {
    int l = 0, r = nn;
    while(l != r-1) {
        int mid = (l+r)>>1;
        if(true == check(mid))
            r = mid;
        else
            l = mid;
    }
    return r;
}

int main() {
    while(cin >> nn >> m, nn + m) {
        read();
        cout << solve() << endl;
    }
    return 0;
}
