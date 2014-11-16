******************************
    Author : townboy
    Submit time : 2013-07-15 08:48:31
    Judge Status : Accepted
    HDOJ Runid : 8589402
    Problem id : 1527
    Exe.time : 62MS
    Exe.memory : 284K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<math.h>

using namespace std;

int main() {
    int n,m;
    while(cin >> n >> m) {
        if(n < m)
            swap(n,m);
        int k = n-m;
        int state = k*((1.0+sqrt((double)5))/2.0);
        if(m == state)
            cout << "0" << endl;
        else
            cout << "1" << endl;
    }
    return 0;
}

/* Íþ×ô·ò²©ÞÈ
 ½áÂÛ ËùÓÐµÄ±Ø°ÜÌ¬µÄÍ¨Ïî¹«Ê½
 µÚKÏîµÄak = k*(1+sqrt(5))/2
 bk = ak+k;
 */
