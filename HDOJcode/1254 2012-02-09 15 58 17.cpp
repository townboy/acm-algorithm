******************************
    Author : townboy
    Submit time : 2012-02-09 15:58:17
    Judge Status : Accepted
    HDOJ Runid : 5333453
    Problem id : 1254
    Exe.time : 0MS
    Exe.memory : 320K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<queue>
#include<math.h>
using namespace std;
int dir[4][2]={0,1,0,-1,1,0,-1,0},map[20][20],hash[20][20][20][20],ei,ef,si,sf,xi,xf;
struct node 
{
    int x1;
    int y1;
    int x2;
    int y2;
    int time;
    friend bool operator < (node a,node b)
    {
        return a.time>b.time;
    }
};
struct node tem,ru;
int bfs()
{
    int i,d1,d2;
    priority_queue<node>q;
    ru.x1=si;
    ru.y1=sf;
    ru.x2=xi;
    ru.y2=xf;
    ru.time=0;
    hash[si][sf][xi][xf]=1;
    q.push(ru);
    while(!q.empty())
    {
        tem=q.top();
        q.pop();
        if(tem.x2==ei&&tem.y2==ef)
        {
            return tem.time;
        }
        if(abs(tem.x2-tem.x1)+abs(tem.y2-tem.y1)<2)
        {
            d1=tem.x2-tem.x1;
            d2=tem.y2-tem.y1;
            if(0==hash[tem.x1+d1][tem.y1+d2][tem.x2+d1][tem.y2+d2]&&1!=map[tem.x2+d1][tem.y2+d2])
            {
                hash[tem.x1+d1][tem.y1+d2][tem.x2+d1][tem.y2+d2]=1;
                ru.x1=tem.x1+d1;
                ru.y1=tem.y1+d2;
                ru.x2=tem.x2+d1;
                ru.y2=tem.y2+d2;
                ru.time=tem.time+1;
                q.push(ru);
            }
            for(i=0;i<4;i++)
            {
                if(d1==dir[i][0]&&d2==dir[i][1])
                {
                    continue;
                }
                if(0==hash[tem.x1+dir[i][0]][tem.y1+dir[i][1]][tem.x2][tem.y2]&&1!=map[tem.x1+dir[i][0]][tem.y1+dir[i][1]])
                {
                    hash[tem.x1+dir[i][0]][tem.y1+dir[i][1]][tem.x2][tem.y2]=1;
                    ru.x1=tem.x1+dir[i][0];
                    ru.y1=tem.y1+dir[i][1];
                    ru.x2=tem.x2;
                    ru.y2=tem.y2;
                    ru.time=tem.time;
                    q.push(ru);
                }
            }
        }
        else
        {
            for(i=0;i<4;i++)
            {
                if(0==hash[tem.x1+dir[i][0]][tem.y1+dir[i][1]][tem.x2][tem.y2]&&1!=map[tem.x1+dir[i][0]][tem.y1+dir[i][1]])
                {
                    hash[tem.x1+dir[i][0]][tem.y1+dir[i][1]][tem.x2][tem.y2]=1;
                    ru.x1=tem.x1+dir[i][0];
                    ru.y1=tem.y1+dir[i][1];
                    ru.x2=tem.x2;
                    ru.y2=tem.y2;
                    ru.time=tem.time;
                    q.push(ru);
                }
            }
        }
    }
    return -1;
}
int main()
{
    int i,f,g,m,n,res,h,j,num;
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        scanf("%d%d",&m,&n);
        for(f=0;f<=m+1;f++)
        {
            for(g=0;g<=n+1;g++)
            {
                map[f][g]=1;
            }
        }
        for(f=1;f<=m;f++)
        {
            for(g=1;g<=n;g++)
            {
                for(h=0;h<=m+1;h++)
                {
                    for(j=0;j<=n+1;j++)
                    {
                        hash[f][g][h][j]=0;
                    }
                }
                scanf("%d",&map[f][g]);
                if(4==map[f][g])
                {
                    si=f;
                    sf=g;
                }
                else if(3==map[f][g])
                {
                    ei=f;
                    ef=g;
                } 
                else if(2==map[f][g])
                {
                    xi=f;
                    xf=g;
                }
            }
        }
        res=bfs();
        printf("%d\n",res);
    }
    return 0;
}