******************************
    Author : townboy
    Submit time : 2013-08-08 20:23:11
    Judge Status : Accepted
    HDOJ Runid : 8877394
    Problem id : 4662
    Exe.time : 31MS
    Exe.memory : 300K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<memory.h>
#include<algorithm>

using namespace std;

char ch[1100000];

bool solve() {
    int ans = 0;
    if(2 == strlen(ch) && 'I' == ch[1] && 'M' == ch[0])
        return true;
    if('M' != ch[0])
        return false;
    for(int i = 1 ;ch[i] ; i++) {
        if('M' == ch[i])
            return false;
        if('I' == ch[i])
            ans ++;
        else
            ans += 3;
    }
    if(2 == ans%6 || 4 == ans%6)
        return true;
    return false;
}

int main() {
    int cas;
    cin >> cas;
    for(int i = 0 ;i < cas;i ++) {
        scanf("%s",ch);
        bool ret = solve();
        if(true == ret)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
