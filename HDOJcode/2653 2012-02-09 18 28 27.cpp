******************************
    Author : townboy
    Submit time : 2012-02-09 18:28:27
    Judge Status : Accepted
    HDOJ Runid : 5334015
    Problem id : 2653
    Exe.time : 390MS
    Exe.memory : 5520K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<queue>
using namespace std;
int dir[4][2]={0,1,0,-1,1,0,-1,0},hash[90][90][90],si,sf,ei,ef,t,p,val[90][90][90];
char map[90][90];
struct node
{
    int x;
    int y;
    int p;
    int time;
    friend bool operator < (node a,node b)
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
    ru.time=0;
    ru.p=p;
    q.push(ru);
    while(!q.empty())
    {
        tem=q.top();
        q.pop();
        if(tem.time>t)
        {
            return -1;
        }
        if(1==hash[tem.x][tem.y][tem.p])
        {
            continue;
        }
        hash[tem.x][tem.y][tem.p]=1;
        if(tem.x==ei&&tem.y==ef)
        {
            return tem.time;
        }
        if('@'==map[tem.x][tem.y])
        {
            if(0==tem.p)
            {
                continue;
            }
            for(i=0;i<4;i++)
            {
                if('#'!=map[tem.x+dir[i][0]][tem.y+dir[i][1]]&&0==hash[tem.x+dir[i][0]][tem.y+dir[i][1]][tem.p-1])
                {
                    if(tem.time+1>=val[tem.x+dir[i][0]][tem.y+dir[i][1]][tem.p-1]&&0!=val[tem.x+dir[i][0]][tem.y+dir[i][1]][tem.p-1])
                    {
                        continue;
                    }
                    val[tem.x+dir[i][0]][tem.y+dir[i][1]][tem.p-1]=tem.time+1;
                    ru.x=tem.x+dir[i][0];
                    ru.y=tem.y+dir[i][1];
                    ru.p=tem.p-1;
                    ru.time=tem.time+1;
                    q.push(ru);
                }
            }
        }
        else
        { 
            for(i=0;i<4;i++)
            {
                if('#'==map[tem.x+dir[i][0]][tem.y+dir[i][1]])
                {
                    continue;
                }
                if('@'==map[tem.x+dir[i][0]][tem.y+dir[i][1]])
                {
                    if(0==tem.p)
                    {
                        continue;
                    }
                    if(1==hash[tem.x+dir[i][0]][tem.y+dir[i][1]][tem.p-1])
                    {
                        continue;
                    }
                    if(tem.time+1>=val[tem.x+dir[i][0]][tem.y+dir[i][1]][tem.p-1]&&0!=val[tem.x+dir[i][0]][tem.y+dir[i][1]][tem.p-1])
                    {
                        continue;
                    }
                    val[tem.x+dir[i][0]][tem.y+dir[i][1]][tem.p-1]=tem.time+1;
                    ru.x=tem.x+dir[i][0];
                    ru.y=tem.y+dir[i][1];
                    ru.p=tem.p-1;
                    ru.time=tem.time+1;
                    q.push(ru);
                }
                else
                {
                    if(0==tem.p)
                    {
                        if(1==hash[tem.x+dir[i][0]][tem.y+dir[i][1]][tem.p])
                        {
                            continue;
                        }
                        if(tem.time+2>=val[tem.x+dir[i][0]][tem.y+dir[i][1]][tem.p]&&0!=val[tem.x+dir[i][0]][tem.y+dir[i][1]][tem.p])
                        {
                            continue;
                        }
                        val[tem.x+dir[i][0]][tem.y+dir[i][1]][tem.p]=tem.time+2;            
                        ru.x=tem.x+dir[i][0];
                        ru.y=tem.y+dir[i][1];
                        ru.p=tem.p;
                        ru.time=tem.time+2;
                        q.push(ru);
                    }
                    else
                    {
                        if(1==hash[tem.x+dir[i][0]][tem.y+dir[i][1]][tem.p])
                        {
                            continue;
                        }
                        if(tem.time+2>=val[tem.x+dir[i][0]][tem.y+dir[i][1]][tem.p]&&0!=val[tem.x+dir[i][0]][tem.y+dir[i][1]][tem.p])
                        {
                            continue;
                        }
                        val[tem.x+dir[i][0]][tem.y+dir[i][1]][tem.p]=tem.time+2;            
                        ru.x=tem.x+dir[i][0];
                        ru.y=tem.y+dir[i][1];
                        ru.p=tem.p;
                        ru.time=tem.time+2;
                        q.push(ru);
                        if(1==hash[tem.x+dir[i][0]][tem.y+dir[i][1]][tem.p-1])
                        {
                            continue;
                        }
                        if(tem.time+1>=val[tem.x+dir[i][0]][tem.y+dir[i][1]][tem.p-1]&&0!=val[tem.x+dir[i][0]][tem.y+dir[i][1]][tem.p-1])
                        {
                            continue;
                        }
                        val[tem.x+dir[i][0]][tem.y+dir[i][1]][tem.p-1]=tem.time+1;            
                        ru.x=tem.x+dir[i][0];
                        ru.y=tem.y+dir[i][1];
                        ru.p=tem.p-1;
                        ru.time=tem.time+1;
                        q.push(ru);
                    }
                }
            }
        }
    }
    return -1;
}
int main()
{
    int i,f,g,m,n,res,ji;
    ji=0;
    while(scanf("%d%d%d%d",&m,&n,&t,&p)!=EOF)
    {
        getchar();
        ji++;
        for(i=0;i<=m+1;i++)
        {
            for(f=0;f<=n+1;f++)
            {
                map[i][f]='#';
            }
        }
        for(i=1;i<=m;i++)
        {
            for(f=1;f<=n;f++)
            {
                scanf("%c",&map[i][f]);
                if('Y'==map[i][f])
                {
                    si=i;
                    sf=f;
                }
                else if('L'==map[i][f])
                {
                    ei=i;
                    ef=f;
                }
                for(g=0;g<=p;g++)
                {
                    hash[i][f][g]=0;
                    val[i][f][g]=0;
                }
            }
            getchar();
        }
        res=bfs();
        if(-1==res)
        {
            printf("Case %d:\nPoor Yifenfei, he has to wait another ten thousand years.\n",ji);
        } 
        else
        {
            printf("Case %d:\nYes, Yifenfei will kill Lemon at %d sec.\n",ji,res);
        }
    }
    return 0;
}