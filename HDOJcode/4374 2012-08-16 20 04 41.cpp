******************************
    Author : townboy
    Submit time : 2012-08-16 20:04:41
    Judge Status : Accepted
    HDOJ Runid : 6578391
    Problem id : 4374
    Exe.time : 828MS
    Exe.memory : 12244K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>
#include<queue>
#include<algorithm>
#define INF 100000000
using namespace std;

int dp[110][11000];
int n,m,x,t,map[110][11000],sum[110][11000];

struct node 
{
    int id;
    int val;
    friend bool operator < (node a,node b)
    {
        return a.val<b.val;
    } 
};
priority_queue<node>left,right;
struct node ru,tem;

void chu()
{
    int i;
    memset(sum,0,sizeof(sum));
    for(i=1;i<=m;i++)
    {
        dp[0][i]=-INF;
    }
    dp[0][x]=0;
}

void inti()
{
    while(!left.empty())
    {
        left.pop();    
    }
    while(!right.empty())
    {
        right.pop();    
    }
}

int xz(int x,int y)
{
    int l=-INF,r=-INF;
    while(!right.empty())
    {
        tem=right.top();
        if(tem.id < y)
        {
            right.pop();            
            continue;
        }
        r=tem.val-sum[x][y-1];
        break;
    } 
    while(!left.empty()) 
    {
        tem=left.top();
        if(tem.id < y-t)
        {
            left.pop();            
            continue;
        }
        l=tem.val+sum[x][y];
        break;
    }
    return max(l,r);
}

void add(int x,int y)
{
    int i;
    if(1 == y)
    {
        inti();
        for(i=1;i<=t+1;i++)
        {
            ru.id=i;
            ru.val=dp[x-1][i]+sum[x][i];                    
            right.push(ru);
        }
        return ;    
    }
    if(y+t <= m)
    {
        ru.id=y+t;
        ru.val=dp[x-1][ru.id]+sum[x][ru.id];
        right.push(ru);
    }
    
    
    ru.id=y-1;
    ru.val=dp[x-1][ru.id]-sum[x][ru.id-1];
    left.push(ru);
}



void fun()
{
    int i,f,g;
    for(i=1;i<=n;i++)
    {
        for(f=1;f<=m;f++)                            
        {
            add(i,f);
            dp[i][f]=xz(i,f);
        }
    }    
}

void debug()
{
    int i,f;
    for(i=0;i<=n;i++)
    {
        for(f=1;f<=m;f++)
            printf("%d ",dp[i][f]);
        printf("\n");
    }
}

int main()
{
    int maxx,i,f;
    while(scanf("%d%d%d%d",&n,&m,&x,&t)!=EOF)
    {
        chu();
        for(i=1;i<=n;i++)
        {
            for(f=1;f<=m;f++)
            {
                scanf("%d",&map[i][f]);
                sum[i][f]=sum[i][f-1]+map[i][f];
            }
        }
        fun();
        maxx=-INF;
        for(i=1;i<=m;i++)
        {
            maxx=max(maxx,dp[n][i]);
        }
        printf("%d\n",maxx);        
    } 
    return 0; 
} 
