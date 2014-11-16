******************************
    Author : townboy
    Submit time : 2013-07-08 20:59:42
    Judge Status : Accepted
    HDOJ Runid : 8548556
    Problem id : 3729
    Exe.time : 203MS
    Exe.memory : 1172K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<memory.h>
#include<algorithm>

using namespace std;

int n;
int match[110000],mk[110000];
int tt[70][2];

int dfs(int x){
    for(int i = tt[x][0]; i <= tt[x][1] ;i++){
        if( 0 == mk[i]){
            mk[i] = 1;
            int t = match[i];
            match[i] = x;
            if(-1==t || 1 ==dfs(t))
                return 1;
            match[i] = t;
        }
    }
    return 0;
}

int choose[70];

int xyl(){
    int ans = 0 ; 
    memset(match, -1 ,sizeof(match));
    for(int i = n-1;i >= 0 ;i--){
        memset(mk,0,sizeof(mk));
        if(1 == dfs(i)){
            choose[i] = 1;
            ans++;
        }
    }
    return ans;
}

void ans(){
    int flag = 0;
    for(int i = 0; i < n; i++){
        if(0 == choose[i])
            continue;
        if(1 == flag)
            cout << " " ;
        cout << i+1;
        flag = 1;
    }
    cout << endl;
}

int main(){
    int cas;
    cin >> cas;
    for(int i = 0 ; i < cas; i++){
        cin >> n;
        memset(choose,0,sizeof(choose));
        for(int f = 0 ;f < n; f++)
            cin >> tt[f][0] >> tt[f][1];
        cout << xyl() << endl;
        ans();
    }
    
    return 0;
}
