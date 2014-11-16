******************************
    Author : townboy
    Submit time : 2012-02-15 23:26:07
    Judge Status : Accepted
    HDOJ Runid : 5358899
    Problem id : 1242
    Exe.time : 31MS
    Exe.memory : 1072K
    https://github.com/townboy
******************************


#include<stdio.h>
int dir[4][2]={0,1,0,-1,1,0,-1,0},hash[220][220][5],si,sf;
char map[220][220];
struct node
{
    int x;
    int y;
    int tai;
    int time;
};
struct node que[50000],tem;
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
        if('r'==map[tem.x][tem.y])
        {
            return tem.time;
        }
        if(0==tem.tai)
        {
            for(i=0;i<4;i++)
            {
                if('#'==map[tem.x+dir[i][0]][tem.y+dir[i][1]])
                {
                    continue;
                }
                if('x'==map[tem.x+dir[i][0]][tem.y+dir[i][1]])
                {
                    if(1==hash[tem.x+dir[i][0]][tem.y+dir[i][1]][1])
                    {
                        continue;
                    }
                    hash[tem.x+dir[i][0]][tem.y+dir[i][1]][1]=1;
                    tail++;
                    que[tail].x=tem.x+dir[i][0];
                    que[tail].y=tem.y+dir[i][1];
                    que[tail].tai=1;
                    que[tail].time=tem.time+1;
                }
                else
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
                }
            }
        }
        else
        {
            hash[tem.x][tem.y][0]=1;
            tail++;
            que[tail].x=tem.x;
            que[tail].y=tem.y;
            que[tail].tai=0;
            que[tail].time=tem.time+1;
        }
    }
    return -1;
}
int main()
{
    int i,f,g,m,n,res;
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        getchar();
        for(i=0;i<=m+1;i++)
        {
            for(f=0;f<=n+1;f++)
            {
                map[i][f]='#';
                for(g=0;g<=1;g++)
                {
                    hash[i][f][g]=0;
                }
            }
        }
        for(i=1;i<=m;i++)
        {
            for(f=1;f<=n;f++)
            {
                scanf("%c",&map[i][f]);
                if('a'==map[i][f])
                {
                    si=i;    
                    sf=f;
                }
            }
            getchar();
        }
        res=bfs();
        if(-1==res)
        {
            printf("Poor ANGEL has to stay in the prison all his life.\n");
        }
        else
        {
            printf("%d\n",res);
        }       
    }
    return 0;
}