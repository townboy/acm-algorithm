******************************
    Author : townboy
    Submit time : 2012-01-18 18:35:13
    Judge Status : Accepted
    HDOJ Runid : 5272932
    Problem id : 2717
    Exe.time : 15MS
    Exe.memory : 2072K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>
int x,y,hash[250000];
struct node
{
    int x;
    int time;
};
struct node que[250000],tem;
int bfs()
{
    int head,tail;
    tail=0;
    head=0;
    que[head].x=x;
    que[head].time=0;
    while(head<=tail)
    {
        tem=que[head];
        head++;
        if(tem.x==y)
        {
            return tem.time;
        }
        if(tem.x-1>=0)
        {
            if(0==hash[tem.x-1])
            {
                hash[tem.x-1]=1;
                tail++;
                que[tail].x=tem.x-1;
                que[tail].time=tem.time+1;
            }
        }
        if(tem.x<y)
        {
            if(0==hash[tem.x+1])
            {
                hash[tem.x+1]=1;
                tail++;
                que[tail].x=tem.x+1;
                que[tail].time=tem.time+1;
            }
            if(0==hash[tem.x*2])
            {
                hash[tem.x*2]=1;
                tail++;
                 que[tail].x=tem.x*2;
                que[tail].time=tem.time+1;
            }
        }
    }
    return -1;
}
int main(void)
{
    while(scanf("%d%d",&x,&y)!=EOF)
    {
        if(x>=y)
        {
            printf("%d\n",x-y);
        }
        else
        {
            memset(hash,0,250000*sizeof(hash[0]));
            printf("%d\n",bfs());
        }
    }
return 0;
}
