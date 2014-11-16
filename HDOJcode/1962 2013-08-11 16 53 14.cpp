******************************
    Author : townboy
    Submit time : 2013-08-11 16:53:14
    Judge Status : Accepted
    HDOJ Runid : 8906845
    Problem id : 1962
    Exe.time : 0MS
    Exe.memory : 316K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<memory.h>
#include<algorithm>

using namespace std;

int n;
char E[30][5];
char A[30][5];

void read() {
    for(int i = 0 ;i < n;i++)
        scanf("%s",A[i]);
    for(int i = 0 ;i < n;i++)
        scanf("%s",E[i]);
}

char num[15] = "23456789TJQKA";
char suit[10] = "CDSH";

bool check(int e,int a) {
    int ve,va;
    for(int i = 0 ;i < 13;i++)
        if(num[i] == E[e][0])
            ve = i;
    for(int i = 0 ;i < 13;i++)
        if(num[i] == A[a][0])
            va = i;
    if(ve > va)
        return true;
    if(ve < va)
        return false;
    
    for(int i = 0 ;i < 4;i++)
        if(suit[i] == E[e][1])
            ve = i;
    for(int i = 0 ;i < 4;i++)
        if(suit[i] == A[a][1])
            va = i;
    if(ve > va)
        return true;
    return false;
}

bool mk[100];
int match[100];

bool find(int x) {
    for(int i = 0 ;i < n; i++) {
        if(true == mk[i+n] || false == check(x,i))
            continue;
        mk[i+n] = true;
        if(-1 == match[i+n] || find(match[i+n])) {
            match[i+n] = x;
            return true;
        }
    }
    return false;
}

int solve() {
    int ans = 0;
    memset(match,-1,sizeof(match));
    for(int i = 0 ;i < n;i++) {
        memset(mk,false,sizeof(mk));
        if(true == find(i))
            ans ++;
    }
    return ans;
}

int main() {
    int cas;
    cin >> cas;
    for(int i = 0 ;i < cas;i++) {
        cin >> n;
        read();
        cout << solve() << endl;
    }
    return 0;
}
