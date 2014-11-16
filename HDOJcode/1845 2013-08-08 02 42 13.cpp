******************************
    Author : townboy
    Submit time : 2013-08-08 02:42:13
    Judge Status : Accepted
    HDOJ Runid : 8868492
    Problem id : 1845
    Exe.time : 15MS
    Exe.memory : 288K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<memory.h>

using namespace std;

int main() {
    char ch[10];
    int cas;
    int n, u ,v;
    cin >> cas;
    for(int i = 0 ;i < cas;i++) {
        cin >> n;
        getchar();
        for(int f = 0;f < n*3/2; f++)
            gets(ch);
        cout << n/2 << endl;
    }
    return 0;
}
