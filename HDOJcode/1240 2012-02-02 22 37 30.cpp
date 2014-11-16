******************************
    Author : townboy
    Submit time : 2012-02-02 22:37:30
    Judge Status : Accepted
    HDOJ Runid : 5308095
    Problem id : 1240
    Exe.time : 0MS
    Exe.memory : 180K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<string.h>
int si,sf,sg,ei,ef,eg,dir[8][3]={0,0,1,0,0,-1,0,1,0,0,-1,0,1,0,0,-1,0,0},hash[15][15][15];
char map[20][20][20];
struct node
{
    int x;
    int y;
    int z;
    int time;
};
struct node que[10000],tem;
int bfs()
{
    int head,tail,i;
    head=0;
    tail=0;
    que[head].time=0;
    que[head].x=si+1;
    que[head].y=sf+1;
    que[head].z=sg+1;
    while(head<=tail)
    {
        tem=que[head];
        head++;
        if(tem.x==ei+1&&tem.y==ef+1&&tem.z==eg+1)
        {
            return tem.time;
        }
        if(1==hash[tem.x][tem.y][tem.z])
        {
            continue;
        }
        hash[tem.x][tem.y][tem.z]=1;
        if('X'==map[tem.x][tem.y][tem.z])
        {
            hash[tem.x][tem.y][tem.z]=1;
            continue;
        }
        for(i=0;i<8;i++)
        {
            tail++;
            que[tail].x=tem.x+dir[i][0];
            que[tail].y=tem.y+dir[i][1];
            que[tail].z=tem.z+dir[i][2];
            que[tail].time=tem.time+1;
        }
    }
    return -1;
}
int main(void)
{
    int n,i,f,g,len,res;
    char ch[15];
    while(gets(ch)!=NULL)
    {
        len=strlen(ch);
        if(8==len)
        {
            n=10;
        }
        else
        {
            n=ch[6]-'0';
        }
        for(i=1;i<=n;i++)
        {
            for(f=1;f<=n;f++)
            {
                for(g=1;g<=n;g++)
                {
                    scanf("%c",&map[f][g][i]);
                }
                getchar();
            }
        }
        scanf("%d%d%d",&si,&sf,&sg);
        scanf("%d%d%d",&ei,&ef,&eg);
        getchar();
        gets(ch);
        for(i=0;i<=n+1;i++)
        {
            for(f=0;f<=n+1;f++)
            {
                for(g=0;g<=n+1;g++)
                {
                    hash[i][f][g]=1;
                }
            }
        }
        for(i=1;i<=n;i++)
        {
            for(f=1;f<=n;f++)
            {
                for(g=1;g<=n;g++)
                {
                    hash[i][f][g]=0;
                }
            }
        }
        res=bfs();
        if(-1==res)
        {
            printf("NO ROUTE\n");
        }
        else
        {
            printf("%d %d\n",n,res);
        }
    }
    return 0;
}