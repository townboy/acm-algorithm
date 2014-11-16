******************************
    Author : townboy
    Submit time : 2012-06-21 20:09:40
    Judge Status : Accepted
    HDOJ Runid : 6089532
    Problem id : 2254
    Exe.time : 203MS
    Exe.memory : 42904K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<math.h>
#include<memory.h>

__int64 hash[40];
int buf[33][33],inti[10010][33][33],ji,m;

int id(__int64 x)
{
    int i;
    for(i=0;i<ji;i++)
    {    
        if(hash[i] == x)
        {
            return i;
        }
    }
    hash[ji++]=x;
    return ji-1;
}

int ser(__int64 x)
{
    int i;
    for(i=0;i<ji;i++)
    {
        if(hash[i] == x)
        {
            return i; 
        }
    }
    return -1;
}

void mul(int a[][33],int b[][33],int cun[][33])
{
    int i,f,k;
    memset(buf,0,sizeof(buf));
    for(i=0;i<ji;i++)
    {
        for(k=0;k<ji;k++)
        {
            if(0 == a[i][k])
            {
                continue;
            }
            for(f=0;f<ji;f++)
            {
                if(0 == b[k][f])
                {
                    continue;
                }
                buf[i][f]=(buf[i][f]+a[i][k]*b[k][f])%2008;
            }
        }
    }
    for(i=0;i<ji;i++)
    {
        for(f=0;f<ji;f++)
        {
            cun[i][f]=buf[i][f];
        }
    }
}

void matrix()
{
    int i;
    for(i=2;i<=10000;i++)
    {
        mul(inti[1],inti[i-1],inti[i]);
    }
}

void chu()
{
    ji=0;
    memset(inti,0,sizeof(inti));
}

int main()
{
    __int64 s,e,v1,v2;
    int k,i,num,tem,res,f;
    int t1,t2,u,v;
    while(scanf("%d",&num)!=EOF)
    {
        chu();
        for(i=0;i<num;i++)
        {
            scanf("%I64d%I64d",&s,&e);
            inti[1][id(s)][id(e)]++;
        }
    
        matrix();        

        scanf("%d",&k);
        for(i=0;i<k;i++)
        {
            scanf("%I64d%I64d%d%d",&v1,&v2,&t1,&t2);
            if(t1 > t2)
            {
                tem=t1;
                t1=t2;
                t2=t1;
            }
            u=ser(v1);
            v=ser(v2);
            if(-1 == u || -1 ==v)
            {
                printf("0\n");
                continue;
            }
            res=0;          
            
            for(f=t1;f<=t2;f++)
            {
                res=(res+inti[f][u][v])%2008;
            }

            printf("%d\n",res);
        }
    }
    return 0;
}