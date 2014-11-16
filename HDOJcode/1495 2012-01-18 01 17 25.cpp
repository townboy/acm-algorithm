******************************
    Author : townboy
    Submit time : 2012-01-18 01:17:25
    Judge Status : Accepted
    HDOJ Runid : 5270755
    Problem id : 1495
    Exe.time : 62MS
    Exe.memory : 4288K
    https://github.com/townboy
******************************


#include<stdio.h>
int r[3],hash[102][102][102],dir[6][3]={{0,1,2},{0,2,1},{1,0,2},{1,2,0},{2,1,0},{2,0,1}};
struct node
{
    int x[3];
    int time;
};
struct node que[101*101*101],tem;
int bfs()
{
    int head,tail,i,x,y,z,s[3],f;
    head=0;
    tail=0;
    que[head].time=0;
    que[head].x[0]=r[0];
    que[head].x[1]=0;
    que[head].x[2]=0;
    while(head<=tail)
    {
        tem=que[head];
        head++;
        if(1==hash[tem.x[0]][tem.x[1]][tem.x[2]])
        {
            continue;
        }
        hash[tem.x[0]][tem.x[1]][tem.x[2]]=1;
        if(0==tem.x[0]^tem.x[1]^tem.x[2])
        {
            if((0==tem.x[0]-tem.x[1]||0==tem.x[0]-tem.x[2]||0==tem.x[1]-tem.x[2])&&(0==tem.x[0]*tem.x[1]*tem.x[2]))
            {
                return tem.time;
            }
        }
        for(i=0;i<6;i++)
        {
            x=dir[i][0];
            y=dir[i][1];
            z=dir[i][2];
            if(tem.x[x]<=r[y]-tem.x[y])
            {
                s[x]=0;
                s[y]=tem.x[x]+tem.x[y];
                s[z]=tem.x[z];
            }
            else
            {
                s[x]=tem.x[x]-(r[y]-tem.x[y]);
                s[y]=r[y];
                s[z]=tem.x[z];
            }
            tail++;
            for(f=0;f<3;f++)
            {
                que[tail].x[f]=s[f];
            }
            que[tail].time=tem.time+1;
        }
    }
    return -1;
}
int main(void)
{
    int res,i,f,g;
    while(scanf("%d%d%d",&r[0],&r[1],&r[2]),!(0==r[0]&&0==r[1]&&0==r[2]))
    {
        for(i=0;i<=r[0];i++)
        {
            for(f=0;f<=r[1];f++)
            {
                for(g=0;g<=r[2];g++)
                {
                    hash[i][f][g]=0;
                }
            }
        }
        res=bfs();
        if(res<0)
        {
            printf("NO\n");
        }
        else
        {
            printf("%d\n",res);
        }
    }
return 0;
}
