******************************
    Author : townboy
    Submit time : 2013-07-09 22:23:00
    Judge Status : Accepted
    HDOJ Runid : 8556004
    Problem id : 2065
    Exe.time : 0MS
    Exe.memory : 312K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<memory.h>
#include<algorithm>

using namespace std;

unsigned __int64 m;
int n,mod;                    // ¾ØÕó´óÐ¡£¬µü´ú´ÎÊý£¬È¡Ä£Öµ
int ret[4][4];                // ½á¹û¾ØÕó
int init[4][4],buf[4][4];        //³õÊ¼¾ØÕó£¬ÖÐ¼ä¾ØÕó

void mul(int a[][4],int b[][4])        // ´«Ö·µ÷ÓÃ
{
    int i,f,k;

    memset(buf,0,sizeof(buf));

    for(i=0;i<n;i++)
        for(k=0;k<n;k++){
            if(0 == a[i][k])
                continue;
            for(f=0;f<n;f++)
            {
                if(0 == b[k][f])
                    continue;
                buf[i][f]=(buf[i][f]+a[i][k]*b[k][f])%mod;
            }
        }
    
    for(i=0;i<n;i++)
        for(f=0;f<n;f++)
            a[i][f]=buf[i][f];
}

unsigned __int64 nn;

int old[4][4] = {
    {2,1,1,0},
    {1,2,0,1},
    {1,0,2,1},
    {0,1,1,2},
};

void matrix()
{
    int i,f;
    n = 4;
    m = nn;
    mod = 100;

    memset(ret,0,sizeof(ret));
    ret[0][0] = 1;

    memcpy(init,old,sizeof(old));

    for(;m;m>>=1){
        if(1&m)
            mul(ret,init);
        mul(init,init);
    }
}

int solve(){
    matrix();
    return ret[0][0];
}

int main(){
    int cas ;
    while(cin >> cas,cas){
        for(int i = 0 ;i < cas ;i++){
            scanf("%I64u",&nn);
            printf("Case %d: ",i+1);
            printf("%d\n",solve());
        }
        cout << endl;
    }
    return 0;
}
