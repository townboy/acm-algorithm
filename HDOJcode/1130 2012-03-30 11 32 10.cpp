******************************
    Author : townboy
    Submit time : 2012-03-30 11:32:10
    Judge Status : Accepted
    HDOJ Runid : 5670044
    Problem id : 1130
    Exe.time : 15MS
    Exe.memory : 204K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>
int ka[110][25];

void muti(int a,int b)
{
    int i,f,j,k;
    for(i=0;i<=20;i++)
    {
        for(f=0;f<=20;f++)
        {
            ka[a+b+1][i+f]+=ka[a][i]*ka[b][f];
        }
    }
    k=0;
    for(i=0;i<=20;i++)
    {
        j=(ka[a+b+1][i]+k)/1000;
        ka[a+b+1][i]=(ka[a+b+1][i]+k)%1000;
        k=j;
    }
}

void print(int n)
{
    int i,flag;
    flag=0;
    for(i=20;i>-1;i--)
    {
        if(0==ka[n][i])
        {
            if(1==flag)
            {
                 if(ka[n][i]<10)
                 {
                     printf("00%d",ka[n][i]);
                 }
                 else if(ka[n][i]<100)
                 {
                     printf("0%d",ka[n][i]);
                 }
                 else
                 {
                     printf("%d",ka[n][i]);
                 }
            }
        }
        else
        {
            if(1==flag)
            {
                if(ka[n][i]<10)
                 {
                     printf("00%d",ka[n][i]);
                 }
                 else if(ka[n][i]<100)
                 {
                     printf("0%d",ka[n][i]);
                 }
                 else
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
    }
    printf("\n");
}

int main()
{
    int i,f,n;
    memset(ka,0,sizeof(ka));
    ka[0][0]=1;
    ka[1][0]=1;
    for(i=2;i<=101;i++)
    {
        for(f=0;f<=i-1;f++)
        { 
            muti(f,i-1-f);
        }
    }
    while(scanf("%d",&n)!=EOF)
    {
        print(n);
    }
    return 0;
}