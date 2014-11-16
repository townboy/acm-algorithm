******************************
    Author : townboy
    Submit time : 2013-04-09 23:57:39
    Judge Status : Accepted
    HDOJ Runid : 8044850
    Problem id : 2122
    Exe.time : 78MS
    Exe.memory : 368K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<algorithm>

using namespace std;

struct node 
{
    int u,v,len;
    friend bool operator < (node a,node b)
    {
        return a.len < b.len;
    }
};
struct node que[10010];

int set[1100];

int find(int x)
{
    return set[x]==x?x:set[x]=find(set[x]);
}

void merge(int a,int b)
{
    set[a]=b;
}

int main()
{
    int u,v,cnt;
    int i,n,m,ans;
    while(scanf("%d%d",&n,&m)!=EOF)
    {    
        ans=0;
        cnt=0;
        for(i=0;i<n;i++)
            set[i]=i;
        for(i=0;i<m;i++)
            scanf("%d %d %d",&que[i].u,&que[i].v,&que[i].len);
        sort(que,que+m);
        for(i=0;i<m;i++)
        {
            u=find(que[i].u);
            v=find(que[i].v);
            if(u == v)    continue;
            merge(u,v);
            ans+=que[i].len;
            cnt++;
            if(cnt == n-1)
                break;
        }
        if(n-1 == cnt)
            printf("%d\n\n",ans);
        else 
            printf("impossible\n\n");
    }
    return 0;
}