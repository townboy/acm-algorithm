******************************
    Author : townboy
    Submit time : 2013-07-06 16:35:53
    Judge Status : Accepted
    HDOJ Runid : 8535146
    Problem id : 1603
    Exe.time : 0MS
    Exe.memory : 556K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<memory.h>
#include<algorithm>
#include<math.h>

using namespace std;

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

int to[maxn][3];
int len;
int ans[10][10];

struct node{
    int n,m;
    char mp[10][10];
};
node block[50];

void Ans(){
    for(int i = 0 ; i < len ;i ++){
        for(int f = 0 ; f < len ; f++)
            cout <<  ans[i][f];
        cout << endl;
    }
}

void print(int sx,int sy,int aim){
    for(int i = 0 ; i < block[aim].n ; i++)
        for(int f = 0 ;f < block[aim].m ;f++)
            if('1' == block[aim].mp[i][f])
                ans[sx+i][sy+f] = aim+1;
}

bool dlx(int k)  {
    if(R[head]==head)  //È«²¿ÌîÍê
        return true;
    int s=INF,c; //ÕÒ1×îÉÙµÄÁÐ¶ÔÓ¦µÄµÚÒ»¸ö1µÄÎ»ÖÃi
    for(int i=R[head];i!=head;i=R[i])
        if(S[i]<s) s=S[i],c=i;

    remove(c); //É¾³ýc¶ÔÓ¦µÄÁÐ
    for(int i=D[c];i!=c;i=D[i]) {
        int sx = to[row[i]][1];
        int sy = to[row[i]][2];
        int aim = to[row[i]][0];
        print(sx,sy,aim);
        
        for(int j=R[i];j!=i;j=R[j]) remove(C[j]); //É¾³ýÄÇÒ»ÐÐÓÐ1µÄÁÐ
        if(true == dlx(k+1))
            return true;
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

int n;
bool flag;

int read(){
    int sum = 0;
    cin >> n;
    if(0 == n)
        return 0;
    for(int i = 0 ;i < n;i++){
        cin >> block[i].n >> block[i].m ;
        getchar();
        for(int f = 0 ; f < block[i].n ;f++){
            gets(block[i].mp[f]);
            for(int g = 0; g <  block[i].m ;g++)
                sum += block[i].mp[f][g] - '0';
        }
    }
    flag = (16==sum?true:false);
    len = 4;
    return 1;
}

int mul(int x,int y){
    return x*len + y;
}

void build(){
    int nn = 1;
    init(len*len + n);
    for(int i = 0 ; i < n;i++){
        for(int f = 0; f < len-block[i].n+1 ;f++)
            for(int g= 0 ;g < len-block[i].m+1 ;g++){
                to[nn][0] = i;
                to[nn][1] = f;
                to[nn][2] = g;
                addnode(nn,1 + len*len + i);
                for(int j = 0 ; j < block[i].n ;j++)
                    for(int k = 0 ; k < block[i].m ; k++)
                        if('1' == block[i].mp[j][k])
                            addnode(nn,1 + mul(f+j ,g+k ));
                nn++;
            }
    }
}

void solve(){
    if(false == flag){
        cout << "No solution possible" << endl << endl;
        return ;
    }
    build();
    if(false == dlx(0))
        cout << "No solution possible" <<  endl;
    else
        Ans();
    cout << endl;
}

int main(){
    int cas = 0 ;
    while(1 == read()){
        solve();
    }
    return 0;
}