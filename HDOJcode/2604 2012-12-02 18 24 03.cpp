******************************
    Author : townboy
    Submit time : 2012-12-02 18:24:03
    Judge Status : Accepted
    HDOJ Runid : 7314223
    Problem id : 2604
    Exe.time : 4000MS
    Exe.memory : 15956K
    https://github.com/townboy
******************************


#include<stdio.h>

int l,mod;
int ff[1000010],fm[1000010],mm[1000010],mf[1000010];

int chu()
{
    int i;
    ff[2]=1;
    fm[2]=1;
    mm[2]=1;
    mf[2]=1;
    for(i=3;i<=l;i++)
    {
        ff[i]=mf[i-1];
        fm[i]=(ff[i-1]+mf[i-1])%mod;
        mm[i]=(mm[i-1]+fm[i-1])%mod;
        mf[i]=mm[i-1];
    }
    return (ff[l]+fm[l]+mm[l]+mf[l])%mod;        
}

int main()
{    
    while(scanf("%d%d",&l,&mod)!=EOF)
    {
        if(0 == l)
        {
            printf("0\n");
            continue;
        }
        if(1 == l)
        {
            printf("2\n");
            continue;
        }
        printf("%d\n",chu());
    }
    return 0;
}