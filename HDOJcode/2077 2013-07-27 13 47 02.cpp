******************************
    Author : townboy
    Submit time : 2013-07-27 13:47:02
    Judge Status : Accepted
    HDOJ Runid : 8732065
    Problem id : 2077
    Exe.time : 15MS
    Exe.memory : 340K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<memory.h>

using namespace std;

int a[30];

int main() {
    a[1] = 2;
    int cas;
    for(int i = 2;i <= 20;i++)
        a[i] = 3*a[i-1] + 2;
    cin >> cas;
    int n;
    for(int i = 0 ;i < cas;i++) {
        cin >> n;
        cout << 2 + a[n-1] << endl;
    }
    return 0;
}
