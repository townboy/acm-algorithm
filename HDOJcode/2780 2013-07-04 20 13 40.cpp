******************************
    Author : townboy
    Submit time : 2013-07-04 20:13:40
    Judge Status : Accepted
    HDOJ Runid : 8525533
    Problem id : 2780
    Exe.time : 0MS
    Exe.memory : 372K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>
#include<iostream>
#include<algorithm>
#include<string.h>

using namespace std;
#define maxn 3000
#define INF 0x3f3f3f3f

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

int to[1000][3];
int    sudoku[9][9];

void ans(){
    for(int i = 0; i < 9;i++){
        cout << sudoku[i][0]+1;
        for(int f = 1; f < 9; f++)
            cout << sudoku[i][f]+1;
        cout << endl;
    }
}

bool dlx(int k)  {
    if(R[head]==head) { //È«²¿ÌîÍê
        ans();
        return true;
    }
    int s=INF,c; //ÕÒ1×îÉÙµÄÁÐ¶ÔÓ¦µÄµÚÒ»¸ö1µÄÎ»ÖÃi
    for(int i=R[head];i!=head;i=R[i])
        if(S[i]<s) s=S[i],c=i;

    remove(c); //É¾³ýc¶ÔÓ¦µÄÁÐ
    for(int i=D[c];i!=c;i=D[i]) {
        int x = to[row[i]][0] , y = to[row[i]][1], z = to[row[i]][2];
        sudoku[x][y] = z;
        for(int j=R[i];j!=i;j=R[j]) remove(C[j]); //É¾³ýÄÇÒ»ÐÐÓÐ1µÄÁÐ
        if(dlx(k+1)) return true;
        for(int j=L[i];j!=i;j=L[j]) resume(C[j]); //»Ö¸´ÄÇÒ»ÐÐÓÐ1µÄÁÐ
    }
    resume(c); //»Ö¸´c¶ÔÓ¦µÄÁÐ
    return false;
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

int turn(char ch){
    return ch - '0' -1;
}

int mul(int x,int y){
    return 9*x + y;
}

int getkuai(int x,int y){
    return (x/3)*3 + y/3;
}

bool solve_sudoku(){
    int ji = 0;
    int m = 27*9 + 81;
    int sh = 1,ss = 82,sk = 163,sg = 244;        // ÐÐ Êú ¿é 
    init(m);
    for(int i = 0;i < 9;i++)
        for(int f = 0;f < 9;f++)
            for(int g = 0;g < 9;g++){
                to[ji][0] = i;
                to[ji][1] = f;
                to[ji][2] = g;
                
                if(-1==sudoku[i][f] || g==sudoku[i][f]){
                    addnode(ji,sh+ mul(i,g));
                    addnode(ji,ss+ mul(f,g));
                    addnode(ji,sk+ mul( getkuai(i,f),g ));
                    addnode(ji,sg+ mul(i,f));
                }
                ji++;
            }
    return dlx(0);
}

void read(){
    char ch[10];
    for(int i = 0 ;i < 9;i++){
        gets(ch);
        for(int f = 0;f < 9;f ++)
            sudoku[i][f] = turn(ch[f]);
    }
}

int main(){
    int cas = 0;
    scanf("%d",&cas);
    getchar();
    for(int i = 0 ;i < cas;i ++ ){
        if(0 != i)
            cout << endl;
        read();
        if(false == solve_sudoku())
            cout << "Could not complete this grid." << endl;
    }
    return 0;
}