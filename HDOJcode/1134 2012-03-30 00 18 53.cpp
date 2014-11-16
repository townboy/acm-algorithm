******************************
    Author : townboy
    Submit time : 2012-03-30 00:18:53
    Judge Status : Accepted
    HDOJ Runid : 5668943
    Problem id : 1134
    Exe.time : 62MS
    Exe.memory : 240K
    https://github.com/townboy
******************************


#include<stdio.h>

int ka[105][110];

void muti(int a,int b)
{
    int f,g,ji,k;
    for(f=0;f<=60;f++)
    {
        for(g=0;g<=60;g++)
        {
            ka[a+b+1][f+g]+=ka[a][f]*ka[b][g];
        }
    }
    k=0;
     for(f=0;f<=60;f++)
    { 
        ji=(k+ka[a+b+1][f])/10;
        ka[a+b+1][f]=(k+ka[a+b+1][f])%10;
        k=ji;
    }
}

void print(int n)
{
    int i,flag=0;
    for(i=60;i>=0;i--)
    {
        if(0==ka[n][i])
        {
            if(1==flag)
            {
                printf("%d",ka[n][i]);
            }
        }
        else 
        {
            flag=1;
            printf("%d",ka[n][i]);
        }
    }
    printf("\n");
}

int main()
{
    int i,f,n;
    ka[0][0]=1;
    ka[1][0]=1;
    for(i=2;i<=101;i++)
    {
        for(f=0;f<=i-1;f++)
        {
            muti(f,i-1-f);
        }
    }
    while(scanf("%d",&n),n!=-1)
    {
        print(n);
    }
    return 0;
}