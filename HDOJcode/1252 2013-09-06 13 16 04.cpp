******************************
    Author : townboy
    Submit time : 2013-09-06 13:16:04
    Judge Status : Accepted
    HDOJ Runid : 9117218
    Problem id : 1252
    Exe.time : 46MS
    Exe.memory : 1436K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<memory.h>
#include<queue>

using namespace std;

int n ,p[3];
int G[55][55];

void read() {
    for(int i = 0 ;i < 3;i ++)
        cin >> p[i];
    char tem[10];
    for(int i = 1 ;i <= n;i ++)
        for(int f = 1;f <= n;f ++) {
            scanf("%s",tem);
            G[i][f] = tem[0]-'a';
        }
}

bool hash[55][55][55];

int bfs() {
    queue<int>q;
    for(int i = 0 ;i < 3;i ++)
        q.push(p[i]);
    q.push(0);
    hash[p[0]][p[1]][p[2]] = true;

    while(!q.empty()) {
        int a = q.front();q.pop();
        int b = q.front();q.pop();
        int c = q.front();q.pop();
        int ans = q.front();q.pop();
        if(a == b && a == c)
            return ans;

        for(int i = 1; i <= n;i++) {
            if(G[a][i] != G[b][c])
                continue;
            if(true == hash[i][b][c])
                continue;
            hash[i][b][c] = true;
            q.push(i);
            q.push(b);
            q.push(c);
            q.push(ans+1);
        }

        for(int i = 1; i <= n;i++) {
            if(G[b][i] != G[a][c])
                continue;
            if(true == hash[a][i][c])
                continue;
            hash[a][i][c] = true;
            q.push(a);
            q.push(i);
            q.push(c);
            q.push(ans+1);
        }

        for(int i = 1; i <= n;i++) {
            if(G[c][i] != G[a][b])
                continue;
            if(true == hash[a][b][i])
                continue;
            hash[a][b][i] = true;
            q.push(a);
            q.push(b);
            q.push(i);
            q.push(ans+1);
        }
    }
    return -1;
}

void init() {
    memset(hash,false,sizeof(hash));
}

int main() {
    while(cin >> n , n) {
        init();
        read();
        int ans = bfs();
        if(-1 == ans)
            cout << "impossible" << endl;
        else
            cout << ans << endl;
    }
    return 0;
}
