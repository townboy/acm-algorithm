******************************
    Author : townboy
    Submit time : 2013-07-05 20:24:51
    Judge Status : Accepted
    HDOJ Runid : 8530985
    Problem id : 3909
    Exe.time : 9359MS
    Exe.memory : 1004K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<memory.h>
#include<algorithm>
#include<string.h>
#include<math.h>

using namespace std;

int sudoku[20][20];
int n;

#define INF 0x3f3f3f3f
#define maxn 50000

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

int to[50000][3];

int solution;
int ans[20][20],uniq[20][20];

int dlx(int k){
    int res = 0;
    if(R[head] == head){
        memcpy(uniq,ans,sizeof(ans));
        return 1;
    }
    int s = INF,c;
    for(int i = R[head];i!=head ; i = R[i]){
        if(S[i] < s ) s = S[i] ,c = i;
    }
    
    remove(c);
    for(int i = D[c] ; i != c; i = D[i]){
        
        int tt = row[i];
        ans[ to[tt][0] ][ to[tt][1] ] = to[tt][2];
         for(int f= R[i];f != i ; f = R[f])    remove(C[f]);
        res += dlx(k+1);
        if(res > 1)
            return res;
        for(int f= L[i]; f != i ; f = L[f]) resume(C[f]);
    }
    resume(c);
    return res;
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
    if('.' == ch)
        return -1;
    int state = ch - '0';
    if(state < 10 && state >= 0)
        return state -1;
    return ch-'A'+9;
}

string pr = "123456789ABCDEFG" ;

int final[20][20];

void Ans(){
    for(int i = 0; i < n;i++){
        for(int f= 0; f < n;f++)
            cout << pr[final[i][f]];
        cout << endl;
    }
}

void read(){
    getchar();
    char ch[20];
    for(int i = 0 ;i < n;i++){
        gets(ch);
        for(int f = 0 ;f < n;f++)
            sudoku[i][f] = turn(ch[f]);
    }
}

int mul(int x,int y){
    return n*x + y;
}

int getkuai(int x,int y){
    int tem = (int)sqrt(n+0.1);
    return x/tem*tem + y/tem; 
}

void build(){
    init( 4*n*n );
    int nn = 0;
    for(int i = 0 ; i< n ;i++)
        for(int f = 0 ;f < n;f++)
            for(int g= 0 ; g< n; g++){
                to[nn][0] = i;
                to[nn][1] = f;
                to[nn][2] = g;
                
                if(-1==sudoku[i][f] || g==sudoku[i][f]){
                    addnode(nn,1+mul(i,g));
                    addnode(nn,1 + n*n + mul(f,g));
                    addnode(nn,1 + 2*n*n + mul( getkuai(i,f),g) );
                    addnode(nn,1 + 3*n*n + mul(i,f));
                }
                nn++;
            }
}

void mini(){
    memcpy(final,uniq,sizeof(final));
    for(int i = 0 ; i < n;i ++)
        for(int f= 0 ; f < n ;f++){
            if(-1 == sudoku[i][f])
                continue;
            int tem = sudoku[i][f];
            sudoku[i][f] = -1;
            build();
            if(dlx(0) <= 1){
                cout << "Not Minimal" << endl;
                return ;
            }
            sudoku[i][f] = tem;
        }
    Ans();
}

void solve_sudoku(){
    build();
    int solution = dlx(0);
    if(0 == solution)
        cout << "No Solution" << endl;
    else if(1 < solution)
        cout << "Multiple Solutions" << endl;
    else
        mini();
}

int main(){
    while(scanf("%d",&n)!=EOF){
        n = n*n;
        read();
        solve_sudoku();
    }
    return 0;
}