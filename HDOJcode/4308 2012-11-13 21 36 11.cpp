******************************
    Author : townboy
    Submit time : 2012-11-13 21:36:11
    Judge Status : Accepted
    HDOJ Runid : 7151241
    Problem id : 4308
    Exe.time : 62MS
    Exe.memory : 528K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<string>
#include<memory.h>
#include<queue> 

using namespace std;

int dir[4][2]={0,1,0,-1,1,0,-1,0};
int sx,sy,ex,ey;
int cost,n,m,hash[5100];
string map[5100];

void debug()
{
    int i,f;
    printf("%d %d\n",n,m);
    for(i=0;i<n;i++)
    {
        for(f=0;f<m;f++)
        {
            printf("%c",map[i][f]);
        }
        printf("\n");
    }
} 

struct node 
{
    int x;
    int y;
    int val;
    friend bool operator < (node a,node b)
    {
        return a.val > b.val;
    }
};
struct node ru;

priority_queue<node>que;

int turn(int x,int y)
{
    return (y+1)+x*m;
}

void all(int val)
{
    int i,f;
    for(i=0;i<n;i++)
    {
        for(f=0;f<m;f++)
        {
            if('P' == map[i][f])
            {
                ru.x=i;
                ru.y=f;
                ru.val=val;
                que.push(ru);
            }    
        }
    }
}

int bfs()
{
    int nx,ny;
    int temx,temy,i,val; 
    
    ru.x=sx;
    ru.y=sy;
    ru.val=0;
    que.push(ru);
    
    while(!que.empty())
    {
        temx=que.top().x;
        temy=que.top().y;
        val=que.top().val;
        que.pop();
            
        if('C' == map[temx][temy])
        {
            return val;
        }
        
        if(1 == hash[turn(temx,temy)])
        {
            continue;
        }
        hash[turn(temx,temy)]=1;
        
        for(i=0;i<4;i++)
        {
            nx=temx+dir[i][0];
            ny=temy+dir[i][1];
            if(nx < 0 || nx >= n || ny < 0 || ny >=m)
            {
                continue;
            }
            if('#' == map[nx][ny])
            {
                continue;
            }
            if(1 == hash[turn(nx,ny)])
            {
                continue;
            }
            if('P' == map[nx][ny])
            {
                all(val);
            }
            else if('*' == map[nx][ny])
            {
                ru.x=nx;
                ru.y=ny;
                ru.val=val+1;
                que.push(ru);
            }
            else if('C' == map[nx][ny])
            {
                ru.x=nx;
                ru.y=ny;
                ru.val=val;
                que.push(ru);
            }
        }
    } 
    return -1;
}

void chu()
{
    memset(hash,0,sizeof(hash));
    while(!que.empty())
    {
        que.pop();
    }
}

int main()
{
    int i,f,ans;
    char ch[5100];
    while(scanf("%d%d%d",&n,&m,&cost)!=EOF)
    {
        getchar();
        chu();
        for(i=0;i<n;i++)
        {
            gets(ch);
            map[i]=ch;
        }
        for(i=0;i<n;i++)
        {
            for(f=0;f<m;f++)
            {
                if('Y' == map[i][f])
                {
                    sx=i;
                    sy=f;
                }
                if('C' == map[i][f])
                {
                    ex=i;
                    ey=f;
                }
            }
        }
        ans=bfs();
        if(-1 == ans)
        {
            printf("Damn teoy!\n");
            continue;
        }
        printf("%d\n",cost*ans);
    }
    return 0;
}