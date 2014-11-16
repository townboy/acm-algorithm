******************************
    Author : townboy
    Submit time : 2012-11-18 19:27:03
    Judge Status : Accepted
    HDOJ Runid : 7192385
    Problem id : 3860
    Exe.time : 468MS
    Exe.memory : 1364K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<queue>
#include<vector>
#include<memory.h> 
#include<stdlib.h> 
#include<iostream>
#define INF 0x7fffffff

using namespace std;

int cmp(const void *a,const void *b)
{
    return *(int*)a-*(int*)b; 
} 

struct xx
{
    int pos;
    int val;
};
struct xx posp[210],poso[210];

int cmp2(const void *a,const void *b)
{
    return (*(struct xx*)a).pos - (*(struct xx*)b).pos;
}

int dir[4][2]={0,1,1,0,0,-1,-1,0};
int to[4][3]={{0,1,1},{1,0,0},{0,0,1},{0,0,0}};
int check[4][4]={{0,1,1,1},{1,0,1,1},{0,0,1,0},{0,0,0,1}}; 
int k,w,q,edge[210][210][2];
int broken[210][210]; 
int p,o; 
int n,m,wire[11000]; 
int dis[210][210],hash[210][210];
int s,t,src[210],get[210],need;

void chu()
{
    int i,f;
    memset(broken,0,sizeof(broken)); 
    for(i=1;i<=n;i++)
    {
        for(f=1;f<=m;f++)
        {    
            edge[i][f][0]=edge[i][f][1]=INF; 
        }        
    }
}

