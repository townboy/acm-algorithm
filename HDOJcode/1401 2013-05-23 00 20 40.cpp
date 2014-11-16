******************************
    Author : townboy
    Submit time : 2013-05-23 00:20:40
    Judge Status : Accepted
    HDOJ Runid : 8363150
    Problem id : 1401
    Exe.time : 78MS
    Exe.memory : 17140K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>
#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

int dir[4][2]={0,1,0,-1,1,0,-1,0};
char hash[17000000];

struct point{
    int x,y;
    friend bool operator < (point a,point b){
        if(a.x != b.x)
            return a.x < b.x;
        return a.y < b.y;
    }
};

struct node{
    int cost;
    point pos[4];
};
node s,e;

void init(){
    memset(hash,-1,sizeof(hash));
    sort(s.pos,s.pos+4);
    sort(e.pos,e.pos+4);
    s.cost=e.cost=0;
}

int getState(node x){
    int ji=1,sum=0;
    for(int i=0;i<4;i++)
    {
        sum+=x.pos[i].x * ji;
        ji<<=3;
        sum+=x.pos[i].y * ji;
        ji<<=3;        
    }
    return sum;
}

int check(int x,int y){
    if(x<0 || x>7 || y<0 || y>7)
        return 0;
    return 1;
}

int exist(node tem,int x,int y){
    for(int i=0;i<4;i++)
        if(x==tem.pos[i].x && y==tem.pos[i].y)
            return 1;
    return 0;
}

int make(node x,int i,int tox,int toy,int cnt,queue<node>&q){
    node add = x;
    add.cost++;
    add.pos[i].x=tox;    add.pos[i].y=toy;
    sort(add.pos,add.pos+4);
    int state = getState(add);
    if(cnt == hash[state])
        return 0;
    else if((1-cnt) == hash[state])
        return 1;
    else{
        hash[state]=cnt;
        q.push(add);
    }
    return 0;
}

int extend(int cnt,queue<node> &q){
    int i,tox,toy,toox,tooy,f;
    node x = q.front();
    q.pop();
    if(x.cost == 4)    return 0;
    for(i=0;i<4;i++)
        for(f=0;f<4;f++)
        {
            tox = x.pos[i].x+dir[f][0];
            toy = x.pos[i].y+dir[f][1];
            if(0 == check(tox,toy))    continue;
            if(1 == exist(x,tox,toy))
            {
                toox=tox+dir[f][0];
                tooy=toy+dir[f][1];
                if(0==check(toox,tooy) || 1==exist(x,toox,tooy))    continue;
                if(1 == make(x,i,toox,tooy,cnt,q))
                    return 1;
            }
            else
            {
                if(1 == make(x,i,tox,toy,cnt,q))
                    return 1;
            }
        }
    return 0;
}

int fun(){
    queue<node>q[2];
    q[0].push(s);
    q[1].push(e);
    hash[getState(s)]=0;
    hash[getState(e)]=1;
    while(!q[0].empty() || !q[1].empty())
    {
        if( ( 0!=q[0].size()&&q[0].size()<q[1].size() ) || 0==q[1].size() ){
            if(1 == extend(0,q[0]))
                return 1;
        }    
        else{
            if(1 == extend(1,q[1]))
                return 1;
        }
    }
    return 0;
}

int same(){
    for(int i=0;i<4;i++)
        if(s.pos[i].x!=e.pos[i].x || s.pos[i].y!=e.pos[i].y)
            return 0;
    return 1;
}

int main()
{
    int i,ans;
    while(scanf("%d%d",&s.pos[0].x,&s.pos[0].y)!=EOF)
    {
        s.pos[0].x--;
        s.pos[0].y--;
        for(i=1;i<4;i++){
            scanf("%d%d",&s.pos[i].x,&s.pos[i].y);
            s.pos[i].x--;
            s.pos[i].y--;
        }
        for(i=0;i<4;i++){
            scanf("%d%d",&e.pos[i].x,&e.pos[i].y);
            e.pos[i].x--;
            e.pos[i].y--;
        }
        init();
        if(1 == same()){
            puts("YES");
            continue;
        }
        ans = fun();
        puts(0==ans?"NO":"YES");
    }
    return 0;
}