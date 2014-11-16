******************************
    Author : townboy
    Submit time : 2013-08-07 01:07:19
    Judge Status : Accepted
    HDOJ Runid : 8852607
    Problem id : 4623
    Exe.time : 9984MS
    Exe.memory : 208704K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<memory.h>
#include<algorithm>
#include<queue>

using namespace std;

int mod;
int n;
int dp[3000000][14];
int belong[28] = {0,1,2,1,3, 4,5,1,2,6, 7,4,8,9,10, 1,0,4,0,6, 
    11,12,0,4,3, 13,2,9
};

int num[14] = {4,4,3,2,4,1,2,1,1,2,1,1,1,1};
int base[14];

char can[14][20] = {
    "11111111111111",
    "10110101101100",
    "11010111110011",
    "11101101110111",
    "10010101100000",
    "11111011101011",
    "10100101100100",
    "11111110111101",
    "11111111011110",
    "10110001101000",
    "11000101110011",
    "11010011100011",
    "10110100101100",
    "10110101001100"
};

int sum[14];
int end;

int cal(int x) {
    int sum = 1;
    for(int i = 2; i <= x;i++)
        sum = (sum*i)%mod;
    return sum;
}

int fun(int ans) {
    for(int i = 0; i < 14;i++) 
        if(sum[i] > 1)
            ans  = ( ans*cal(sum[i]) ) % mod;
    return ans;
}

queue<int> q;
bool hash[2000000][14];

void extend(int state,int jie) {
    int olds = state, news;
    int now[14];
    memset(now,0,sizeof(now));
    int pos = 0;
    while(0 != state) {
        now[pos] = state % (1+num[pos]);
        state /= (num[pos]+1);
        pos ++;
    }

    for(int i = 0 ; i < 14;i++) {
        if(now[i] < sum[i] && ('1' == can[jie][i] || 0 == olds)) {
            news = olds + base[i];
            dp[news][i] = (dp[olds][jie]+dp[news][i])%mod;
            if(false == hash[news][i]) {
                hash[news][i] = true;
                q.push(news);
                q.push(i);
            }
        }
    }
}

int solve() {
    int ans = 0;

    memset(sum,0,sizeof(sum));
    memset(dp,0,sizeof(dp));
    memset(hash,false,sizeof(hash));

    for(int i = 0; i < n;i++)
        sum[belong[i]] ++;
    end = 0;
    for(int i = 0 ;i < 14;i++)
        end += sum[i] * base[i];

    while(!q.empty() )
        q.pop();
    q.push(0);
    q.push(0);
    dp[0][0] = 1;

    while(!q.empty() ) {
        int state = q.front(); q.pop();
        int jie = q.front(); q.pop();
        if(end == state) {
            ans = (dp[state][jie]+ans)%mod;
            continue;
        }
        extend(state,jie);
    }
    return fun(ans);
}

void init() {
    int sum = 1;
    for(int i = 0 ;i < 14; i++) {
        base[i] = sum;
        sum *= (num[i]+1);
    }
}

#include<time.h>

int main() {
    int cas;
    cin >> cas;
    init();

    time_t st = clock();

    for(int i = 0 ;i < cas; i++) {
        cin >> n >> mod;
        cout << solve() << endl;
    }
    time_t ed = clock();
    return 0;
}

