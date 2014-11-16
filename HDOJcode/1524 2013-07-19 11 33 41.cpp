******************************
    Author : townboy
    Submit time : 2013-07-19 11:33:41
    Judge Status : Accepted
    HDOJ Runid : 8637944
    Problem id : 1524
    Exe.time : 15MS
    Exe.memory : 440K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<memory.h>

using namespace std;

int n;
vector<int> G[1100];
int nim[1100];

void init() {
    for(int i = 0;i < n;i++)
        G[i].clear();
    memset(nim,-1,sizeof(nim[0])*n);
} 

int fun(int x) {
    if(-1 != nim[x])
        return nim[x];
    int size = G[x].size();
    int exist[1100];
    memset(exist,0,n*sizeof(exist[0]));
    for(int i = 0 ;i < size;i++)
        exist[fun(G[x][i])] = 1;
    for(int i = 0;i < n;i++) 
        if(0 == exist[i])
            return nim[x] = i;
}

int main() {
    int tem,k;
    while(cin >> n) {
        init();
        for(int i = 0;i < n; i++) {
            cin >> k;
            for(int f = 0; f < k; f ++) {
                scanf("%d",&tem);
                G[i].push_back(tem);
            }
        }

        for(int i = 0;i < n;i++)
            if(-1 == nim[i])
                fun(i);

        int q;
        while(scanf("%d",&q), q) {
            int sum = 0;
            for(int i = 0;i < q;i++) {
                scanf("%d",&tem);
                sum ^= nim[tem];
            }
            if(0 != sum)
                puts("WIN");
            else
                puts("LOSE");
        }
    }
    return 0;
}
