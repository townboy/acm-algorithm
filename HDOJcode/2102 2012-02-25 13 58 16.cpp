******************************
    Author : townboy
    Submit time : 2012-02-25 13:58:16
    Judge Status : Accepted
    HDOJ Runid : 5411512
    Problem id : 2102
    Exe.time : 0MS
    Exe.memory : 204K
    https://github.com/townboy
******************************


#include<stdio.h>
int dir[4][2]={0,1,0,-1,1,0,-1,0},si,sf,hash[2][20][20],sc,t;
char map[2][20][20];
struct node 
{
    int x;
    int y;
    int c;
    int time;
};
struct node que[1000000],tem;
int bfs()
{
    int i,head,tail;
    head=0;
    tail=0;
    que[head].c=sc;
    que[head].x=si;
    que[head].y=sf;
    que[head].time=0;
    hash[sc][si][sf]=1;
    while(head<=tail)
    {
        tem=que[head];
        head++;
        if(tem.time>t)
        {
            return 0;
        }
        if('P'==map[tem.c][tem.x][tem.y])
        {
            return 1;
        }
        for(i=0;i<4;i++)
        {
            if('*'==map[tem.c][tem.x+dir[i][0]][tem.y+dir[i][1]])
            {
                continue;
            }
            else if('#'==map[tem.c][tem.x+dir[i][0]][tem.y+dir[i][1]])
            {
                if('#'==map[1-tem.c][tem.x+dir[i][0]][tem.y+dir[i][1]])
                {
                    continue;
                }
                else if('*'==map[1-tem.c][tem.x+dir[i][0]][tem.y+dir[i][1]])
                {
                    continue;
                }
                else
                {
                    if(1==hash[1-tem.c][tem.x+dir[i][0]][tem.y+dir[i][1]])
                    {
                        continue;
                    }
                    hash[1-tem.c][tem.x+dir[i][0]][tem.y+dir[i][1]]=1;
                    tail++;
                    que[tail].x=tem.x+dir[i][0];
                    que[tail].y=tem.y+dir[i][1];
                    que[tail].c=1-tem.c;
                    que[tail].time=tem.time+1;
                }
            }
            else
            {
                if(1==hash[tem.c][tem.x+dir[i][0]][tem.y+dir[i][1]])
                {
                    continue ;
                }
                hash[tem.c][tem.x+dir[i][0]][tem.y+dir[i][1]]=1;
                tail++;
                que[tail].x=tem.x+dir[i][0];
                que[tail].y=tem.y+dir[i][1];
                que[tail].c=tem.c;
                que[tail].time=tem.time+1;

            }
        }
    }
    return 0;
}
void chu(int m,int n)
{
    int i,f,g;
    for(i=0;i<2;i++)
    {
        for(f=0;f<=m+1;f++)
        {
            for(g=0;g<=n+1;g++)
            {
                map[i][f][g]='*';
                hash[i][f][g]=0;
            }
        }
    }    
}
int main()
{
    int num,i,m,n,f,g,res;
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        scanf("%d%d%d",&m,&n,&t);
        chu(m,n);
        getchar();
        for(f=1;f<=m;f++)
        {
            for(g=1;g<=n;g++)
            {
                scanf("%c",&map[0][f][g]);
                if('S'==map[0][f][g])
                {
                    si=f;
                    sf=g;
                    sc=0;
                }
            } 
            getchar();
        }
        getchar();
        for(f=1;f<=m;f++)
        {
            for(g=1;g<=n;g++)
            {
                scanf("%c",&map[1][f][g]);
                if('S'==map[1][f][g])
                {
                    si=f;
                    sf=g;
                    sc=1;
                }
            }
            getchar();
        }
        res=bfs();
        if(1==res)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}