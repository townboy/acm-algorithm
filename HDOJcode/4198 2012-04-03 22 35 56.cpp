******************************
    Author : townboy
    Submit time : 2012-04-03 22:35:56
    Judge Status : Accepted
    HDOJ Runid : 5699734
    Problem id : 4198
    Exe.time : 328MS
    Exe.memory : 2012K
    https://github.com/townboy
******************************


#include<memory.h>
#include<stdio.h>
#include<iostream>
#include<queue>
using namespace std;

int dir[4][2]={0,1,1,0,-1,0,0,-1};
int ei,ef,hash[600][600],h,d,w;
char map[600][600];

struct node 
{
    int x;
    int y;
    int time;
    bool friend operator < (node a,node b)
    {
        return a.time>b.time;
    }
};

struct node ru,tem;

int bfs()
{
    int i;
    priority_queue<node> q;
    ru.x=ei;
    ru.y=ef;
    ru.time=0;
    q.push(ru);
    while(!q.empty())
    {
        tem=q.top();
        q.pop();
        if(1==hash[tem.x][tem.y])
        {
            continue;
        }
        if(tem.x>h||tem.x<1||tem.y>w||tem.y<1)
        {
            return tem.time;
        }
        hash[tem.x][tem.y]=1;
        for(i=0;i<4;i++)
        {
            if(1==hash[tem.x+dir[i][0]][tem.y+dir[i][1]])
            {
                continue;
            }
            if('@'==map[tem.x+dir[i][0]][tem.y+dir[i][1]])
            {
                ru.x=tem.x+dir[i][0];
                ru.y=tem.y+dir[i][1];
                ru.time=tem.time+d+1;
                q.push(ru);
            }
            else
            {
                ru.x=tem.x+dir[i][0];
                ru.y=tem.y+dir[i][1];
                ru.time=tem.time+1;
                q.push(ru);            
            }
        }
    }
    return -1;
}


void chu()
{
    memset(hash,0,sizeof(hash));
}

int main()
{
    int i,f,g,num;
//    freopen("D:\\in.txt","r",stdin);
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        scanf("%d%d%d",&h,&w,&d);
        
        chu();

        getchar();
        for(f=1;f<=h;f++)
        {
            for(g=1;g<=w;g++)
            {
                scanf("%c",&map[f][g]);
                if('S'==map[f][g])
                {
                    ei=f;
                    ef=g;
                }
                else if('#'==map[f][g])
                {
                    hash[f][g]=1;
                }
            }
            getchar();
        }
        printf("%d\n",bfs());
    }
    return 0;
}
