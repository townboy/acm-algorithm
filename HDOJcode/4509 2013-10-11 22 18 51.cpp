******************************
    Author : townboy
    Submit time : 2013-10-11 22:18:51
    Judge Status : Accepted
    HDOJ Runid : 9321202
    Problem id : 4509
    Exe.time : 296MS
    Exe.memory : 324K
    https://github.com/townboy
******************************


#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;

#define len 1440

int turn(int x,int y) {
    return 60 * x + y;
}

#define father int l,int r,int rt
#define lson l ,m ,rt << 1
#define rson m+1, r, rt<<1|1

int sum[1500<<2];
int n;
bool cnt[1500<<2];

void pushup(father) {
    if(true == cnt[rt])
        sum[rt] = r - l + 1;
    else
        sum[rt] = sum[rt<<1] + sum[rt<<1|1];
}

void update(int L,int R,father) {
    if(l >= L && r <= R) {
        cnt[rt] = true;
        pushup(l,r,rt);
        return ;
    }
    int m = (l+r) >> 1;
    if(L <= m)
        update(L,R,lson);
    if(R >= m+1)
        update(L,R,rson);
    pushup(l,r,rt);
}

void solve() {
    int a, b, c, d;
    memset(sum,0,sizeof(sum));
    memset(cnt,false,sizeof(cnt));
    for(int i = 0 ;i < n; i++) {
        scanf("%d:%d %d:%d",&a,&b,&c,&d);
        int st = turn(a,b);
        int ed = turn(c,d);
        if(ed <= st)
            continue;
        update(st+1,ed,1,len,1);
    }
}

int main() {
    while(cin >> n) {
        solve();
        cout << len - sum[1] << endl;
    }
    return 0;
}
