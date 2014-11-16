******************************
    Author : townboy
    Submit time : 2012-09-09 19:45:10
    Judge Status : Accepted
    HDOJ Runid : 6728359
    Problem id : 4284
    Exe.time : 2234MS
    Exe.memory : 8144K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>
#include<iostream>

#define INF 100000000
using namespace std; 

int h,n,m,dis[110][110],id[20],add[20],cost[20]; 
int dp[100000][20],wei[100000];  

void chu()
{
    int i,f; 
    for(i=1;i<=105;i++)
    {
        for(f=1;f<=105;f++)
        {
            dis[i][f]=INF; 
        } 
        dis[i][i]=0; 
    }
    memset(dp,-1,sizeof(dp));  
} 

int lowbit(int t)
{
    return t&(-t); 
} 

void update(int x) 
{
    int san,neww,i,old=x,pos;
    while(0 != old)
    {
        san=lowbit(old); 
        old^=san;
        neww=(x^san);
        pos=wei[san]; 
        for(i=0;i<=15;i++)
        {
            if(-1 == dp[neww][i])
            {
                continue; 
            } 
            if(dp[neww][i] >= dis[id[i]][id[pos]]+cost[pos])
            {
                dp[x][pos]=max(dp[x][pos],dp[neww][i]-dis[id[i]][id[pos]]+add[pos]-cost[pos]);    
            } 
        } 
    } 
} 
 
void dpp()
{
    int i,san,neww,old,x=(1<<h)-1;
    for(i=1;i<=x;i++)
    {
        update(i);
    }
    for(i=1;i<=h;i++)
    {
        if(dp[x][i] >= dis[id[i]][1])
        {
            printf("YES\n"); 
            return ; 
        } 
    }    
    printf("NO\n"); 
} 

void folyd()
{
    int i,f,g;
    for(g=1;g<=n;g++)
    {
        for(i=1;i<=n;i++)
        {
            for(f=1;f<=n;f++)
            {
                dis[i][f]=min(dis[i][f],dis[i][g]+dis[g][f]);        
            } 
        } 
    }      
} 

void debug()
{
    int i,f;
    for(i=0;i<=(1<<h)-1;i++) 
    {
        for(f=0;f<=n;f++)
        {
            printf("%d ",dp[i][f]); 
        } 
        printf("\n"); 
    } 
} 

int main()
{
    int c,d,i,num,u,v,w,f;
    
    for(i=1;i<=15;i++)
    {
        wei[1<<(i-1)]=i; 
    } 
    
    
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        chu(); 
        scanf("%d%d%d",&n,&m,&dp[0][0]);
        for(f=0;f<m;f++)
        {
            scanf("%d%d%d",&u,&v,&w);
            dis[v][u]=dis[u][v]=min(w,dis[u][v]);     
        }             
        folyd();     

        scanf("%d",&h);
        for(f=1;f<=h;f++)
        {
            scanf("%d%d%d",&id[f],&add[f],&cost[f]);
        } 
        id[0]=1; 
        
        dpp(); 
    } 
    return 0; 
} 