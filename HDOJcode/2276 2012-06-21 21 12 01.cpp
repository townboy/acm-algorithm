******************************
    Author : townboy
    Submit time : 2012-06-21 21:12:01
    Judge Status : Accepted
    HDOJ Runid : 6089696
    Problem id : 2276
    Exe.time : 31MS
    Exe.memory : 344K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>
#include<string.h>

char ch[110];
int ret[110][110],buf[110][110],inti[110][110];
int n,m;

void mul(int a[][110],int b[][110])
{
    int i,f,k;
    memset(buf,0,sizeof(buf));
    for(i=0;i<n;i++)
    {
        for(k=0;k<n;k++)
        {
            if(0 == a[i][k])
            {
                continue;
            }
            for(f=0;f<n;f++)
            {
                if(0 == b[k][f])
                {
                    continue;
                }
                buf[i][f]=(buf[i][f]+a[i][k]*b[k][f])%2;
            }
        }
    }
    for(i=0;i<n;i++)
    {
        for(f=0;f<n;f++)
        {
            a[i][f]=buf[i][f];
        }
    }
}

void matrix()
{
    int i;
    memset(ret,0,sizeof(ret));
    for(i=0;i<n;i++)
    {
        ret[0][i]=ch[i]-'0';
    }
    memset(inti,0,sizeof(inti));
    for(i=0;i<n;i++)
    {
        inti[i][i]=1;
    }
    for(i=0;i<n-1;i++)
    {
        inti[i][i+1]=1;
    }
    inti[n-1][0]=1;

    for(;m;m>>=1)
    {
        if(1&m)
        {    
            mul(ret,inti);
        }
        mul(inti,inti);
    }
}

int main()
{
    int i;
    while(scanf("%d",&m)!=EOF)
    {
        getchar();
        gets(ch);
        n=strlen(ch);
        matrix();
        for(i=0;i<n;i++)
        {
            printf("%d",ret[0][i]);
        }
        printf("\n");
    }    
    return 0;
}
