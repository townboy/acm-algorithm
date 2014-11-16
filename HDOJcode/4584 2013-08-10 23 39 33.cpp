******************************
    Author : townboy
    Submit time : 2013-08-10 23:39:33
    Judge Status : Accepted
    HDOJ Runid : 8901000
    Problem id : 4584
    Exe.time : 0MS
    Exe.memory : 320K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<memory.h>
#include<algorithm>

using namespace std;

int n,m;
char mp[50][50];

void read() {
    for(int i = 0 ;i < n;i++)
        scanf("%s",mp[i]);
}

void solve() {
    pair<int,int>h,c;
    int ans = 100;
    for(int hi = 0 ;hi < n;hi++)
        for(int hf = 0 ;hf < m;hf++) {
            if('H' != mp[hi][hf])
                continue;
            for(int ci = 0 ;ci < n;ci++)
                for(int cf = 0 ;cf < m;cf++) {
                    if('C' != mp[ci][cf])
                        continue;
                    int dis = abs(hi-ci) + abs(hf-cf);
                    if(dis < ans) {
                        ans = dis;
                        h = make_pair(hi,hf);
                        c = make_pair(ci,cf);
                    }
                }
        }
    cout << h.first << " " << h.second << " " ;
    cout << c.first << " " << c.second << endl;
}

int main() {
    while(cin >> n >> m ,n+m) {
        read();
        solve();
    }
    return 0;
}
