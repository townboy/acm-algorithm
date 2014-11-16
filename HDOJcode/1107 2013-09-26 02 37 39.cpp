******************************
    Author : townboy
    Submit time : 2013-09-26 02:37:39
    Judge Status : Accepted
    HDOJ Runid : 9229616
    Problem id : 1107
    Exe.time : 0MS
    Exe.memory : 320K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<memory.h>
#include<vector>

using namespace std;

int step;

struct node {
    int men;
    int nei, wu ,hp;
    int dir;
    node(int a,int b,int c,int d,int e) :men(a),nei(b),wu(c),hp(d),dir(e) {}
};
vector<node>G[2][12][12];

bool read() {
    char ch[10];
    int x, y ,nei, wu, hp;
    scanf("%s",ch);
    if('0' == ch[0])
        return false;
    scanf("%d%d%d%d%d",&x,&y,&nei,&wu,&hp);
    x --;
    y --;
    int men;
    if('S' == ch[0])
        men = 0;
    else if('W' == ch[0])
        men = 1;
    else
        men = 2;

    int dir;
    if(0 == men) {
        if(11 == x)
            dir = -1;
        else
            dir = 1;
    }
    else if(1 == men) {
        if(11 == y)
            dir = -1;
        else
            dir = 1;
    }
    else {
        if((0 == x && 11 == y) || (0 == y && 11 == x))
            dir = 0;
        else if(11 == x || 11 == y)
            dir = -1;
        else
            dir = 1;
    }

    G[0][x][y].push_back(node(men,nei,wu,hp,dir));
    return true;
}

void init(int k) {
    for(int i = 0 ;i < 12; i++)
        for(int f = 0 ; f < 12;f++)
            G[k][i][f].clear();
}

double cal(node tt) {
    int men = tt.men;
    double att;
    if(0 == men)
        att = (0.5*tt.nei + 0.5*tt.wu)*(tt.hp+10.0)/100.0;
    else if(1 == men)
        att = (0.8*tt.nei + 0.2*tt.wu)*(tt.hp+10.0)/100.0;
    else 
        att = (0.2*tt.nei + 0.8*tt.wu)*(tt.hp+10.0)/100.0;
    return att;
}

void fight(int k,int x,int y) {
    node t1 = G[k][x][y][0];
    node t2 = G[k][x][y][1];
    G[k][x][y].clear();
    int att1 = cal(t1);
    int att2 = cal(t2);
    t1.hp -= att2;
    if(t1.hp > 0)
        G[k][x][y].push_back(t1);

    t2.hp -= att1;
    if(t2.hp > 0)
        G[k][x][y].push_back(t2);
}

void handle(int k) {
    for(int i = 0 ;i < 12;i++)
        for(int f = 0 ;f < 12;f++) {
            int size = G[k][i][f].size();
            if(2 == size && (G[k][i][f][0].men != G[k][i][f][1].men))
                fight(k,i,f);
            size = G[k][i][f].size();
            for(int g = 0 ;g < size; g++) {
                node tt = G[k][i][f][g];
                int men = tt.men;
                int x = i ,y = f;
                if(0 == men) {
                    if(1 == tt.dir) {
                        x ++;
                        if(11 == x)
                            tt.dir = -1;
                    }
                    else if(-1 == tt.dir) {
                        x --;
                        if(0 == x)
                            tt.dir = 1;
                    }
                }
                else if(1 == men) {
                    if(1 == tt.dir) {
                        y ++;
                        if(11 == y)
                            tt.dir = -1;
                    }
                    else if(-1 == tt.dir) {
                        y --;
                        if(0 == y)
                            tt.dir = 1;
                    }
                }
                else {
                    if(1 == tt.dir) {
                        x ++;
                        y ++;
                        if(11 == x || 11 == y)
                            tt.dir = -1;
                    }
                    else if(-1 == tt.dir) {
                        x --;
                        y --;
                        if(0 == x || 0 == y)
                            tt.dir = 1;
                    }
                }
                G[1-k][x][y].push_back(tt);
            }
        }
}

void solve() {
    for(int i = 0 ;i < step ;i++) {
        init(1-i%2);
        handle(i%2);
    }
}

void ans() {
    pair<int,int>ans[3];
    int k = step % 2;
    for(int i = 0 ;i < 3;i++)
        ans[i].first = ans[i].second = 0;

    for(int i = 0 ;i < 12;i ++)
        for(int f = 0 ;f < 12;f++) {
            int size = G[k][i][f].size();
            for(int g = 0; g < size;g++) {
                int men = G[k][i][f][g].men;
                int hp = G[k][i][f][g].hp;
                ans[men].first ++;
                ans[men].second += hp;
            }
        }
    for(int i = 0 ;i < 3;i++)
        cout << ans[i].first << " " << ans[i].second << endl;
    cout << "***" << endl;
}

int main() {
    int cas;
    cin >> cas;
    for(int i = 0 ;i < cas; i++) {
        cin >> step;
        init(0);
        init(1);
        while(true == read()) {
        }
        solve();
        ans();
    }
    return 0;
}
