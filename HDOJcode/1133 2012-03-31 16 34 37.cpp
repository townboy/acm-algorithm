******************************
    Author : townboy
    Submit time : 2012-03-31 16:34:37
    Judge Status : Accepted
    HDOJ Runid : 5678478
    Problem id : 1133
    Exe.time : 15MS
    Exe.memory : 1340K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>

int ka[110][110][25];

void plus(int a,int b)
{
    int i,k,j;
    for(i=0;i<=20;i++)
    {
        ka[a][b][i]=ka[a-1][b][i]+ka[a][b-1][i];
    }
    k=0;
    for(i=0;i<=20;i++)
    {
        j=(ka[a][b][i]+k)/1000;
        ka[a][b][i]=(ka[a][b][i]+k)%1000;
        k=j;
    }
}

void print(int m,int n)
{
    int i,flag=0,zan[400],f,k,j;
    
    memset(zan,0,sizeof(zan));

    for(i=0;i<=20;i++)
    {
        zan[i]=ka[m][n][i];
    }

    for(i=m;i>=2;i--)
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
    
    for(i=n;i>=2;i--)
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
    int m,n,i,f,ji;
    ji=0;
    for(i=0;i<=105;i++)
    {
        for(f=0;f<=105;f++)
        {
            ka[i][f][0]=-1;
        }
    }
    for(i=0;i<=105;i++)
    {
        for(f=i+1;f<=104;f++)
        {
            ka[i][f][0]=0;
        }
    }
    for(i=0;i<=105;i++)
    {
        ka[i][0][0]=1;
    }
    for(i=0;i<=105;i++)
    {
        for(f=0;f<=105;f++)
        {
            if(-1==ka[i][f][0])
            {
                plus(i,f);
            }
        }
    }
    while(scanf("%d%d",&m,&n),!(0==m&&0==n))
    {
        ji++;
        printf("Test #%d:\n",ji);
        if(m<n)
        {
            printf("0\n");
        }
        else
        {
            print(m,n);
        }
    }
    return 0;
}