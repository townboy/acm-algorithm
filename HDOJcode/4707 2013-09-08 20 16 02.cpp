******************************
    Author : townboy
    Submit time : 2013-09-08 20:16:02
    Judge Status : Accepted
    HDOJ Runid : 9132446
    Problem id : 4707
    Exe.time : 812MS
    Exe.memory : 4040K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<memory.h>
#include<vector>

using namespace std;

vector<int>G[100100];
int n, D;

void init() {
    for(int i = 0 ;i < n;i++)
        G[i].clear();
}

int dfs(int rt,int fa,int d) {
    int sum = 0;
    int size = G[rt].size();
    for(int i = 0 ;i < size;i++) {
        int v = G[rt][i];
        if(v == fa)
            continue;
        sum += dfs(v,rt,d+1);
    }
    if(d > D)
        sum ++;
    return sum;
}

int main() {
    int cas, tem;
    cin >> cas;
    for(int i = 0 ;i < cas;i++) {
        cin >> n >> D;
        init();
        for(int f = 0 ;f < n-1;f++) {
            int a,b;
            scanf("%d%d",&a,&b);
            G[a].push_back(b);
            G[b].push_back(a);
        }
        cout << dfs(0,-1,0) << endl;
    }
    return 0;
}

