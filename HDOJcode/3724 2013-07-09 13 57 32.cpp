******************************
    Author : townboy
    Submit time : 2013-07-09 13:57:32
    Judge Status : Accepted
    HDOJ Runid : 8551914
    Problem id : 3724
    Exe.time : 593MS
    Exe.memory : 1924K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>
#include<memory.h>

using namespace std;

int fac[8] = {128,64,32,16,8,4,2,1};

char ch[11000];
char qian[40];
int fun(double asc[8]){
    double tem = asc[0];
    int sum = 0 ;
    for(int i = 1; i < 8; i++)
        if(asc[i] > tem*1.5)
            sum += fac[i];
    return sum;
}

int len ,num[100000];
int size,next[100000][26];

int ser(){
    int c;
    int now = 0 ;
    for(int i = 0 ;i < len ;i++){
        c = qian[i] - 'a';
        if(-1 == next[now][c])    
            return 0;
        now = next[now][c];
    }
    return num[now]; 
}

void build(){
    int c;
    int now = 0 ;
    for(int i = 0; ch[i] ; i ++){
        c = ch[i] - 'a';
        if(next[now][c] == -1){
            next[now][c] = size;
            memset(next[size],-1,sizeof(next[size]));
            num[size] = 0;
            size ++;
        }    
        now = next[now][c];
        num[now]++;
    }
}

void init(){
    memset(next[0],-1,sizeof(next[0]));
    memset(num,0,sizeof(num));
    size = 1 ;
}

void debug(){
    for(int i = 0 ; i < size; i++){
        cout << num[i] << endl;
        for(int f = 0 ; f < 26; f++)
            cout << next[i][f] << " ";
        cout << endl;
    }
}


int main(){
    int n,m;
    while(cin >> n >> m){
        
        init();
        for(int i = 0 ; i < n; i++){
            scanf("%s",ch);
            build();
        }
        int ans = 0 ;
        
        for(int i = 0 ; i < m; i++){
            cin >> len;
            for(int f = 0 ;f < len ;f++){
                double asc[8];
                for(int g = 0 ; g < 8; g++)
                    cin >> asc[g];
                qian[f] = fun(asc);
            }
            qian[len] = 0;
            ans += ser();
        }
        cout << ans << endl;
    }
    return 0;
}

