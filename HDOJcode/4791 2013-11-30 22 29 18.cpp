******************************
    Author : townboy
    Submit time : 2013-11-30 22:29:18
    Judge Status : Accepted
    HDOJ Runid : 9723336
    Problem id : 4791
    Exe.time : 296MS
    Exe.memory : 2756K
    https://github.com/townboy
******************************


#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <functional>

using namespace std;
#define maxn 110000

int n ,q;

typedef long long LL;
typedef pair<int ,int>  PII;
PII tt[maxn];
LL ret[maxn];

#define INF 0x7ffffffffffffffLL
int s[maxn] , p[maxn];

void fun() {
    int x;
    for(int i = 0;i < q; i++) {
        scanf("%d",&x);
        tt[i] = make_pair(x, i);
    }
    sort(tt , tt + q);

    LL minn = INF;
    int pos = n - 1;
    for(int i = q-1; i >= 0;i --) {
        x = tt[i].first;
        int id = tt[i].second;
        while(s[pos] > x) {
            minn = min(minn, (LL)s[pos] * (LL)p[pos]);
            pos --;
        }
        ret[id] = min(minn , (LL) x * p[pos]);
    }
}

void read() {
    for(int i = 0 ;i < n;i++)
        scanf("%d%d", s + i ,p + i);
}

void ans() {
    for(int i = 0 ;i < q; i++)
        printf("%I64d\n",ret[i]);
}

int main() {
    //freopen("D:\\in.txt","r",stdin);
    int cas;
    cin >> cas;
    for(int i = 0 ;i < cas; i++) {
        cin >> n >> q;
        read();
        fun();
        ans();
    }
    return 0;
}



