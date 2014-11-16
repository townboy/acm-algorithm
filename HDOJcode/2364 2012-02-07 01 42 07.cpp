******************************
    Author : townboy
    Submit time : 2012-02-07 01:42:07
    Judge Status : Accepted
    HDOJ Runid : 5324145
    Problem id : 2364
    Exe.time : 15MS
    Exe.memory : 676K
    https://github.com/townboy
******************************


#include<stdio.h>
int dir[4][2]={0,1,1,0,0,-1,-1,0},si,sf,hash[90][90][5],m,n;
char map[90][90];
struct node
{
    int x;
    int y;
    int time;
    int tai;
};
struct node que[300000],tem;
int bfs()
{
    int head,tail,i,ji;
    head=0;
    tail=0;
    que[head].x=si;
    que[head].y=sf;
    que[head].time=0;
    que[head].tai=4;
    for(i=0;i<=4;i++)
    {
        hash[si][sf][i]=1;
    }
    while(head<=tail)
    {
        tem=que[head];
        head++;
        if(1==tem.x||1==tem.y||m==tem.x||n==tem.y)
        {
            return tem.time;
        }
        if(4==tem.tai)
        {
            for(i=0;i<4;i++)
            {
                if('.'==map[tem.x+dir[i][0]][tem.y+dir[i][1]])
                {
                    tail++;
                    que[tail].x=tem.x+dir[i][0];
                    que[tail].y=tem.y+dir[i][1];
                    que[tail].time=tem.time+1;
                    que[tail].tai=i;
                    hash[tem.x+dir[i][0]][tem.y+dir[i][1]][i]=1;
                }
            }
        }
        else
        {
            ji=0;
            if('.'==map[tem.x+dir[(tem.tai+1)%4][0]][tem.y+dir[(tem.tai+1)%4][1]])
            {
                if(1==hash[tem.x+dir[(tem.tai+1)%4][0]][tem.y+dir[(tem.tai+1)%4][1]][(tem.tai+1)%4])
                {
                    continue;
                }
                ji++;
                hash[tem.x+dir[(tem.tai+1)%4][0]][tem.y+dir[(tem.tai+1)%4][1]][(tem.tai+1)%4]=1;
                tail++;
                que[tail].x=tem.x+dir[(tem.tai+1)%4][0];
                que[tail].y=tem.y+dir[(tem.tai+1)%4][1];
                que[tail].time=tem.time+1;
                que[tail].tai=(tem.tai+1)%4;
            }
            if('.'==map[tem.x+dir[(tem.tai+3)%4][0]][tem.y+dir[(tem.tai+3)%4][1]])
            {
                if(1==hash[tem.x+dir[(tem.tai+3)%4][0]][tem.y+dir[(tem.tai+3)%4][1]][(tem.tai+3)%4])
                {
                    continue;
                }
                ji++;
                hash[tem.x+dir[(tem.tai+3)%4][0]][tem.y+dir[(tem.tai+3)%4][1]][(tem.tai+3)%4]=1;
                tail++;
                que[tail].x=tem.x+dir[(tem.tai+3)%4][0];
                que[tail].y=tem.y+dir[(tem.tai+3)%4][1];
                que[tail].time=tem.time+1;
                que[tail].tai=(tem.tai+3)%4;
            }
            if(0==ji)
            {
                if('.'==map[tem.x+dir[tem.tai][0]][tem.y+dir[tem.tai][1]])
                {
                    ji++;
                    if(1==hash[tem.x+dir[tem.tai][0]][tem.y+dir[tem.tai][1]][tem.tai])
                    {
                        continue;
                    }
                    hash[tem.x+dir[tem.tai][0]][tem.y+dir[tem.tai][1]][tem.tai]=1;
                    tail++;
                    que[tail].x=tem.x+dir[tem.tai][0];
                    que[tail].y=tem.y+dir[tem.tai][1];
                    que[tail].time=tem.time+1;
                    que[tail].tai=tem.tai;
                }
            }
        }
    }
    return -1;
}
int main()
{
    int i,f,g,h,num,res;
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        scanf("%d%d",&m,&n);
        getchar();
        for(f=1;f<=m;f++)
        {
            for(g=1;g<=n;g++)
            {
                for(h=0;h<5;h++)
                {
                    hash[f][g][h]=0;
                }
                scanf("%c",&map[f][g]);
                if('@'==map[f][g])
                {
                    si=f;
                    sf=g;
                }
            }
            getchar();
        }
        res=bfs();
        printf("%d\n",res);
    }
    return 0;
}