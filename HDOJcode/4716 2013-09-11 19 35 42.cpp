******************************
    Author : townboy
    Submit time : 2013-09-11 19:35:42
    Judge Status : Accepted
    HDOJ Runid : 9150908
    Problem id : 4716
    Exe.time : 0MS
    Exe.memory : 292K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<memory.h>

using namespace std;

void ans(int t) {
    cout << "*------------*" << endl;
    for(int i = 0 ;i < 10-t;i++)
        cout << "|............|" << endl;;
    for(int i = 0 ;i < t; i++) 
        cout << "|------------|" << endl;
    cout << "*------------*" << endl;
}

int main() {
    int cas ,t;
    cin >> cas;
    for(int i = 0 ;i < cas;i++) {
        scanf("%d",&t);
        printf("Case #%d:\n",i+1);
        ans(t/10);
    }
    return 0;
}

