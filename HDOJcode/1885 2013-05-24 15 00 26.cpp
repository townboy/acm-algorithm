******************************
    Author : townboy
    Submit time : 2013-05-24 15:00:26
    Judge Status : Accepted
    HDOJ Runid : 8372475
    Problem id : 1885
    Exe.time : 203MS
    Exe.memory : 1080K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>
#include<iostream>
#include<queue>
#define maxn 110
#define diff 32 

using namespace std;

int key[4]={'b','y','r','g'};
int dir[4][2]={0,-1,0,1,1,0,-1,0};
int n,m,sx,sy;
char map[maxn][maxn];
int state[maxn][maxn][16];

int check(int x,int y){
    if(x<0 || x>=n || y<0 || y>=m)    return 0;
    if('#' == map[x][y])    return 0;
    return 1;
}

int iskey(int x)
{
    if(x >= 'a')
        return 1;
    return 0;
}

void push(queue<int>&q,int x,int y,int S,int cost){
    if(-1 != state[x][y][S])    return ;
    state[x][y][S]=cost;
    q.push(x);q.push(y);q.push(S);
}

int cal(int x,int y,int S){
    int i,door=map[x][y];
    for(i=0;i<4;i++)
        if(door == key[i])
            break;
    return S|(1<<i);
}

int ownkey(int door,int S){
    int i;
    for(i=0;i<4;i++)
        if(door == key[i]-diff)
            break;
    if(0 == ((1<<i)&S))
        return 0;
    return 1;
}

int bfs(){
    int i,x,y,S;
    int nx,ny,nS;
    queue<int>q;
    q.push(sx);q.push(sy);q.push(0);
    state[sx][sy][0]=0;
    map[sx][sy]='.';
    while(!q.empty())
    {
        x=q.front();q.pop();
        y=q.front();q.pop();
        S=q.front();q.pop();
        for(i=0;i<4;i++)
        {
            nx=x+dir[i][0];
            ny=y+dir[i][1];
            if(0 == check(nx,ny))    continue;
            if('.' == map[nx][ny])
                push(q,nx,ny,S,state[x][y][S]+1);
            else if('X' == map[nx][ny])
                return state[x][y][S]+1;
            else if(1 == iskey(map[nx][ny]))
                push(q,nx,ny,cal(nx,ny,S),state[x][y][S]+1);
            else{
                if(0 == ownkey(map[nx][ny],S))    continue;
                push(q,nx,ny,S,state[x][y][S]+1);
            }
        }
    }
    return -1;
}

void init(){
    int i,f;
    memset(state,-1,sizeof(state));
    for(i=0;i<n;i++)
        for(f=0;f<m;f++)
            if('*' == map[i][f]){
                sx=i;
                sy=f;
            }
}

int main()
{
    int i,ans;
    while(scanf("%d%d",&n,&m),n+m)
    {
        getchar();
        for(i=0;i<n;i++)
            gets(map[i]);
        init();
        ans=bfs();
        if(-1 == ans){
            puts("The poor student is trapped!");
            continue;
        }
        printf("Escape possible in %d steps.\n",ans);
    }
    return 0;
}