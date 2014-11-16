******************************
    Author : townboy
    Submit time : 2013-07-08 01:32:31
    Judge Status : Accepted
    HDOJ Runid : 8542144
    Problem id : 3663
    Exe.time : 15MS
    Exe.memory : 628K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<memory.h>
#include<algorithm>

#define maxn 10000
#define INF 0x3f3f3f3f
using namespace std;

int L[maxn],R[maxn],U[maxn],D[maxn]; //×óÓÒÉÏÏÂ
int C[maxn],H[maxn]; //½ÚµãÊôÓÚÄÄÒ»ÁÐ  H[i]±íÊ¾¸ÃÐÐµÄÍ·½áµã
int row[maxn]; //½ÚµãÊôÓÚÄÄÒ»ÐÐ
int S[maxn]; //ÁÐÁ´±íÖÐ½ÚµãµÄ×ÜÊý
int O[maxn]; //¼ÇÂ¼´ð°¸
int head,num; //head, numÎª×Ü½ÚµãÊý(¼´1µÄ×Ü¸öÊý)

int n,m,d;

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

int res[65][2];
int to[10000][3];

bool dlx(int k)  {
    if(R[head]==head) { //È«²¿ÌîÍê
        return true;
    }
    int s=INF,c; //ÕÒ1×îÉÙµÄÁÐ¶ÔÓ¦µÄµÚÒ»¸ö1µÄÎ»ÖÃi
    for(int i=R[head];i!=head;i=R[i])
        if(S[i]<s) s=S[i],c=i;

    remove(c); //É¾³ýc¶ÔÓ¦µÄÁÐ
    for(int i=D[c];i!=c;i=D[i]) {
        int num = to[row[i]][0];
        int s = to[row[i]][1];
        int t = to[row[i]][2];

        res[num][0] = s;
        res[num][1] = t;

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

int con[65][65];
int t[65][2];

int mul(int x,int y){
    return x*d + y;
}
bool solve(){
    init(n*d + n);
    int nn = 0;
    for(int i = 0 ; i < n ;i++) { 
        for(int f = t[i][0]; f <= t[i][1] ;f++)
            for(int g = f; g<= t[i][1] ;g++){
                to[nn][0] = i;
                to[nn][1] = f;
                to[nn][2] = g;
                addnode(nn, n*d+1+i);
                for(int h = 0; h < n;h++)
                    if(1 == con[i+1][h+1] || i == h)
                        for(int j = f;j <= g;j++)
                            addnode(nn,mul(h,j-1)+1);
                nn++;
            }
        to[nn][0] = i;
        to[nn][1] = 0;
        to[nn][2] = 0;
        addnode(nn,n*d + 1 + i);
        nn++;
    }
    return dlx(0);
}

void chu(){
    memset(con,0,sizeof(con));
}
void Ans(){
    for(int i = 0 ; i < n; i++)
        cout << res[i][0] << " " << res[i][1] << endl;
}
int main(){
    while(cin >> n){
        int a , b;
        chu();
        cin >> m >> d;
        for(int i = 0 ; i < m; i++){
            cin >> a >> b; 
            con[a][b] = 1;
            con[b][a] = 1;
        }
        for(int i = 0; i < n; i++)
            cin >> t[i][0] >> t[i][1];
        if(false == solve())
            cout << "No solution" << endl;
        else 
            Ans();
        cout << endl;
    }


    return 0;
}
