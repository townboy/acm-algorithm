******************************
    Author : townboy
    Submit time : 2013-08-07 21:55:05
    Judge Status : Accepted
    HDOJ Runid : 8865177
    Problem id : 4620
    Exe.time : 93MS
    Exe.memory : 304K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<memory.h>
#include<algorithm>
#include<vector>

using namespace std;

struct cut {
    int t, num ,id;
    int apple[10];
    friend bool operator < (cut a, cut b) {
        return a.t < b.t;
    }
};
cut que[35];

int n ,m ,w;

bool exist[210];
vector<int>finalans;
int temans[35], ans;
int maxx[35];

void dfs(int pos,int t ,bool choose,int ret) {
    int change[10], len = 0;
    if(pos == n || t > w || maxx[pos]-pos+1+ret < ans) {
        if(ret > ans) {
            ans = ret;
            finalans.clear();
            for(int i = 0;i < ans;i++)
                finalans.push_back( temans[i] );
        }
        return ;
    }

    int num = que[pos].num;
    int ans = 0;
    for(int i = 0 ;i < num; i++) {
        int id = que[pos].apple[i];
        if(false == exist[id]) {
            exist[id] = true;
            ans ++;
            change[len ++] = id;
        }
    }
    if(ans >= 3) {
        temans[ret] = que[pos].id;
        dfs(pos+1, que[pos+1].t-que[pos].t, false, ret+1);
    }
    for(int i = 0 ;i < len; i++) 
        exist[change[i]] = false;

    if(false == choose)
        dfs(pos+1,t + (que[pos+1].t-que[pos].t),false, ret);
}

void Ans() {
    sort(finalans.begin(),finalans.end());
    int size = finalans.size();
    for(int i = 0 ;i < size;i++) {
        if(0 != i)
            cout << " " ;
        cout << finalans[i];
    }
    cout << endl;
}

void init() {
    maxx[n-1] = n-1;
    for(int i = n-2 ;i > -1;i--)
        if(que[i+1].t - que[i].t > w || que[i].num < 3)
            maxx[i] = i;
        else
            maxx[i] = maxx[i+1];    
}

int solve() {
    finalans.clear();
    ans = 0;
    init();

    for(int i = 0 ;i < n;i++) {
        memset(exist,false,sizeof(exist));
        dfs(i,0,true,0);
    }
    cout << ans << endl;
    Ans();
    return ans;
}

int main() {
    int cas;
    cin >> cas;
    for(int i = 0 ;i < cas;i++) {
        scanf("%d%d%d",&n,&m,&w);
        for(int f = 0;f < n;f++) {
            que[f].id = f+1;
            scanf("%d%d",&que[f].num,&que[f].t);
            for(int g = 0 ;g < que[f].num; g++)
                scanf("%d",&que[f].apple[g]);
        }
        sort(que,que+n);
        solve();
    }
    return 0;
}
