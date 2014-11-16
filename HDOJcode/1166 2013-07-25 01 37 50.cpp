******************************
    Author : townboy
    Submit time : 2013-07-25 01:37:50
    Judge Status : Accepted
    HDOJ Runid : 8701113
    Problem id : 1166
    Exe.time : 218MS
    Exe.memory : 828K
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

typedef vector<int>     VI;
#define f(i,l,r)            for(int i = l;i < r;i++)
#define F(i,l,r)            for(int i = l;i <= r;i++)
#define pb(x)                 push_back(x)

#define lch         rt<<1
#define rch         rt<<1|1
#define father        int l,int r,int rt
#define lson         l,m,rt<<1
#define rson         m+1,r,rt<<1|1
#define calm         int m = (l+r) >> 1
void read(char *a) {    freopen(a,"r",stdin);}
void write(char *a) {    freopen(a,"w",stdout);}

#define maxn 51000

int n;
int sum[maxn << 2];

void pushup(int rt) {
    sum[rt] = sum[lch] + sum[rch];
}

void build(father) {
    if(l == r) {
        scanf("%d",sum+rt);
        return ;
    }
    calm ;
    build(lson);
    build(rson);
    pushup(rt);
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
    if(l >= L && r <= R)
        return sum[rt];
    calm ;
    int ans = 0;
    if(m >= L)
        ans += query(L,R,lson);
    if(m+1 <= R)
        ans += query(L,R,rson);
    return ans;
}

void debug( father) {
    if(l == r) {
        cout << l << " " << sum[rt] << endl;
        return ;
    }
    calm;
    debug(lson);
    debug(rson);
}

int main() {
    int a ,b;
    int cas;
    cin >> cas;
    for(int i = 0 ; i < cas;i++) {
        printf("Case %d:\n",i+1);
        scanf("%d",&n);
        build(1,n,1);

        char ch[10];
        while(scanf("%s",ch) != EOF) {
            if('E' == ch[0])
                break;
            scanf("%d%d",&a,&b);
            if('A' == ch[0])
                add(a,b,1,n,1);
            else if('S' == ch[0])
                add(a,-b,1,n,1);
            else
                printf("%d\n",query(a,b,1,n,1));
        }
    }
    return 0;
}

