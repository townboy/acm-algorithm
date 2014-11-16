******************************
    Author : townboy
    Submit time : 2012-02-09 22:57:10
    Judge Status : Accepted
    HDOJ Runid : 5335085
    Problem id : 1180
    Exe.time : 0MS
    Exe.memory : 180K
    https://github.com/townboy
******************************


#include<stdio.h>
int dir[4][2]={0,1,1,0,0,-1,-1,0},hash[25][25][5],si,sf,ei,ef;
char map[25][25];
struct node
{
    int x;
    int y;
    int tai;
    int time;
};
struct node que[500000],tem;
int bfs()
{
    int i,head,tail;
    head=0;
    tail=0;
    que[head].x=si;
    que[head].y=sf;
    que[head].tai=0;
    que[head].time=0;
    hash[si][sf][0]=1;
    while(head<=tail)
    {
        tem=que[head];
        head++;
        if(tem.x==ei&&tem.y==ef)
        {
            return tem.time;
        }
        if(0==hash[tem.x][tem.y][1-tem.tai])
        {
            hash[tem.x][tem.y][1-tem.tai]=1;
            tail++;
            que[tail].x=tem.x;
            que[tail].y=tem.y;
            que[tail].tai=1-tem.tai;
            que[tail].time=tem.time+1;
        }
        for(i=0;i<4;i++)
        {
            if('*'==map[tem.x+dir[i][0]][tem.y+dir[i][1]])
            {
                continue;
            }
            if('.'==map[tem.x+dir[i][0]][tem.y+dir[i][1]])
            {
                if(1==hash[tem.x+dir[i][0]][tem.y+dir[i][1]][1-tem.tai])
                {
                    continue;
                }
                hash[tem.x+dir[i][0]][tem.y+dir[i][1]][1-tem.tai]=1;
                tail++;
                que[tail].x=tem.x+dir[i][0];
                que[tail].y=tem.y+dir[i][1];
                que[tail].tai=1-tem.tai;
                que[tail].time=tem.time+1;
            }
            else
            {
                if((map[tem.x+dir[i][0]][tem.y+dir[i][1]]+tem.tai)%2==i%2)
                {
                    if('*'==map[tem.x+2*dir[i][0]][tem.y+2*dir[i][1]])
                    {
                        continue;
                    }
                    if(1==hash[tem.x+2*dir[i][0]][tem.y+2*dir[i][1]][1-tem.tai])
                    {
                        continue;
                    }
                    hash[tem.x+2*dir[i][0]][tem.y+2*dir[i][1]][1-tem.tai]=1;
                    tail++;
                    que[tail].x=tem.x+2*dir[i][0];
                    que[tail].y=tem.y+2*dir[i][1];
                    que[tail].tai=1-tem.tai;
                    que[tail].time=tem.time+1;
                }
            }
        }
    }
    return -1;
}
int main()
{
    int i,f,res,m,n,g;
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        getchar();
        for(i=0;i<=m+1;i++)
        {
            for(f=0;f<=n+1;f++)
            { 
                map[i][f]='*';
            }
        }
        for(i=1;i<=m;i++)
        {
            for(f=1;f<=n;f++)
            {
                for(g=0;g<2;g++)
                {
                    hash[i][f][g]=0;
                }
                scanf("%c",&map[i][f]);
                if('S'==map[i][f])
                {
                    si=i;
                    sf=f;
                    map[i][f]='.';
                }
                else if('T'==map[i][f])
                {
                    ei=i;
                    ef=f;
                    map[i][f]='.';
                }
                else if('-'==map[i][f])
                {
                    map[i][f]=0;
                }
                else if('|'==map[i][f])
                {
                    map[i][f]=1;
                }
            }
            getchar();
        }
        res=bfs();
        printf("%d\n",res);
    }
    return 0;
}