******************************
    Author : townboy
    Submit time : 2014-05-18 23:02:01
    Judge Status : Accepted
    HDOJ Runid : 10765070
    Problem id : 3549
    Exe.time : 234MS
    Exe.memory : 320K
    https://github.com/townboy
******************************


#include <stdio.h>
#include <iostream>
#include <memory.h>

using namespace std;

#define maxn 100
#define maxe 10000

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
loop:    for(int &i = cur[u]; i != -1; i = E[i].next) {
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

int main() {
    int _, m;
    cin >> _;
    for(int i = 0 ;i < _; i++) {
        cin >> n >> m;
        int u, v, c;
        init();
        for(int f = 0 ;f < m;f ++) {
            cin >> u >> v >> c;
            add(u ,v, c);
        }
        cout << "Case " << i + 1 << ": " << sap(1, n) << endl;
    }
    return 0;
}
