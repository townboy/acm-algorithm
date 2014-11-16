******************************
    Author : townboy
    Submit time : 2013-08-13 21:56:04
    Judge Status : Accepted
    HDOJ Runid : 8933741
    Problem id : 4666
    Exe.time : 9687MS
    Exe.memory : 13964K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<memory.h>
#include<set>

using namespace std;

int k;
multiset<int>s[32];
int ji;

int p[61000][5];

void init() {
    for(int i = 0 ;i < 32;i++)
        s[i].clear();
    ji = 0;
}

void debug() {
    multiset<int> :: iterator it;
    for(it = s[3].begin(); it != s[3].end(); it++)
        cout << *it << " ";
    cout << endl;
}

void dfs(int pos,int sum,int dis,bool add,int aim) {
    if(k == pos) {
        if(true == add)
            s[sum].insert(dis);
        else
            s[sum].erase(s[sum].find(dis));
        return ;
    }
    dfs(pos+1,sum*2+1,dis+p[aim][pos],add,aim);
    dfs(pos+1,sum*2,dis-p[aim][pos],add,aim);
}

void ans() {
    int ans = 0;
    for(int i = 0;i < (1<<k);i++) {
        if(1 < s[i].size()) {
            multiset<int> :: iterator it;
            it = s[i].end();
            it --;
            ans = max(ans,*it - *s[i].begin());
        }
    }
    printf("%d\n",ans);
}

void fun() {
    int t ;
    cin >> t ;
    ji ++;
    if(0 == t) {
        for(int i = 0; i < k;i++)
            scanf("%d",&p[ji][i]);
        dfs(0,0,0,true,ji);
    }
    else {
        cin >> t;
        dfs(0,0,0,false,t);
    }
    ans();
}

int main() {
    int q;
    while(cin >> q >> k) {
        init();
        for(int i = 0 ;i < q;i++)
            fun();
    }
    return 0;
}
