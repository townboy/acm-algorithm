******************************
    Author : townboy
    Submit time : 2012-02-05 18:14:53
    Judge Status : Accepted
    HDOJ Runid : 5318641
    Problem id : 1728
    Exe.time : 62MS
    Exe.memory : 548K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
using namespace std;
char map[110][110];
int dir[5][2]={0,0,1,0,-1,0,0,1,0,-1},hash[110][110],k,ei,ef,si,sf,m,n;
struct node
{
    int x;
    int y;
    int time;
    int tai;
};
struct node tem,ru,que[21000];
int bfs()
{
    int i,head,tail,ji;
    head=0;
    tail=0;
    ru.x=si;
    ru.y=sf;
    ru.tai=0;
    ru.time=0;
    hash[si][sf]=1;
    que[tail]=ru;
    while(head<=tail)
    {
        tem=que[head];
        head++;
        if(tem.time>k)
        {
            return -1;
        }
        if(tem.x==ei&&tem.y==ef)
        {
            return 1;
        }
        for(i=1;i<5;i++)
        {
            ji=1;
            if(0==tem.tai)
            {
                while(tem.x+ji*dir[i][0]>=1&&tem.x+ji*dir[i][0]<=m&&tem.y+ji*dir[i][1]<=n&&tem.y+ji*dir[i][1]>=1&&'.'==map[tem.x+ji*dir[i][0]][tem.y+ji*dir[i][1]])
                {
                    if(1==hash[tem.x+ji*dir[i][0]][tem.y+ji*dir[i][1]])
                    {
                        ji++;
                        continue;
                    }
                    hash[tem.x+ji*dir[i][0]][tem.y+ji*dir[i][1]]=1;
                    ru.x=tem.x+ji*dir[i][0];
                    ru.y=tem.y+ji*dir[i][1];
                    ru.time=tem.time;
                    ru.tai=i;
                    tail++;
                    que[tail]=ru;
                    ji++;
                }
            }
            else if(i!=tem.tai)
            {
                while(tem.x+ji*dir[i][0]>=1&&tem.x+ji*dir[i][0]<=m&&tem.y+ji*dir[i][1]<=n&&tem.y+ji*dir[i][1]>=1&&'.'==map[tem.x+ji*dir[i][0]][tem.y+ji*dir[i][1]])
                {
                    if(1==hash[tem.x+ji*dir[i][0]][tem.y+ji*dir[i][1]])
                    {
                        ji++;
                        continue;
                    }
                    hash[tem.x+ji*dir[i][0]][tem.y+ji*dir[i][1]]=1;
                    ru.x=tem.x+ji*dir[i][0];
                    ru.y=tem.y+ji*dir[i][1];
                    ru.time=tem.time+1;
                    ru.tai=i;
                    tail++;
                    que[tail]=ru;
                    ji++;
                }
            }
        }
    }
    return -1;
}
int main()
{
    int num,i,f,g,res;
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        scanf("%d%d",&m,&n);
        getchar();
        for(f=0;f<=m+1;f++)
        {
            for(g=0;g<=n+1;g++)
            {
                hash[f][g]=1;
            }
        }
        for(f=1;f<=m;f++)
        {
            for(g=1;g<=n;g++)
            {
                scanf("%c",&map[f][g]);
                hash[f][g]=0;    
            }
            getchar();
        }
        scanf("%d%d%d%d%d",&k,&sf,&si,&ef,&ei);    
        res=bfs();
        if(1==res)
        {
            printf("yes\n");
        }
        else
        {
            printf("no\n");
        }
    }
    return 0;
}