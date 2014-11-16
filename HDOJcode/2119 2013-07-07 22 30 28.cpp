******************************
    Author : townboy
    Submit time : 2013-07-07 22:30:28
    Judge Status : Accepted
    HDOJ Runid : 8541657
    Problem id : 2119
    Exe.time : 921MS
    Exe.memory : 776K
    https://github.com/townboy
******************************


#include<iostream>
#include<memory.h>
#include<algorithm>
#include<stdio.h>

#define INF 0x3f3f3f3f
#define maxn 110
#define N 25000

using namespace std;

//Ò»°ãÇóÖÁÉÙÑ¡Ôñ¶àÉÙÐÐ,Ê¹µÃÃ¿Ò»ÁÐÖÁÉÙÓÐÒ»¸ö1.
int L[N],R[N],U[N],D[N]; //×óÓÒÉÏÏÂ
int C[N],H[N]; //C[i],H[i]±íÊ¾i¶ÔÓ¦µÄÄÄÒ»ÁÐ,ÄÄÒ»ÐÐ
int S[N]; //ÁÐÁ´±íÖÐ½ÚµãµÄ×ÜÊý
int O[N]; //¼ÇÂ¼´ð°¸
int head,num,ans;    //head, numÎª×Ü½ÚµãÊý(¼´1µÄ×Ü¸öÊý),ansÎªÖÁÉÙÑ¡ÔñµÄÐÐÊý
void remove(int c) {
    for(int i=D[c];i!=c;i=D[i]) {
        L[R[i]]=L[i]; R[L[i]]=R[i];
    }
}
void resume(int c) {
    for(int i=U[c];i!=c;i=U[i]) {
        R[L[i]]=i; L[R[i]]=i;
    }
}

bool use[N]; //´óÐ¡ÎªÁÐÊý

int h() {
    memset(use,0,sizeof(use));
    int ret=0;
    for(int c=R[head];c!=head;c=R[c])
        if(!use[c]) {
            ret+=1;
            use[c]=1;
            for(int i=D[c];i!=c;i=D[i])
                for(int j=R[i];j!=i;j=R[j]) use[C[j]]=1;
        }
    return ret;
}

void dlx(int k) {
    if(k+h()>= ans) return;
    if(R[head]==head) {
        ans = min(ans,k);
        return;
    }

    int s=INF,c;
    for(int i=R[head];i!=head;i=R[i]){
        if(S[i]<s) s=S[i],c=i;
    }

    for(int i=D[c];i!=c;i=D[i]) {
        remove(i);
        for(int j=R[i];j!=i;j=R[j]) remove(j);
        dlx(k+1);
        for(int j=L[i];j!=i;j=L[j]) resume(j);
        resume(i);
    }
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
    S[c]++;     //ÏàÓ¦µÄÁÐ1µÄ¸öÊý++
}

void init(int m) {
    head=0;
    memset(H,-1,sizeof(H));
    for(int i=0;i<=m;i++) {
        U[i]=i; D[i]=i;
        L[i+1]=i; R[i]=i+1;
        S[i]=0; C[i]=i;
    }
    L[0]=m; R[m]=0;
    num=m;
}

int mat[maxn][maxn];
int a,b;

int solve(){
    ans = INF;
    int sum = 0;
    for(int i = 0 ;i < a;i++)
        for(int f = 0 ; f< b;f++)
            sum += mat[i][f];
    init(sum);

    int nn = 1;
    for(int i = 0 ;i < a;i++)
        for(int f = 0 ; f< b;f++){
            if(1 == mat[i][f]){
                addnode(i,nn);
                addnode(a+f,nn);
                nn++;
            }
        }
    dlx(0);
    return ans;
}

int main(){
    while(cin >> a,a){
        cin >> b;
        for(int i = 0 ; i < a;i++)
            for(int f = 0 ; f < b;f++)
                scanf("%d",&mat[i][f]);
        cout << solve() << endl;
    }
    return 0;
}



