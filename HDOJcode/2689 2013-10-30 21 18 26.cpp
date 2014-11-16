******************************
    Author : townboy
    Submit time : 2013-10-30 21:18:26
    Judge Status : Accepted
    HDOJ Runid : 9458783
    Problem id : 2689
    Exe.time : 31MS
    Exe.memory : 308K
    https://github.com/townboy
******************************


#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;

int n;
int sum[1010 << 2];

#define father int l,int r,int rt
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1

void add(int pos, father) {
    sum[rt] ++;
    if(l == r)
        return ;
    int m = (l + r) >> 1;
    if(pos <= m)
        add(pos ,lson);
    else
        add(pos, rson);
}

int query(int L,int R, father) {
    if(l >= L && r <= R) 
        return sum[rt];
    int m = (l+r) >> 1;
    int ret = 0;
    if(m >= L) 
        ret += query(L,R,lson);
    if(m+1 <= R)
        ret += query(L,R,rson);
    return ret;
}

int main() {
    while(cin >> n) {
        memset(sum, 0, sizeof(sum));
        int ret = 0 ,tt;
        for(int i = 1;i <= n;i++) {
            scanf("%d",&tt);
            ret += query(tt + 1, n, 1, n ,1);
            add(tt, 1, n, 1);
        }
        cout << ret << endl;
    }
    return 0;
}

