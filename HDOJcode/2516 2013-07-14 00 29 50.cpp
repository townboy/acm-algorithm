******************************
    Author : townboy
    Submit time : 2013-07-14 00:29:50
    Judge Status : Accepted
    HDOJ Runid : 8583513
    Problem id : 2516
    Exe.time : 0MS
    Exe.memory : 288K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<map>

using namespace std;

int n;
map<int,int>mp;

bool find() {
    if(1 == mp[n])
        return true;
    return false;
}

void init() {
    mp[2] = 1;
    mp[3] = 1;
    int a = 3, b = 2;
    while(true) {
        int res = a+b;
        b = a;
        a = res;
        if(res > 0)
            mp[res] = 1;
        else
            break;
    }
}

int main() {
    init();
    while(cin >> n ,n) {
        if(true == find())
            cout << "Second win" << endl;
        else 
            cout << "First win" << endl;
    }
    return 0;
}
/*
´ò±í³ÌÐò ¶þ±¶¶¯Ì¬¼õ·¨ÓÎÏ·¡£
¹æÂÉ¾ÍÊÇì³²¨ÄÇÆõÏîÎª±Ø°Ü
#include<stdio.h>
#include<iostream>

using namespace std;

int fun(int n,int lim) {
    if(0 == n)
        return false;
    for(int i = 1; i <= lim; i++) {
        if(false == fun(n-i,2*i))
            return true;
    }
    return false;
}

int main(){
    for(int i = 2; i <= 40; i++) {
        cout << i << " " << fun(i,i-1) << endl;
    }
    return 0;
}
*/

