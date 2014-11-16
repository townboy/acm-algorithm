******************************
    Author : townboy
    Submit time : 2012-03-14 21:31:29
    Judge Status : Accepted
    HDOJ Runid : 5548941
    Problem id : 1081
    Exe.time : 15MS
    Exe.memory : 5384K
    https://github.com/townboy
******************************


#include<stdio.h>
int val[120][120],map[120][120][120];
int main()
{
    int max,n,i,f,sum,last,g,dep;
    while(scanf("%d",&n)!=EOF)
    { 
        for(i=1;i<=n;i++)
        {
            for(f=1;f<=n;f++)
            {
                scanf("%d",&val[i][f]);
            }
        }
        for(i=1;i<=n;i++)
        {
            for(dep=0;dep<=n-1;dep++)
            {
                sum=0;
                for(f=1;f<=1+dep;f++)
                {
                     sum=sum+val[f][i];
                }
                map[i][1][1+dep]=sum;
                for(f=2+dep;f<=n;f++)
                {
                    sum=sum+val[f][i]-val[f-dep-1][i];
                    map[i][f-dep][f]=sum;
                }
            }
        }
        max=-1000000;
        for(i=1;i<=n;i++)
        {
            for(f=i;f<=n;f++)
            {
                last=0;
                for(g=1;g<=n;g++)
                {
                    if(last>0)
                    {
                        last=last+map[g][i][f];
                    }
                    else
                    {
                        last=map[g][i][f];
                    }
                    if(last>max)
                    {
                        max=last;
                    }
                }
            }
        }
        printf("%d\n",max);
    }
    return 0;
}