void add(int x1,int y1,int x2,int y2,int len) 
{
    int i; 
    for(i=0;i<2;i++)
    {
        if(x2 == x1+dir[i][0] && y2 == y1+dir[i][1])
            edge[x1][y1][i]=min(edge[x1][y1][i],len);    
        else if(x1 == x2+dir[i][0] && y1 == y2+dir[i][1])
            edge[x2][y2][i]=min(edge[x2][y2][i],len);    
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

void update(int aimx,int aimy,int srcx,int srcy,int len)
{
    if(dis[aimx][aimy] > dis[srcx][srcy]+len)
    {
        dis[aimx][aimy]=dis[srcx][srcy]+len;
        ru.x=aimx;
        ru.y=aimy;
        ru.val=dis[aimx][aimy];
        que.push(ru);
    }    
}

int bfs(int cap)
{
    int x,y,val,i,len;
    int newx,newy;

    while(!que.empty())
    {
        que.pop();
    }

    ru.x=s;
    ru.y=s;
    ru.val=0;
    dis[s][s]=0;
    que.push(ru);

    while(!que.empty())
    {
        x=que.top().x;
        y=que.top().y;
        val=que.top().val;
        que.pop();
        
        if(1 == hash[x][y])
        {
            continue;
        }
        hash[x][y]=1;
        
        if(t == x && t == y)
        {
            break;
        }
        if(s == x && s == y)
        {
            for(i=1;i<=m-1;i++)
            {
                if(1 == broken[1][i] || 1 == broken[1][i+1]) 
                    len=0;                
                else
                    len=min(cap,edge[1][i][0]);
                
                update(1,i,s,s,len);
            }
            
            if(p > 1)
                update(0,0,s,s,posp[0].val);
            else
                update(t,t,s,s,posp[0].val);
            
            if(o > 1)    
                update(0,m,s,s,poso[0].val);
            else 
                update(t,t,s,s,poso[0].val);
            
            for(i=1;i<=n-1;i++)
            {
                if(-1 == src[i])
                {
                    if(1 == broken[i][1] || 1 == broken[i+1][1])
                        len=0;
                    else
                        len=min(cap,edge[i][1][1]);

                    update(i,1,s,s,len);
                }

                if(-1 == get[i])
                {
                    if(1 == broken[i][m] || 1 == broken[i+1][m])
                        len=0;
                    else
                        len=min(cap,edge[i][m][1]);

                    update(i,m-1,s,s,len); 
                }
            }
        }
        else if(0 == y)        // ×ó²àµã 
        {
            if(0 != x)
            {
                len=posp[x].val;
                update(x-1,0,x,y,len); 
            }
            
            len=posp[x+1].val;
            if(x+1 == p)
                update(t,t,x,y,len);
            else
                update(x+1,y,x,y,len); 

            for(i=1;i<=n-1;i++)
            {
                if(x == src[i])
                {
                    if(1 == broken[i][1]|| 1 == broken[i+1][1])
                        len=0;
                    else
                        len=min(cap,edge[i][1][1]);
                    
                    update(i,1,x,y,len);
                }
            }
        }
        else if(m == y)        // ÓÒ²àµã 
        {
            if(0 != x)
            {
                len=poso[x].val;
                update(x-1,y,x,y,len); 
            }

            len=poso[x+1].val;
            if(x+1 == o)
                update(t,t,x,y,len);
            else
                update(x+1,y,x,y,len);
        
            for(i=1;i<=n-1;i++)
            {
                if(x == get[i])
                {
                    if(1 == broken[i][m] || 1 == broken[i+1][m]) 
                        len=0;
                    else
                        len=min(cap,edge[i][m][1]);
                
                    update(i,m-1,x,y,len);
                }
            }
        }
        else                // ÆÕÍ¨µã 
        {
            for(i=0;i<4;i++)
            {
                newx=x+dir[i][0];
                newy=y+dir[i][1];
                if(0 == newy) 
                {
                    if(-1 == src[x])
                        continue;    
                    else if(INF == src[x])
                    {
                        if(1 == broken[x][y] || 1 == broken[x+1][y])
                            len=0;
                        else
                            len=min(cap,edge[x][y][1]);
                        update(t,t,x,y,len);
                    }
                    else
                    {
                        if(1 == broken[x][y] || 1 == broken[x+1][y])
                            len=0;
                        else
                            len=min(cap,edge[x][y][1]);
                        update(src[x],0,x,y,len);    
                    }        
                }
                else if(m == newy)
                {
                    if(-1 == get[x])
                        continue;    
                    else if(INF == get[x])
                    {
                        if(1 == broken[x][y+1] || 1 == broken[x+1][y+1])
                            len=0;
                        else
                            len=min(cap,edge[x][y+1][1]);
                        update(t,t,x,y,len);    
                    }
                    else
                    {
                        if(1 == broken[x][y+1] || 1 == broken[x+1][y+1])
                            len=0;
                        else
                            len=min(cap,edge[x][y+1][1]);
                        update(get[x],m,x,y,len);
                    }                
                }
                else if(0 == newx)
                {
                    continue;    
                }
                else if(n == newx)
                {
                    if(1 == broken[x+1][y] || 1 == broken[x+1][y+1])
                        len=0;
                    else
                        len=min(cap,edge[x+1][y][0]);
                    update(t,t,x,y,len);
                }
                else
                {
                    if(1 == broken[x+check[i][0]][y+check[i][1]] || 1 == broken[x+check[i][2]][y+check[i][3]])
                        len=0;
                    else
                        len=min(cap,edge[x+to[i][0]][y+to[i][1]][to[i][2]]);
                    update(newx,newy,x,y,len);
                }
            }
        }        
    }
    
    return need == dis[t][t]?1:-1;
}

void build()
{
    int i,f;
    for(i=0;i<=t;i++)
    {
        for(f=0;f<=t;f++)
        {
            dis[i][f]=INF;
        }
    }
    memset(hash,0,sizeof(hash));
}

int bs()
{
    int mid,l=-1,r=w;
    s=205;
    t=206;
    
    while(l != r-1)
    {
        mid=(l+r)>>1;
        build();
        if(1 == bfs(wire[mid]))
        {
            r=mid;                    
        }
        else
        {
            l=mid;        
        }
    }
    if(r == w)
    {
        return -1;
    }
    return wire[r];
}

void yu()
{
    int i,last;
    memset(src,-1,sizeof(src));
    memset(get,-1,sizeof(get));
    for(i=0;i<p;i++)
    {
        src[posp[i].pos]=i;
    }
    last=-1;
    for(i=1;i<=n-1;i++)
    {
        if(-1 != src[i])
        {
            last=src[i];
        }
        if(last == p-1)
        {
            last=INF;
        }
        src[i]=last;    
    }

    last=-1;
    for(i=0;i<o;i++)
    {
        get[poso[i].pos]=i;
    }
    for(i=1;i<=n-1;i++)
    {
        if(-1 != get[i])
        {
            last=get[i];
        }
        if(o-1 == last)
        {
            last=INF;
        }
        get[i]=last;    
    }
}

void debug()
{
    int i,f;
    for(i=1;i<=n;i++)
    {
        for(f=1;f<=m;f++)
        {
            printf("%d ",edge[i][f][1]);    
        }
        printf("\n");
    }
    printf("\n");
}    

int er(int x)
{
    int l=-1,r=w,mid;
    while(l != r-1)
    {
        mid=(l+r)>>1;
        if(wire[mid] <= x)
        {
            l=mid;
        }
        else
        {
            r=mid;
        }
    }
    if(-1 == l)
    {
        return 0;
    }
    return wire[l];
}

void cap()
{
    int i,f,g;
    for(i=1;i<=n;i++)
    {
        for(f=1;f<=m;f++)
        {
            for(g=0;g<2;g++)
            {
                if(INF == edge[i][f][g])
                    continue;
                edge[i][f][g]=er(edge[i][f][g]);
            }
        }
    }
}

int main()
{
    int x,y,x1,x2,y1,y2,len; 
    int i,cas,f; 
    scanf("%d",&cas);
    for(i=0;i<cas;i++)
    {
        scanf("%d%d",&n,&m);
        scanf("%d",&p);
        
        chu();
        
        for(f=0;f<p;f++)
        {
            scanf("%d%d",&posp[f].pos,&posp[f].val); 
        } 
        qsort(posp,p,sizeof(posp[0]),cmp2);
        
        need=0;
        scanf("%d",&o);
        for(f=0;f<o;f++)
        {
            scanf("%d%d",&poso[f].pos,&poso[f].val); 
            need+=poso[f].val; 
        }
        qsort(poso,o,sizeof(poso[0]),cmp2);
        yu();
        
        scanf("%d",&q);
        for(f=0;f<q;f++)
        {
            scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&len);
            add(x1,y1,x2,y2,len);
        }
        
        scanf("%d",&k); 
        for(f=0;f<k;f++)
        {
            scanf("%d%d",&x,&y);
            broken[x][y]=1;
        }
        
        scanf("%d",&w);
        for(f=0;f<w;f++)
        {
            scanf("%d",&wire[f]);
        }         
        qsort(wire,w,sizeof(wire[0]),cmp);
        cap();
    
        printf("%d\n",bs());
    }
    return 0;
}