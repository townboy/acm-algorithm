******************************
    Author : townboy
    Submit time : 2012-10-25 23:27:17
    Judge Status : Accepted
    HDOJ Runid : 7000683
    Problem id : 4430
    Exe.time : 2281MS
    Exe.memory : 236K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<math.h>

int flag;
__int64 r,n,ansr,ansk;

void chu()
{
    ansr=1;
    ansk=n-1;
}

void bs()
{
    __int64 ans,tem;
    int i,left=2,right=sqrt((double)n)+100,mid;
    while(left <= right)
    {
        mid=(left+right)>>1;
        
        tem=1;
        ans=1;
        for(i=0;i<r;i++)
        {
            tem*=mid;
            ans+=tem;
            if(tem < 0 || ans > n)
            {
                break;
            }
        }
        
        if(ans == n)
        {
            if(mid*r < ansr*ansk)
            {
                ansr=r;
                ansk=mid;
            }        
            return ;
        }
        
         if(ans < n)
        {
            left=mid+1;
        }
        else
        {
            right=mid-1;
        }
    }    
}

int main()
{
    int i,shangjie;
    while(scanf("%I64d",&n)!=EOF)
    {
        chu();
        shangjie=log10((double)n+1)/log10((double)2)+100;
        for(i=shangjie;i>1;i--)
        {
            r=i;
            bs();
            n++;
            bs();
            n--;
        }
        printf("%I64d %I64d\n",ansr,ansk);
    }
    return 0;
}