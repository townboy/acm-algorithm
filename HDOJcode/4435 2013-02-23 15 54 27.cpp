******************************
    Author : townboy
    Submit time : 2013-02-23 15:54:27
    Judge Status : Accepted
    HDOJ Runid : 7644713
    Problem id : 4435
    Exe.time : 31MS
    Exe.memory : 312K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<stdlib.h>
#include<queue>
#include<math.h>

using namespace std;

int n,d;
int dis[130][130];
int loc[130][2],ans[130];

void chu()
{
    int i;
    for(i=0;i<n;i++)
        ans[i]=1;
}    

int check()
{
    int tem,hash[130],i;    
    queue<int>que;
    memset(hash,0,sizeof(hash));
    hash[0]=1;
    que.push(0);
    while(!que.empty())
    {
        tem=que.front();
        que.pop();
        for(i=0;i<n;i++)
        {
            if(1 == hash[i])
                continue;
            if(1 == ans[i])
            {
                if(d >= dis[tem][i])
                {
                    hash[i]=1;
                    que.push(i);
                }
            }
            else
            {
                if(d >= 2*dis[tem][i])
                    hash[i]=1;
            }
        }
    }
    for(i=0;i<n;i++)
    {
        if(0 == hash[i])
            return 0;
    }    
    return 1;
}

void print()
{
    int i,flag=0;
    for(i=n-1;i>=0;i--)
    {
        if(0 == ans[i])
        {
            if(1 == flag)
                printf("0");    
        }
        else
        {
            printf("1");
            flag=1;        
        }
    }
    printf("\n");
}

int main()
{
    double tem;
    int i,f;
    while(scanf("%d%d",&n,&d)!=EOF)
    {
        chu();
        for(i=0;i<n;i++)
            scanf("%d%d",&loc[i][0],&loc[i][1]);
        for(i=0;i<n;i++)
            for(f=0;f<n;f++)
            {
                tem=sqrt( (double)(loc[i][0]-loc[f][0])*(loc[i][0]-loc[f][0]) + (loc[i][1]-loc[f][1])*(loc[i][1]-loc[f][1]) );
                if(tem == (int)tem)
                    dis[i][f]=(int)tem;
                else
                    dis[i][f]=(int)tem+1;
            }
        if(0 == check())
        {
            printf("-1\n");
            continue;
        }
        for(i=n-1;i>0;i--)
        {
            ans[i]=0;
            if(0 == check())
                ans[i]=1;
        }
        print();
    }
    return 0;
}