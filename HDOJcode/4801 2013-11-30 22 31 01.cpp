******************************
    Author : townboy
    Submit time : 2013-11-30 22:31:01
    Judge Status : Accepted
    HDOJ Runid : 9723354
    Problem id : 4801
    Exe.time : 750MS
    Exe.memory : 320K
    https://github.com/townboy
******************************


#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;

int s[24];

int cvr[6][12] = {
    {4, 12, 13, 5, 11, 22, 14, 2, 19, 20, 6, 0},
    {12 ,13, 5, 4, 22, 14, 2, 11 ,20, 6, 0, 19},
    {6, 14, 15, 7, 5, 20, 16, 3, 13, 21, 8, 2},
    {14, 15, 7, 6, 20, 16, 3, 5, 21, 8, 2, 13},
    {0, 2, 3, 1 ,4, 6, 8, 10, 5, 7, 9, 11},
    {2 ,3 , 1, 0, 6, 8, 10 ,4, 7, 9, 11, 5}
};

int to[24] = {12, 4, 13, 5, 22, 20, 14, 6, 2, 0, 23, 21, 15, 7, 3, 1, 16, 8, 17, 9, 18, 10, 19, 11};

int n;
int mian[6][4] = {
    {0, 1 ,2 ,3},
    {4, 5, 12, 13},
    {6, 7, 14, 15},
    {8, 9, 16, 17},
    {10, 11, 18, 19},
    {20, 21, 22, 23}
};

int cal() {
    int f, ret = 0;
    for(int i = 0 ;i < 6;i++) {
        for(f = 1; f < 4;f++)
            if(s[mian[i][f]] != s[mian[i][0]])
                break;
        if(4 == f)
            ret ++;
    }
    return ret;
}

int dfs(int deep) {
    int ret = cal();
    int old[24];
    memcpy(old, s, sizeof(s));
    if(deep == n)
        return ret;

    for(int i = 0 ; i < 6; i++) {
        for(int f = 0; f < 12; f++)
            s[cvr[i][f]] = old[cvr[i^1][f]];
        ret = max(ret ,dfs(deep + 1));
        memcpy(s, old, sizeof(s));
    }
    return ret;
}

int main() {
    while(cin >> n) {
        for(int i = 0 ;i < 24; i++)
            scanf("%d",&s[ to[i] ]);
        cout << dfs(0) << endl;
    }
    return 0;
}


