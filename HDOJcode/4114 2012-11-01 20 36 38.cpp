******************************
    Author : townboy
    Submit time : 2012-11-01 20:36:38
    Judge Status : Accepted
    HDOJ Runid : 7060751
    Problem id : 4114
    Exe.time : 5640MS
    Exe.memory : 19336K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>
#include<queue>
#define INF 0x7fffffff

using namespace std;

int dp[55][260][260];
int n,m,k,M; 
int map[60][60];
char hash[55][260][260]; 
int t[10],ft[10];
vector<int>own[60],build[60];

void chu()
{
    int i,f,g;
    for(i=1;i<=n;i++)
    {
        for(f=0;f<=270;f++)
        {
            for(g=0;g<=270;g++)
            {
                dp[i][f][g]=INF;
            }
        }
        own[i].clear(); 
        build[i].clear(); 
    }
    memset(map,-1,sizeof(map));
    memset(hash,0,sizeof(hash)); 
    M=(1<<k)-1; 
}

struct node
{
    int v;
    int a;
    int b;
};
struct node tem,ru; 

void spfa()
{
    int f,a,b,x; 
    int size,i,v,id; 
    int newa,newb; 
    queue<node>que;

    size=own[1].size();
    a=0; 
    for(i=0;i<size;i++)
    {
        a|=(1<<(own[1][i]-1)); 
    }

    ru.v=1;
    ru.a=a;
    ru.b=0; 
    hash[1][a][0]=1; 
    dp[1][a][0]=0;
    que.push(ru);
    
    while(!que.empty())
    {
        tem=que.front();
        id=tem.v; 
        a=tem.a;
        b=tem.b; 
        que.pop();
        hash[id][a][b]=0;
         
        for(i=1;i<=n;i++)
        {
            if(-1 == map[id][i])
            {
                continue; 
            }
            size=own[i].size();
            newa=a; 
            for(f=0;f<size;f++)
            {
                newa|=(1<<(own[i][f]-1)); 
            }
            
            if(dp[i][newa][b] > dp[id][a][b]+map[id][i])
            {
                dp[i][newa][b]=dp[id][a][b]+map[id][i];
                if(0 == hash[i][newa][b])
                {
                    hash[i][newa][b]=1;
                    ru.v=i;
                    ru.a=newa;
                    ru.b=b;
                    que.push(ru);    
                }
            }
        }        
        
        size=build[id].size();
        for(i=0;i<size;i++)
        {
            x=build[id][i]; 
            if(0 != (b&(1<<(x-1))))
            {
                continue; 
            }
            newb=b|(1<<(x-1));    
            newa=a|(1<<(x-1));
            if(0 != (a&(1<<(x-1))))
            {
                if(dp[id][newa][newb] > dp[id][a][b]+ft[x])
                {
                    dp[id][newa][newb] = dp[id][a][b]+ft[x];    
                    if(0 == hash[id][newa][newb])
                    {
                        hash[id][newa][newb]=1;
                        ru.v=id;
                        ru.a=newa;
                        ru.b=newb; 
                        que.push(ru); 
                    } 
                } 
            }
            else
            {
                if(dp[id][newa][newb] > dp[id][a][b]+t[x])
                {
                    dp[id][newa][newb] = dp[id][a][b]+t[x];        
                    if(0 == hash[id][newa][newb])
                    {
                        hash[id][newa][newb]=1;
                        ru.v=id;
                        ru.a=newa;
                        ru.b=newb;
                        que.push(ru); 
                    } 
                } 
            } 
        } 
    }    
}

int main()
{
    int u,v,len,s;
    int cas,i,f,ji,g;
    scanf("%d",&cas);
    for(i=0;i<cas;i++)
    {
        scanf("%d%d%d",&n,&m,&k); 
        chu();
        for(f=0;f<m;f++)
        {
            scanf("%d%d%d",&u,&v,&len);
            map[u][v]=map[v][u]=len;
        }
        for(f=1;f<=k;f++)
        {
            scanf("%d%d%d%d",&s,&t[f],&ft[f],&ji);
            build[s].push_back(f);
            for(g=0;g<ji;g++)
            {
                scanf("%d",&v); 
                own[v].push_back(f);
            } 
        }
        spfa();
        
        printf("Case #%d: %d\n",i+1,dp[1][M][M]);
    } 
    return 0; 
}