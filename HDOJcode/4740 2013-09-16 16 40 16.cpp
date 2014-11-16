******************************
    Author : townboy
    Submit time : 2013-09-16 16:40:16
    Judge Status : Accepted
    HDOJ Runid : 9180011
    Problem id : 4740
    Exe.time : 31MS
    Exe.memory : 5668K
    https://github.com/townboy
******************************


#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;

#define maxn 1100

int n;
int dd, td;
int dx ,dy, tx, ty;
int hash[maxn][maxn];
int dir[4][2] = {0,1,1,0,0,-1,-1,0};

bool able(int x,int y,int tt) {
    if(x < 0 || x >= n || y < 0 || y >= n)
        return false;
    if(0 != (hash[x][y] & tt))
        return false;
    return true;
}

void solve() {
    memset(hash,0,sizeof(hash));
    bool drun = true, trun = true;
    for(int ret = 0; ; ret ++) {
        if(dx == tx && dy == ty) {
            cout << dx << " " << dy << endl;
            return ;
        }

        if(false == drun && false == trun)
            break;

        hash[dx][dy] |= 1;
        hash[tx][ty] |= 2;

        if(true == drun) {
            int nx = dx + dir[dd][0];
            int ny = dy + dir[dd][1];
            if(true == able(nx,ny,1)) {
                dx = nx;
                dy = ny;
            }
            else {
                dd = (dd+1)%4;
                int nx = dx + dir[dd][0];
                int ny = dy + dir[dd][1];
                if(true == able(nx,ny,1)) {
                    dx = nx;
                    dy = ny;
                }
                else
                    drun = false;
            }
        }

        if(true == trun) {
            int nx = tx + dir[td][0];
            int ny = ty + dir[td][1];
            if(true == able(nx,ny,2)) {
                tx = nx;
                ty = ny;
            }
            else {
                td = (td+3)%4;
                int nx = tx + dir[td][0];
                int ny = ty + dir[td][1];
                if(true == able(nx,ny,2)) {
                    tx = nx;
                    ty = ny;
                }
                else
                    trun = false;
            }
        }
    }
    cout << "-1" << endl;
}

void read() {
    cin >> dx >> dy >> dd;
    cin >> tx >> ty >> td;
}

int main() {
    while(cin >> n, n) {
        read();
        solve();
    }
    return 0;
}
