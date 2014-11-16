******************************
    Author : townboy
    Submit time : 2013-07-31 23:03:14
    Judge Status : Accepted
    HDOJ Runid : 8784545
    Problem id : 4630
    Exe.time : 1140MS
    Exe.memory : 6936K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<memory.h>
#include<algorithm>
#include<vector>

using namespace std;

#define MP(first,second) make_pair(first,second)
#define PB(a) push_back(a)
#define FT first
#define SE second
#define father int l,int r,int rt
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define lch rt<<1
#define rch rt<<1|1

int q ,n;
int ans[51000] ,val[51000];

vector< pair<int,int> > qes[51000];


void Ans() {
    for(int i = 0 ;i < q;i++) 
        printf("%d\n",ans[i]);
}

int last[51000] ;
int maxx[51000 << 2];

void init() {
    memset(last,0,sizeof(last));
    memset(maxx,0,sizeof(maxx));
    for(int i = 1;i <= n; i++)
        qes[i].clear();
}

vector<int> dio[51000];

int query(int L,int R, father) {
    int ans = 0;
    if(l >= L && r <= R)
        return maxx[rt];
    int m = (l+r)>>1;
    if(m >= L)
        ans = max(ans,query(L,R,lson));
    if(m+1 <= R)
        ans = max(ans,query(L,r,rson));
    return ans;
}

void pushup(int rt) {
    maxx[rt] = max(maxx[lch], maxx[rch]);
}

void update(int pos,int v, father) {
    if(l == r) {
        maxx[rt] = max(maxx[rt],v);
        return ;
    }
    int m = (l+r)>>1;
    if(pos <= m)
        update(pos,v,lson);
    else
        update(pos,v,rson);
    pushup(rt);
}

void solve() {
    int x, size;
    for(int i = 1;i <= n;i++) {
        x = val[i];
        size = dio[x].size();
        for(int f = 0;f < size; f++) {
            int tem = dio[x][f];
            int pos = last[tem];
            if(0 != pos)
                update(pos,tem,1,n,1);
            last[tem] = i;
        }

        size = qes[i].size();
        for(int f = 0 ;f < size; f++) {
            int ft = qes[i][f].FT;
            int se = qes[i][f].SE;
            ans[se] = query(ft,i,1,n,1);
        }
    }
    Ans();
}

void chu() {
    for(int i = 1; i <= 50000; i++)
        for(int f = i; f <= 50000; f+=i)
            dio[f].PB(i);
}

int main() {
    int cas ;
    cin >> cas;
    chu();
    for(int i = 0;i < cas; i++) {
        cin >> n;
        init();
        for(int f = 1; f <= n;f++)
            scanf("%d",val+f);
        cin >> q;
        int l ,r;
        for(int f = 0; f < q;f++) {
            scanf("%d%d",&l,&r);
            qes[r].PB(MP(l,f));
        }
        solve();
    }
    return 0;
}
