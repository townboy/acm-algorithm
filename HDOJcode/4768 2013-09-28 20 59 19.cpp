******************************
    Author : townboy
    Submit time : 2013-09-28 20:59:19
    Judge Status : Accepted
    HDOJ Runid : 9243353
    Problem id : 4768
    Exe.time : 31MS
    Exe.memory : 552K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<algorithm>
#include<iostream>

using namespace std;

#define maxn 21000
typedef long long LL;

int a[maxn], b[maxn] ,c[maxn];
int n;

void read() {
    for(int i = 0 ;i < n; i++)
        scanf("%d%d%d",a+i,b+i,c+i);
}

#define INF ((LL)1<<31)

int check(int mid) {
    int sum = 0;
    for(int i = 0 ;i < n;i++)
        if(mid >= a[i])
            sum += 1 + (min(mid,b[i])-a[i])/c[i];
    return sum;
}

pair<LL,LL> solve() {
    LL l = -1, r = INF, mid;

    while(l != r-1) {
        mid = (l+r) >> 1;
        if(0 == check(mid)%2)
            l = mid;
        else
            r = mid;
    }
    return make_pair(r,check(r)-check(r-1));
}

int main() {
    while(cin >> n) {
        read();
        pair<LL,LL> ret = solve();
        if(INF == ret.first)
            cout << "DC Qiang is unhappy." << endl;
        else
            cout << ret.first << " " << ret.second << endl;
    }
    return 0;
}

