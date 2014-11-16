******************************
    Author : townboy
    Submit time : 2012-06-30 16:48:55
    Judge Status : Accepted
    HDOJ Runid : 6110910
    Problem id : 2571
    Exe.time : 0MS
    Exe.memory : 452K
    https://github.com/townboy
******************************


#include<stdio.h>
#define INF -99999999 

int dp[30][1500],map[30][2000]; 
int n,m; 

void test(int f,int g)
{
    int k; 
    if(dp[f+1][g] < dp[f][g]+map[f+1][g])
    {
        dp[f+1][g]=dp[f][g]+map[f+1][g]; 
    }     
    if(dp[f][g+1] < dp[f][g]+map[f][g+1])
    {
        dp[f][g+1]=dp[f][g]+map[f][g+1]; 
    }     
    for(k=2;g*k<=m;k++)
    { 
        if(dp[f][g*k] < dp[f][g]+map[f][g*k])
        {
            dp[f][g*k]=dp[f][g]+map[f][g*k]; 
        }     
     } 
} 

void chu()
{
    int i,f;
    for(i=1;i<=n;i++)
    {
        for(f=1;f<=m;f++)
        {
            dp[i][f]=INF; 
        } 
    } 
} 

int main()
{
    int num,i,f,g;
    scanf("%d",&num); 
    for(i=0;i<num;i++)
    {
        scanf("%d%d",&n,&m);
        chu(); 
        for(f=1;f<=n;f++)
        {
            for(g=1;g<=m;g++)
            {    
                scanf("%d",&map[f][g]); 
            } 
        }
        dp[1][1]=map[1][1];
         for(f=1;f<=n;f++)
        {
            for(g=1;g<=m;g++)
            {    
                test(f,g); 
            } 
        }
        printf("%d\n",dp[n][m]); 
    }
    return 0;
}