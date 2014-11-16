******************************
    Author : townboy
    Submit time : 2012-10-04 20:00:16
    Judge Status : Accepted
    HDOJ Runid : 6864706
    Problem id : 3687
    Exe.time : 31MS
    Exe.memory : 248K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>
#include<stdlib.h>
#include<iostream>
#define INF 0x7fffffff

using namespace std;

int num[60];
int pos[60][60];

int cmp(const void *a,const void *b)
{
    return *(int *)a-*(int *)b;
}

void chu()
{
    memset(num,0,sizeof(num));
}

int abs(int x)
{
    return x>0?x:-x; 
}

int main()
{
    int sum,ans;
    int i,f,x,y,n,m,g;
    while(scanf("%d%d",&n,&m),n+m)
    {
        chu();
        for(i=0;i<n*n;i++)
        {
            scanf("%d%d",&x,&y);
            pos[x][num[x]]=y;
            num[x]++;            
        }
        for(i=1;i<=n;i++)
        {
            qsort(pos[i],n,sizeof(pos[i][0]),cmp);
        }
        ans=INF;
        for(i=1;i<=m-n+1;i++)
        {
            sum=0;
            for(f=1;f<=n;f++)
            {
                for(g=0;g<n;g++)
                {
                    sum+=abs(pos[f][g]-(i+g));            
                }
            }
            ans=min(ans,sum);
        }
        printf("%d\n",ans);    
    }
    return 0;
}