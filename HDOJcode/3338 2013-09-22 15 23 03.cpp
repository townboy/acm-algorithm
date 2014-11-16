******************************
    Author : townboy
    Submit time : 2013-09-22 15:23:03
    Judge Status : Accepted
    HDOJ Runid : 9211156
    Problem id : 3338
    Exe.time : 171MS
    Exe.memory : 1004K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<memory.h>
#include<queue>
#include<vector>

using namespace std;

#define maxn 21000
#define maxe  2100000

int nn ,m;
bool white[110][110];
int col[110][110];
int row[110][110];
int id_col, id_row;
int flow_col[maxn];
int flow_row[maxn];

void read() {
    char ch[100], tem[100];
    memset(white,false,sizeof(white));
    memset(col,-1,sizeof(col));
    memset(row,-1,sizeof(row));
    id_col = id_row = 0;

    int tt;
    for(int i = 0 ;i < nn;i++) {
        for(int f = 0; f < m;f++) {
            scanf("%s",ch);
            if(0 == strcmp("XXXXXXX",ch))
                continue;
            if(0 == strcmp(".......",ch)) {
                white[i][f] = true;
                continue;
            }
            if(ch[0] != 'X') {
                col[i][f] = ++ id_col;
                sscanf(ch,"%d\\%s",&tt,tem);
                flow_col[id_col] = tt;
            }
            if(ch[4] != 'X') {
                row[i][f] = ++ id_row;
                sscanf(ch,"%3s\\%d",tem,&tt);
                flow_row[id_row] = tt;
            }
        }
    }
}

int gap[maxn],dis[maxn],pre[maxn],cur[maxn];
int size ,n ,head[maxn];

struct Node {
    int c,v,next;
    Node() {}
    Node(int _v,int _c,int _next):v(_v),c(_c),next(_next) {}
}E[maxe];

int sap(int s,int t) {
    memset(dis,0,sizeof(dis));
    memset(gap,0,sizeof(gap));
    for(int i = 1;i <= n;i++)
        cur[i] = head[i];
    int u = pre[s] = s , maxflow = 0 , aug = -1;
    gap[0] = n;
    while(dis[s] < n) {
loop:    for(int & i = cur[u]; i != -1;i = E[i].next) {
            int v = E[i].v;
            if(E[i].c && dis[u] == dis[v]+1) {
                if(aug == -1 | aug > E[i].c)    aug = E[i].c;
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
        for(int i = head[u];i != -1;i = E[i].next) {
            int v = E[i].v;
            if(E[i].c && mindis > dis[v]) {
                cur[u] = i;
                mindis = dis[v];
            }
        }
        if(--gap[dis[u]] == 0)
            break;
        gap[dis[u] = mindis+1] ++;
        u = pre[u];
    }
    return maxflow;
}

void init() {
    memset(head,-1,sizeof(head));
    size = 0;
}

void add(int u ,int v ,int c,int cc = 0) {
    //cout << u << " " << v << " " << c << endl;
    E[size] = Node(v,c,head[u]);
    head[u] = size ++;
    E[size] = Node(u,cc,head[v]);
    head[v] = size ++;
}

int getcol(int x,int y) {
    while(-1 == col[x][y])
        x --;
    flow_col[col[x][y]] --;
    return col[x][y];
}

int getrow(int x,int y) {
    while(-1 == row[x][y]) 
        y --;
    flow_row[row[x][y]] --;
    return row[x][y];
}

int pos[110][110];

void ans() {
    for(int i = 0 ;i < nn;i++) {
        for(int f = 0;f < m;f++) {
            if(0 != f)
                cout << " ";
            if(true == white[i][f])
                cout << 9-E[pos[i][f]].c;
            else
                cout << "_";
        }
        cout << endl;
    }
}

void solve() {
    n = id_col + id_row + 2;
    int s = n - 1, t = n;
    init();
    for(int i = 0 ; i < nn ;i++)
        for(int f = 0 ; f < m;f++)
            if(true == white[i][f]) {
                pos[i][f] = size;
                add(getcol(i,f),getrow(i,f) + id_col,8);
            }
    for(int i = 1;i <= id_col ;i++)
        add(s,i,flow_col[i]);
    for(int i = 1;i <= id_row; i++)
        add(id_col+i, t, flow_row[i]);
    sap(s,t);
    ans();
}

void debug() {
    for(int i = 0; i < nn;i++) {
        for(int f = 0 ;f < m;f++)
            cout << white[i][f] << " ";
        cout << endl;
    }
}
int main() {
    while(cin >> nn >> m) {
        read();
        solve();
    }
    return 0;
}
