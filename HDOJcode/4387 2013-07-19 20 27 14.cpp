******************************
    Author : townboy
    Submit time : 2013-07-19 20:27:14
    Judge Status : Accepted
    HDOJ Runid : 8644147
    Problem id : 4387
    Exe.time : 0MS
    Exe.memory : 292K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<memory.h>
#include<algorithm>

using namespace std;

int main() {
    int n,k;
    int cas = 0;
    while(cin >> n >> k) {
        cas ++;
        cout << "Case " << cas << ": " ;
        if(1 == k) {
            if(1 == n%2)
                cout << "Bob" << endl;
            else
                cout << "Alice 1" << endl;
            continue;
        }
        cout << "Alice " ;
        if(n == k*2+1)
            cout << k << endl;
        else 
            cout << "1" << endl;
    }
    return 0;
}

/*
#include<stdio.h>
#include<iostream>
#include<memory.h>
#include<algorithm>

using namespace std;

struct state {
    int t[100];
    int n;
};

int fun(int player,state tem,int hash) {
    int len = tem.n;
    int flag = 0;
    state next;
    if(-1 == player) {
        for(int i = len-1; i >= 0;i--) {
            if(tem.t[i] == -1) {
                next = tem;
                for(int f = i+1; f < len;f++)
                    if(0 == next.t[f]) {
                        next.t[f] = -1;
                        next.t[i] = 0;
                        if(false == fun(1,next,0) ) {
                            if(1 == hash)
                                cout << i+1 << endl;
                            return true;
                        }
                        flag = 1;
                        break;
                    }
            }
        }
        if(0 == flag)
            return true;
    }
    else {
        for(int i = len-1;i >= 0;i--) {
            if(tem.t[i] == 1) {
                next = tem;
                for(int f = i-1; f >= 0;f--) {
                    if(0 == next.t[f]) {
                        next.t[f] = 1;
                        next.t[i] = 0;
                        if(false == fun(-1,next,0))
                            return true;
                        flag = 1;
                        break;
                    }
                }
            }
        }
        if(0 == flag)
            return true;
    }
    return false;
}

int main() {
    state tem;
    while(true) {
        int n,k;
        cin >> n >> k;
        tem.n = n;
        memset(tem.t,0,sizeof(tem.t));
        for(int i = 0;i < k;i++)
            tem.t[i] = -1;
        for(int i = n-k;i < n;i++)
            tem.t[i] = 1;
        cout << fun(-1,tem,1) << endl;
    }
    return 0;
}
*/

