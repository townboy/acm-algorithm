******************************
    Author : townboy
    Submit time : 2012-09-12 20:55:10
    Judge Status : Accepted
    HDOJ Runid : 6752738
    Problem id : 3137
    Exe.time : 0MS
    Exe.memory : 268K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>
#include<queue> 
#define INF 1000000
using namespace std; 

char map[25][25];
int hash[25][25][4],sx,sy; 
int dir[4][2]={-1,0,0,1,1,0,0,-1}; 

struct node 
{
    int x;
    int y;
    int dirr; 
};
struct node tem,ru; 

void chu()
{
    int i,f,g;
    for(i=1;i<=20;i++) 
    {
        for(f=1;f<=20;f++)
        {
            for(g=0;g<4;g++)
            {
                hash[i][f][g]=INF; 
            } 
        } 
    }
} 

int bfs()
{
    int i;
    queue<node>que; 
    tem.x=sx;
    tem.y=sy; 
    for(i=0;i<4;i++)
    {
        tem.dirr=i;
        que.push(tem);    
        hash[sx][sy][i]=0; 
    } 
    while(!que.empty())
    {
        tem=que.front();
        que.pop();
        if('F' == map[tem.x][tem.y])
        {
            return hash[tem.x][tem.y][tem.dirr];    
        } 
        for(i=0;i<2;i++)
        {
            ru.dirr=(tem.dirr+i)%4; 
            ru.x=tem.x+dir[ru.dirr][0];
            ru.y=tem.y+dir[ru.dirr][1]; 
            if('X' == map[ru.x][ru.y])
            {
                continue;    
            }
            if(hash[tem.x][tem.y][tem.dirr]+1 < hash[ru.x][ru.y][ru.dirr])
            {
                hash[ru.x][ru.y][ru.dirr]=hash[tem.x][tem.y][tem.dirr]+1;        
                que.push(ru); 
            }             
        } 
    }
    return -1; 
} 

int main()
{
    int i,num,f,g,n,m;
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        scanf("%d%d",&n,&m);
        chu(); 
        getchar(); 
        for(f=1;f<=n;f++)
        {
            for(g=1;g<=m;g++)
            {
                scanf("%c",&map[f][g]); 
                if('S' == map[f][g])
                {
                    sx=f;
                    sy=g;                
                } 
            } 
            getchar(); 
        }
        
        printf("%d\n",bfs()); 
    }     
    return 0; 
} 