******************************
    Author : townboy
    Submit time : 2013-09-21 20:40:58
    Judge Status : Accepted
    HDOJ Runid : 9207440
    Problem id : 3234
    Exe.time : 375MS
    Exe.memory : 1488K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<memory.h>
#include<vector>
#include<queue>

using namespace std;

#define maxn 21000

int n ,m;
int set[maxn] ,dis[maxn];
int val[maxn];
vector<int>G[maxn] ,cost[maxn];
bool vis[maxn];

void init() {
    for(int i = 0 ;i < n;i++) {
        set[i] = i;
        G[i].clear();
        cost[i].clear();
    }
    memset(val,-1,sizeof(val));
    memset(vis,false,sizeof(vis));
}

void bfs(int st ,int v) {
    queue <int> q;
    q.push(st);
    vis[st] = true;
    val[st] = v;
    while(!q.empty()) {
        int v = q.front(); q.pop();
        int size = G[v].size();
        for(int i = 0 ;i < size; i++) {
            int to = G[v][i] , len = cost[v][i];
            if(true == vis[to])
                continue;
            vis[to] = true;
            val[to] = len ^ val[v];
            q.push(to);
        }
    }
}

int cnt;

pair<int,int> find(int x) {
    int len = 0;
    while(set[x] != x) {
        len ^= dis[x];
        x = set[x];
    }
    return make_pair(x,len);
}

void merge(int uu,int vv,int len) {
    //cout << "merge " << uu << " " << vv << " " << len << endl;
    set[vv] = uu;
    dis[vv] = len;
    G[uu].push_back(vv);
    cost[uu].push_back(len);
    G[vv].push_back(uu);
    cost[vv].push_back(len);
}

bool handle(vector<int> tt) {
    if(2 == tt.size()) {
        int p = tt[0] , v = tt[1];
        if(-1 != val[p]) {
            if(val[p] != v) {
                printf("The first %d facts are conflicting.\n",cnt);
                return true;
            }
        }
        else
            bfs(p,v);
    }
    else {
        int p = tt[0], q = tt[1], v = tt[2];
        if(-1 != val[p] && -1 != val[q]) {
            if( (val[p] ^ val[q]) != v) {
                printf("The first %d facts are conflicting.\n",cnt);
                return true;
            }
        }
        else if(-1 != val[p] || -1 != val[q]) {
            if(-1 == val[p])
                bfs(p,v ^ val[q]);
            else
                bfs(q,v ^ val[p]);
        }
        else { // ºÏ²¢
            pair<int,int> pp = find(p);
            pair<int,int> qq = find(q);
            int uu = pp.first;
            int vv = qq.first;
            if(uu == vv) {
                int len = (qq.second ^ pp.second);
                if(len != v) {
                    printf("The first %d facts are conflicting.\n",cnt);
                    return true;
                }
            }
            else {
                int len = (qq.second ^ pp.second ^ v);
                merge(uu,vv,len);
            }
        }
    }
    return false;
}

void ask(vector<int> tt) {
    int size = tt.size();
    int sum = 0;
    vector< pair<int,int> > s;
    pair<int,int> tem;
    for(int i = 0 ;i < size;i++) {
        int v = tt[i];
        if(-1 != val[v])
            sum ^= val[v];
        else
            s.push_back(find(v));
    }

    size = s.size();
    if(1 == size%2) {
        cout << "I don't know." << endl;
        return ;
    }
    sort(s.begin(),s.end());
    for(int i = 0 ;i < size; i+=2) {
        if(s[i].first != s[i+1].first) {
            cout << "I don't know." << endl;
            return ;
        }
        sum ^= (s[i].second ^ s[i+1].second);
    }
    printf("%d\n",sum);
}

void solve() {
    char type[10] ,t ,ch[100];
    vector <int> tt;
    bool end = false;
    cnt = 0;
    for(int i = 0;i < m;i++) {
        scanf("%s",type);
        tt.clear();
        if('I' == type[0]) {
            int a, b, c;
            cnt ++;
            gets(ch);
            int num = sscanf(ch,"%d%d%d",&a,&b,&c);
            tt.push_back(a);
            tt.push_back(b);
            if(3 == num)
                tt.push_back(c);

            if(true == end) 
                continue;
            end = handle(tt);
        }
        else {
            int k, tem;
            scanf("%d",&k);
            for(int i = 0 ;i < k;i++) {
                cin >> tem;
                tt.push_back(tem);
            }
            if(true == end)
                continue;
            ask(tt);
        }
    }
}

int main() {
    int cas = 0;
    while(cin >> n >> m, n+m) {
        init();
        cas ++;
        printf("Case %d:\n",cas);
        solve();
        cout << endl;
    }
    return 0;
}
