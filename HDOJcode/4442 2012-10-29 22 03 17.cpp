******************************
    Author : townboy
    Submit time : 2012-10-29 22:03:17
    Judge Status : Accepted
    HDOJ Runid : 7035617
    Problem id : 4442
    Exe.time : 156MS
    Exe.memory : 2580K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<stdlib.h>

__int64 sum,left;
int n,mod=365*24*60*60;
struct node
{
    __int64 old;
    __int64 add;
    double ans;
};
struct node que[110000];

int cmp(const void*a,const void *b)
{
    return (*(struct node*)b).ans>(*(struct node*)a).ans?1:-1;
}

int main()
{
    int old,add,i,ji;
    while(scanf("%d",&n),n)
    {
        sum=0;
        ji=0;
        left=0; 
        for(i=0;i<n;i++)
        {
            scanf("%d%d",&old,&add);
            if(0 == old*add)
            {
                left+=old;
                left%=mod; 
                continue;
            }
             que[ji].old=old;
            que[ji].add=add; 
            que[ji].ans=(double)que[ji].add/que[ji].old;
            ji++;
        }
        qsort(que,ji,sizeof(que[0]),cmp);
        for(i=0;i<ji;i++)
        {
            sum+=(sum*que[i].add+que[i].old)%mod;
            sum%=mod;
        }
        printf("%I64d\n",(left+sum)%mod); 
    }
    return 0;
}