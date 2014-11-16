******************************
    Author : townboy
    Submit time : 2012-12-03 00:02:40
    Judge Status : Accepted
    HDOJ Runid : 7317360
    Problem id : 2830
    Exe.time : 296MS
    Exe.memory : 4248K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std; 

int n,m;
int map[1010][1010];
char ch[1100];

int cmp(const void *a,const void *b)
{
    return *(int *)b-*(int *)a;
}

void chu()
{
    int i,f;
    for(i=1;i<=n;i++)
    {
        for(f=1;f<=m;f++)
        {
            if(0 != map[i][f])
                map[i][f]+=map[i-1][f];
        }
    }
}

int dp()
{
    int i,f,ans=0;
    for(i=1;i<=n;i++)
    {
        qsort(&map[i][1],m,sizeof(map[i][1]),cmp);
        for(f=1;f<=m;f++)
        {    
            if(0 == map[i][f])
                break;
            ans=max(ans,map[i][f]*f);        
        }    
    }
    return ans;
}

int main()
{
    int i,f;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        getchar();
        for(i=1;i<=n;i++)
        {
            gets(ch);
            for(f=1;f<=m;f++)
            {
                map[i][f]=ch[f-1]-'0';
            }
        }
        chu();
        printf("%d\n",dp());
    }
    return 0;
}