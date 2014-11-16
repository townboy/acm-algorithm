******************************
    Author : townboy
    Submit time : 2012-04-14 00:35:25
    Judge Status : Accepted
    HDOJ Runid : 5770308
    Problem id : 1052
    Exe.time : 46MS
    Exe.memory : 228K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

int cmp(const void *a,const void *b)
{
    return *(int *)a-*(int *)b;
}

int tmin,tmax,kmax,kmin,ht[1100],hk[1100],tian[1100],king[1100],n;

int getmin()
{
    int i;
    for(i=0;i<n;i++)
    {
        if(0==ht[i])
        {
            tmin=i;
            break;
        }
    }
    for(i=0;i<n;i++)
    {
        if(0==hk[i])
        {
            kmin=i;
            break;
        }
    }
    if(i==n)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int getmax()
{
    int i;
    for(i=n-1;i>-1;i--)
    {
        if(0==ht[i])
        {
            tmax=i;
            break;
        }
    }
    for(i=n-1;i>-1;i--)
    {
        if(0==hk[i])
        {
            kmax=i;
            break;
        }
    }
    if(-1==i)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

void chu()
{
    memset(ht,0,sizeof(ht));
    memset(hk,0,sizeof(hk));
}

int main()
{
    int i,sum;
    while(scanf("%d",&n),n)
    {
        chu();
        
        for(i=0;i<n;i++)
        {
            scanf("%d",&tian[i]);
        }
        
        for(i=0;i<n;i++)
        {
            scanf("%d",&king[i]);
        }
        
        qsort(tian,n,sizeof(tian[0]),cmp);
        
        qsort(king,n,sizeof(king[0]),cmp);
        
        sum=0;
        while(1==getmax())
        {
            if(tian[tmax]>king[kmax])
            {
                sum+=200;
                ht[tmax]=1;
                hk[kmax]=1;
                continue;
            }
            if(tian[tmax]<king[kmax])
            {
                getmin();
                sum-=200;
                ht[tmin]=1;
                hk[kmax]=1;
                continue;
            }
            else
            {
                getmin();
                if(tian[tmin]<king[kmin])
                {
                    sum-=200;
                    ht[tmin]=1;
                    hk[kmax]=1;
                    continue;  
                }
                if(tian[tmin]==king[kmin])
                {
                    if(tian[tmin]==king[kmax])
                    {
                        break;
                    }
                    sum-=200;
                    ht[tmin]=1;
                    hk[kmax]=1;
                    continue;  
                }
                if(tian[tmin]>king[kmin])
                {
                    ht[tmin]=1;
                    hk[kmin]=1;
                    sum+=200;
                    continue;
                }
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}
