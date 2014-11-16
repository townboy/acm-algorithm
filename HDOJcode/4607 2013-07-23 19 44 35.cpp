******************************
    Author : townboy
    Submit time : 2013-07-23 19:44:35
    Judge Status : Accepted
    HDOJ Runid : 8681633
    Problem id : 4607
    Exe.time : 671MS
    Exe.memory : 4040K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<vector>
#include<memory.h>

using namespace std;

int n;
vector<int>G[110000];
int maxlen ;

void init() {
    for(int i = 1;i <= n;i++)
        G[i].clear();
    maxlen = -1;
}

int dfs(int rt,int fa) {
    int size = G[rt].size();

    int one = -1, two = -1;
    
    for(int i = 0;i < size;i++) {
        int son = G[rt][i];
        if(fa == son)
            continue;
        int tem = dfs(son,rt);
        if(tem > one) {
            two = one;
            one = tem;
        }
        else if(tem > two) 
            two = tem;
    }
    if(-1 == one)
        return 0;
    if(-1 == two) {
        maxlen = max(maxlen,one+1);
        return one+1;
    }
    maxlen = max(maxlen,one+two+2);
    return one+1;
}

int main() {
    int cas ,q;
    int u,v;
    cin >> cas;
    for(int i = 0; i < cas;i++) {
        init();
        cin >> n >> q;
        for(int f = 0 ; f< n-1;f++) {
            scanf("%d%d",&u,&v);
            G[u].push_back(v);
            G[v].push_back(u);
        }
        
        dfs(1,-1);
        int tem;
        
        for(int f = 0; f< q;f++) {
            scanf("%d",&tem);
            printf("%d\n", max(tem-1,2*(tem-1)-maxlen));
        }
    }
    return 0;
}