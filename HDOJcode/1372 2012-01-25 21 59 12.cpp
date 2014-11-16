******************************
    Author : townboy
    Submit time : 2012-01-25 21:59:12
    Judge Status : Accepted
    HDOJ Runid : 5294217
    Problem id : 1372
    Exe.time : 15MS
    Exe.memory : 184K
    https://github.com/townboy
******************************


#include<stdio.h>
int hash[20][20],dir[8][2]={1,2,2,1,-1,2,2,-1,-1,-2,-2,-1,1,-2,-2,1},ei,ef,ai,af,res;
struct node
{
    int x;
    int y;
    int time;
};
struct node que[50000],tem;
int bfs(void)
{
    int head,tail,i;
    head=0;
    tail=0;
    que[head].x=ai;
    que[head].y=af;
    que[head].time=0;
    while(head<=tail)
    {
        tem=que[head];
        head++;
        if(1==hash[tem.x][tem.y])
        {
            continue;
        }
        if(ei==tem.x&&ef==tem.y)
        {
            return tem.time;
        }
        hash[tem.x][tem.y]=1;
        for(i=0;i<8;i++)
        {
            tail++;
            que[tail].x=tem.x+dir[i][0];
            que[tail].y=tem.y+dir[i][1];
            que[tail].time=tem.time+1;
        }
    }
    return -1;
}
int main(void)
{
    int i,f;
    char ch[10];
    while(gets(ch)!=NULL)
    {
        for(i=0;i<=11;i++)
        {
            for(f=0;f<=11;f++)
            {
                hash[i][f]=1;
            }
        }
        for(i=2;i<10;i++)
        {
            for(f=2;f<10;f++)
            {
                hash[i][f]=0;
            }
        }
        ai=ch[0]-'a'+2;
        af=ch[1]-'1'+2;
        ei=ch[3]-'a'+2;
        ef=ch[4]-'1'+2;
        res=bfs();
        printf("To get from %c%c to %c%c takes %d knight moves.\n",ch[0],ch[1],ch[3],ch[4],res);
    }
    return 0;
}