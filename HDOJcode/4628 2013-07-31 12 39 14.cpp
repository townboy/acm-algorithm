******************************
    Author : townboy
    Submit time : 2013-07-31 12:39:14
    Judge Status : Accepted
    HDOJ Runid : 8775385
    Problem id : 4628
    Exe.time : 234MS
    Exe.memory : 920K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<memory.h>
#include<algorithm>
#include<queue>

using namespace std;

int dis[70000] ,end;
int len ;
bool hefa[70000];

char ch[20];

bool check(int state) {
    int pos = 0;
    int len = 0;
    int t1[20];
    while(0 != state) {
        if(1 == state%2)
            t1[len ++] = ch[pos];
        state >>= 1;
        pos ++;
    }
    for(int i = 0 ; i < len/2;i++) 
        if(t1[i] != t1[len-1-i])
            return false;
    return true;
}

void init() {
    len = strlen(ch);
    end = (1<<len) - 1;
    memset(dis,0x3f,sizeof(dis));
    for(int i = 1;i <= end; i++)
        hefa[i] = check(i);
}

int bfs() {
    queue<int>q;
    q.push( end );
    dis[end] = 0;
    while(!q.empty()) {
        int now = q.front();
        q.pop();
        if(0 == now) 
            return dis[now];
        for (int mask = now ; mask ; mask = now & (mask - 1)) {
            if(false == hefa[mask])
                continue;
            int newstate = now - mask;
            if(dis[now] + 1 < dis[newstate]) {
                dis[newstate] = dis[now] + 1;
                q.push(newstate);
            }
        }
    }
    return -1;
}

int main() {
    int cas;
    cin >> cas;
    for(int i = 0 ;i < cas;i++) {
        scanf("%s",ch);
        init();
        printf("%d\n",bfs());
    }
    return 0;
}
