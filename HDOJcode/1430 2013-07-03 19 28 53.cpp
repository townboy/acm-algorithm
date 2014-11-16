******************************
    Author : townboy
    Submit time : 2013-07-03 19:28:53
    Judge Status : Accepted
    HDOJ Runid : 8519990
    Problem id : 1430
    Exe.time : 93MS
    Exe.memory : 2968K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<memory.h>
#include<algorithm>
#include<string>
#include<queue>

using namespace std;

char begin[10],end[10];
string ans[50000];

int fac[] = {5040,720,120,24,6,2,1,1};

int conto(string tem){
    int ans = 0 ,exist[10];
    memset(exist,0,sizeof(exist));
    for(int i = 0;i < 8;i++){
        char ch = tem[i];
        int n = ch - '0';
        int num = 0;
        for(int f = 1; f < n; f++)
            if(0 == exist[f])
                num++;
        ans += fac[i]*num;
        exist[n] = 1;
    }
    return ans;
}

string dig = "0123456789";

int init(){
    int to[10];
    string tem = "";
    for(int i = 0 ;i < 8 ;i++)
        to[ begin[i]-'0' ] = i+1; 
    for(int i = 0 ;i < 8 ;i++)
        tem += dig[ to[ end[i]-'0' ] ] ;
    return conto(tem);
}

void debug(){
    cout << begin << endl;
    cout << end << endl;
}

queue<string>q;
queue<int>int_q;

int get[3][8]={
    {7,6,5,4,3,2,1,0},
    {3,0,1,2,5,6,7,4},
    {0,6,1,3,4,2,5,7},
};
string dir = "ABC";

void fun(string old,int state){
    string tem = old;
    for(int i = 0 ;i < 3;i++){
        for(int f = 0;f < 8;f++)
            tem[f] = old[ get[i][f] ];
        int newstate = conto(tem);
        if(0!=newstate && ""==ans[newstate]){
            ans[newstate] = ans[state]+dir[i];
            q.push(tem);
            int_q.push(newstate);
        }
    }
}

void bfs()
{
    int state;
    string tem;
    while(!q.empty()){
        tem = q.front();    q.pop();
        state = int_q.front(); int_q.pop();
        fun(tem,state);
    }
}

int main()
{
    ans[0] = "";
    q.push("12345678");
    int_q.push(0);
    bfs();
    
    while(gets(begin)!=NULL){
        gets(end);
        int state = init();
        cout << ans[state] << endl;
    }
    return 0;
}