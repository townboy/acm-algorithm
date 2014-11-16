******************************
    Author : townboy
    Submit time : 2013-08-05 14:54:02
    Judge Status : Accepted
    HDOJ Runid : 8834338
    Problem id : 4634
    Exe.time : 140MS
    Exe.memory : 6636K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<memory.h>
#include<algorithm>
#include<queue>

using namespace std;

int n ,m;
char mp[210][210];
bool hash[210][210][1<<7];
int sx ,sy;
int end;
int keyid[210][210];
int cas = 0;

void init() {
    int sum = 0;
    memset(hash,false,sizeof(hash));
    for(int i = 0 ;i < n;i++)
        for(int f = 0 ;f < m;f++) {
            if('S' == mp[i][f]) {
                sx = i;
                sy = f;
            }
            if('K' == mp[i][f])
                keyid[i][f] = sum ++;
        }
    end = 1 << sum;
    end --;
}

void read() {
    getchar();
    for(int i = 0 ;i < n;i++)
        gets(mp[i]);
}

int fx ,fy ,fstate;
int dir[4][2] = {0,1,0,-1,1,0,-1,0};
char ch[4] = {'R','L','D','U'};

void isfang(int x,int y,int &d) {
    for(int i = 0 ;i < 4;i++)
        if(ch[i] == mp[x][y])
            d = i;
}

int vis[210][210][4];
bool getpos(int x,int y,int state, int d) {
    cas ++;
    while(true) {
        vis[x][y][d] = cas;
        x += dir[d][0];
        y += dir[d][1];
        if(x < 0 || x >= n || y < 0 || y >= m)
            return false;

        if('K' == mp[x][y])
            state |= (1 << keyid[x][y]);
        if('#' == mp[x][y]) {
            fx = x - dir[d][0];
            fy = y - dir[d][1];
            fstate = state;
            return true;
        }
        if(state == end && mp[x][y] == 'E') {
            fx = x ;
            fy = y ;
            fstate = state;
            return true;
        }
        isfang(x,y,d);
        if(cas == vis[x][y][d])
            return false;
    }
    return false;
}

queue<int>q;

void get(int &x,int &y,int &state,int &ans) {
    x = q.front(); q.pop();
    y = q.front(); q.pop();
    state = q.front(); q.pop();
    ans = q.front(); q.pop();
}

void push(int x,int y,int state ,int ans) {
    hash[x][y][state] = true;
    q.push(x);
    q.push(y);
    q.push(state);
    q.push(ans);
}

bool check() {
    if('E' == mp[fx][fy] && end == fstate)
        return true;
    return false;
}

int getfang(int x,int y) {
    for(int i = 0; i < 4;i++)
        if(mp[x][y] == ch[i])
            return i;
    return -1;
}

int solve() {
    while(!q.empty())
        q.pop();
    push(sx ,sy ,0 ,0);
    while(!q.empty()) {
        int x ,y ,state ,ans;
        get(x, y ,state, ans);
    //    cout << x << " " << y << " " << state << " " << ans << endl;
        int d = getfang(x,y);
        for(int i = 0; i < 4;i++) {
            if(-1 != d && i != d)
                continue;
            if(false == getpos(x, y, state, i))
                continue;
            if(true == check())
                return ans + 1;
            if(true == hash[fx][fy][fstate])
                continue;
            push(fx,fy,fstate,ans+1);
        }
    }
    return -1;
}

void debug() {
    for(int i = 0;i < n;i++) 
        cout << mp[i] << endl;
}

int main() {
    while(scanf("%d%d",&n,&m) != EOF) {
        read();
        init();
        cout << solve() << endl;
    }
    return 0;
}
