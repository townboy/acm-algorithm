******************************
    Author : townboy
    Submit time : 2013-09-30 20:28:20
    Judge Status : Accepted
    HDOJ Runid : 9254230
    Problem id : 2523
    Exe.time : 265MS
    Exe.memory : 324K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<algorithm>
#include<memory.h>
#include<iostream>
#include<math.h>

using namespace std;

int n ,k;
int val[1100];

void read() {
    for(int i = 0;i < n;i++)
        scanf("%d",val+i);
}

bool exist[2010];

int solve() {
    memset(exist,false,sizeof(exist));
    for(int i = 0 ;i < n;i++) 
        for(int f = 0 ;f < n;f++)
            if(i != f)
                exist[abs(val[i] - val[f])] = true;
    int sum = 0;
    for(int i = 0 ;i < 2001;i++) {
        if(true == exist[i])
            sum ++;
        if(sum == k)
            return i;
    }
    return -1;
}

int main() {
    int cas;
    cin >> cas;
    for(int i = 0 ;i < cas;i++) {
        cin >> n >> k;
        read();
        cout << solve() << endl;
    }
    return 0;
}

