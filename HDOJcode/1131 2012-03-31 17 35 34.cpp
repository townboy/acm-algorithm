******************************
    Author : townboy
    Submit time : 2012-03-31 17:35:34
    Judge Status : Accepted
    HDOJ Runid : 5678824
    Problem id : 1131
    Exe.time : 15MS
    Exe.memory : 204K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>

int ka[105][25];

void muti(int a,int b)
{
    int i,f,k,j;
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
        j=(k+ka[a+b+1][i])/1000;
        ka[a+b+1][i]=(k+ka[a+b+1][i])%1000;
        k=j;
    }
}

void print(int n)
{
    int zan[400],i,f,k,j,flag;
    memset(zan,0,sizeof(zan));
    for(i=20;i>-1;i--)
    {
        zan[i]=ka[n][i];
    }
    
    for(i=n;i>1;i--)
    {
        for(f=0;f<=300;f++)
        {
            zan[f]*=i;
        }
        k=0;
        for(f=0;f<=300;f++)
        {
            j=(zan[f]+k)/1000;
            zan[f]=(zan[f]+k)%1000;
            k=j;
        }
    }
    flag=0;
    for(i=300;i>-1;i--)
    {
        if(0==zan[i])
        {
            if(1==flag)
            {
                if(zan[i]<10)
                {
                    printf("00%d",zan[i]);
                }
                else if(zan[i]<100)
                {
                    printf("0%d",zan[i]);
                }
                else
                {
                    printf("%d",zan[i]);
                }
            }
        }
        else
        {
            if(1==flag)
            {
                if(zan[i]<10)
                {
                    printf("00%d",zan[i]);
                }
                else if(zan[i]<100)
                {
                    printf("0%d",zan[i]);
                }
                else
                {
                    printf("%d",zan[i]);
                }
            }
            else
            {
                flag=1;
                printf("%d",zan[i]);
            }
        }
    }
    printf("\n");
}

int main()
{
    int i,f,n;
    ka[0][0]=1;
    ka[1][0]=1;
    for(i=2;i<102;i++)
    {
        for(f=0;f<=i-1;f++)
        {
            muti(f,i-1-f);
        }
    }
    while(scanf("%d",&n),n)
    {
        print(n);
    }
    return 0;    
}
