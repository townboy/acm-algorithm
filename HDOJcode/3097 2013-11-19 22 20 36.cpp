******************************
    Author : townboy
    Submit time : 2013-11-19 22:20:36
    Judge Status : Accepted
    HDOJ Runid : 9628198
    Problem id : 3097
    Exe.time : 15MS
    Exe.memory : 320K
    https://github.com/townboy
******************************


#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define maxn 1010

int set[maxn], num[maxn];
int n ,m;

int find(int x) {
    return x == set[x] ? x : set[x] = find(set[x]);
}

void read() {
    int u ,v;
    for(int i = 1;i <= n;i++) {
        set[i] = i;
        num[i] = 0;
    }
    for(int i = 0 ;i < m; i++) {
        scanf("%d%d",&u, &v);
        u = find(u);
        v = find(v);
        if(u == v)
            num[u] ++;
        else {
            set[u] = v;
            num[v] += num[u] + 1;
        }
    }
}

string solve() {
    for(int i = 1;i <= n; i++) 
        if(set[i] == i && 1 == (num[i] % 2) )
            return "No";
    return "Yes";
}

int main() {
    while(cin >> n >> m, n + m) {
        read();
        cout << solve() << endl;
    }
    return 0;
}

