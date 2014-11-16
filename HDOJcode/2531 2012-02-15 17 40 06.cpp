******************************
    Author : townboy
    Submit time : 2012-02-15 17:40:06
    Judge Status : Accepted
    HDOJ Runid : 5356881
    Problem id : 2531
    Exe.time : 93MS
    Exe.memory : 396K
    https://github.com/townboy
******************************


#include<stdio.h>
int dir[4][2]={0,1,0,-1,1,0,-1,0},hash[150][150],fang[30][30],mini,minf;
char map[150][150];
struct node
{
    int x;
    int y;
    int time;
};
struct node que[15000],tem;
int check(int x,int y)
{
    int i,f;
    for(i=0;i<=25;i++)
    {
        for(f=0;f<=25;f++)
        {
            if(1==fang[i][f])
            {
                if('O'==map[x+i][y+f])
                {
                    return 0;
                }
            } 
        }
    }
    return 1;
}
int chemu(int x,int y)
{
    int i,f;
    for(i=0;i<=25;i++)
    {
        for(f=0;f<=25;f++)
        {
            if(1==fang[i][f])
            {
                if('Q'==map[x+i][y+f])
                {
                    return 1;
                }
            }    
        }
    }
    return 0;
}
int bfs()
{
    int i,head,tail;
    head=0;
    tail=0;
    que[head].x=mini;
    que[head].y=minf;
    que[head].time=0;
    hash[mini][minf]=1;
    while(head<=tail)
    {
        tem=que[head];
        head++;
        if(1==chemu(tem.x,tem.y))
        {
            return tem.time;
        }
        for(i=0;i<4;i++)
        {
            if(0==hash[tem.x+dir[i][0]][tem.y+dir[i][1]]&&1==check(tem.x+dir[i][0],tem.y+dir[i][1]))
            {
                hash[tem.x+dir[i][0]][tem.y+dir[i][1]]=1;
                tail++;
                que[tail].x=tem.x+dir[i][0];
                que[tail].y=tem.y+dir[i][1];
                que[tail].time=tem.time+1;
            }
        }
    }
    return -1;
}
int main()
{
    int i,f,m,n,res;
    while(scanf("%d%d",&m,&n),!(0==m&&0==n))
    {
        for(i=0;i<=140;i++)
        {
            for(f=0;f<=140;f++)
            {
                hash[i][f]=0;
                map[i][f]='O';
            }
        }
        getchar();
        mini=m+1;
        minf=n+1;
        for(i=1;i<=m;i++)
        {
            scanf("%s",&map[i][1]);
            map[i][n+1]='O';
            for(f=1;f<=n;f++)
            {
                  if('D'==map[i][f])
                {
                    if(i<mini)
                    {
                        mini=i;
                    }
                    if(f<minf)
                    {
                        minf=f;
                    }
                }
            }
        }
        for(i=0;i<=25;i++)
        {
            for(f=0;f<=25;f++)
            {
                fang[i][f]=0;
            }
        }
        for(i=0;i<=25;i++)
        {
            for(f=0;f<=25;f++)
            {
                if('D'==map[i+mini][f+minf])
                {
                    fang[i][f]=1;
                }
            }
        }
        res=bfs();
        if(-1==res)
        {
            printf("Impossible\n");
        }
        else
        {
            printf("%d\n",res);
        }
    }
    return 0;
}