******************************
    Author : townboy
    Submit time : 2013-08-04 15:01:58
    Judge Status : Accepted
    HDOJ Runid : 8826319
    Problem id : 4638
    Exe.time : 906MS
    Exe.memory : 7388K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<memory.h>
#include<vector>
#include<queue>

using namespace std;

int val[110000];
vector<int>from[110000];
int n;

struct Que {
    pair<int,int> t;
    int ans;
    void in(int id) {
        int st ,ed ;
        scanf("%d%d",&st,&ed);
        t = make_pair(st,ed);
        from[ed].push_back(id);
    }
    void out() {
        printf("%d\n",ans);
    }
};
Que Q[110000];

void init() {
    for(int i = 1; i <= n;i++)
        from[i].clear();
}

#define lch rt<<1
#define rch rt<<1|1
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define father int l,int r,int rt

int pos[110000];
int sum[110000 << 2];

void pushup(int rt) {
    sum[rt] = sum[lch]+sum[rch];
}

void update(int pos,int add, father) {
    if(l == r) {
        sum[rt] += add;
        return ;
    }
    int m = (l+r)>>1;
    if(pos <= m)
        update(pos,add,lson);
    else
        update(pos,add,rson);
    pushup(rt);
}

int query(int L,int R, father) {
    int ans = 0;
    if(l >= L && r <= R)
        return sum[rt];
    int m = (l+r)>>1;
    if(m >= L)
        ans += query(L,R,lson);
    if(m+1 <= R)
        ans += query(L,R,rson);
    return ans;
}

void solve() {
    memset(sum,0,sizeof(sum));
    memset(pos,-1,sizeof(pos));
    for(int i = 1;i <= n;i++) {
        int size = from[i].size();
        int t = val[i];
        pos[t] = i;
        update(i,1,1,n,1);
        if(-1 != pos[t-1])
            update(pos[t-1] ,-1,1,n,1);
        if(-1 != pos[t+1])
            update(pos[t+1], -1,1,n,1);

        for(int f = 0 ;f < size; f++) {
            int id = from[i][f];
            int l = Q[id].t.first;
            Q[id].ans = query(l,i,1,n,1);
        }
    }
}

int main() {
    int q ,cas;
    cin >> cas;
    for(int i = 0 ;i < cas; i++) {
        cin >> n >> q;
        init();
        for(int f = 1; f <= n;f++)
            scanf("%d",val+f);
        for(int f = 0; f < q; f++) {
            Q[f].in(f);
        }
        solve();
        for(int f = 0 ;f < q;f++)
            Q[f].out();
    }
    return 0;
}
