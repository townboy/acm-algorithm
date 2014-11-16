******************************
    Author : townboy
    Submit time : 2013-07-23 19:43:13
    Judge Status : Accepted
    HDOJ Runid : 8681605
    Problem id : 4602
    Exe.time : 46MS
    Exe.memory : 304K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<memory.h>

using namespace  std;

typedef __int64 LL;

int n,m,mod;                    // ¾ØÕó´óÐ¡£¬µü´ú´ÎÊý£¬È¡Ä£Öµ
int ret[2][2];                // ½á¹û¾ØÕó
int init[2][2],buf[2][2];        //³õÊ¼¾ØÕó£¬ÖÐ¼ä¾ØÕó

void mul(int a[][2],int b[][2])        // ´«Ö·µ÷ÓÃ
{
    int i,f,k;

    memset(buf,0,sizeof(buf));

    for(i=0;i<n;i++)
    {
        for(k=0;k<n;k++)
        {
            if(0 == a[i][k])
                continue;
            for(f=0;f<n;f++)
            {
                if(0 == b[k][f])
                    continue;
                buf[i][f]=((LL)buf[i][f]+((LL)a[i][k]*(LL)b[k][f]))%mod;
            }
        }
    }
    
    for(i=0;i<n;i++)
        for(f=0;f<n;f++)
            a[i][f]=buf[i][f];
}

void matrix()
{
    for(;m;m>>=1)
    {
        if(1&m)
            mul(ret,init);
        mul(init,init);
    }
}

int solve(int k) {
    if(0 == k)
        return 1;
    if(1 == k)
        return 2;

    m = k - 1;
    n = 2;
    mod = 1e9+7;
    init[0][0] = 2;
    init[0][1] = 0;
    init[1][0] = 1;
    init[1][1] = 2;
    
    memset(ret,0,sizeof(ret));
    ret[0][0] = 2;
    ret[0][1] = 1;

    matrix();
    return ret[0][0];
}

int main() {
    int cas;
    int  n ,k;
    cin >> cas;
    for(int i = 0;i < cas;i++) {
        scanf("%d%d",&n,&k);
        if(n < k) {
            printf("0\n");
            continue;
        }
        printf("%d\n",solve(n-k));
    }
    return 0;
}