******************************
    Author : townboy
    Submit time : 2013-09-30 22:31:49
    Judge Status : Accepted
    HDOJ Runid : 9255029
    Problem id : 2537
    Exe.time : 0MS
    Exe.memory : 304K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<memory.h>

using namespace std;

int main() {
    int n;
    char ch[110];
    while(cin >> n, n) {
        scanf("%s",ch);
        int r = 0, y = 0;
        for(int i = 0;i < n-1;i++) {
            if('R' == ch[i])
                r ++;
            else
                y ++;
        }
        if('B' == ch[n-1]) {
            if(7 == r) 
                cout << "Red" << endl;
            else
                cout << "Yellow" << endl;
        }
        else {
            if(7 == y)
                cout << "Yellow" << endl;
            else
                cout << "Red" << endl;
        }
    }
    return 0;
}

