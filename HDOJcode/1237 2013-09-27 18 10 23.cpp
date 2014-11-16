******************************
    Author : townboy
    Submit time : 2013-09-27 18:10:23
    Judge Status : Accepted
    HDOJ Runid : 9237833
    Problem id : 1237
    Exe.time : 15MS
    Exe.memory : 312K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<memory.h>
#include<vector>
#include<string>
#include<stack>
#include<algorithm>

using namespace std;

stack<double> dig;
stack<string> op;

void init() {
    while(false == dig.empty())
        dig.pop();
    while(false == op.empty())
        op.pop();
}

bool read() {
    int ji = 0;
    string ch;
    double t;
    int k = 0;
    init();
    while(true) {
        if(0 == k) {
            ji ++;
            cin >> t;
            dig.push(t);
            if(false == op.empty()) {
                if("*" == op.top()) {
                    double a = dig.top(); dig.pop();
                    double b = dig.top(); dig.pop();
                    op.pop();
                    dig.push(a*b);
                }
                else if("/" == op.top()) {
                    double a = dig.top(); dig.pop();
                    double b = dig.top(); dig.pop();
                    op.pop();
                    dig.push(b/a);
                }
            }
        }
        else {
            cin >> ch;
            op.push(ch);
        }
        if('\n' == getchar())
            break;
        k ^= 1;
    }
    if(1 == ji && 0 == dig.top())
        return false;
    return true;
}

double solve() {
    vector<double> vdig;
    vector<string> vop;
    while(false == dig.empty()) {
        vdig.push_back(dig.top());
        dig.pop();
    }

    while(false == op.empty()) {
        vop.push_back(op.top());
        op.pop();
    }

    reverse(vdig.begin(),vdig.end());
    reverse(vop.begin(),vop.end());
    double sum = vdig[0];
    int size = vop.size();
    for(int i = 0;i < size;i++) {
        if("+" == vop[i])
            sum += vdig[i+1];
        else
            sum -= vdig[i+1];
    }
    return sum;
}

int main() {
    while(true == read()) {
        printf("%.2lf\n",solve());
    }
    return 0;
}

