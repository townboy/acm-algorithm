******************************
    Author : townboy
    Submit time : 2013-07-31 13:59:42
    Judge Status : Accepted
    HDOJ Runid : 8776178
    Problem id : 1210
    Exe.time : 46MS
    Exe.memory : 1472K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<memory.h>
#include<vector>
#include<algorithm>

using namespace std;

typedef __int64 LL;

vector<int>q;
bool hash[210000];
int to[210000];

int ans() {
    int size = q.size();
    LL ans = 1;
    for(int i = 0 ;i < size;i++)
        ans = ans/__gcd(ans,(LL)q[i])*q[i];
    return ans;
}

int cnt(int x) {
    if(true == hash[x])
        return 0;
    hash[x] = true;
    return cnt(to[x]) + 1;
}

int solve(int n) {
    q.clear();

    for(int i = 0;i < n;i++) 
        to[i] = i*2+1;
    for(int i = n;i < 2*n;i++)
        to[i] = (i-n)*2;
    memset(hash,false,sizeof(hash));
    for(int i = 0 ;i < 2*n;i++) {
        if(false == hash[i])
            q.push_back(cnt(i));
    }
    return ans();
}

int main() {
    int n;
    while(scanf("%d",&n) != EOF)
        cout << solve(n) << endl;
    return 0;
}
