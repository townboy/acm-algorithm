******************************
    Author : townboy
    Submit time : 2013-07-09 19:53:14
    Judge Status : Accepted
    HDOJ Runid : 8554968
    Problem id : 1711
    Exe.time : 515MS
    Exe.memory : 4320K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<string.h>
#include<memory.h>
#include<iostream>
#include<algorithm>

using namespace std;

int fail[11000];
void init(int B[],int m){
    fail[0] = -1;
    for(int i = 1 ,f = -1;i < m; i++){
        while(f >= 0 && B[f+1]!=B[i])
            f = fail[f];
        if(B[f+1] == B[i])
            f ++ ;
        fail[i] = f;
    }
}

int kmp(int A[],int B[],int n,int m){
    for(int i = 0, f = 0; i < n ;i++){
        while( f > 0 && B[f] != A[i])
            f = fail[f-1] + 1;
        if(B[f] == A[i])
            f ++ ;
        if(f == m)
            return i-m+2;
    }
    return -1;
}

int A[1100000],B[11000];
int n , m ;

int main(){
    int cas;
    cin >> cas;
    for(int i = 0 ;i < cas;i++){
        cin >> n >> m;
        for(int f = 0 ; f < n; f++)
            scanf("%d", A+f);
        for(int f = 0 ; f < m; f++)
            scanf("%d",B+f);
        init(B,m);
        cout << kmp(A,B,n,m) << endl;
    }
    return 0;
}
