******************************
    Author : townboy
    Submit time : 2012-02-08 01:01:52
    Judge Status : Accepted
    HDOJ Runid : 5327862
    Problem id : 2822
    Exe.time : 281MS
    Exe.memory : 28616K
    https://github.com/townboy
******************************


#include<stdio.h>
int dir[4][2]={0,1,0,-1,1,0,-1,0},head,tail,hash[1010][1010],si,sf,ei,ef;
char map[1010][1010];
struct node 
{
    int x;
    int y;
    int time;
};
struct node que[1001000],que2[1001000],tem,tem2;
void srh(int x,int y,int time)
{
    int head2,tail2,i;
    head2=0;
    tail2=0;
    que2[head2].x=x;
    que2[head2].y=y;
    que2[head2].time=time;
    while(head2<=tail2)
    {
        tem2=que2[head2];
        head2++;
        for(i=0;i<4;i++)
        {
            if((0==hash[tem2.x+dir[i][0]][tem2.y+dir[i][1]])&&('X'==map[tem2.x+dir[i][0]][tem2.y+dir[i][1]]))
            {
                hash[tem2.x+dir[i][0]][tem2.y+dir[i][1]]=1;
                tail2++;
                que2[tail2].x=tem2.x+dir[i][0];   
                que2[tail2].y=tem2.y+dir[i][1];
                que2[tail2].time=tem2.time;
                tail++;
                que[tail].x=tem2.x+dir[i][0];   
                que[tail].y=tem2.y+dir[i][1];
                que[tail].time=tem2.time;
            }
        }
    }
}
int bfs()
{
    int i;
    head=0;
    tail=0;
    que[head].x=si;
    que[head].y=sf;
    que[head].time=0;
    hash[si][sf]=1;
    srh(si,sf,0);
    while(head<=tail)
    {
        tem=que[head];
        head++;
        if(tem.x==ei&&tem.y==ef)
        {
            return tem.time;
        }
        for(i=0;i<4;i++)
        {
            if(1==hash[tem.x+dir[i][0]][tem.y+dir[i][1]])
            {
                continue;
            }
            hash[tem.x+dir[i][0]][tem.y+dir[i][1]]=1;
            tail++;
            que[tail].x=tem.x+dir[i][0];
            que[tail].y=tem.y+dir[i][1];
            que[tail].time=tem.time+1;
            srh(tem.x+dir[i][0],tem.y+dir[i][1],tem.time+1);
        }
    }
    return -1;
}
int main()
{
    int m,n,i,f,res;
    while(scanf("%d%d",&m,&n),!(0==m&&0==n))
    {
        getchar();
        for(i=0;i<=m+1;i++)
        {
            for(f=0;f<=n+1;f++)
            {
                hash[i][f]=1;
            }
        }
        for(i=1;i<=m;i++)
        {
            for(f=1;f<=n;f++)
            {
                scanf("%c",&map[i][f]);
                hash[i][f]=0;
            }
            getchar();
        }
        scanf("%d%d%d%d",&si,&sf,&ei,&ef);
        res=bfs();
        printf("%d\n",res);
    }
    return 0;
}