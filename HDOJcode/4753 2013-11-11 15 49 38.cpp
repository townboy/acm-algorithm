******************************
    Author : townboy
    Submit time : 2013-11-11 15:49:38
    Judge Status : Accepted
    HDOJ Runid : 9555898
    Problem id : 4753
    Exe.time : 562MS
    Exe.memory : 16192K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<vector>
#include<memory.h>

using namespace std;

int own[9][4] = {
    {0,3,4,7},
    {1,4,5,8},
    {2,5,6,9},
    {7,10,11,14},
    {8,11,12,15},
    {9,12,13,16},
    {14,17,18,21},
    {15,18,19,22},
    {16,19,20,23},
};

int id[24][2] = {
    {1,2},
    {2,3},
    {3,4},
    {1,5},
    {2,6},
    {3,7},
    {4,8},
    {5,6},
    {6,7},
    {7,8},
    {5,9},
    {6,10},
    {7,11},
    {8,12},
    {9,10},
    {10,11},
    {11,12},
    {9,13},
    {10,14},
    {11,15},
    {12,16},
    {13,14},
    {14,15},
    {15,16},
};

int getid(int a, int b) {
    int u = min(a,b);
    int v = max(a,b);
    for(int i = 0 ;i < 24;i++) {
        if(id[i][0] == u && id[i][1] == v)
            return i;
    }
}

int n;
bool edge[24];
bool mat[9];

int add(int t) {
    edge[t] = true;
    int ret = 0, i ,f;
    for(i = 0;i < 9;i++) {
        if(true == mat[i])
            continue;
        for(f = 0;f < 4;f++) 
            if(false == edge[ own[i][f]])
                break;
        if(4 == f) {
            ret ++;
            mat[i] = true;
        }
    }
    return ret;
}

int add(int a,int b) {
    int t = getid(a,b);
    edge[t] = true;
    int ret = 0, i ,f;
    for(i = 0;i < 9;i++) {
        if(true == mat[i])
            continue;
        for(f = 0;f < 4;f++) 
            if(false == edge[ own[i][f]])
                break;
        if(4 == f) {
            ret ++;
            mat[i] = true;
        }
    }
    return ret;
}

int State;
int dig[24];

int read() {
    int a, b;
    int S = 0;
    State = 0;
    memset(edge,false,sizeof(edge));
    memset(mat,false,sizeof(mat));
    for(int i = 0 ;i < n;i++) {
        scanf("%d%d",&a,&b);
        State |= dig[getid(a,b)];
        if(0 == i%2)
            S += add(a,b);
        else
            S -= add(a,b);
    }
    return S;
}

char hash[16800000];
char dp[16800000];
#define INF 0x3f3f3f3f

int getvalue(int state ,int ee) {
    memset(mat,false,sizeof(mat));
    memset(edge,false,sizeof(edge));
    int pos = 0;
    while(0 != state) {
        if(1 == state%2)
            add(pos);
        pos ++;
        state >>= 1;
    }
    return add(ee);
}

int dfs(int state,int player) {
    if(hash[state] == true)
        return dp[state];
    //cout << state << "  " << player << endl;

    int ans;
    if(0 == player) {
        ans = -INF;
        for(int i = 0;i < 24;i++)
            if(0 == (dig[i] & state))
                ans = max(ans, dfs(state|dig[i],1-player) + getvalue(state,i)); 
    }
    else {
        ans = INF;
        for(int i = 0 ;i < 24;i++) {
            if(0 == (dig[i] & state)) {
                ans = min(ans, dfs(state|dig[i],1-player) - getvalue(state,i));
            }
        }
    }
    hash[state] = true;
    return dp[state] = ans;
}

bool solve() {
    int S = read(), state = 0;
    //cout << "score = " << S << endl;

    int ret = dfs(State ,n%2);
    if(S + ret >= 0)
        return true;
    return false;
}

int main() {
    int cas;
    cin >> cas;

    dig[0] = 1;
    for(int i = 1;i < 24;i++)
        dig[i] = dig[i-1] * 2;

    memset(hash,false,sizeof(false));
    hash[16777215] = true;
    dp[16777215] = 0;

    for(int i = 0 ;i < cas;i++) {
        cin >> n;
        bool ret = solve();
        printf("Case #%d: ",i+1);
        if(false == ret)
            cout << "Jerry404" << endl;
        else
            cout << "Tom200" << endl;
    }
    return 0;
}

