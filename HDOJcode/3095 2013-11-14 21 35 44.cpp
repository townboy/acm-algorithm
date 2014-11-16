******************************
    Author : townboy
    Submit time : 2013-11-14 21:35:44
    Judge Status : Accepted
    HDOJ Runid : 9586723
    Problem id : 3095
    Exe.time : 3250MS
    Exe.memory : 300K
    https://github.com/townboy
******************************


#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <memory.h>
#include <vector>

using namespace std;

int mat[5][5];
bool finish[5][5];
int pos[13][2] = {
    0,2,
    1,1,
    1,2,
    1,3,
    2,0,
    2,1,
    2,2,
    2,3,
    2,4,
    3,1,
    3,2,
    3,3, 
    4,2
};

void debug() {
    for(int i = 0 ;i < 5;i ++) {
        for(int f = 0 ;f < 5;f++)
            cout << mat[i][f] << " " ;
        cout << endl;
    }
}

void init() {
    memset(finish, false, sizeof(finish));
    for(int i = 0;i < 13; i++)
        finish[pos[i][0] ] [pos[i][1]] = true;
}

void read() {
    int tt;
    memset(mat, -1, sizeof(mat));
    for(int i = 0;i < 13;i++) {
        cin >> tt;
        mat[pos[i][0] ][pos[i][1]] = tt;
    }
}

int dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
int lim;

int h() {
    int ret = 0;
    for(int i = 0;i < 5;i ++) {
        for(int f = 0 ;f < 5;f ++)
            if(mat[i][f] > 0) {
                int t = mat[i][f];
                int x = pos[t][0];
                int y = pos[t][1];
                if(i != x || f != y)
                    ret += abs(i - x) + abs(f - y);
            }
    }
    return ret;
}

bool test(int x,int y) {
    if(x < 0 || x > 4 || y < 0 || y > 4)
        return false;
    return finish[x][y];
}

bool dfs(int deep) {
    int diff = h();
    if(0 == diff)
        return true;
    if(diff + deep > lim)
        return false;
    for(int i = 0 ;i < 5;i ++)
        for(int f = 0 ;f < 5;f++) {
            if(0 != mat[i][f])
                continue;
            for(int g = 0 ;g < 4;g++) {
                int tox = i + dir[g][0];
                int toy = f + dir[g][1];
                if(test(tox, toy) == false)
                    continue;
                mat[i][f] = mat[tox][toy];
                   mat[tox][toy] = 0;
                if(true == dfs(deep + 1) )
                    return true;
                mat[tox][toy] = mat[i][f];
                mat[i][f] = 0;
            }
        }
    return false;
}

int solve() {
    for(lim = 0; lim <= 20; lim ++)
        if(true == dfs(0))
            return lim;
    return -1;
}

int main() {
    int cas;
    cin >> cas;
    init();
    for(int i = 0 ;i < cas; i++) {
        read();
        int ret = solve();
        if(-1 == ret)
            cout << "No solution!" << endl;
        else
            cout << ret << endl;
    }
    return 0;
}

