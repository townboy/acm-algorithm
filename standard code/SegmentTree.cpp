//3.2线段树

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

