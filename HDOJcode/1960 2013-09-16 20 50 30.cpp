******************************
    Author : townboy
    Submit time : 2013-09-16 20:50:30
    Judge Status : Accepted
    HDOJ Runid : 9182010
    Problem id : 1960
    Exe.time : 62MS
    Exe.memory : 768K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<memory.h>
#include<algorithm>
#include<vector>

using namespace std;

#define maxn 510

int n;
int st[maxn], pos[maxn][4];

void read() {
    int h ,m ;
    for(int i = 0 ;i < n; i++) {
        scanf("%d:%d",&h,&m);
        st[i] = h*60+m;
        for(int f = 0;f < 4; f++)
            scanf("%d",&pos[i][f]);
    }
}

vector<int>G[maxn];

void build() {
    for(int i = 0 ;i < n;i++) {
        G[i].clear();
        for(int f = i+1;f < n;f++) {
            if(st[f] < st[i])
                st[f] += 24*60;
            if(st[i] + abs(pos[i][2]-pos[i][0]) + abs(pos[i][3]-pos[i][1]) +abs(pos[f][0]-pos[i][2])+abs(pos[f][1]-pos[i][3]) < st[f])
                G[i].push_back(f);
        }
    }
}

int match[maxn];
bool mk[maxn];

bool find(int x) {
    int size = G[x].size();
    for(int i = 0;i < size;i++) {
        int v = G[x][i];
        if(true == mk[v])
            continue;
        mk[v] = true;
        if(-1 == match[v] || true == find(match[v])) {
            match[v] = x;
            return true;
        }
    }
    return false;
}

int solve() {
    int ret = 0;
    memset(match,-1,sizeof(match));
    for(int i = 0 ;i < n;i++) {
        memset(mk,false,sizeof(mk));
        if(true == find(i))
            ret ++;
    }
    return n - ret;
}

int main() {
    int cas;
    cin >> cas;
    for(int i = 0 ;i < cas; i++) {
        cin >> n;
        read();
        build();
        cout << solve() << endl;
    }
    return 0;
}
