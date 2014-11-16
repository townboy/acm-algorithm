******************************
    Author : townboy
    Submit time : 2012-01-17 21:01:27
    Judge Status : Accepted
    HDOJ Runid : 5269787
    Problem id : 1253
    Exe.time : 531MS
    Exe.memory : 904K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<math.h>
int head,tail,map[52][52][52],a,b,c,t,dir[6][3]={{0,0,1},{0,0,-1},{0,1,0},{0,-1,0},{1,0,0,},{-1,0,0,}};
struct node
{
    int x;
    int y;
    int z;
    int time;
};
struct node que[52*52*53],tem;
int bfs()
{
    int i;
    head=0;
    tail=0;
    que[0].x=1;
    que[0].y=1;
    que[0].z=1;
    que[0].time=0;
    map[1][1][1]=0;
    while(head<=tail)
    {
        tem=que[head];
        head++;
        if(1==map[tem.x][tem.y][tem.z])
        {
            continue;
        }
        map[tem.x][tem.y][tem.z]=1;
        if((t-tem.time)<((a-tem.x)+(b-tem.y)+(c-tem.z)))
        {
            continue;
        }
        if(tem.x==a&&tem.y==b&&tem.z==c)
        {
            return tem.time;
        }
        for(i=0;i<6;i++)
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
    int num,i,f,g,h,res;
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        scanf("%d%d%d%d",&a,&b,&c,&t);
           for(f=0;f<=a+1;f++)
        {
            for(g=0;g<=b+1;g++)
            {
                for(h=0;h<=c+1;h++)
                {
                    map[f][g][h]=1;
                }
            }
        }
        for(f=1;f<=a;f++)
        {
            for(g=1;g<=b;g++)
            {
                for(h=1;h<=c;h++)
                {
                    scanf("%d",&map[f][g][h]);
                }
            }
        }
        res=bfs();
        printf("%d\n",res);
    }
return 0;
}