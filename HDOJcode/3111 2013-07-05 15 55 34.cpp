******************************
    Author : townboy
    Submit time : 2013-07-05 15:55:34
    Judge Status : Accepted
    HDOJ Runid : 8529381
    Problem id : 3111
    Exe.time : 0MS
    Exe.memory : 412K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<memory.h>
#include<algorithm>
#include<string.h>

using namespace std;

char ch[20];
int sudoku[9][9];

#define INF 0x3f3f3f3f
#define maxn 5000

int L[maxn],R[maxn],U[maxn],D[maxn];
int C[maxn],H[maxn];
int row[maxn];
int S[maxn];
int O[maxn];
int head,num;

void remove(int c){
    L[R[c]] = L[c]; R[L[c]] = R[c];
    for(int i = D[c];i !=c ; i = D[i]){
        for(int f= R[i];f!= i ;f= R[f]){
            U[D[f]] = U[f]; D[U[f]]  = D[f];
            S[C[f]] -- ;
        }
    }
}

void resume(int c){
    for(int i = U[c];i != c;i = U[i]){
        for(int f = L[i] ; f!= i ;f = L[f]){
            U[D[f]]= f; D[U[f]] = f;
            S[C[f]] ++;
        }
    }
    L[R[c]] = c; 
    R[L[c]] = c;
}

int to[800][3];

bool dlx(int k){
    if(R[head] == head){
        return true;
    }
    int s = INF,c;
    for(int i = R[head];i!=head ; i = R[i]){
        if(S[i] < s ) s = S[i] ,c = i;
    }
    
    remove(c);
    for(int i = D[c] ; i != c; i = D[i]){
        
        int tt = row[i];
        sudoku[ to[tt][0] ][ to[tt][1] ] = to[tt][2];
         for(int f= R[i];f != i ; f = R[f])    remove(C[f]);
        if(dlx(k+1)) return true;
        for(int f= L[i]; f != i ; f = L[f]) resume(C[f]);
    }
    resume(c);
    return false;
}

void addnode(int r,int c){
    num++;
    U[num] = U[c]; D[U[c]] = num;
    U[c] = num; D[num] =c;

    if(-1 == H[r]) H[r] = L[num] = R[num] =num;
    else{
        L[num] = L[H[r]] ; R[num] = H[r];
        R[L[H[r]]] = num; L[H[r]] = num;
    }
    C[num] = c;
    row[num] = r;
    S[c] ++;
}

void init(int m){
    head = 0 ;
    memset(H,-1,sizeof(H));
    for(int i = 0 ; i <= m;i ++ ){
        U[i] = i ; D[i] = i;
        L[i+1] = i; R[i] = i+1;
        S[i] = 0; C[i] = i;
    }
    L[0] = m; R[m] = 0;
    num = m;
}

int turn(char ch){
    if('?' == ch)
        return -1;
    return ch - '0' -1;
}

void ans(){
    for(int i = 0; i < 9;i++){
        for(int f= 0; f < 9;f++)
            cout << sudoku[i][f]+1;
        cout << endl;
    }
}

void read(){
    gets(ch);
    for(int i = 0 ;i < 9;i++){
        gets(ch);
        for(int f = 0 ;f < 9;f++)
            sudoku[i][f] = turn(ch[f]);
    }
}

int mul(int x,int y){
    return 9*x + y;
}

int getkuai(int x,int y){
    return x/3*3 + y/3; 
}

void solve_sudoku(){
    init(27*9 + 81);
    int nn = 0;
    for(int i = 0 ; i< 9 ;i++)
        for(int f = 0 ;f < 9;f++)
            for(int g= 0 ; g< 9; g++){
                to[nn][0] = i;
                to[nn][1] = f;
                to[nn][2] = g;
                
                if(-1==sudoku[i][f] || g==sudoku[i][f]){
                    addnode(nn,1+mul(i,g));
                    addnode(nn,82+mul(f,g));
                    addnode(nn,163+ mul( getkuai(i,f),g) );
                    addnode(nn,244+ mul(i,f));
                }
                nn++;
            }
    if(false == dlx(0))
        cout << "impossible" << endl;
    else 
        ans();
}

int main(){
    int i , cas ; 
    scanf("%d",&cas);
    for(int i = 0 ; i<cas;i++){
        read();
        if(0 != i)
            cout << "---" << endl;
        solve_sudoku();
    }
    return 0;
}