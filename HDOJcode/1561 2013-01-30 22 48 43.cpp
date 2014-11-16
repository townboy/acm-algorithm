******************************
    Author : townboy
    Submit time : 2013-01-30 22:48:43
    Judge Status : Accepted
    HDOJ Runid : 7571608
    Problem id : 1561
    Exe.time : 15MS
    Exe.memory : 444K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<vector>
#include<memory.h>
#define INF 10000000

using namespace std;

int dp[210][210];
int sumcity[210];
int n,m; 
int val[210];
vector<int>map[210];

void chu()
{
    int i,f;
    for(i=0;i<=n;i++)
    {
        sumcity[i]=1;
        map[i].clear();
        for(f=1;f<=n;f++)
            dp[i][f]=INF;
        dp[i][0]=0;
    }
}

void dfs(int rt)
{
    int yu;
    int size=map[rt].size();
    int i,son,f,g;
    
    for(i=0;i<size;i++)
    {
        son=map[rt][i];
        dfs(son);
        sumcity[rt]+=sumcity[son];
        
        if(0 == i)
        {
            for(f=0;f<=sumcity[son];f++)
                dp[rt][f]=dp[son][f];
        }
        else
        {
            for(f=sumcity[rt]-1;f>0;f--)
            {
                for(g=sumcity[son];g>0;g--)
                {
                    yu=f-g;
                    if(yu > sumcity[rt]-sumcity[son]-1 || yu < 0)
                        continue;
                    dp[rt][f]=min(dp[rt][f],dp[rt][yu]+dp[son][g]);            
                }
            }
        }
    }
    dp[rt][sumcity[rt]]=dp[rt][sumcity[rt]-1]+val[rt];
}

int main()
{
    int fa,tem;
    int i,sum;
    while(scanf("%d%d",&n,&m),n+m)
    {
        chu();
        sum=0;
        val[0]=0;
        for(i=1;i<=n;i++)
        {
            scanf("%d%d",&fa,&tem);
            map[fa].push_back(i);
            val[i]=tem;
            sum+=tem;
        }
        dfs(0);
        
        printf("%d\n",sum-dp[0][n-m]);
    }
    return 0;
}