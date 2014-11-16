******************************
    Author : townboy
    Submit time : 2012-07-29 01:15:06
    Judge Status : Accepted
    HDOJ Runid : 6366739
    Problem id : 3339
    Exe.time : 203MS
    Exe.memory : 364K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>
#include<queue>
#define INF 99999999 
using namespace std; 

int dp[11100],map[110][110],oil[110],val[110],n; 

void chu()
{
    int i; 
    memset(map,-1,sizeof(map));
    for(i=0;i<=n;i++)
    {
        val[i]=INF; 
    }
    for(i=0;i<=11000;i++)
    {
        dp[i]=INF; 
    } 
    dp[0]=0;
} 

int minn(int a,int b)
{
    return a<b?a:b;    
}

void pack(int v,int w)
{
    int i; 
    for(i=11000;i>=v;i--)
    {
        dp[i]=minn(dp[i],dp[i-v]+w);    
    }
} 

void spfa()
{
    int hash[110],i,tem; 
    queue<int>q;
    val[0]=0;
    q.push(0);
    memset(hash,0,sizeof(hash)); 
    while(!q.empty())
    {
        tem=q.front();
        q.pop(); 
        hash[tem]=0; 
        for(i=1;i<=n;i++)
        {
            if(-1 == map[tem][i])
            {
                continue;
            }
            if(val[i] > val[tem]+map[tem][i])
            {
                val[i]=val[tem]+map[tem][i]; 
                if(0 == hash[i])
                {
                    hash[i]=1;
                    q.push(i);
                } 
            }
        } 
    }    
} 

void debug()
{
    int i,f;
    for(i=0;i<50;i++)
    {
        printf("%d ",dp[i]);
    }
    printf("\n");
}

int main()
{
    int pr,m,s,t,len,i,f,num,sum;
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        scanf("%d%d",&n,&m);
        chu(); 
        for(f=0;f<m;f++)
        {
            scanf("%d%d%d",&s,&t,&len); 
            if(-1 == map[s][t])
            {
                map[s][t]=len;
                map[t][s]=len; 
            }
            else
            {
                map[s][t]=minn(map[s][t],len);
                map[t][s]=map[s][t]; 
            }
        }
        sum=0;
        for(f=1;f<=n;f++)
        {
            scanf("%d",&oil[f]);
            sum+=oil[f];
        }
        spfa();
        for(f=1;f<=n;f++)
        {
            pack(oil[f],val[f]); 
        }
        pr=INF;
        for(f=11000;f>=sum/2+1;f--)
        {
            pr=minn(dp[f],pr);
        }
        if(INF == pr)
        {
            printf("impossible\n");    
        }
        else
        {
            printf("%d\n",pr);
        }
    } 
    return 0; 
} 