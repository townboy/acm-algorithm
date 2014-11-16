******************************
    Author : townboy
    Submit time : 2013-08-07 14:18:45
    Judge Status : Accepted
    HDOJ Runid : 8857505
    Problem id : 4647
    Exe.time : 109MS
    Exe.memory : 1152K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<memory.h>
#include<functional>

using namespace std;

typedef long long LL;
int n ,m;
LL val[110000];

int main() {
    LL w;
    int u, v;
    while(cin >> n >> m) {
        memset(val,0,sizeof(val));
        for(int i = 1; i <= n;i++) {
            scanf("%I64d",val+i);
            val[i] <<= 1;
        }
        for(int i = 0 ;i < m; i++) {
            scanf("%d%d%I64d",&u,&v,&w);
            val[u] += w;
            val[v] += w;
        }

        sort(val+1,val+n+1,greater<LL>() );
        LL ans = 0;
        for(int i = 1;i <= n;i+=2)
            ans += val[i]-val[i+1];
        cout << (ans>>1)  << endl;
    }
    return 0;
}