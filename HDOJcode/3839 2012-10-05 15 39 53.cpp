******************************
    Author : townboy
    Submit time : 2012-10-05 15:39:53
    Judge Status : Accepted
    HDOJ Runid : 6869600
    Problem id : 3839
    Exe.time : 62MS
    Exe.memory : 488K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<string>
#include<queue>
#include<stdlib.h>
#include<memory.h>
using namespace std;

int n,m,map[210][210],id;
string ch[210],chuli[16]={"0000","0001","0010","0011","0100","0101","0110","0111","1000","1001","1010","1011","1100","1101","1110","1111"};
int idc[1000],dir[4][2]={0,1,0,-1,1,0,-1,0};
int now,flag,zimu[6]={'W','A','K','J','S','D'};

int cmp(const void *a,const void*b)
{
    return *(int *)a-*(int *)b;
}

struct node 
{
    int x;
    int y;
};
struct node ru,tem;

void bfs(int col,int x,int y)
{
    int i;
    queue<node>q;
    ru.x=x;
    ru.y=y;
    q.push(ru);
    map[x][y]=col;
    while(!q.empty())
    {
        tem=q.front();
        q.pop();
        for(i=0;i<4;i++)
        {
            ru.x=tem.x+dir[i][0];
            ru.y=tem.y+dir[i][1];
            if('1' == ch[ru.x][ru.y] && 0 == map[ru.x][ru.y])
            {
                map[ru.x][ru.y]=col;
                q.push(ru);
            }
        }
    } 
}

int check(int x,int y)
{
    if(x >= 1 && x <= n && y >= 1 && y <= m)
    {
        return 1;    
    }
    return 0;
}

void bfs2(int x,int y)
{
    int i;
    queue<node>q;
    ru.x=x;
    ru.y=y;
    q.push(ru);    
    map[x][y]=-1;
    while(!q.empty())
    {
        tem=q.front();
        q.pop();
        for(i=0;i<4;i++)
        {
            ru.x=tem.x+dir[i][0];
            ru.y=tem.y+dir[i][1];
            if(1 == check(ru.x,ru.y))
            {
                if('0' == ch[ru.x][ru.y])
                {
                    if(-1 == map[ru.x][ru.y])
                    {
                        continue;
                    }
                    map[ru.x][ru.y]=-1;
                    q.push(ru);                        
                }    
                else
                {
                    if(0 == flag)
                    {
                        flag=1;
                        now=map[ru.x][ru.y];
                    }
                    else if(1 == flag)
                    {
                        if(map[ru.x][ru.y] != now)
                        {
                            flag=2;                
                        }
                    }
                }
            }
            else
            {    
                flag=2;
            }
        }
    } 
}

void debug()
{
    int i,f;
    for(i=1;i<=n;i++)
    {
        for(f=1;f<=m;f++)
        {
            printf("%d",map[i][f]);
        }
        printf("\n");
    }
}

void solve()
{
    int i,f;
    id=0;
    for(i=1;i<=n;i++)
    {
        for(f=1;f<=m;f++)
        {
            if(0 == map[i][f] && '1' == ch[i][f])
            {
                ++id;
                bfs(id,i,f);
            }
        }
    }    
    for(i=1;i<=n;i++)
    {
        for(f=1;f<=m;f++)
        {
            if(0 == map[i][f] && '0' == ch[i][f])
            {
                now=-1;
                flag=0;
                bfs2(i,f);
                if(2 == flag)
                {
                    continue;
                }
                idc[now]++;
            }
        }
    }    
    for(i=1;i<=id;i++)
    {
        idc[i]=zimu[idc[i]];
    }
}

void print()
{
    int i;
    qsort(&idc[1],id,sizeof(idc[0]),cmp);
    for(i=1;i<=id;i++)
    {
        printf("%c",idc[i]);
    }    
    printf("\n");
}

void chu()
{
    memset(map,0,sizeof(map));
    memset(idc,0,sizeof(idc));
}

int main()
{
    int i,f;
    char zan,cas=0;
    while(scanf("%d%d",&n,&m),n+m)
    {
        getchar();
        cas++;
        chu();
        for(i=1;i<=n;i++)
        {
            ch[i]=" ";
            for(f=1;f<=m;f++)
            {
                scanf("%c",&zan);    
                if(zan < 'a')
                {
                    ch[i]+=chuli[zan-'0'];    
                }
                else
                {
                    ch[i]+=chuli[zan-'a'+10];        
                }
            }
            getchar();        
        }
        m*=4;
        solve();
        printf("Case %d: ",cas);
        print();
    }
    return 0;
}