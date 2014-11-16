******************************
    Author : townboy
    Submit time : 2013-07-18 21:03:41
    Judge Status : Accepted
    HDOJ Runid : 8633210
    Problem id : 3951
    Exe.time : 0MS
    Exe.memory : 292K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<algorithm>

using namespace std;

int fun(int a,int b) {
    if(a <= b)
        return true;
    if(b > 1)
        return false;
    if(0 == a%2)
        return false;
    return true;
}

int main() {
    int cas,n,k;
    cin >> cas;
    for(int i = 0; i < cas;i++) {
        cin >> n >> k;
        cout << "Case " << i+1 << ": " ;
        if(true == fun(n,k))
            cout << "first" << endl;
        else
            cout << "second" << endl;
    }
    return 0;
}

