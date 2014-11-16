******************************
    Author : townboy
    Submit time : 2013-11-25 20:16:25
    Judge Status : Accepted
    HDOJ Runid : 9678030
    Problem id : 3004
    Exe.time : 78MS
    Exe.memory : 7096K
    https://github.com/townboy
******************************


#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <queue>

using namespace std;

char mp[20][20];
int n , m;
int dis[1100000];
int sx ,sy;

int dir[4][2] = {0, 1, 0, -1, 1, 0 ,-1, 0};
int ma_dir[8][2] = {-2, -1, -2, 1, -1, 2, 1, 2, 2, 1, 2 ,-1, 1, -2, -1, -2};
int aim_point[8][2] = {-1, 0, -1, 0 ,0 ,1, 0 ,1, 1, 0 , 1, 0 ,0, -1, 0 ,-1};

struct node {
    int state ;
    int cx, cy;
    int mx, my;
    int px, py;

    bool check(int x,int y) {
        if(x == sx && y == sy)
            return true;
        return false;
    }

    int getstate() {
        return state = cx + 10 * cy + 100 * mx + 1000 * my + 10000 * px + 100000 * py;
    }

    bool valid(int x,int y) { // youmeiyou qizi
        if(false == in(x,y))
            return false;
        if(1 == exist2(x ,y))
            return false;
        return true;
    }

    bool test(int x,int y) {     //     nenggou daoda
        if(false == in(x, y))
            return false;
        if(1 == exist(x, y))
            return false;
        return true;
    }

    bool in(int x,int y) {
        if(x < 0 || x >= n || y < 0 || y >= m)
            return false;
        return true;
    }

    int exist2(int x,int y) {
        if('D' == mp[x][y])
            return 1;
        if(cx == x && cy == y)
            return 1;
        if(mx == x && my == y)
            return 1;
        if(px == x && py == y)
            return 1;
        if(sx == x && sy == y)
            return 1;
        return 0;
    }
    int exist(int x,int y) {
        if('D' == mp[x][y])
            return 1;
        if(cx == x && cy == y)
            return 1;
        if(mx == x && my == y)
            return 1;
        if(px == x && py == y)
            return 1;
        return 0;
    }

    void jv_extend(queue<node> & q) {
        for(int i = 0 ;i < 4; i++) {
            int tox = cx + dir[i][0];
            int toy = cy + dir[i][1];
            while(true == test(tox, toy)) {
                node ex = *this;
                ex.cx = tox;
                ex.cy = toy;
                ex.getstate();
                int len = dis[state] + 1;
                if(len < dis[ex.state]) {
                    dis[ex.state] = len;
                    q.push(ex);
                }
                tox += dir[i][0];
                toy += dir[i][1];
            }
        }
    }

    void ma_extend(queue<node> & q) {
        for(int i = 0 ;i < 8; i++) {
            int tox = mx + ma_dir[i][0];
            int toy = my + ma_dir[i][1];
            int kx = mx + aim_point[i][0];
            int ky = my + aim_point[i][1];
            if(test(tox,toy) == false || valid(kx ,ky) == false)
                continue;
            node ex = *this;
            ex.mx = tox;
            ex.my = toy;
            ex.getstate();
            int len = dis[state] + 1;
            if(len < dis[ex.state]) {
                dis[ex.state] = len;
                q.push(ex);
            }
        }
    }

    void pao_extend(queue<node> & q) {
        for(int i = 0 ;i < 4; i++) {
            for(int f = 1; ; f++) {
                int tox = px + f * dir[i][0];
                int toy = py + f * dir[i][1];
                if(false == in(tox,toy))
                    break;
                int ret = 0;
                for(int g = 1 ;g < f;g++) {
                    int tx = px + g * dir[i][0];
                    int ty = py + g * dir[i][1];
                    ret += exist2(tx, ty);
                }
                if('S' != mp[tox][toy]) {
                    if(0 == exist(tox, toy) && 0 == ret) {
                        node ex = *this;
                        ex.px = tox;
                        ex.py = toy;
                        ex.getstate();
                        int len = dis[state] + 1;
                        if(len < dis[ex.state]) {
                            dis[ex.state] = len;
                            q.push(ex);
                        }
                    }
                }
                else {
                    if(1 == ret) {
                        node ex = *this;
                        ex.px = tox;
                        ex.py = toy;
                        ex.getstate();
                        int len = dis[state] + 1;
                        if(len < dis[ex.state]) {
                            dis[ex.state] = len;
                            q.push(ex);
                        }
                    }
                }
            }
        }
    }

    bool success() {
        if(check(cx, cy) || check(mx, my) || check(px,py))
            return true;
        return false;
    }
};

int bfs(node init) {
    init.getstate();

    queue<node> q;

    memset(dis, 0x3f, sizeof(dis));
    dis[init.state] = 0;

    q.push(init);
    while(! q.empty()) {
        node tem = q.front();
        q.pop();
        if(true == tem.success())
            return dis[tem.state];
        tem.jv_extend(q);
        tem.ma_extend(q);
        tem.pao_extend(q);
    }
    return -1;
}

int read() {
    for(int i = 0 ;i < n;i++)
        scanf("%s",mp[i]);
    node init;

    for(int i = 0 ;i < n;i++)
        for(int f = 0;f < m;f++) {
            if('C' == mp[i][f]) {
                init.cx = i;
                init.cy = f;
            }
            else if('M' == mp[i][f]) {
                init.mx = i;
                init.my = f;
            }
            else if('P' == mp[i][f]) {
                init.px = i;
                init.py = f;
            }
            else if('S' == mp[i][f]) {
                sx = i;
                sy = f;
            }
        }
    return bfs(init);
}

int main() {
    int cas = 0;
    while(cin >> n >> m) {
        cas ++;
        int ret = read();
        printf("Scenario #%d\n",cas);
        if(-1 == ret)
            cout << "OH!That's impossible!" << endl;
        else
            cout << ret << endl;
        cout << endl;
    }
    return 0;
}

