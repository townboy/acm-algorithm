******************************
    Author : townboy
    Submit time : 2012-04-06 20:50:18
    Judge Status : Accepted
    HDOJ Runid : 5719968
    Problem id : 4190
    Exe.time : 750MS
    Exe.memory : 2196K
    https://github.com/townboy
******************************


#include<stdio.h>

int n,zan[510000];
int maxx(int a,int b)
{
    return a>b?a:b;
}

int fun(int mid)
{
    int i,sum;
    sum=0;
    for(i=0;i<n;i++)
    {
        if((double)zan[i]/mid==zan[i]/mid)
        {
            sum+=(zan[i]/mid);
        }
        else
        {
            sum+=(zan[i]/mid+1);
        }
    }  
    return sum;
}

int main()
{
    int k,max,l,r,mid,i;
//    freopen("D:\\in.txt","r",stdin);
    while(scanf("%d%d",&n,&k),!(-1==n&&-1==k))
    {
        max=-1;
        for(i=0;i<n;i++)
        {
            scanf("%d",&zan[i]);
            max=maxx(max,zan[i]);
        }
        if(n==k)
        {
            printf("%d\n",max);
            continue;
        }
        l=0;
        r=max;
        while(l!=r)
        {
            mid=(l+r)>>1;
            if(fun(mid)<=k)
            { 
                r=mid;
            }
            else
            {
                l=mid+1;
            }
        }
        printf("%d\n",r);
    }
    return 0;
}