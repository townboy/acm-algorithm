******************************
    Author : townboy
    Submit time : 2013-07-26 17:18:01
    Judge Status : Accepted
    HDOJ Runid : 8723643
    Problem id : 4614
    Exe.time : 1156MS
    Exe.memory : 1924K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<memory.h>
#include<string.h>
#include<string>
#include<math.h>

using namespace std;

#define INF 0x3f3f3f3f
typedef vector<int>     VI;
#define f(i,l,r)            for(int i = l;i < r;i++)
#define F(i,l,r)            for(int i = l;i <= r;i++)
#define pb(x)                 push_back(x)
// Ïß¶ÎÊ÷×¨ÓÃ
#define lch         rt<<1
#define rch         rt<<1|1
#define father        int l,int r,int rt
#define lson         l,m,rt<<1
#define rson         m+1,r,rt<<1|1
#define calm         int m = (l+r) >> 1
void read(char *a) {    freopen(a,"r",stdin);}
void write(char *a) {    freopen(a,"w",stdout);}

int sum[51000 << 2],lazy[51000 << 2];

void init() {
    memset(sum,0,sizeof(sum));
    memset(lazy,-1,sizeof(lazy));
}

void pushup(int rt) {
    sum[rt] = sum[lch]+sum[rch];
}

void pushdown( father ) {
    if(-1 == lazy[rt])
        return ;
    if(0 == lazy[rt]) {
        sum[lch] = sum[rch] = 0;
        lazy[lch] = lazy[rch] = 0;
    }
    else {
        calm;
        sum[lch] = m-l+1;
        sum[rch] = r-m;
        lazy[lch] = lazy[rch] = 1;
    }
    lazy[rt] = -1;
}

int query(int L,int R, father) {
    if(l >= L && r <= R)
        return r-l+1 - sum[rt];
    calm;
    pushdown(l,r,rt);
    int ans = 0;
    if(m >= L)
        ans += query(L,R,lson);
    if(m+1 <= R)
        ans += query(L,R,rson);
    return ans;
}

int drop(int L,int R,father) {
    if(l >= L && r <= R) {
        int ans = sum[rt];
        sum[rt] = 0;
        lazy[rt] = 0;
        return ans;
    }
    calm;
    pushdown(l,r,rt);
    int ans = 0;
    if(m >= L) 
        ans += drop(L,R,lson);
    if(m+1 <= R)
        ans += drop(L,R,rson);
    pushup(rt);
    return ans;
}

void put(int L,int R, father) {
    if(l >= L && r <= R) {
        sum[rt] = r-l+1;
        lazy[rt] = 1;
        return ;
    }
    calm ;
    if(m >= L)
        put(L,R,lson);
    if(m+1 <= R)
        put(L,R,rson);
    pushup(rt);
}

int n;

int ffir(int x) {
    int l = x-1 ,r = n-1 ,mid;
    while(l != r-1) {
        mid = (l+r) >> 1;
        if(0 == query(x,mid,0,n-1,1))
            l = mid;
        else
            r = mid;
    }
    return r;
}

int fsec(int x,int k) {
    int l = x-1 ,r = n, mid;
    while(l != r-1) {
        mid = (l+r) >> 1;
        if(query(x,mid,0,n-1,1) < k)
            l = mid;
        else
            r = mid;
    }
    return r;
}

void solve(int a,int b) {
    int state = query(a,n-1,0,n-1,1);
    if(0 == state) {
        cout << "Can not put any one." << endl;
        return ;
    }
    int first = ffir(a);
    int second;
    if(state < b)
        second = fsec(a,state);    
    else
        second = fsec(a,b);
    put(first,second,0,n-1,1);
    printf("%d %d\n",first,second);
}

void debug(int l,int r,int rt) {
    cout << l << " " << r << " " << rt << " sum = " << sum[rt];
    cout << " lazy = " << lazy[rt] << endl;
    if(l == r)
        return ;
    calm;
    debug(lson);
    debug(rson);
}

int main() {
    int k ,a ,b ,m;
    int cas;
    //freopen("D:\\in.txt","r",stdin);
    cin >> cas;
    for(int i = 0 ;i < cas;i++) {
        cin >> n >> m;
        init();
        for(int f = 0;f < m;f++) {
            scanf("%d%d%d",&k,&a,&b);
            if(1 == k)
                solve(a,b);
            else
                printf("%d\n",drop(a,b,0, n-1,1));
        }
        cout << endl;
    }
    return 0;
}
