******************************
    Author : townboy
    Submit time : 2013-10-11 20:12:39
    Judge Status : Accepted
    HDOJ Runid : 9319771
    Problem id : 4508
    Exe.time : 46MS
    Exe.memory : 724K
    https://github.com/townboy
******************************


#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <memory.h>

using namespace std;

int n ,m, dp[110000];
int a[110], b[110];
void read() {
    for(int i = 0 ;i < n;i++)
        scanf("%d%d",a+i,b+i);
    cin >> m;
}

int solve() {
    memset(dp,0,sizeof(dp));
    for(int i = 0 ;i < n;i++)
        for(int f = b[i]; f <= m;f++)
            dp[f] = max(dp[f], dp[f-b[i]] + a[i]);
    int ret = 0;
    for(int i = 0 ;i <= m;i++)
        ret = max(ret,dp[i]);
    return ret;
}

int main() {
    while(cin >> n) {
        read();
        cout << solve() << endl;
    }
    return 0;
}
