******************************
    Author : townboy
    Submit time : 2013-07-23 19:31:32
    Judge Status : Accepted
    HDOJ Runid : 8681385
    Problem id : 4608
    Exe.time : 468MS
    Exe.memory : 396K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<memory.h>
#include<string.h>
#include<algorithm>

using namespace std;

char ch[110000];
int len;

void add() {
    int i,ji = 1;
    for(i = 0 ;i < len;i++) {
        ch[i] += ji;
        if(ch[i] == '9' + 1) {
            ch[i] = '0';
            ji = 1;
        }
        else 
            break;
    }
    if(i == len) {
        ch[i] = '1';
        len ++;
    }
}

bool check() {
    int s = 0;
    for(int i = 0 ;i < len;i++)
        s = (s+ch[i]-'0')%10;
    if(0 == s)
        return true;
    return false;
}

void ans() {
    reverse(ch,ch+len);
    puts(ch);
}

int main() {
    int cas;
    cin >> cas;
    getchar();
    for(int i = 0 ;i < cas;i++) {
        gets(ch);
        len = strlen(ch);
        reverse(ch,ch+len);

        add();
        while(false == check())
            add();
        ans();
    }
    return 0;
}