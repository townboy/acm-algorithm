******************************
    Author : townboy
    Submit time : 2013-07-08 18:31:44
    Judge Status : Accepted
    HDOJ Runid : 8547332
    Problem id : 3720
    Exe.time : 2156MS
    Exe.memory : 320K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<memory.h>
#include<algorithm>
#include<string>
#include<map>
#define INF 0x3f3f3f3f
using namespace std;

struct node{
    int flag;
    int val;
    friend bool operator < (node a, node b){
        return a.flag < b.flag;
    }
};
node player[23];

string lei[4];

int get(string ru){
    for(int i = 0 ; i < 4; i++)
        if(lei[i] == ru)
            return i;
}

int choose[23];
int ans;
map<string,int>mp;
int add[23][23];
int now[4];
int lim[4] = {1,4,4,2};

int check(){
    for(int i = 0 ;i < 4 ;i++)
        if(now[i] != lim[i])
            return 0;
    return 1;
}

void debug(){
    for(int i = 0 ; i < 23;i++)
        cout << choose[i] << " ";
    cout << endl;
}

void dfs(int d,int sum){
    if(23 == d){
        if(1 == check()){
            ans = max(ans,sum);
        }
         return ;
    }
    int flag = player[d].flag;
    
    dfs(d+1,sum);
    
    if(lim[flag] != now[flag]){
        int duo = 0;
        for(int i = 0; i < 23 ;i++)
            if(1 == choose[i])
                duo += add[d][i];
        choose[d] = 1;
        now[flag] ++;
        dfs(d+1,sum + duo + player[d].val);
        choose[d] = 0;
        now[flag] --;
    }
}


void init(){
    mp.clear();
}
    
int main(){
    
    lei[0] = "goalkeeper";
    lei[1] = "defender";
    lei[2] = "midfielder";
    lei[3] = "striker";
        

    string name,tem;
    while(cin >> name){
        
        init();
        mp[name] = 0;
        cin >> player[0].val;
        cin >> tem;
        player[0].flag = get(tem);
        for(int i = 1 ;i < 23;i++){
            cin >> name;
            mp[name] = i;
            cin >> player[i].val;
            cin >> tem;
            player[i].flag = get(tem);    
        }
        
        int n,val;
        cin >> n;
        string a,b;
        
        memset(add,0,sizeof(add));
        for(int i = 0 ; i<n ;i++){
            cin >> a >> b;
            cin >> val;
            add[ mp[a] ][ mp[b] ] = val;
            add[ mp[b] ][ mp[a] ] = val; 
        }
    
        ans = -INF;
        memset(now,0,sizeof(now));
        dfs(0,0);
        if(-INF == ans)
            cout << "impossible" << endl;
        else
            cout << ans << endl;
    }
    return 0;
}