******************************
    Author : townboy
    Submit time : 2012-02-06 19:40:00
    Judge Status : Accepted
    HDOJ Runid : 5323060
    Problem id : 2216
    Exe.time : 15MS
    Exe.memory : 1800K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<math.h>
#include<iostream>
using namespace std;
int hash[25][25][25][25],dir[4][2]={0,1,0,-1,1,0,-1,0},ax,ay,bx,by;
char map[25][25];
struct node
{
    int x1;
    int y1;
    int x2;
    int y2;
    int time;
};
struct node que[300000],tem;
int bfs()
{
    int head,tail,i;
    head=0;
    tail=0;
    que[head].x1=ax;
    que[head].y1=ay;
    que[head].x2=bx;
    que[head].y2=by;
    que[head].time=0;
    hash[ax][ay][bx][by]=1;
    while(head<=tail)
    {
        tem=que[head];
        head++;
        if(abs(tem.x1-tem.x2)+abs(tem.y1-tem.y2)<2)
        {
            return tem.time;
        }
        for(i=0;i<4;i++)
        {
            if('X'==map[tem.x1+dir[i][0]][tem.y1+dir[i][1]])
            {
                continue;
            }
            if('X'==map[tem.x2-dir[i][0]][tem.y2-dir[i][1]])
            {
                if(1==hash[tem.x1+dir[i][0]][tem.y1+dir[i][1]][tem.x2][tem.y2])
                {
                    continue;
                }
                hash[tem.x1+dir[i][0]][tem.y1+dir[i][1]][tem.x2][tem.y2]=1;
                tail++;
                que[tail].x1=tem.x1+dir[i][0];
                que[tail].y1=tem.y1+dir[i][1];
                que[tail].x2=tem.x2;
                que[tail].y2=tem.y2;
                que[tail].time=tem.time+1;
            }
            else
            {
                if(1==hash[tem.x1+dir[i][0]][tem.y1+dir[i][1]][tem.x2-dir[i][0]][tem.y2-dir[i][1]])
                {
                    continue;
                }
                hash[tem.x1+dir[i][0]][tem.y1+dir[i][1]][tem.x2-dir[i][0]][tem.y2-dir[i][1]]=1;
                tail++;
                que[tail].x1=tem.x1+dir[i][0];
                que[tail].y1=tem.y1+dir[i][1];
                que[tail].x2=tem.x2-dir[i][0];
                que[tail].y2=tem.y2-dir[i][1];
                que[tail].time=tem.time+1;
            }
        }
    }
    return -1;
}
int main()
{
    int i,f,g,h,m,n,res;
    while(scanf("%d%d",&m,&n)!=EOF)
    { 
        for(i=0;i<=m+1;i++)
        {
            for(f=0;f<=n+1;f++)
            { 
                map[i][f]='X';
                for(g=0;g<=m+1;g++)
                {
                    for(h=0;h<=n+1;h++)
                    {
                        hash[i][f][g][h]=0;
                    }
                }
            }
        
        }
        getchar();
        for(i=1;i<=m;i++)
        {
            gets(&map[i][1]);
            map[i][n+1]='X';
            for(f=1;f<=n;f++)
            {
                if('Z'==map[i][f])
                {
                    ax=i;
                    ay=f;
                }
                if('S'==map[i][f])
                {
                    bx=i;
                    by=f;
                }
            }
        }
        res=bfs();
        if(-1==res)
        {
            printf("Bad Luck!\n");
        }
        else
        {
            printf("%d\n",res);
        }
    }
    return 0;
}

