******************************
    Author : townboy
    Submit time : 2013-07-06 14:15:09
    Judge Status : Accepted
    HDOJ Runid : 8533955
    Problem id : 4069
    Exe.time : 812MS
    Exe.memory : 624K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<memory.h>

#define maxn 50000
#define INF 0x3f3f3f3f

using namespace std;

int L[maxn],R[maxn],U[maxn],D[maxn]; //×óÓÒÉÏÏÂ
int C[maxn],H[maxn]; //½ÚµãÊôÓÚÄÄÒ»ÁÐ  H[i]±íÊ¾¸ÃÐÐµÄÍ·½áµã
int row[maxn]; //½ÚµãÊôÓÚÄÄÒ»ÐÐ
int S[maxn]; //ÁÐÁ´±íÖÐ½ÚµãµÄ×ÜÊý
int O[maxn]; //¼ÇÂ¼´ð°¸
int head,num; //head, numÎª×Ü½ÚµãÊý(¼´1µÄ×Ü¸öÊý)

void remove(int c) { //É¾³ýµÚcÁÐ
    L[R[c]]=L[c]; R[L[c]]=R[c];
    for(int i=D[c];i!=c;i=D[i]) { //É¾³ý¶ÔÓ¦cÁÐÓÐ1µÄÐÐ
        for(int j=R[i];j!=i;j=R[j]) {
            U[D[j]]=U[j]; D[U[j]]=D[j];
            S[C[j]]--;
        }
    }
}

void resume(int c) { //»Ö¸´µÚcÁÐ
    for(int i=U[c];i!=c;i=U[i]) { //»Ö¸´c¶ÔÓ¦µÄÓÐ1µÄÐÐ
        for(int j=L[i];j!=i;j=L[j]) {
            U[D[j]]=j; D[U[j]]=j;
            S[C[j]]++;
        }
    }
    L[R[c]]=c; R[L[c]]=c;
}

int uniq[9][9];
int to[5000][3];
int sudoku[9][9];

int dlx(int k)  {
    int ans = 0;
    if(R[head]==head) { //È«²¿ÌîÍê
        memcpy(uniq,sudoku,sizeof(uniq));
        return 1;
    }
    int s=INF,c; //ÕÒ1×îÉÙµÄÁÐ¶ÔÓ¦µÄµÚÒ»¸ö1µÄÎ»ÖÃi
    for(int i=R[head];i!=head;i=R[i])
        if(S[i]<s) s=S[i],c=i;

    remove(c); //É¾³ýc¶ÔÓ¦µÄÁÐ
    for(int i=D[c];i!=c;i=D[i]) {
        sudoku[ to[row[i]][0] ][ to[row[i]][1] ] = to[row[i]][2];
        for(int j=R[i];j!=i;j=R[j]) remove(C[j]); //É¾³ýÄÇÒ»ÐÐÓÐ1µÄÁÐ
        ans += dlx(k+1);
        if(ans > 1)
            return ans;
        for(int j=L[i];j!=i;j=L[j]) resume(C[j]); //»Ö¸´ÄÇÒ»ÐÐÓÐ1µÄÁÐ
    }
    resume(c); //»Ö¸´c¶ÔÓ¦µÄÁÐ
    return ans;
}

void addnode(int r,int c) {
    num++;
    U[num]=U[c]; D[U[c]]=num;  //ÀÏµÄ×îºóÐÐÖ¸ÏòÐÂµÄ×îºóÐÐ
    U[c]=num; D[num]=c;   //ÐÂµÄ×îºóÐÐÖ¸ÏòÁÐÊ×

    if(H[r]==-1) H[r]=L[num]=R[num]=num; //ÐÐµÄµÚÒ»¸ö1
    else { //²åÈëµ½ÐÐÁÐ±íÖÐ
        L[num]=L[H[r]]; R[num]=H[r];
        R[L[H[r]]]=num; L[H[r]]=num;
    }
    C[num]=c;   //ÁÐÖ¸Õë,±íÊ¾numËùÔÚµÄÁÐ
    row[num]=r; //±íÊ¾numËùÔÚµÄÐÐ
    S[c]++;     //ÏàÓ¦µÄÁÐ1µÄ¸öÊý+
}

void init(int m) {            //³õÊ¼»¯ÁÐÊý
    head = 0;
    memset(H,-1,sizeof(H));
    for(int i=0;i<=m;i++) {
        U[i]=i; D[i]=i;
        L[i+1]=i; R[i]=i+1;
        S[i]=0; C[i]=i;
    }
    L[0]=m; R[m]=0;
    num=m;
}

int dir[4][2] = {0,-1,1,0,0,1,-1,0};
bool lim[9][9][4];
int tt[4] = {128,64,32,16};
int belong[9][9];

void turn(int x,int y,int tem){
    for(int i = 0 ; i < 4; i++){
        if(tem >= tt[i])
            lim[x][y][i] = true;
        tem %= tt[i];
    }
    sudoku[x][y] = tem-1;
}

int cnt;

void dfs(int x,int y){
    belong[x][y] = cnt;
    for(int i = 0 ; i < 4; i++){
        if(true == lim[x][y][i])
            continue;
        int nx = x+dir[i][0];
        int ny = y+dir[i][1];
        if(cnt == belong[ nx ][ ny ])
            continue;
        dfs(nx , ny);
    }
}

void read(){
    int tem;
    memset(lim,false,sizeof(lim));
    for(int i = 0;i < 9 ;i ++)
        for(int f =  0 ; f < 9 ;f ++){
            cin >> tem;
            turn(i,f,tem);
        }
    
    cnt = 0;
    memset(belong,-1,sizeof(belong));
    for(int i = 0 ; i < 9 ; i++)
        for(int f = 0; f < 9 ; f++)
            if(-1 == belong[i][f]){
                dfs(i,f);
                cnt ++;
            }
}

void debug(){
    for(int i = 0 ;i < 9 ;i++){
        for(int f= 0 ; f < 9 ;f++)
            cout << belong[i][f] << "  ";
        cout << endl;
    }
    cout << endl;
}

void ans(){
    for(int i = 0 ;i < 9 ;i ++){
        for(int f= 0 ; f< 9 ;f++)
            cout << uniq[i][f]+1 ;
        cout << endl;
    }
}

int mul(int x,int y){
    return 9*x + y;
}

void solve_sudoku(){
    init(27*9 + 81);
    int nn = 0 ;
    for(int i = 0 ; i < 9 ;i ++)
        for(int f = 0 ; f < 9 ;f++)
            for(int g = 0 ;g < 9 ;g++){
                to[nn][0] = i;
                to[nn][1] = f;
                to[nn][2] = g;
                
                if(-1==sudoku[i][f] || g == sudoku[i][f]){
                    addnode(nn,1 + mul(i,f));
                    addnode(nn,82 + mul(i,g));
                    addnode(nn,163 + mul(f,g));
                    addnode(nn,244 + mul(belong[i][f],g));
                }
                nn++;
            }
    int result = dlx(0);
    if(1 == result)
        ans();
    else if(0 == result)
        cout << "No solution" << endl;
    else 
        cout << "Multiple Solutions" << endl;
}

int main(){
    int i,cas;
    cin >> cas;
    for(int i = 0 ; i < cas; i ++ ) {
        cout << "Case " << i+1 << ":" << endl;
        read();
        solve_sudoku();
    }
    return 0;
}