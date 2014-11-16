******************************
    Author : townboy
    Submit time : 2013-07-15 09:21:37
    Judge Status : Accepted
    HDOJ Runid : 8589673
    Problem id : 2176
    Exe.time : 31MS
    Exe.memory : 1076K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>

using namespace std;

int S[210000];

int main() {
    int m ;
    while(cin >> m, m) {
        int sum = 0;
        for(int i = 0; i < m ;i++) {
            scanf("%d",S+i);
            sum ^= S[i];
        }
        if(0 == sum) {
            cout << "No" << endl;
            continue;
        }
        cout << "Yes" << endl;
        for(int i = 0 ;i < m; i++) {
            int tem = S[i]^sum;
            if(tem < S[i])
                printf("%d %d\n",S[i],tem);
        }
    }
    return 0;
}
