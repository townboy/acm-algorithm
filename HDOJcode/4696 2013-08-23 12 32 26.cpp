******************************
    Author : townboy
    Submit time : 2013-08-23 12:32:26
    Judge Status : Accepted
    HDOJ Runid : 9040007
    Problem id : 4696
    Exe.time : 93MS
    Exe.memory : 280K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<algorithm>

using namespace std;

int main() {
    int n ,q, t;
    while(cin >> n >> q) {
        bool flag = false;
        for(int i = 0;i < n;i++)
            scanf("%d",&t);
        for(int i = 0 ;i < n;i++) {
            scanf("%d",&t);
            if(1 == t)
                flag = true;
        }
        for(int i = 0 ;i < q;i++) {
            scanf("%d",&t);
            if(0 >= t) {
                puts("NO");
                continue;
            }
            if(false == flag && 1 == t%2)
                puts("NO");
            else
                puts("YES");
        }
    }
    return 0;
}

