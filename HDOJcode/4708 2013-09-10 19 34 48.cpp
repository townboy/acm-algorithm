******************************
    Author : townboy
    Submit time : 2013-09-10 19:34:48
    Judge Status : Accepted
    HDOJ Runid : 9144883
    Problem id : 4708
    Exe.time : 15MS
    Exe.memory : 296K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<memory.h>
#include<algorithm>

using namespace std;

int G[15][15];
int n;

void read() {
    for(int i = 0 ;i < n;i++) 
        for(int f = 0;f < n;f++)
            scanf("%d",&G[i][f]);
}

int value ,cost;

#define INF 0x3f3f3f3f

void handle(int x,int dis) {
    int maxx = -INF, cc;
    for(int i = 0;i <= 2*dis;i++) {
        int sum = G[x-dis][x-dis+i] + G[x-dis+i][x+dis]+G[x+dis][x+dis-i]+G[x+dis-i][x-dis];
        int dd = min(i,2*dis-i);
        if(sum > maxx || (sum == maxx && dd < cc) ) {
            maxx = sum;
            cc = dd;
        }
    }
    value += maxx;
    cost += cc;
}

void solve() {
    value = 0;
       cost = 0;
    int ban = n/2;
    for(int i = 1; i <= ban;i++) 
        handle(ban ,i);    
    cout << value+G[ban][ban] << " " << cost << endl;
}

int main() {
    while(cin >> n, n) {
        read();
        solve();
    }
    return 0;
}
