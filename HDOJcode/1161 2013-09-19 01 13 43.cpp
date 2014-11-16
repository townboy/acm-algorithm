******************************
    Author : townboy
    Submit time : 2013-09-19 01:13:43
    Judge Status : Accepted
    HDOJ Runid : 9194078
    Problem id : 1161
    Exe.time : 15MS
    Exe.memory : 268K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<ctype.h>

using namespace std;

int main() {
    char ch[1100];
    while(gets(ch) != NULL) {
        for(int i = 0 ;ch[i] ;i ++)
            printf("%c",tolower(ch[i]));
        cout << endl;
    }
    return 0;
}

