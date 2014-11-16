******************************
    Author : townboy
    Submit time : 2013-09-30 21:03:47
    Judge Status : Accepted
    HDOJ Runid : 9254502
    Problem id : 2539
    Exe.time : 0MS
    Exe.memory : 304K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<memory.h>

using namespace std;

bool goal[18];
int n;
char patt[10] = " no good";

bool check(char ch[110]) {
    int len = strlen(ch);
    if(len < 9)
        return true;
    for(int i = len - 8;i < len;i++)
        if(patt[i - len + 8] != ch[i])
            return true;
    return false;
}

void read() {
    char ch[110];
    getchar();
    for(int i = 0 ;i < n;i++) {
        gets(ch);
        goal[i] = check(ch);
    }
}

void solve() {
    int sum = 0;
    int lun = (n+1) / 2;
    for(int i = 0 ;i < lun;i++)
        cout << i+1 << " ";
    cout << "Score" << endl;
    for(int i = 0 ;i < lun;i++) {
        if(true == goal[i*2]) {
            sum ++;
            cout << "O " ;
        }
        else
            cout << "X ";
    }
    cout << sum << endl;

    sum = 0;
    for(int i = 0 ;i < lun;i++) {
        int pos = i*2+1;
        if(pos >= n) {
            cout << "- ";
        }
        else if(true == goal[pos]) {
            cout << "O ";
            sum ++;
        }
        else
            cout << "X ";
    }
    cout << sum << endl;
}

int main() {
    while(cin >> n, n) {
        read();
        solve();
    }
    return 0;
}

