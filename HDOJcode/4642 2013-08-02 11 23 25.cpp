******************************
    Author : townboy
    Submit time : 2013-08-02 11:23:25
    Judge Status : Accepted
    HDOJ Runid : 8801905
    Problem id : 4642
    Exe.time : 93MS
    Exe.memory : 284K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>

using namespace std;

int main() {
    int cas;
    int n,m ,tem;
    cin >> cas;
    for(int i = 0 ;i < cas;i++) {
        cin >> n >> m;
        for(int f = 0 ;f < n;f++)
            for(int g = 0 ; g < m;g++)
                scanf("%d",&tem);
        if(1 == tem)
            cout << "Alice" << endl;
        else 
            cout << "Bob" << endl;
    }
    return 0;
}
