******************************
    Author : townboy
    Submit time : 2013-10-10 20:50:28
    Judge Status : Accepted
    HDOJ Runid : 9313775
    Problem id : 1255
    Exe.time : 578MS
    Exe.memory : 488K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<memory.h>

using namespace std;

int n ,m;
double pos[2100];

struct node {
    double l,r,x;
    bool ru;
    node () {}
    node (double l,double r,double x,bool ru) : l(l),r(r),x(x),ru(ru) {}
    friend bool operator < (node a,node b) {
        return a.x < b.x;
    }
}Q[2100];

void read() {
    double l ,d, r, u; 
    for(int i = 0 ;i < n;i++) {
        scanf("%lf%lf%lf%lf",&l,&d,&r,&u);
        Q[i<<1] = node(l ,r, d, true);
        Q[i<<1|1] = node(l ,r, u, false);
        pos[i<<1] = l;
        pos[i<<1|1] = r;
    }
    sort(Q,Q+2*n);
    sort(pos,pos+2*n);
    m = unique(pos,pos+2*n) - pos;
}

int cnt[2100 << 2];
double sum[2100 << 2];

#define father int l,int r,int rt
#define lson l , m , rt << 1
#define rson m+1, r, rt<<1|1
#define lch rt << 1
#define rch rt << 1 | 1

void pushup(father) {
    if(cnt[rt] > 1)
        sum[rt] = pos[r] - pos[l-1];
    else
        sum[rt] = sum[lch] + sum[rch];
}

double query(int L,int R, father) {
    double ret = 0;
    if(l >= L && r <= R)
        return sum[rt];
    int m = (l+r) >> 1;
    if(L < m)
        ret += query(L,R,lson);
    if(R >= m+1)
        ret += query(L,R,rson);
    return ret;
}

void update(int L,int R,int c,father) {
    if(l >= L && r <= R) {
        cnt[rt] += c;
        pushup(l,r,rt);
        return ;
    }
    int m = (l+r) >> 1;
    if(L < m) 
        update(L,R,c,lson);
    if(R >= m+1)
        update(L,R,c,rson);
    pushup(l,r,rt);
}

void update(int l,int r,int c) {
    for(int i = l;i <= r;i++)
        cnt[i] += c;
}

double val[2100];

double query() {
    double ret = 0;
    for(int i = 1;i < m;i++)
        if(cnt[i] > 1)
            ret += val[i];
    return ret;
}

double solve() {
    double ret = 0;
    memset(cnt,0,sizeof(cnt));
    memset(sum,0,sizeof(sum));

    for(int i = 1;i < m;i++)
        val[i] = pos[i] - pos[i-1];
    
    for(int i = 0 ;i < 2*n ;i++) {
        double l = Q[i].l;
        double r = Q[i].r;
        int ll = lower_bound(pos,pos+m,l) - pos;
        int rr = lower_bound(pos,pos+m,r) - pos;
        bool ru = Q[i].ru;

        if(true == ru)
            update(ll+1,rr,1);
        //    update(ll+1,rr,1,1,m-1,1);
        else
            update(ll+1,rr,-1);
        //    update(ll+1,rr,-1,1,m-1,1);

        ret += (Q[i+1].x - Q[i].x) * query();
        //ret += (Q[i+1].x - Q[i].x) * query(1,m-1,1,m-1,1);
    }
    return ret;
}

int main() {
    int cas;
    cin >> cas;
    for(int i = 0 ;i < cas;i++) {
        cin >> n;
        read();
        printf("%.2lf\n",solve());
    }
    return 0;
}

