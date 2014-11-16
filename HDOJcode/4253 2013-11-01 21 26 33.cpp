******************************
    Author : townboy
    Submit time : 2013-11-01 21:26:33
    Judge Status : Accepted
    HDOJ Runid : 9476256
    Problem id : 4253
    Exe.time : 1625MS
    Exe.memory : 1716K
    https://github.com/townboy
******************************


#include <stdio.h>
#include <iostream>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <assert.h>

using namespace std;

#define maxe 100010
#define INF 1000
#define maxn 51000

int n ,m ,k;
struct Node {
    int u ,v;
    int w;
    Node () {}
    Node (int u,int v,int w) : u(u), v(v), w(w) {}
    friend bool operator < (Node a, Node b) {
        return a.w < b.w;
    }
};
Node telecom[maxe], unicom[maxe];
int st ,su;

void read() {
    int u ,v, w, t;
    for(int i = 0 ;i < m;i ++) {
        scanf("%d%d%d%d",&u,&v,&w,&t);
        if(0 == t) {
            telecom[st] = Node (u,v,w);
            st ++;
        }
        else {
            unicom[su] = Node (u,v,w);
            su ++;
        }
    }
    sort(telecom,telecom + st);
    sort(unicom,unicom + su);
}

int set[maxn];

void init() {
    for(int i = 0;i < n;i++)
        set[i] = i;
}

int find(int x) {
    return x == set[x] ? x : set[x] = find(set[x]);
}

void merge(int u ,int v) {
    set[u] = v;
}

int ret ;

struct findmin {
    int ft, fu;
    int delta ;
    void init(int tt) {
        ft = fu = 0;
        delta = tt;
    }
    pair<int ,int> next() {
        if(ft == st)
            return make_pair(1,fu ++);
        if(fu == su)
            return make_pair(0,ft ++);
        if(telecom[ft].w + delta < unicom[fu].w)
            return make_pair(0,ft ++);
        return make_pair(1,fu ++);
    }
};

struct findmax {
    int ft, fu;
    int delta ;
    void init(int tt) {
        ft = fu = 0;
        delta = tt;
    }
    pair<int ,int> next() {
        if(ft == st)
            return make_pair(1,fu ++);
        if(fu == su)
            return make_pair(0,ft ++);
        if(telecom[ft].w + delta <= unicom[fu].w)
            return make_pair(0,ft ++);
        return make_pair(1,fu ++);
    }
};

int MIN(int delta) {
    init();
    ret = 0;
    int use = 0;
    findmin tt;
    tt.init(delta);
    int kuai = n;
    for(int i = 0 ;i < m;i++) {
        pair<int ,int> now = tt.next();
        int no = now.second;
        int u ,v, w;
        if(0 == now.first) {
            u = telecom[no].u;
            v = telecom[no].v;
            w = telecom[no].w + delta;
        }
        else {
            u = unicom[no].u;
            v = unicom[no].v;
            w = unicom[no].w;
        }

        if(find(u) != find(v)) {
            ret += w;
            merge(find(u), find(v));
            if(0 == now.first)
                use ++;
            kuai --;
            if(1 == kuai)
                return use;
        }
    }
    return use;
}

int MAX(int delta) {
    init();
    ret = 0;
    int use = 0;
    findmax tt;
    tt.init(delta);
    int kuai = n;
    for(int i = 0 ;i < m;i++) {
        pair<int ,int> now = tt.next();
        int no = now.second;
        int u ,v, w;
        if(0 == now.first) {
            u = telecom[no].u;
            v = telecom[no].v;
            w = telecom[no].w + delta;
        }
        else {
            u = unicom[no].u;
            v = unicom[no].v;
            w = unicom[no].w;
        }

        if(find(u) != find(v)) {
            ret += w;
            merge(find(u), find(v));
            if(0 == now.first)
                use ++;
            kuai --;
            if(1 == kuai)
                return use;
        }
    }
    return use;
}

int solve() {
    int l = -INF , r = INF;
    while(l != r-1) {
        int mid = (l + r) >> 1;
        int minn = MIN(mid);
        int tt = ret;
        int maxx = MAX(mid);
        if( minn <= k && maxx >= k)
            return ret - k * mid;
        if(minn > k)
            l = mid;
        else
            r = mid;
    }
    return -1;
}

int main() {
    int cas = 0;
    while(cin >> n >> m >> k) {
        cas ++;
        st = su = 0;
        read();
        printf("Case %d: ",cas);
        cout << solve() << endl;
    }
    return 0;
}

