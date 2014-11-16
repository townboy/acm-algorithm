******************************
    Author : townboy
    Submit time : 2013-09-14 20:49:30
    Judge Status : Accepted
    HDOJ Runid : 9170451
    Problem id : 4734
    Exe.time : 15MS
    Exe.memory : 1752K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<memory.h>

using namespace std;

int a, b;
int val[15];
int dp[15][25000];
int dig[15];

int dfs(int pos,int state) {
    int ans = 0;
    if(0 == pos) {
        if(state <= a)
            return 1;
        return 0;
    }

    for(int i = 0;i < val[pos];i++) {
        int newstate = state + dig[pos]*i;
        if(newstate <= a) {
            ans += dp[pos-1][a-newstate];
        }
    }

    ans += dfs(pos-1,state+dig[pos]*val[pos]);
    return ans;
}

int ff(int x) {
    int pos = 0;
    int ret = 0;
    while(0 != x) {
        pos++;
        ret += dig[pos]*(x%10);
        x /= 10;
    }
    return ret;
}

int solve(int x) {
    int pos = 0;
    a = ff(a);
    while(0 != x) {
        pos ++;
        val[pos] = x%10;
        x /= 10;
    }
    return dfs(pos,0);
}

void init() {
    memset(dp,0,sizeof(dp));
    dp[0][0] = 1;

    dig[1] = 1;
    for(int i = 2;i < 15;i++)
        dig[i] = dig[i-1] * 2;

    for(int i = 1 ;i <= 10;i++) {
        for(int f = 0; f < 15000;f++)
            for(int g = 0;g < 10;g++)
                if(f+dig[i]*g < 15000)
                    dp[i][f+dig[i]*g] += dp[i-1][f];
    }
    for(int i = 0; i <= 10; i++)
        for(int f = 1;f < 15000;f++)
            dp[i][f] += dp[i][f-1];
}

void debug() {
    for(int i = 0 ;i <= 3;i++) {
        for(int f = 0;f < 10;f++)
            cout << dp[i][f] << " ";
        cout << endl;
    }
}

int cal() {
    int ret = 0;
    for(int i = 0;i <= b;i++)
        if(ff(i) <= a)
            ret ++;
    return ret;
}

int main() {
    int cas ;
    cin >> cas;
    init();
    for(int i = 0 ;i < cas;i++) {
        scanf("%d%d",&a,&b);
        printf("Case #%d: ",i+1);
        printf("%d\n",solve(b));
    }
    return 0;
}
