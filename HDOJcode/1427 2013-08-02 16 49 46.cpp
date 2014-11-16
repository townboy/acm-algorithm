******************************
    Author : townboy
    Submit time : 2013-08-02 16:49:46
    Judge Status : Accepted
    HDOJ Runid : 8806802
    Problem id : 1427
    Exe.time : 390MS
    Exe.memory : 344K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<string.h>
#include<memory.h>
#include<queue>

using namespace std;

char ch[10];
int p[4];

int id() {
    if('A' == ch[0])
        return 1;
    if('1' == ch[0])
        return 10;
    if('J' == ch[0])
        return 11;
    if('Q' == ch[0])
        return 12;
    if('K' == ch[0])
        return 13;
    return ch[0] - '0';
}

bool read() {
    if(EOF == scanf("%s",ch))
        return false;
    p[0] = id();
    for(int i = 0 ;i < 3;i++) {
        scanf("%s",ch);
        p[i+1] = id();
    }
    return true;
}

void debug() {
    for(int i = 0; i < 4;i++) 
        cout << p[i] << endl;
}

struct node {
    int p[4];
    int n;
    node() {}
    node(int _n):n(_n)
    {}
};

bool solve() {
    queue<node>q;

    node tem(4), ru;
    for(int i = 0 ;i < 4;i++)
        tem.p[i] = p[i];
    q.push(tem);

    while(!q.empty()) {
        tem = q.front();
        q.pop();

        int n = tem.n;
        ru.n = n-1;
        for(int i = 0 ;i < n;i++)
            for(int f = i+1; f < n;f++) {
                int pos = 0;
                int a = tem.p[i];
                int b = tem.p[f];
                for(int g = 0 ;g < n; g++) {
                    if(g == i || g == f)
                        continue;
                    ru.p[pos ++] = tem.p[g];
                }
                int ret = a+b;
                ru.p[n-2] = ret;
                if(2 != n)
                    q.push(ru);
                else if(24 == ret)
                    return true;

                ret = a-b;
                ru.p[n-2] = ret;
                if(2 != n)
                    q.push(ru);
                else if(24 == ret)
                    return true;

                ret = b-a;
                ru.p[n-2] = ret;
                if(2 != n)
                    q.push(ru);
                else if(24 == ret)
                    return true;

                ret = a*b;
                ru.p[n-2] = ret;
                if(2 != n)
                    q.push(ru);
                else if(24 == ret)
                    return true;

                if(0 != b && a%b == 0) {
                    ret = a/b;
                    ru.p[n-2] = ret;
                    if(2 != n)
                        q.push(ru);
                    else if(24 == ret)
                        return true;
                }
                
                if(0 != a && b%a == 0) {
                    ret = b/a;
                    ru.p[n-2] = ret;
                    if(2 != n)
                        q.push(ru);
                    else if(24 == ret)
                        return true;
                }

            }
    }
    return false;
}

int main() {
    while(true == read()) {
        bool ans = solve();
        if(false == ans)
            puts("No");
        else
            puts("Yes");
    }
    return 0;
}

