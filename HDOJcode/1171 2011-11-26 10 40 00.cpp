******************************
    Author : townboy
    Submit time : 2011-11-26 10:40:00
    Judge Status : Accepted
    HDOJ Runid : 5057459
    Problem id : 1171
    Exe.time : 1421MS
    Exe.memory : 1196K
    https://github.com/townboy
******************************


#include<stdio.h>
__int64 c1[200000],c2[200000];
int main(void)
{
    int num,i,f,g,sum,a[2000],b[2000];
    while(scanf("%d",&num),num>=0)
    {
        sum=0;
        for(i=1;i<=num;i++)
        {
            scanf("%d%d",&a[i],&b[i]);
            sum=sum+a[i]*b[i];
        }
        for(i=0;i<=(sum/2+1);i++)
        {
            c1[i]=0;
            c2[i]=0;
        }
        for(i=0;i<=a[1]*b[1];i=i+a[1])
        {
            c1[i]=1;
        }

        for(i=2;i<=num;i++)
        {
            for(f=0;f<=(sum/2+1);f++)
            {
                for(g=0;((g+f)<=(sum/2+1))&&(g<=b[i]*a[i]);g=g+a[i])
                {
                    c2[f+g]=c2[f+g]+c1[f];
                }
            }
            for(f=0;f<=(sum/2+1);f++)
            {
                c1[f]=c2[f];
                c2[f]=0;
            }
        }
        for(i=sum/2;;i--)
        {
            if(0!=c1[i])
            {
                printf("%d %d\n",sum-i,i);
                break;
            }
        }

    
    }
    return 0;
} 
