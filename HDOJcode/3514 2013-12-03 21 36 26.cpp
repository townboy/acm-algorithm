******************************
    Author : townboy
    Submit time : 2013-12-03 21:36:26
    Judge Status : Accepted
    HDOJ Runid : 9749442
    Problem id : 3514
    Exe.time : 343MS
    Exe.memory : 14812K
    https://github.com/townboy
******************************


#include <stdio.h>
#include <iostream>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n, m;
char mp[40][40];
int dp[2][820000];        // ×´Ì¬¶¨ÒåµÄÊÇºóÊÖ
bool vis[2][820000];
int du[2][820000];

void read() {
    for(int i = 0 ;i < n;i++)
        scanf("%s",mp[i]);
}

int getState(int a,int b,int c,int d) {                // Queen Army
    return a + b * 30 + c * 900 + d * 27000;
}

int dir[5][2] = {0 ,1, 0, -1, 1, 0, -1, 0, 0, 0};

bool test(int x,int y) {
    if(x < 0 || x >= n || y < 0 || y >= m)
        return false;
    if('#' == mp[x][y])
        return false;
    return true;
}

queue<int > q;

void add(int k,int a,int b,int c,int d) {
    vis[k][getState(a ,b ,c, d)] = true;
    q.push(k); q.push(a); q.push(b); q.push(c); q.push(d);
}

void init() {
    memset(dp, -1, sizeof(dp));
    memset(du, 0, sizeof(du));
    memset(vis, false, sizeof(vis));

    while( !q.empty() )
        q.pop();

    for(int i = 0 ;i < n;i++)
        for(int f = 0 ;f < m;f++) {
            if(false == test(i, f))
                continue;
            dp[0][getState(i, f, i ,f)] = 0;
            add(0 ,i ,f, i, f);
            if('E' != mp[i][f])
                continue;
            for(int g = 0 ;g < n; g++)
                for(int h = 0;h < m; h++) {
                    if(false == test(g, h)) 
                        continue;
                    if(i == g && f == h)
                        continue;
                    dp[0][getState(i, f, g, h)] = 1;
                    add(0, i, f, g, h);
                }
        }

    for(int k = 0;k < 2; k++)
        for(int i = 0 ; i < n;i++)
            for(int f = 0 ;f < m;f++)
                for(int g = 0 ;g < n;g ++)
                    for(int h = 0;h < m; h++) {
                        if('#' == mp[i][f] || '#' == mp[g][h])
                            continue;
                        int state = getState(i ,f, g, h);
                        for(int d = 0;d < 5;d++) {
                            int tox ,toy;
                            if(0 == k) {
                                tox = i + dir[d][0];
                                toy = f + dir[d][1];
                            }
                            else {
                                tox = g + dir[d][0];
                                toy = h + dir[d][1];
                            }
                            if(false == test(tox, toy))
                                continue;
                            du[k][state] ++;
                        }
                    }
}

int solve() {
    int t[4];
    for(int i = 0;i < n;i++) 
        for(int f = 0;f < m;f++) {
            if('Q' == mp[i][f]) {
                t[0] = i;
                t[1] = f;
            }
            else if('A' == mp[i][f]) {
                t[2] = i;
                t[3] = f;
            }
        }

    while( !q.empty() ) {
        int k = q.front(); q.pop();
        int Qx = q.front(); q.pop();
        int Qy = q.front(); q.pop();
        int Ax = q.front(); q.pop();
        int Ay = q.front(); q.pop();
        int tox ,toy;
        int state = getState(Qx ,Qy ,Ax ,Ay);
        int newState ;
        for(int i = 0 ;i < 5; i++) {
            if(1 == k) {
                tox = Qx + dir[i][0];
                toy = Qy + dir[i][1];
                if(false == test(tox, toy))
                    continue;
                newState = getState(tox, toy ,Ax, Ay);
            }
            else {
                tox = Ax + dir[i][0];
                toy = Ay + dir[i][1];
                if(false == test(tox, toy))
                    continue;
                newState = getState(Qx ,Qy, tox, toy);
            }
            if(true == vis[1 - k][newState])
                continue;
            if(0 == dp[k][state]) {
                dp[1 - k][newState] = 1;
                if(1 == k)
                    add(1 - k ,tox, toy ,Ax, Ay);
                else
                    add(1 - k, Qx, Qy, tox, toy);
            }
            else {
                du[1 - k][newState] --;
                if(0 == du[1 - k][newState]) {
                    dp[1 - k][newState] = 0;
                    if(1 == k)
                        add(1 - k, tox, toy, Ax, Ay);
                    else
                        add(1 - k, Qx, Qy ,tox, toy);
                }
            }
        }
    }
    int state = getState(t[0], t[1], t[2], t[3]);
    return dp[0][state];
}

void debug() {
    for(int k = 0;k < 2; k++) {
        for(int i = 0 ;i < n;i ++) 
            for(int f = 0 ;f < m;f++)
                for(int g = 0; g < n; g++)
                    for(int h = 0; h < m; h++) {
                        cout << k << " " << i << " " << f << " " << g << " " << h << " " << dp[k][getState(i, f, g, h)] << " " ;
                        cout << du[k][getState(i, f, g, h)] << endl;
                    }
    }
    cout << "debug end" << endl;
}

int main() {
    while(cin >> m >> n) {
        read();
        init();
        int ret = solve();
        if(0 == ret)
            cout << "Army can catch Queen." << endl;
        else if(-1 == ret)
            cout << "Queen can not escape and Army can not catch Queen." << endl;
        else
            cout << "Queen can escape." << endl;
    }
    return 0;
}

