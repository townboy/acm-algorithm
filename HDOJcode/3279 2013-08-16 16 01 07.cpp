******************************
    Author : townboy
    Submit time : 2013-08-16 16:01:07
    Judge Status : Accepted
    HDOJ Runid : 8965790
    Problem id : 3279
    Exe.time : 15MS
    Exe.memory : 292K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<algorithm>

using namespace std;

int val[20];

int main() {
    int cas, t;
    cin >> cas;
    for(int i = 0 ;i < cas;i++) {
        cin >> t;
        for(int f = 0 ;f < 10;f++)
            scanf("%d",val+f);
        sort(val,val+10);
        printf("%d %d\n",t,val[7]);
    }
    return 0;
}
