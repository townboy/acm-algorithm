******************************
    Author : townboy
    Submit time : 2012-06-23 18:10:30
    Judge Status : Accepted
    HDOJ Runid : 6094010
    Problem id : 2578
    Exe.time : 437MS
    Exe.memory : 360K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<stdlib.h>

int n,que[110000];

int cmp(void const *a, void const *b)
{
    return *(int*)a-*(int*)b;    
}

int bs(int x)
{
    int l,r,mid;
    l=0;
    r=n-1;
    while(l <= r)
    {
        mid=(l+r)>>1;
        if(x == que[mid])
        {
            return 1;
        }
        if(x < que[mid])
        {
            r=mid-1;
        }
        else
        {
            l=mid+1;
        }
    }
    return 0;
}

int main()
{
    int num,k,i,f,ans,last;
//    freopen("D:\\in.txt","r",stdin);
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        scanf("%d%d",&n,&k);
        for(f=0;f<n;f++)
        {
            scanf("%d",&que[f]);
        }
        qsort(que,n,sizeof(que[0]),cmp);
        
        last=-1;
        ans=0;
        for(f=0;f<n;f++)
        {
            if(last == que[f])
            {
                continue;
            }
            last=que[f];
            if(1 == bs(k-que[f]))
            {
                ans++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}