******************************
    Author : townboy
    Submit time : 2012-02-04 01:44:42
    Judge Status : Accepted
    HDOJ Runid : 5312300
    Problem id : 1072
    Exe.time : 0MS
    Exe.memory : 176K
    https://github.com/townboy
******************************


#include<stdio.h>
int hash[10][10][10],dir[8][2]={0,1,0,-1,1,0,-1,0},si,sf;
int map[10][10];
struct node
{
    int x;
    int y;
    int time;
    int val;
};
struct node que[10000],tem;
int bfs()
{
    int head,tail,i;
    head=0;
    tail=0;
    que[head].x=si;
    que[head].y=sf;
    que[head].time=0;
    que[head].val=6;
    while(head<=tail)
    {
        tem=que[head];
        head++;
        if(tem.val<=0)
        {
            continue;
        }
        if(3==map[tem.x][tem.y])
        {
            return tem.time;
        }
        if(0==map[tem.x][tem.y])
        {
            continue;
        }
        if(1==hash[tem.x][tem.y][tem.val])
        {
            continue;
        }
        hash[tem.x][tem.y][tem.val]=1;
        if(4==map[tem.x][tem.y])
        {
            tem.val=6;
        }
        for(i=0;i<8;i++)
        {
            tail++;
            que[tail].x=tem.x+dir[i][0];
            que[tail].y=tem.y+dir[i][1];
            que[tail].val=tem.val-1;
            que[tail].time=tem.time+1;
        }
    }
    return -1;
}
int main(void)
{
    int num,i,f,g,h,m,n;
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        scanf("%d%d",&m,&n);
        for(f=0;f<=m+1;f++)
        {
            for(g=0;g<=n+1;g++)
            {
                for(h=0;h<7;h++)
                {
                    hash[f][g][h]=1;
                }
            }
        }
        for(f=1;f<=m;f++)
        {
            for(g=1;g<=n;g++)
            {
                for(h=0;h<7;h++)
                {
                    hash[f][g][h]=0;
                }
            }
        }
        for(f=1;f<=m;f++)
        {
            for(g=1;g<=n;g++)
            {
                scanf("%d",&map[f][g]);
                if(2==map[f][g])
                {
                    si=f;
                    sf=g;
                }
            }
        }
        printf("%d\n",bfs());
    }
    return 0;
}