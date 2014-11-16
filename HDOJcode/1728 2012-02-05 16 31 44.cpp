******************************
    Author : townboy
    Submit time : 2012-02-05 16:31:44
    Judge Status : Accepted
    HDOJ Runid : 5318245
    Problem id : 1728
    Exe.time : 250MS
    Exe.memory : 668K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<queue>
using namespace std;
char map[110][110];
int dir[5][2]={0,0,1,0,-1,0,0,1,0,-1},hash[110][110][5],k,ei,ef,si,sf;
struct node
{
    int x;
    int y;
    int time;
    int tai;
    friend bool operator< (node a,node b)
    {
        return a.time>b.time;
    }
};
struct node tem,ru;
int bfs()
{
    int i;
    priority_queue<node>q;
    ru.x=si;
    ru.y=sf;
    ru.tai=0;
    ru.time=0;
    q.push(ru);
    while(!q.empty())
    {
        tem=q.top();
        q.pop();
        if(tem.time>k)
        {
            continue;
        }
        if(tem.x==ei&&tem.y==ef)
        {
            return 1;
        }
        if(1==hash[tem.x][tem.y][tem.tai])
        {
            continue;
        }
        hash[tem.x][tem.y][tem.tai]=1;
        if('*'==map[tem.x][tem.y])
        {
            continue;
        }
        for(i=1;i<5;i++)
        {
            if(0==tem.tai)
            {
                ru.x=tem.x+dir[i][0];
                ru.y=tem.y+dir[i][1];
                ru.time=tem.time;
                ru.tai=i;
                q.push(ru);
            }
            else if(i==tem.tai)
            {
                ru.x=tem.x+dir[i][0];
                ru.y=tem.y+dir[i][1];
                ru.time=tem.time;
                ru.tai=i;
                q.push(ru);
            }
            else
            {
                ru.x=tem.x+dir[i][0];
                ru.y=tem.y+dir[i][1];
                ru.time=tem.time+1;
                ru.tai=i;
                q.push(ru);
            }
        }
    }
    return -1;
}
int main()
{
    int num,i,f,g,res,h,m,n;
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        scanf("%d%d",&m,&n);
        getchar();
        for(f=0;f<=m+1;f++)
        {
            for(g=0;g<=n+1;g++)
            {
                for(h=0;h<=4;h++)
                {
                    hash[f][g][h]=1;
                }
            }
        }
        for(f=1;f<=m;f++)
        {
            for(g=1;g<=n;g++)
            {
                scanf("%c",&map[f][g]);
                for(h=0;h<=4;h++)
                {
                    hash[f][g][h]=0;    
                }
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