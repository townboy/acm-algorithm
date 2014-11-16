******************************
    Author : townboy
    Submit time : 2013-09-29 15:33:04
    Judge Status : Accepted
    HDOJ Runid : 9247289
    Problem id : 3726
    Exe.time : 906MS
    Exe.memory : 6192K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<memory.h>

using namespace std;

struct Node {
    Node *ch[2];
    int r;
    int v;
    int s;
    Node(int v):v(v) {
        ch[0] = ch[1] = NULL;
        r = rand();
        s = 1;
    }
    bool operator < (const Node& rhs) const {
        return r < rhs.r;
    }
    int cmp(int x) const {
        if(x == v)    return -1;
        return x < v ? 0 : 1;
    }
    void maintain() {
        s = 1;
        if(ch[0] != NULL)
            s += ch[0]->s;
        if(ch[1] != NULL)
            s += ch[1]->s;
    }
};

void rotate(Node* & o,int d) {
    Node* k = o->ch[d^1];
    o->ch[d^1] = k->ch[d];
    k->ch[d] = o;
    o->maintain();
    k->maintain();
    o = k;
}

void insert(Node* & o,int x) {
    if(o == NULL) 
        o = new Node(x);
    else {
        int d = (x < o->v ? 0 : 1);
        insert(o->ch[d],x);
        if(*o < *o->ch[d])
            rotate(o,d^1);
    }
    o->maintain();
}

void remove(Node* & o,int x) {
    int d = o->cmp(x);
    if(-1 == d) {
        Node* u = o;
        if(o->ch[0] != NULL && o->ch[1] != NULL) {
            int d2 = (*o->ch[1] < *o->ch[0] ? 1 : 0);
            rotate(o,d2);
            remove(o->ch[d2],x);
        }
        else {
            if(o->ch[0] == NULL) 
                o = o->ch[1];
            else
                o = o->ch[0];
            delete u;
        }
    }
    else
        remove(o->ch[d],x);
    if(o != NULL)
        o->maintain();
}

bool find(Node* o,int x) {
    while(o != NULL) {
        int d = o->cmp(x);
        if(-1 == d)
            return true;
        o = o->ch[d];
    }
    return false;
}

int kth(Node* o,int k) {        //  ÕÒµ½µÚK´óµÄÔªËØ
    if(o == NULL || k <= 0 || k > o->s)
        return 0;
    int s = (o->ch[1] == NULL ? 0 : o->ch[1]->s);
    if(k == s+1)
        return o->v;
    else if(k <= s)
        return kth(o->ch[1],k);
    else
        return kth(o->ch[0],k-s-1);
}

int rank(Node* o,int x) {        //·µ»Ø¸ºÊýËµÃ÷²»´æÔÚ
    int ret = 1;
    while(o != NULL) {
        int d = o->cmp(x);
        if(-1 == d)
            return ret + (o->ch[0] == NULL ? 0 : o->ch[0]->s);
        if(1 == d)
            ret += 1 + (o->ch[0] == NULL ? 0 : o->ch[0]->s);
        o = o->ch[d];
    }
    return -1;
}

int n ,m;
pair<int,int>edge[61000];
int wei[21000];
bool exist[61000];

struct Command{
    int type;
    int a,b;
    Command(){}
    Command(int _type,int _a,int _b) : type(_type),a(_a),b(_b) {}; 
};
Command op[510000];

int cnt_query;

void read() {
    int u ,v;
    for(int i = 1;i <= n;i++)
        scanf("%d",wei+i);
    for(int i = 1;i <= m;i++) {
        scanf("%d%d",&u,&v);
        edge[i] = make_pair(u,v);
    }
    memset(exist,true,sizeof(exist));
}

int set[21000];
int find(int x) {
    return x == set[x] ? x : set[x] = find(set[x]);
}
void merge(int a,int b) {
    set[b] = a;
}

Node * root[21000];

void removetree(Node* &root) {
    if(NULL == root)
        return ;
    removetree(root->ch[0]);
    removetree(root->ch[1]);
    delete root;
    root = NULL;
}

void movetree(Node* &to,Node* &from) {
    if(NULL == from)
        return;
    movetree(to,from->ch[0]);
    movetree(to,from->ch[1]);
    insert(to,from->v);
    delete(from);
    from = NULL;
}

void add_edge(int u,int v) {
    int uu = find(u);
    int vv = find(v);
    if(uu == vv)
        return;
    if(root[uu]->s > root[vv]->s) {
        merge(uu,vv);
        movetree(root[uu],root[vv]);
    }
    else {
        merge(vv,uu);
        movetree(root[vv],root[uu]);
    }
}

void init() {
    for(int i = 1;i <= n;i++) {
        removetree(root[i]);
        root[i] = new Node(wei[i]);
        set[i] = i;
    }
    for(int i = 1;i <= m;i++)
        if(true == exist[i])
            add_edge(edge[i].first,edge[i].second);
}

void solve() {
    char ch[10];
    int a,b;
    cnt_query = 0;
    int sum = 0;
    while(scanf("%s",ch),'E' != ch[0]) {
        if('Q' == ch[0]) {
            scanf("%d%d",&a,&b);
            op[sum] = Command(0,a,b);
        }
        else if('D' == ch[0]) {
            scanf("%d",&a);
            op[sum] = Command(1,a,0);
            exist[a] = false;
        }
        else {
            scanf("%d%d",&a,&b);
            op[sum] = Command(2,a,wei[a]);
            wei[a] = b;
        }
        sum ++;
    }

    init();
    long long ret = 0;
    for(int i = sum - 1;i >= 0; i--) {
        if(0 == op[i].type) {
            int x = op[i].a;
            int k = op[i].b;
            x = find(x);
            cnt_query ++;
            ret += (long long)kth(root[x],k);
        }
        else if(1 == op[i].type) {
            int x = op[i].a;
            add_edge(edge[x].first,edge[x].second);
        }
        else {
            int x = op[i].a;
            int v = op[i].b;
            int rt = find(x);
            remove(root[rt],wei[x]);
            insert(root[rt],v);
            wei[x] = v;
        }
    }
    printf("%.6lf\n",(double) ret / (double)cnt_query);
}

int main() {
    int cas = 0;
    while(cin >> n >> m, n+m) {
        read();
        cas ++;
        printf("Case %d: ",cas);
        solve();
    }
    return 0;
}

