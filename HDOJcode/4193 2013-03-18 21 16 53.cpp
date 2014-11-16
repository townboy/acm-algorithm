******************************
    Author : townboy
    Submit time : 2013-03-18 21:16:53
    Judge Status : Accepted
    HDOJ Runid : 7803036
    Problem id : 4193
    Exe.time : 765MS
    Exe.memory : 19932K
    https://github.com/townboy
******************************


#include<stdio.h>

int n,val[2000010];
__int64 sum[2000010];
int left,right,que[2000010];

void init()
{
    left=0;
    right=-1;
}    

void que_push(int pos)
{
    while(right >= left)
    {
        if(sum[pos] <= sum[que[right]])
            right--;
        else
            break;
    }
    right++;
    que[right]=pos;
}

void que_pop(int pos)
{
    if(que[left] == pos)
        left++;
}

void debug()
{
    int i;
    for(i=0;i<2*n;i++)
        printf("%d ",sum[i]);
    printf("\n");
}

int main()
{
    int i,ans;
    while(scanf("%d",&n),n)
    {
        init();
        ans=0;
        for(i=0;i<n;i++)
            scanf("%d",val+i);
    
        sum[0]=val[0];
        for(i=0;i<n;i++)
        {
            sum[i]=sum[i-1]+val[i];
            que_push(i);
        }
        for(i=n;i<2*n;i++)
        {
            sum[i]=sum[i-1]+val[i-n];
            que_pop(i-n);
            que_push(i);
            if(sum[que[left]]-sum[i-n] >= 0)
                ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}