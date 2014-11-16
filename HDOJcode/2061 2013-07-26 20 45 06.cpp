******************************
    Author : townboy
    Submit time : 2013-07-26 20:45:06
    Judge Status : Accepted
    HDOJ Runid : 8726030
    Problem id : 2061
    Exe.time : 0MS
    Exe.memory : 340K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<string.h>

using namespace std;

int main() {
    int cas ,n;
    char ch[40];
    cin >> cas;
    for(int i = 0 ;i < cas;i++) {
        if(0 != i)
            puts("");
        cin >> n;
        double sc = 0 , ss = 0;
        double c,s;
        bool gua = false;
        for(int f = 0 ;f < n;f++) {
            scanf("%s%lf%lf",ch,&c,&s);
            sc += c;
            ss += c*s;
            if(s < 60)
                gua = true;
        }
        if(true == gua) 
            cout << "Sorry!" << endl;
        else
            printf("%.2lf\n",ss/sc);
    }
    return 0;
}
