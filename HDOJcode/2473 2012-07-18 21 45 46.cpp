******************************
    Author : townboy
    Submit time : 2012-07-18 21:45:46
    Judge Status : Accepted
    HDOJ Runid : 6257775
    Problem id : 2473
    Exe.time : 593MS
    Exe.memory : 7284K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>

int n;
int set[1100000],id[110000],hash[1100000];

void chu()
{
    int i;
    for(i=0;i<n;i++)
    {
        set[i]=i;
        id[i]=i;        
    }
    memset(hash,0,sizeof(hash));
}

int find(int x)
{
     return x==set[x]?x:set[x]=find(set[x]);
}

void merge(int u,int v)
{
    set[u]=v;
}

int main()
{
    char ch[5];
    int i,ji,d,u,v,m,aim,ans,cas=0;
    while(scanf("%d%d",&n,&m),!(0 == m&&0 == n))
    {
        cas++;
        chu();
        ji=n;
        for(i=0;i<m;i++)
        {    
            scanf("%s",ch);
            if('M' == ch[0])
            {
                scanf("%d%d",&u,&v);
                merge(find(id[u]),find(id[v]));
            }
            else
            {
                scanf("%d",&d);    
                id[d]=ji;
                set[ji]=ji;
                ji++;
            }
        }
        ans=0;
        for(i=0;i<n;i++)
        {
            aim=find(id[i]);
            if(0 == hash[aim])
            {
                ans++;
                hash[aim]=1;    
            }
        }
        printf("Case #%d: %d\n",cas,ans);
    }
    return 0;
}