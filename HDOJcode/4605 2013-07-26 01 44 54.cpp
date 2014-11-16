******************************
    Author : townboy
    Submit time : 2013-07-26 01:44:54
    Judge Status : Accepted
    HDOJ Runid : 8714956
    Problem id : 4605
    Exe.time : 1750MS
    Exe.memory : 7572K
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

#define lch         rt<<1
#define rch         rt<<1|1
#define father        int l,int r,int rt
#define lson         l,m,rt<<1
#define rson         m+1,r,rt<<1|1
#define calm         int m = (l+r) >> 1

int n ;
int chd[51000][2];
int val[51000];
vector<int> q[51000];
int li[110000];
int len;

int get(int v) {
    return lower_bound(li,li+len, v) - li + 1;
}

inline void in(int &num){
     char in=getchar();
     while(in<'0'||in>'9'){
           in=getchar();
     }
     num=in-'0';
     in=getchar();
     while(in>='0'&&in<='9'){
           num*=10; num+=in-'0';
           in=getchar();
     }
}

inline void out(int num){
      if(num<0){
            putchar('-');
            num=-num;
      }
      if(num==0){
            putchar('0');
            return;
      }
      char str[20];
      int bas=0;
      for(;num;num/=10) str[bas++]=num%10+'0';
      while(bas--) putchar(str[bas]);
}

struct Segment {
    int sum[111000 << 2];

    void init() {
        memset(sum,0,sizeof(sum));
    }

    void pushup(int rt) {
        sum[rt] = sum[lch] + sum[rch];
    }

    void add(int pos,int val, father) {
        if(l == r) {
            sum[rt] += val;
            return ;
        }
        calm ;
        if(pos <= m)
            add(pos,val,lson);
        else
            add(pos,val,rson);
        pushup(rt);
    }

    int query(int L,int R, father) {
        if(R == 0 || L == len+1)
            return 0;
        if(l >= L && r <= R)
            return sum[rt];
        int ans = 0;
        calm ;
        if(m >= L)
            ans += query(L,R, lson);
        if(m+1 <= R)
            ans += query(L,R, rson);
        return ans;
    }
    bool exist(int pos, father) {
        if(l == r) {
            if(0 == sum[rt])
                return false;
            return true;
        }
        calm ;
        if(pos <= m)
            return exist(pos,lson);
        else
            return exist(pos,rson);
    }
};
Segment ll, rr;

void init() {
    memset(chd,-1,sizeof(chd));
    for(int i = 1; i <= n;i ++)
        q[i].clear();
}

struct Que {
    int v, x;
    Que() {}
    Que(int _v,int _x) : v(_v),x(_x) {}
    int a1 ,a2;
};
Que ans[51000];

void Ans(int Q) {
    for(int i = 0;i < Q;i++) {
        if(-1 == ans[i].a1)
            puts("0");
        else {
            out(ans[i].a1);
            printf(" ");
            out(ans[i].a2);
            puts("");
        }
    }
}

void solve(int k) {
    int x = ans[k].x;
    x = get(x);
    if(true == ll.exist(x,1,len,1) || true == rr.exist(x,1,len,1)) {
        ans[k].a1 = -1;
        return ;
    }
    int small = ll.query(1,x-1,1,len,1), big = ll.query(x+1,len,1,len,1);
    int a1 = 0, a2 = big + 3 * small;
    small = rr.query(1,x-1,1,len,1);
    big = rr.query(x+1,len,1,len,1);
    a1 += small;
    a2 += big + 3 * small;
    ans[k].a1 = a1;
    ans[k].a2 = a2;
}

void dfs(int rt) {
    int size = q[rt].size();
    for(int i = 0; i < size;i++)
        solve(q[rt][i]);
    for(int i = 0 ;i < 2;i++) {
        if(-1 == chd[rt][i])
            continue;
        if(0 == i)
            ll.add(get(val[rt]),1,1,len,1);
        else
            rr.add(get(val[rt]),1,1,len,1);
        dfs(chd[rt][i]);
        
        if(0 == i)
            ll.add(get(val[rt]),-1,1,len,1);
        else
            rr.add(get(val[rt]),-1,1,len,1);
    }
}

int main() {
    int cas, m;
    int u, l ,r;

    in(cas);

    for(int i = 0; i < cas;i++) {
        in(n);
        init();
        for(int f = 1;f <= n; f++) {
            in(val[f]);
            li[f-1] = val[f];
        }

        len = n;
        in(m);
        for(int f = 0;f < m; f++) {
            in(u); in(l); in(r);
            chd[u][0] = l;
            chd[u][1] = r;
        }
        
        int Q;
        in(Q);
        int v ,X;
        for(int f = 0;f < Q; f++) {
            in(v);    in(X);
            q[v].push_back(f);
            ans[f] = Que(v,X);
            li[len ++] = X;
        }
        sort(li ,li + len);
        len = unique(li,li + len) - li;

        ll.init();
        rr.init();
        dfs(1);
        Ans(Q);
    }
    return 0;
}

