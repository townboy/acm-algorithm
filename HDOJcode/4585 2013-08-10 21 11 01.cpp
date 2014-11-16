******************************
    Author : townboy
    Submit time : 2013-08-10 21:11:01
    Judge Status : Accepted
    HDOJ Runid : 8899662
    Problem id : 4585
    Exe.time : 187MS
    Exe.memory : 3444K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<set>
#include<map>
#include<memory.h>

using namespace std;

typedef pair<int,int> PII;

map<int,int>mp;

void init() {
    mp.clear();
    mp[1000000000] = 1;
}

void fun(int id,int score) {
    map<int,int>:: iterator it; 
    it = mp.lower_bound(score);
    int diff = it->first - score;
    if(it != mp.begin()) {
        it --;
        if(score - it->first > diff)
            it ++;
    }
    printf("%d %d\n",id,it->second);
    mp[score] = id;
}

int main() {
    int n;
    int id, score;
    while(cin >> n, n) {
        init();
        for(int i = 0 ;i < n;i++) {
            scanf("%d%d",&id,&score);
            fun(id,score);
        }
    }
    return 0;
}

