******************************
    Author : townboy
    Submit time : 2013-05-02 16:26:25
    Judge Status : Accepted
    HDOJ Runid : 8217737
    Problem id : 2069
    Exe.time : 15MS
    Exe.memory : 268K
    https://github.com/townboy
******************************


#include<stdio.h>

int val[4]={50,25,10,5};
int ans,sum;

void dfs(int pos,int now,int coins)
{
    int i;
    if(4 == pos){
        if(coins+sum-now <= 100)
            ans++;
        return ;
    }
    for(i=0;;i++)
    {
        if(now+val[pos]*i > sum)    break;
        dfs(pos+1,now+val[pos]*i,coins+i);
    }
}

int main()
{
    while(scanf("%d",&sum)!=EOF)
    {
        ans=0;
        dfs(0,0,0);
        printf("%d\n",ans);
    }
    return 0;
}