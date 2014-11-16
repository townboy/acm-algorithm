******************************
    Author : townboy
    Submit time : 2013-11-02 20:35:39
    Judge Status : Accepted
    HDOJ Runid : 9484725
    Problem id : 2428
    Exe.time : 46MS
    Exe.memory : 688K
    https://github.com/townboy
******************************


#include <stdio.h>
#include <map>
#include <algorithm>
#include <memory.h>
#include <iostream>
#include <vector>

using namespace std;

typedef pair<int,int> PII;


int n;
map<PII ,bool> mp;
vector<int>G[21000];

void read() {
    mp.clear();
    for(int i = 0;i <= 20000; i++)
        G[i].clear();
    
    int u ,v;
    for(int i = 0;i < n;i++) {
        scanf("%d%d",&u,&v);
        u += 10000;
        v += 10000;
        G[u].push_back(v);
        mp[ make_pair(u,v) ] = true;
    }
}

int solve() {
    int ret = 0;
    for(int i = 0;i <= 20000;i++) {
        int size = G[i].size();
        for(int f = 0;f < size; f++)
            for(int g = f + 1; g < size; g++) {
                int a = G[i][f] ;
                int b = G[i][g] ;
                int dis = abs(a - b);
                if(mp.find( make_pair(i + dis, a) ) != mp.end() && mp.find( make_pair(i + dis, b)) != mp.end() )
                    ret ++;
            }
    }
    return ret;
}

int main() {
    int cas;
    cin >> cas;
    for(int i = 0 ;i < cas; i++) {
        scanf("%d",&n);
        read();
        cout << solve() << endl;
    }
    return 0;
}

