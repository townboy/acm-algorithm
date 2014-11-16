******************************
    Author : townboy
    Submit time : 2013-09-08 20:18:02
    Judge Status : Accepted
    HDOJ Runid : 9132470
    Problem id : 4714
    Exe.time : 2921MS
    Exe.memory : 62600K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<memory.h>
#include<vector>

using namespace std;
#pragma comment(linker, "/STACK:102400000,102400000")

vector<int>G[1000100];
int n;
int ru[1100000];

int cut;

int dfs(int rt,int fa) {
    int size = G[rt].size();
    for(int i = 0;i < size;i++) {
        int v = G[rt][i];
        if(v == fa)
            continue;
        int ret = dfs(v,rt);

        if(ret > 0) {
            ret --;
            cut ++;
            ru[rt] --;
            cut += ret;
        }
    }
    return max(0,ru[rt]-2);
}

void init() {
    for(int i = 1;i <= n; i++)
        G[i].clear();
    memset(ru,0,sizeof(ru));
    cut = 0;
}

int main() {
    int cas, tem;
    cin >> cas;
    for(int i = 0 ;i < cas;i++) {
        cin >> n;
        init();
        for(int f = 0 ;f < n-1;f++) {
            int a,b;
            scanf("%d%d",&a,&b);
            G[a].push_back(b);
            G[b].push_back(a);
            ru[a] ++;
            ru[b] ++;
        }
        dfs(1,-1);
        if(ru[1] > 2)
            cut += ru[1]-2;
        cout << 1 + 2 * cut << endl;
    }
    return 0;
}