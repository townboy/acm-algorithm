******************************
    Author : townboy
    Submit time : 2013-08-20 00:22:48
    Judge Status : Accepted
    HDOJ Runid : 9010292
    Problem id : 4679
    Exe.time : 1000MS
    Exe.memory : 17340K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<memory.h>
#include<vector>

using namespace std;

#define maxn 110000

vector<int> ID[maxn];

int edge[maxn][2];
int maxdown[maxn];
int maxdandown[maxn];
int n;

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

void read() {
    int u ,v, w;
    for(int i = 0 ;i < n-1; i++) {
        in(u); in(v); in(w);
        edge[i][0] = u ^ v;
        edge[i][1] = w;
        ID[u].push_back(i);
        ID[v].push_back(i);
    }
}

void init() {
    for(int i = 1;i <= n;i++)
        ID[i].clear();
}

struct Max {
    int val[3];
    int from[3];
    void init() {
        memset(val,-1,sizeof(val));
        memset(from,-1,sizeof(from));
    }

    void push(int x,int id) {
        for(int i = 0 ;i < 3; i++) {
            if(x > val[i]) {
                for(int f = 2;f > i; f--) {
                    val[f] = val[f-1];
                    from[f] = from[f-1];
                }
                val[i] = x;
                from[i] = id;
                break;
            }
        }
    }
    int getlong() {
        return val[0] + val[1] + 2;
    }
    int getdanlong() {
        return val[0] + 1;
    }
    int getone(int v) {
        for(int i = 0 ;i < 3; i++) {
            if(from[i] != v)
                return val[i] + 1;
        }
    }
    int gettwo(int v) {
        int sum = 0 ,ans = 0;
        for(int i = 0 ;i < 3; i++) {
            if(from[i] != v) {
                sum ++;
                ans += val[i]+1;
            }
            if(2 == sum)
                return ans;
        }
    }
};

int dfsdown(int rt, int fa) {
    int size = ID[rt].size();
    Max t;
    t.init();
    for(int i = 0 ;i < size; i++) {
        int id = ID[rt][i];
        int v = rt ^ edge[id][0];
        if(v == fa)
            continue;
        t.push(dfsdown(v,rt),v);
    }
    maxdown[rt] = t.getlong();
    return maxdandown[rt] = t.getdanlong();
}

int ans ,ansid;

void dfsup(int rt,int fa,int falen) {
    int size = ID[rt].size();

    Max t;
    t.init();
    t.push(falen, -1);

    for(int i = 0;i < size; i++) {
        int id = ID[rt][i];
        int v = rt ^ edge[id][0];
        if(v == fa)
            continue;
        t.push(maxdandown[v],v);
    }

    for(int i = 0;i < size; i++) {
        int id = ID[rt][i];
        int v = rt ^ edge[id][0];
        int w = edge[id][1];
        if(v == fa)
            continue;
        int maxx = max(maxdown[v] , t.gettwo(v));
        int ret = maxx * w;
        if(ret < ans || (ret==ans && id < ansid)) {
            ans = ret;
            ansid = id;
        }
    }

    for(int i = 0;i < size; i++) {
        int id = ID[rt][i];
        int v = rt ^ edge[id][0];
        if(v == fa)
            continue;
        dfsup(v,rt,t.getone(v));
    }
}

#define INF 0x3f3f3f3f

int solve() {
    dfsdown(1,-1);
    ans = INF;
    dfsup(1,-1,-1);
    return ansid + 1;
}

int main() {
    int cas;
    int size = 256 << 20; // 256MB  
    char *p = (char*)malloc(size) + size;  
    __asm__("movl %0, %%esp\n" :: "r"(p));  
    cin >> cas;
    for(int i = 0 ;i < cas;i ++) {
        cin >> n;
        init();
        read();
        printf("Case #%d: ",i+1);
        printf("%d\n",solve());
    }
    return 0;
}
