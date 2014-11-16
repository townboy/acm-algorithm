******************************
    Author : townboy
    Submit time : 2013-07-15 15:06:35
    Judge Status : Accepted
    HDOJ Runid : 8593379
    Problem id : 2177
    Exe.time : 15MS
    Exe.memory : 5136K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<memory.h>
#include<math.h>

using namespace std;

int k,state;
int bai[1000000][2], ji;

int ans[10][2] , ansnum;

void pr(int a,int b) {
    for(int i = 0; i < ansnum; i++)
        if(a == ans[i][0])
            return ;
    ans[ansnum][0] = a;
    ans[ansnum][1] = b;
    ansnum++;
    cout << a << " " << b << endl;
}

bool check(int n,int m) {
    k = m-n;
    state = k*1.6180339887;
    if(n == state)
        return false;
    return true;
}

void search2(int n,int m) {
    int l = 0, r = ji-1, mid;
    while(l <= r) {
        mid = (l+r)/2;
        if(bai[mid][1] == m) {
            if(n > bai[mid][0])
                pr(bai[mid][0] ,bai[mid][1]);
            return ;
        }
        if(m < bai[mid][1])
            r = mid-1;
        else 
            l = mid+1;
    }
}

void search1(int n,int m) {
    int l = 0, r = ji-1, mid;
    while(l <= r) {
        mid = (l+r)/2;
        if(bai[mid][0] == n) {
            if(m > bai[mid][1])
                pr(bai[mid][0],bai[mid][1]);
            return ;
        }
        if(n < bai[mid][0])
            r = mid-1;
        else
            l = mid+1;
    }
}

void init() {
    ji = 0;
    for(int i = 0 ;; i++) {
        int a = 1.6180339887*i;
        int b = a+i;
        if(a > 1000000)
            break;
        bai[ji][0] = a;
        bai[ji][1] = b;
        ji ++;
    }
}

void debug() {
    for(int i = 0; i < 10; i++) 
        cout << bai[i][0] << " " << bai[i][1] << endl;
}

int main() {
    int n,m;
    init();
    while(cin >> n >> m ,n+m) {
        if(n > m)
            swap(n,m);
        ansnum = 0;
        bool res = check(n,m);
        if(res == false) {
            cout << "0" << endl;
            continue;
        }
        cout << "1" << endl;
        if(n > state)
            pr(state,state+k);
        search2(n,m);
        search1(n,m);
        if(m != n) {
            search2(m,n);
            search1(m,n);
        }
    }
    return 0;
}
