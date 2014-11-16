******************************
    Author : townboy
    Submit time : 2013-08-16 16:15:16
    Judge Status : Accepted
    HDOJ Runid : 8966036
    Problem id : 3283
    Exe.time : 15MS
    Exe.memory : 288K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

string ret;

int main() {
    int cas, t;
    cin >> cas;
    for(int i = 0; i < cas;i++) {
        cin >> t;
        cin >> ret;
        cout << t << " " ;
        if(true == next_permutation(ret.begin(),ret.end()))
            cout << ret;
        else
            cout << "BIGGEST";
        cout << endl;
    }
    return 0;
}