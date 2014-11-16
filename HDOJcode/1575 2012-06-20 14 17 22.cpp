******************************
    Author : townboy
    Submit time : 2012-06-20 14:17:22
    Judge Status : Accepted
    HDOJ Runid : 6084462
    Problem id : 1575
    Exe.time : 0MS
    Exe.memory : 200K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>

int n,m;
int inti[11][11];
int ret[11][11],buf[11][11];

void mul(int a[][11],int b[][11])
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
                buf[i][f]=(buf[i][f]+a[i][k]*b[k][f])%9973;
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
    int i,f;
    for(i=0;i<n;i++)
    {
        for(f=0;f<n;f++)
        {    
            ret[i][f]=(i==f);
        }
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

int main()
{
    int sum,i,f,g,num,x;
//    freopen("D:\\in.txt","r",stdin);
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        scanf("%d%d",&n,&m);
        for(f=0;f<n;f++)
        {
            for(g=0;g<n;g++)
            {
                scanf("%d",&x);
                inti[f][g]=x;                    
            }
        }

        matrix();

        sum=0;
        for(f=0;f<n;f++)
        {
            sum=(sum+ret[f][f])%9973;
        }
        printf("%d\n",sum);
    }
    return 0;
}