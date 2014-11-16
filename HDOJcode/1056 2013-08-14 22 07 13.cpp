******************************
    Author : townboy
    Submit time : 2013-08-14 22:07:13
    Judge Status : Accepted
    HDOJ Runid : 8947890
    Problem id : 1056
    Exe.time : 375MS
    Exe.memory : 332K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<memory.h>

using namespace std;

int main() {
    double len;
    int i;
    while(cin >> len, len != 0) {
        double sum = 0;
        for(i = 1 ; ; i++) {
            sum += 1.0/(i+1);
            if(sum >= len)
                break;
        }
        cout << i << " card(s)" << endl;
    }
    return 0;
}
