******************************
    Author : townboy
    Submit time : 2012-04-02 18:20:49
    Judge Status : Accepted
    HDOJ Runid : 5691167
    Problem id : 4193
    Exe.time : 1234MS
    Exe.memory : 8080K
    https://github.com/townboy
******************************


#include<stdio.h>
int zan[2002000];

int main()
{
    int n,biao,i,j,min,sum,flag;
//    freopen("D:\\in.txt","r",stdin);
    while(scanf("%d",&n),n)
    {
        min=10000000;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&zan[i]);
            zan[i+n]=zan[i];
        }
        biao=0;
        sum=0;
    
        for(i=1;i<=n;i++)
        {
            sum+=zan[i];
            if(sum<=min)
            {
                min=sum;
                biao=i;
            }
        }
        flag=0;
        if(min>=0)
        {
            flag++;
        }
        
        for(i=1;i<=n-1;i++)
        {
            if(i==biao)
            {
                min=100000000;
                sum=0;
                for(j=i+1;j<=i+n;j++)
                {
                    sum+=zan[j];
                    if(sum<=min)
                    {
                        biao=j;
                        min=sum;
                    } 
                }
            }
            else
            {
                min=min-zan[i];
                if(sum<=min)
                {
                    biao=i+n;
                    min=sum;
                }
            }
            if(min>=0)
            {
                flag++;
            }
        }
        printf("%d\n",flag);
    }
    return 0;
}