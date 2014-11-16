******************************
    Author : townboy
    Submit time : 2012-09-18 21:23:42
    Judge Status : Accepted
    HDOJ Runid : 6792408
    Problem id : 2860
    Exe.time : 343MS
    Exe.memory : 1072K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>
#include<iostream>
using namespace std;

int set[110000],low[110000];
int n,m,k;

void chu()
{
    int i;
    memset(low,-1,sizeof(low));
    for(i=0;i<n;i++)
    {
        set[i]=i;
    }
}

int find(int x)
{
    return x==set[x]?x:set[x]=find(set[x]);
}

void merge(int a,int b)
{
    set[b]=a;
}

int main()
{
    char ch[10];
    int x,i,c,r,y;
    while(scanf("%d%d%d",&n,&k,&m)!=EOF)
    {
        chu();
        for(i=0;i<k;i++)
        {
            scanf("%d%d",&r,&c);
            if(-1 == low[c])
            {
                low[c]=r;
                continue;
            }
            low[c]=min(low[c],r);
        }
        for(i=0;i<m;i++)
        {
            scanf("%s",ch);
            if('G' == ch[0])
            {
                scanf("%d",&x);
                if(x == set[x])
                {
                    if(-1 == low[x])
                    {
                        printf("Company %d is empty.\n",x);
                    }
                    else
                    {
                        printf("Lowest rate: %d.\n",low[x]);                    
                    }
                }
                else
                {
                    printf("Company %d is a part of company %d.\n",x,find(x));
                }
            }
            else if('A' == ch[0])
            {
                scanf("%d%d",&x,&y);
                if(y == set[y])
                {
                    if(-1 == low[y])
                    {
                        low[y]=x;
                    }
                    else
                    {
                        low[y]=min(low[y],x);
                    }
                    printf("Accept\n");
                }
                else
                {
                    printf("Reject\n");
                }
            }
            else
            {
                scanf("%d%d",&x,&y);
                if(x == y)
                {
                    printf("Reject\n");
                    continue;
                }
        
                if(x==set[x] && y==set[y])
                {
                    printf("Accept\n");
                    if(low[x] < 0 || low[y] < 0)
                    {
                        low[x]=max(low[x],low[y]);    
                    }
                    else
                    {
                        low[x]=min(low[x],low[y]);
                    }
                    merge(x,y);
                }
                else
                {
                    printf("Reject\n");
                }
            }
        }
        printf("\n");    
    }
    return 0;
}