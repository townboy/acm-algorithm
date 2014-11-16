******************************
    Author : townboy
    Submit time : 2012-07-27 21:03:06
    Judge Status : Accepted
    HDOJ Runid : 6355832
    Problem id : 4311
    Exe.time : 78MS
    Exe.memory : 5720K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int x,y;
    __int64 u,d,l,r;
};
struct node que[110000];

struct xx 
{
    int val;
    int id;
};
struct xx x[110000],y[110000];
__int64 k;

int cmp(const void*a,const void*b)
{
    return (*(struct xx *)a).val - (*(struct xx *)b).val;
}

void cal()
{
    __int64 ans;
    __int64 i;
    ans=0;
    que[x[0].id].l=0;
    for(i=1;i<k;i++)
    {
        ans+=(x[i].val-x[i-1].val)*(i);
        que[x[i].id].l=ans;
    }
    ans=0;
    que[x[k-1].id].r=0;
    for(i=k-2;i>=0;i--)
    {
        ans+=(x[i+1].val-x[i].val)*(k-(i+1));
        que[x[i].id].r=ans;
    }
    
    ans=0;
    que[y[0].id].d=0;
    for(i=1;i<k;i++)
    {
        ans+=(y[i].val-y[i-1].val)*(i);
        que[y[i].id].d=ans;
    }
    ans=0;
    que[x[k-1].id].u=0;
    for(i=k-2;i>=0;i--)
    {
        ans+=(y[i+1].val-y[i].val)*(k-(i+1));
        que[y[i].id].u=ans;
    }
}

int main()
{
    __int64 ans;
    int num,i,f;
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        scanf("%I64d",&k);
        for(f=0;f<k;f++)
        {
            scanf("%d%d",&que[f].x,&que[f].y);
            x[f].val=que[f].x;
            x[f].id=f;
            y[f].val=que[f].y;
            y[f].id=f;
        }
        qsort(x,k,sizeof(x[0]),cmp);
        qsort(y,k,sizeof(y[0]),cmp);
        cal();
        ans=que[0].l+que[0].r+que[0].u+que[0].d;
        for(f=1;f<k;f++)
        {
            if(ans > que[f].l+que[f].r+que[f].u+que[f].d)
            {
                ans=que[f].l+que[f].r+que[f].u+que[f].d;            
            }    
        }        
        printf("%I64d\n",ans);
    }
    return 0;
}