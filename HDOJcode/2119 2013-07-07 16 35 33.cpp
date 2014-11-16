******************************
    Author : townboy
    Submit time : 2013-07-07 16:35:33
    Judge Status : Accepted
    HDOJ Runid : 8539955
    Problem id : 2119
    Exe.time : 125MS
    Exe.memory : 360K
    https://github.com/townboy
******************************


#include<iostream>
#include<memory.h>
#include<algorithm>
#include<stdio.h>

#define maxn 110
using namespace std;

int map[maxn][maxn],match[maxn],mk[maxn];
int a,b;
    
int dfs(int x){
    for(int i = 0;i < b;i++){
        if(1==map[x][i] && 0==mk[i]){
            mk[i] = 1;
            int t = match[i];
            match[i] = x;
            if(-1==t || 1==dfs(t))
                return 1;
            match[i] = t;
        }
    }
    return 0;    
}    

int xyl(){
    int ans = 0;
    for(int i = 0 ;i < a;i++){
        memset(mk,0,sizeof(mk));
        if(1 == dfs(i))
            ans++;
    }
    return ans;
}

void init(){
    memset(map,0,sizeof(map));
    memset(match,-1,sizeof(match));
}

int main(){
    while(cin >> a,a){
        cin >> b;
        init();
        for(int i = 0 ;i < a ;i++)
            for(int f = 0 ;f < b ;f++)
                cin >> map[i][f];
        cout << xyl() << endl;
    }
    return 0;
}
