******************************
    Author : townboy
    Submit time : 2013-07-24 16:31:46
    Judge Status : Accepted
    HDOJ Runid : 8694826
    Problem id : 4604
    Exe.time : 421MS
    Exe.memory : 1500K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<memory.h>

using namespace std;

int n;
int val[110000];
int de[110000], inc[110000];
int delast, inclast;

bool cmp(int a,int b) {
    return a > b;
}

int fde(int val,bool add) {
    int pos = upper_bound(de+1,de+delast,val) - de;
    if(true == add) {
        if(pos == delast) {
            de[pos] = val;
            delast ++;
        }
        else
            de[pos] = min(de[pos] , val);
    }
    return pos-1;
}    

int finc(int val,bool add) {
    int pos = upper_bound(inc+1,inc+inclast,val,cmp) - inc;
    if(true == add) {
        if(pos == inclast) {
            inc[pos] = val;
            inclast ++;
        }
        else 
            inc[pos] = max(inc[pos], val);
    }
    return pos - 1;
}

int solve() {
    int ans = 0;
    delast = 1 , inclast = 1;
    for(int i = n-1; i >= 0 ;i--) {
        int xaddinc = finc(val[i]+1,false) , xinc = finc(val[i],true);    
        int xminde = fde(val[i]-1,false) , xde = fde(val[i],true);
        ans = max(ans , 1 + xaddinc + xde);
        ans = max(ans , 1 + xminde + xinc);
    }
    return ans;
}

int main() {
    int cas;
    cin >> cas;
    for(int i = 0 ;i < cas;i++) {
        cin >> n;
        for(int f = 0 ; f < n;f++)
            scanf("%d", val+f);
        cout << solve() << endl;
    }
    return 0;
}
