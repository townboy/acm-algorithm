******************************
    Author : townboy
    Submit time : 2013-10-02 22:02:35
    Judge Status : Accepted
    HDOJ Runid : 9264783
    Problem id : 2574
    Exe.time : 109MS
    Exe.memory : 756K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<algorithm>
#include<memory.h>
#include<iostream>
#include<string>

using namespace std;

const int N=100000;
int pr[N],p[N/10],lp;

void gp(){
    for(int i=2;i<N;i++){
        if(!pr[i])p[lp++]=pr[i]=i;
        for(int j=0;j<lp && i*p[j]<N;j++){
            pr[i*p[j]]=p[j];
            if(i%p[j]==0)break;
        }
    }
}

int maxx, n;
string name;

int solve(int x) {
    int sum = 0;
    if(0 == x)
        return 0;
    for(int i = 0 ;i < lp;i++) {
        if(0 == x % p[i])
            sum ++;
        while(x % p[i] == 0)
            x /= p[i];
        if(1 == x)
            return sum;
    }
    return sum + 1;
}

void read() {
    int t;
    string tt;
    for(int i = 0 ;i < n;i++) {
        cin >> tt;
        scanf("%d",&t);
        int ret = solve(t);
        if(ret > maxx) {
            maxx = ret;
            name = tt;
        }
        else if(ret == maxx)
            name = min(name ,tt);
    }
}

int main() {
    int cas;
    cin >> cas;
    gp();
    for(int i = 0 ;i < cas;i++) {
        cin >> n;
        maxx = -1;
        read();
        cout << name << endl;
    }
    return 0;
}

