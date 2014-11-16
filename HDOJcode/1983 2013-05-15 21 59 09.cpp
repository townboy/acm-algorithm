******************************
    Author : townboy
    Submit time : 2013-05-15 21:59:09
    Judge Status : Accepted
    HDOJ Runid : 8311122
    Problem id : 1983
    Exe.time : 1140MS
    Exe.memory : 292K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>
#include<iostream>
#include<queue>
#define INF 0x3f3f3f3f

using namespace std;

int dir[4][2]={0,1,0,-1,1,0,-1,0};

int pre[8][8][2][3],hash[8][8][2];
char map[8][8];
int n,m,t;
int k;
int path[8][8];
int sx,sy,ex,ey;

void debug(){
    int i,f;
    for(i=0;i<n;i++)
    {
        for(f=0;f<m;f++)
            printf("%c",map[i][f]);
        puts("");
    }
    puts("");
}

int check(int x,int y){
    if(x < 0 || x >= n || y < 0 || y >= m)
        return 0;
    return 1;
}

void init(){
    int t0,t1,t2;
    int x,y,type;
    int i,f;
    int nx,ny,nt;
    queue<int>q;
    memset(hash,-1,sizeof(hash));
    memset(pre,-1,sizeof(pre));
    
    for(i=0;i<n;i++)
        for(f=0;f<m;f++)
            if('S' == map[i][f]){
                q.push(i);q.push(f);q.push(0);
                sx=i;
                sy=f;
                hash[i][f][0]=0;
            }
            else if('E' == map[i][f]){
                ex=i;
                ey=f;
            }
            
    while(!q.empty())
    {
        x=q.front();q.pop();
        y=q.front();q.pop();
        type=q.front();q.pop();
        if(map[x][y]=='E' && 1==type)    break;
        for(i=0;i<4;i++)
        {
            nx=x+dir[i][0];
            ny=y+dir[i][1];
            if(0 == check(nx,ny))    continue;
            if('#' == map[nx][ny])    continue;
            nt=type;
            if('J' == map[nx][ny])    nt=1;
            if(-1 != hash[nx][ny][nt])
                continue;
            
            hash[nx][ny][nt]=hash[x][y][type]+1;
            pre[nx][ny][nt][0]=x;
            pre[nx][ny][nt][1]=y;
            pre[nx][ny][nt][2]=type;
            
            q.push(nx);
            q.push(ny);
            q.push(nt);
        }
    }
    memset(path,0,sizeof(path));
    type=1;
    x=ex;
    y=ey;
    while(!(x==sx&&y==sy&&0==type))
    {
        t0=pre[x][y][type][0];
        t1=pre[x][y][type][1];
        t2=pre[x][y][type][2];
        x=t0;
        y=t1;
        type=t2;
        path[x][y]=1;
    }
    path[sx][sy]=0;
}

void calk(){
    int sum=0,i;
    for(i=0;i<4;i++)
        if(1==check(sx+dir[i][0],sy+dir[i][1]) && '#'!=map[sx+dir[i][0]][sy+dir[i][1]] )
            sum++;
    k=sum;
    sum=0;
    for(i=0;i<4;i++)
        if(1==check(ex+dir[i][0],ey+dir[i][1]) && '#'!=map[ex+dir[i][0]][ey+dir[i][1]] )
            sum++;
    k=min(sum,k);
}

int dis1[8][8],dis2[8][8];

void bfs(int x,int y)
{
    int i,nx,ny;
    queue<int>q;
    q.push(x);
    q.push(y);
    dis1[x][y]=0;
    while(!q.empty())
    {
        x=q.front();q.pop();
        y=q.front();q.pop();
        for(i=0;i<4;i++)
        {
            nx=x+dir[i][0];
            ny=y+dir[i][1];
            if(0 == check(nx,ny) || INF != dis1[nx][ny])    continue;
            if('#' == map[nx][ny])    continue;
            dis1[nx][ny]=dis1[x][y]+1;
            q.push(nx);
            q.push(ny);
        }
    }
}

int town()
{
    int i,f;
    memset(dis1,0x3f,sizeof(dis1));
    bfs(sx,sy);
    memcpy(dis2,dis1,sizeof(dis1));
    memset(dis1,0x3f,sizeof(dis1));
    bfs(ex,ey);
    for(i=0;i<n;i++)
        for(f=0;f<m;f++)
            if('J' == map[i][f])
                if(dis1[i][f]+dis2[i][f] <= t)
                    return 0;
    return 1;
}

int turn(int x,int y){
    return x*n+y;
}

int dfs(int pos,int deep,int flag,int last)
{
    int newflag,tem;
    int i,f;
    if(pos == deep){
        if(0 == flag)    return 0;
        return town();
    }
    
    for(i=0;i<n;i++)
        for(f=0;f<m;f++)
        {
            if(turn(i,f) <= last)    continue;
            if('S'==map[i][f] || 'E'==map[i][f])    continue;
            tem=map[i][f];
            map[i][f]='#';
            if(flag==1 || path[i][f]==1)
                newflag=1;
            if(1 == dfs(pos+1,deep,newflag,turn(i,f)) )
                return 1;
            map[i][f]=tem;
        }
}

int fun()
{
    int i,f;
    if(k == 1)
        return 1;
    if(1 == dfs(0,1,0,-1))    return 1;
    if(2 == k)    return 2;
    if(1 == dfs(0,2,0,-1))    return 2;
    if(3 == k)    return 3;
    if(1 == dfs(0,3,0,-1))    return 3;
    return 4;
}

int main()
{
    int ans;
    int i,f,cas;
    scanf("%d",&cas);
    for(i=0;i<cas;i++)
    {
        scanf("%d%d%d",&n,&m,&t);
        getchar();
        for(f=0;f<n;f++)
            gets(map[f]);
        init();
        if(hash[ex][ey][1]>t || -1==hash[ex][ey][1]){
            puts("0");
            continue;
        }
        calk();
        ans=fun();
        printf("%d\n",ans);
    }
    return 0;
}