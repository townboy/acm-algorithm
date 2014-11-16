******************************
    Author : townboy
    Submit time : 2012-02-05 14:09:25
    Judge Status : Accepted
    HDOJ Runid : 5317473
    Problem id : 1026
    Exe.time : 15MS
    Exe.memory : 4796K
    https://github.com/townboy
******************************


#include<stdio.h>
int m,n,dir[4][2]={0,1,0,-1,1,0,-1,0},hash[110][110][99];
char map[110][110];
struct node
{
    int x;
    int y;
    int tai;
    int time;
    struct node * p;
};
struct node que[20000],tem;
void pri(int num,struct node * p)
{
    int tai[1000][2],i;
    if(-1==num)
    {
        printf("God please help our poor hero.\nFINISH\n");
    }
    else
    {
        for(i=0;i<=num;i++)
        {
            tai[i][0]=(*p).x;
            tai[i][1]=(*p).y;
            p=(*p).p;
        }
        printf("It takes %d seconds to reach the target position, let me show you the way.\n",num);
        for(i=num;i>0;i--)
        {
            if(tai[i][0]==tai[i-1][0]&&tai[i][1]==tai[i-1][1])
            {
                printf("%ds:FIGHT AT (%d,%d)\n",num-i+1,tai[i][0]-1,tai[i][1]-1);
            }
            else
            {
                printf("%ds:(%d,%d)->(%d,%d)\n",num-i+1,tai[i][0]-1,tai[i][1]-1,tai[i-1][0]-1,tai[i-1][1]-1);
            }
        }
        printf("FINISH\n");
    }
}
void bfs()
{
    int i,head,tail;
    head=0;
    tail=0;
    que[head].x=1;
    que[head].y=1;
    que[head].tai=0;
    que[head].time=0;
    que[head].p=NULL;
    hash[1][1][0]=1;
    while(head<=tail)
    {
        tem=que[head];
        head++;
        if(tem.x==m&&tem.y==n)
        {
            if('.'==map[tem.x][tem.y])
            {
                pri(tem.time,&que[head-1]);
                return ;
            }
            else
            {
                if(1==tem.tai)
                {
                    pri(tem.time,&que[head-1]);
                    return ;
                }
            }
        }
        if('X'==map[tem.x][tem.y])
        {
            continue;
        }
        if('.'==map[tem.x][tem.y])
        {
            for(i=0;i<4;i++)
            {
                if(1==hash[tem.x+dir[i][0]][tem.y+dir[i][1]][0])
                {
                    continue;
                }
                hash[tem.x+dir[i][0]][tem.y+dir[i][1]][0]=1;
                tail++;
                que[tail].x=tem.x+dir[i][0];
                que[tail].y=tem.y+dir[i][1];
                que[tail].tai=0;
                que[tail].time=tem.time+1;
                que[tail].p=&que[head-1];
            }
        }
        else
        {
            if(0==tem.tai)
            {
                   if(1==hash[tem.x][tem.y][map[tem.x][tem.y]-'0'])
                {
                    continue;
                }
                hash[tem.x][tem.y][map[tem.x][tem.y]-'0']=1;
                tail++;
                que[tail].x=tem.x;
                que[tail].y=tem.y;
                que[tail].tai=map[tem.x][tem.y]-'0';
                que[tail].time=tem.time+1;
                que[tail].p=&que[head-1];
            
            }
            else if(1!=tem.tai)
            {
                hash[tem.x][tem.y][tem.tai-1]=1;
                tail++;
                que[tail].x=tem.x;
                que[tail].y=tem.y;
                que[tail].tai=tem.tai-1;
                que[tail].time=tem.time+1;
                que[tail].p=&que[head-1];
            }
            else
            {
                for(i=0;i<4;i++)
                {
                    if(1==hash[tem.x+dir[i][0]][tem.y+dir[i][1]][0])
                    {
                        continue;
                    }
                    hash[tem.x+dir[i][0]][tem.y+dir[i][1]][0]=1;
                    tail++;
                    que[tail].x=tem.x+dir[i][0];
                    que[tail].y=tem.y+dir[i][1];
                    que[tail].tai=0;
                    que[tail].time=tem.time+1;
                     que[tail].p=&que[head-1];
                }  
            }
        }
    }
    pri(-1,NULL);
    return ;
}
int main(void)
{
    int i,f,g;
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        getchar();
        for(i=0;i<=m+1;i++)
        {
            for(f=0;f<=n+1;f++)
            {
                for(g=0;g<=90;g++)
                {
                    hash[i][f][g]=1;
                }
            }
        }
        for(i=1;i<=m;i++)
        {
            for(f=1;f<=n;f++)
            {
                scanf("%c",&map[i][f]);
                for(g=0;g<=90;g++)
                {
                    hash[i][f][g]=0;
                }
            }
            getchar();
        }
        bfs();
    }
    return 0;
}