******************************
    Author : townboy
    Submit time : 2013-09-11 20:05:29
    Judge Status : Accepted
    HDOJ Runid : 9151344
    Problem id : 4721
    Exe.time : 296MS
    Exe.memory : 9244K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<memory.h>
#include<algorithm>

using namespace std;

#define maxx 510

int n ,m, r ,q;
int a[maxx][maxx], b[maxx][maxx];

struct node {
    int in[maxx][maxx];
    void fun() {
        for(int i = 1;i <= n;i++) 
            for(int f = 1;f <= m;f++)
                in[i][f] += in[i-1][f] + in[i][f-1] - in[i-1][f-1];
    }

    int getsum(int n0,int m0,int n1,int m1) {
        return in[n0][m0] - in[n0][m1-1]- in[n1-1][m0] + in[n1-1][m1-1];
    }
};
node A,B;

int sa[maxx][maxx], sb[maxx][maxx];

void read() {
    for(int i = 1;i <= n;i++) 
        for(int f = 1;f <= m;f++)
            scanf("%d",&A.in[i][f]);
    A.fun();

    for(int i = 1;i <= n;i++) 
        for(int f = 1;f <= m;f++)
            scanf("%d",&B.in[i][f]);
    B.fun();

    for(int i = 1;i <= n;i++)
        for(int f = 1;f <= m;f++) {
            sa[i][f] = A.getsum(min(n,i+r) , min(m,f+r), max(1,i-r) , max(1,f-r));
            sb[i][f] = B.getsum(min(n,i+r) , min(m,f+r), max(1,i-r) , max(1,f-r));
        }
}

struct node2 {
    int a, b, diff;
    node2() {}
    node2(int tt){
        diff = tt;
    }
    friend bool operator < (node2 a, node2 b) {
        return a.diff < b.diff;
    }
};

node2 que[300000];
int leftmax[300000];
int rightmax[300000];

#define INF 0x3f3f3f3f

void handle() {
    int sum = 0;
    for(int i = 1;i <= n;i++)
        for(int f = 1;f <= m;f++) {
            que[sum].a = sa[i][f];
            que[sum].b = sb[i][f];
            que[sum].diff = sa[i][f] - sb[i][f];
            sum ++;
        }
    sort(que,que+sum);

    leftmax[0] = que[0].a;
    for(int i = 1 ;i < sum;i++)
        leftmax[i] = max(leftmax[i-1], que[i].a);

    rightmax[sum-1] = que[sum-1].b;
    for(int i = sum-2 ;i >= 0; i --)
        rightmax[i] = max(rightmax[i+1], que[i].b);
}

void solve() {
    int a, b;
    handle();
    for(int i = 0 ; i < q;i++) {
        scanf("%d%d",&a,&b);
        int diff = b - a;
        int pos = lower_bound(que, que+n*m ,node2(diff)) - que;
        int ans ;
        if(0 == pos)
            ans = rightmax[pos]+b;
        else if(n*m == pos)
            ans = leftmax[pos-1]+a;
        else
            ans = max(leftmax[pos-1]+a,rightmax[pos]+b);
        printf("%d\n",ans);
    }
}

void init() {
    memset(A.in,0,sizeof(A.in));
    memset(B.in,0,sizeof(B.in));
}

int main() {
    int cas;
    cin >> cas;
    init();
    for(int i = 0 ;i < cas;i++) {
        cin >>  n >> m >> r >> q;
        if(0 != i)
            puts("");
        printf("Case #%d:\n",i+1);
        read();
        solve();
    }
    return 0;
}
