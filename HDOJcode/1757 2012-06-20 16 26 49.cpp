******************************
    Author : townboy
    Submit time : 2012-06-20 16:26:49
    Judge Status : Accepted
    HDOJ Runid : 6084962
    Problem id : 1757
    Exe.time : 0MS
    Exe.memory : 200K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>

int a[10],mod,m;
int buf[10][10],ret[10][10],inti[10][10];

void mul(int a[][10],int b[][10])
{
    int i,f,k;
    memset(buf,0,sizeof(buf));
    for(i=0;i<10;i++)
    {
        for(k=0;k<10;k++)
        {
            if(0 == a[i][k])
            {
                continue;
            }
            for(f=0;f<10;f++)
            {
                if(0 == b[k][f])
                {
                    continue;
                }
                buf[i][f]=(buf[i][f]+a[i][k]*b[k][f])%mod;
            }
        }
    }
    for(i=0;i<10;i++)
    {
        for(f=0;f<10;f++)
        {
            a[i][f]=buf[i][f];
        }
    }
}

void matrix()
{
    int i,f;
    memset(inti,0,sizeof(inti));
    for(i=1;i<=9;i++)
    {
        inti[i][i-1]=1;
    }
    for(i=0;i<10;i++)
    {
        inti[i][9]=a[i];
    }

    memset(ret,0,sizeof(ret));
    for(i=0;i<=9;i++)
    {
        ret[0][i]=i;
    }

    for(;m;m>>=1)
    {
        if(1&m)
        {
            mul(ret,inti);
        }
        mul(inti,inti);
    }
}

void chu()
{
    memset(a,0,sizeof(a));
}

int main()
{
    int i,f;
//    freopen("D:\\in.txt","r",stdin);
    while(scanf("%d%d",&m,&mod)!=EOF)
    {
        chu();
        m-=9;
        for(i=9;i>-1;i--)
        {
            scanf("%d",&a[i]);        
        }
        matrix();
        
        printf("%d\n",ret[0][9]);
    }
    return 0;
}