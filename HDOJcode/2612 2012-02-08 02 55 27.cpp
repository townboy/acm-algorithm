******************************
    Author : townboy
    Submit time : 2012-02-08 02:55:27
    Judge Status : Accepted
    HDOJ Runid : 5327968
    Problem id : 2612
    Exe.time : 15MS
    Exe.memory : 1252K
    https://github.com/townboy
******************************


#include<stdio.h>
int dir[4][2]={0,1,0,-1,1,0,-1,0},hash[300][300],val[300][300],flag[300][300];
char map[300][300];
struct node 
{
    int x;
    int y;
    int time;
};
struct node que[50000],tem;
void bfs(int x,int y)
{
    int head,tail,i;
    head=0;
    tail=0;
    que[tail].x=x;
    que[tail].y=y;
    que[tail].time=0;
    hash[x][y]=1;
    while(head<=tail)
    {
        tem=que[head];
        head++;
        if('@'==map[tem.x][tem.y])
        {
            val[tem.x][tem.y]=val[tem.x][tem.y]+tem.time;
            flag[tem.x][tem.y]++;
        }        
         for(i=0;i<4;i++)
        {
            if(0==hash[tem.x+dir[i][0]][tem.y+dir[i][1]]&&'#'!=map[tem.x+dir[i][0]][tem.y+dir[i][1]])
            {
                hash[tem.x+dir[i][0]][tem.y+dir[i][1]]=1;
                tail++;
                que[tail].x=tem.x+dir[i][0];
                que[tail].y=tem.y+dir[i][1];
                que[tail].time=tem.time+1;
            }
        }
    }
}
void chu(int m,int n)
{
    int i,f;
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
            hash[i][f]=0;
        }
    }
}
int main()
{
    int i,f,m,n,ax,ay,bx,by,min;
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        getchar();
        for(i=1;i<=m;i++)
        {
            scanf("%s",&map[i][1]);
            for(f=1;f<=n;f++)
            {
                val[i][f]=0;
                flag[i][f]=0;
                if('Y'==map[i][f])
                {
                    ax=i;
                    ay=f;
                }
                else if('M'==map[i][f])
                {
                    bx=i;
                    by=f;
                }
            }
        }
        chu(m,n);
        bfs(ax,ay);
        chu(m,n);
        bfs(bx,by);
        min=5000000;
        for(i=1;i<=m;i++)
        {
            for(f=1;f<=n;f++)
            {
                if('@'==map[i][f]&&2==flag[i][f])
                {
                    if(val[i][f]<min)
                    {
                        min=val[i][f];
                    }
                }
            }
        }
        printf("%d\n",min*11);
    }
    return 0;
}