******************************
    Author : townboy
    Submit time : 2013-09-30 22:10:36
    Judge Status : Accepted
    HDOJ Runid : 9254931
    Problem id : 2526
    Exe.time : 375MS
    Exe.memory : 512K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<memory.h>

using namespace std;

int n ,m;
int get[8];

void read() {
    char ch[10];
    int tt;
    for(int i = 0 ;i < 8;i++) {
        scanf("%s%d",ch,&tt);
        int sum = 4*(ch[0]-'0') + 2*(ch[1]-'0') + (ch[2]-'0');
        get[sum] = tt;
    }
}

char ans[1100][210];

int cal(int x,int y) {
    int sum = 0;
    if(y-1 < m || y-1 >= 0)
        sum += 4*ans[x-1][y-1];
    if(y < m || y >= 0)
        sum += 2*ans[x-1][y];
    if(y+1 < m || y+1 >= 0)
        sum += ans[x-1][y+1];
    return get[sum];
}

void solve() {
    scanf("%s",ans[0]);
    m = strlen(ans[0]);
    for(int i = 0;i < m;i++)
        ans[0][i] -= '0';
    for(int i = 1;i < n;i++)
        for(int f = 0;f < m;f++)
            ans[i][f] = cal(i,f);
}

void ANS() {
    for(int i = 0 ;i < n; i++) {
        for(int f = 0;f < m;f++)
            printf("%d",ans[i][f]);
        cout << endl;
    }
}

int main() {
    int cas;
    cin >> cas;
    for(int i = 0 ;i < cas;i ++) {
        cin >> n;
        read();
        solve();
        ANS();
    }
    return 0;
}

