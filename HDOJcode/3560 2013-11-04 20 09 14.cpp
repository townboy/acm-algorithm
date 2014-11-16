******************************
    Author : townboy
    Submit time : 2013-11-04 20:09:14
    Judge Status : Accepted
    HDOJ Runid : 9498752
    Problem id : 3560
    Exe.time : 640MS
    Exe.memory : 3200K
    https://github.com/townboy
******************************


#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <math.h>

using namespace std;

#define maxn 100100

int set[maxn];
int deg[maxn];
int n ,m;

int find(int x) {
    return set[x] == x ? x : set[x] = find(set[x]);
}

int all , cycle ;
bool C[maxn];

void init() {
    for(int i = 0;i < n;i++) {
        set[i] = i;
        deg[i] = 0;
        C[i] = false;
    }
    all = n;
}


void read() {
    int u ,v;
    for(int i = 0 ;i < m; i++) {
        scanf("%d%d",& u, &v);
        int uu = find(u);
        int vv = find(v);
        if(uu != vv) {
            set[uu] = vv;
            all --;
        }
        deg[u] ++ ;
        deg[v] ++ ;
    }
    cycle = all;
    for(int i = 0;i < n;i ++) {
        if(2 != deg[i]) {
            int head = find(i);
            if(false == C[head]) {
                C[head] = true;
                cycle --;
            }
        }
    }
}

int main() {
    while(cin >> n >> m, n + m) {
        init();
        read();
        cout << all << " " << cycle << endl;
    }
    return 0;
}

