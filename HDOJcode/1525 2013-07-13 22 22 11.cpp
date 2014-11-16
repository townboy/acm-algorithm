******************************
    Author : townboy
    Submit time : 2013-07-13 22:22:11
    Judge Status : Accepted
    HDOJ Runid : 8583196
    Problem id : 1525
    Exe.time : 15MS
    Exe.memory : 228K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>

using namespace std;

bool fun(int a, int b){
    if(0 == a%b)
        return true;
    if(a >= 2*b)
        return true;
    if(true == fun(b,a%b))
        return false;
    return true;
}

int main(){
    int a, b;
    while(scanf("%d%d",&a,&b),a+b) {
        bool ans = fun(max(a,b), min(a,b));
        if(ans == true)
            puts("Stan wins");
        else 
            puts("Ollie wins");
    }
    return 0;
}

