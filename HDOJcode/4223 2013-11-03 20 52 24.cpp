******************************
    Author : townboy
    Submit time : 2013-11-03 20:52:24
    Judge Status : Accepted
    HDOJ Runid : 9492326
    Problem id : 4223
    Exe.time : 62MS
    Exe.memory : 384K
    https://github.com/townboy
******************************


#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <math.h>

using namespace std;

long long sum[110000];

int main() {
    int cas, n;
    cin >> cas;
    for(int i = 0 ;i < cas;i++) {
        scanf("%d",&n);
        sum[0] = 0;
        for(int i = 1 ;i <= n;i++) {
            scanf("%I64d",sum + i);
            sum[i] += sum[i-1];
        }
        long long ret = 0x3f3f3f3f3f3f3f3fLL;
        for(int i = 1;i <= n; i++)
            for(int f = 0;f < i;f++)
                ret = min(ret ,(long long)abs((long long)sum[i] - sum[f]) );
        printf("Case %d: ",i + 1);
        cout << ret << endl;
    }
    return 0;
}

