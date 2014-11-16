******************************
    Author : townboy
    Submit time : 2012-02-03 00:08:30
    Judge Status : Accepted
    HDOJ Runid : 5308402
    Problem id : 1548
    Exe.time : 0MS
    Exe.memory : 148K
    https://github.com/townboy
******************************


#include<stdio.h>
int k[300],hash[300],s,e,num;
struct node 
{
    int val;
    int time;
};
struct node que[10000],tem;
int bfs()
{
    int head,tail;
    head=0;
    tail=0;
    que[head].time=0;
    que[head].val=s;
    while(head<=tail)
    {
        tem=que[head];
        head++;
        if(tem.val==e)
        {
            return tem.time;
        }
        if(tem.val+k[tem.val]<=num&&tem.val+k[tem.val]>=1)
        {
            if(0==hash[tem.val+k[tem.val]])
            {
                hash[tem.val+k[tem.val]]=1;
                tail++;
                que[tail].val=tem.val+k[tem.val];
                que[tail].time=tem.time+1;
            }
        }
        if(tem.val+-k[tem.val]<=num&&tem.val-k[tem.val]>=1)
        {
            if(0==hash[tem.val-k[tem.val]])
            {
                hash[tem.val-k[tem.val]]=1;
                tail++;
                que[tail].val=tem.val-k[tem.val];
                que[tail].time=tem.time+1;
            }
        }
    }
    return -1;
}
int main(void)
{
    int i;
    while(scanf("%d",&num),num)
    {
        scanf("%d%d",&s,&e);
        for(i=1;i<=num;i++)
        {
            scanf("%d",&k[i]);
            hash[i]=0;
        }
        printf("%d\n",bfs());
    }
    return 0;
}