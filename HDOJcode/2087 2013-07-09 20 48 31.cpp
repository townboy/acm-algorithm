******************************
    Author : townboy
    Submit time : 2013-07-09 20:48:31
    Judge Status : Accepted
    HDOJ Runid : 8555458
    Problem id : 2087
    Exe.time : 15MS
    Exe.memory : 316K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>

using namespace std;
int fail[10000];
char A[10000],B[10000];

void init(char B[],int m){
    fail[0] = -1;
    for(int i = 1,f = -1;i < m;i++){
        while(f>=0 && B[f+1]!=B[i])
            f = fail[f];
        if(B[f+1] == B[i])
            f++ ;
        fail[i] = f;
    }
}

int kmp(char A[],char B[],int n,int m){
    int ans = 0 ;
    for(int i = 0 ,f = 0 ; i < n; i++){
        while(f > 0 && B[f]!=A[i])
            f = fail[f-1]+1;
        if(B[f] == A[i])
            f++;
        if(f == m){
            ans ++;
            f = 0;
        }
    }
    return ans ;
}

int main(){
    while(cin >> A){
        if(0 == strcmp(A, "#"))
            return 0;
        cin >> B;
        init(B,strlen(B));
        cout << kmp(A,B,strlen(A),strlen(B)) << endl;
    }
    return 0;
}
