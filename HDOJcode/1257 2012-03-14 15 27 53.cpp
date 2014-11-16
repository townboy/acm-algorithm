******************************
    Author : townboy
    Submit time : 2012-03-14 15:27:53
    Judge Status : Accepted
    HDOJ Runid : 5545150
    Problem id : 1257
    Exe.time : 15MS
    Exe.memory : 228K
    https://github.com/townboy
******************************


#include<stdio.h>
int q[100000],min[100000];
int main()
{
    int i,r,l,m,ji,n;
    while(scanf("%d",&n)!=EOF)
    {
        ji=0;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&q[i]);
        }
        min[0]=0;
        for(i=1;i<=n;i++)
        {
            if(q[i]>min[ji])
            {
                ji++;
                min[ji]=q[i];
            }
            else
            {
                l=1;
                r=ji;
                while(r>=l)
                {
                    m=(l+r)>>1;
                    if(q[i]<=min[m]&&min[m-1]<q[i])
                    {
                        min[m]=q[i];
                        break;
                    }
                    else if(q[i]>min[m])
                    {
                        l=m+1;
                    }
                    else
                    {
                        r=m-1;
                    }
                }
            }
        }
        printf("%d\n",ji);        
    }
    return 0;
}