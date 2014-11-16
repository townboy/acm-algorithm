******************************
    Author : townboy
    Submit time : 2013-05-01 19:29:46
    Judge Status : Accepted
    HDOJ Runid : 8213076
    Problem id : 2120
    Exe.time : 0MS
    Exe.memory : 272K
    https://github.com/townboy
******************************


#include<stdio.h>
#define maxn 1010

int n,m,set[maxn];

int find(int x){
    return set[x]==x?x:set[x]=find(set[x]);
}

void merge(int a,int b){
    set[a]=b;
}

void init(){
    int i;
    for(i=0;i<n;i++)
        set[i]=i;
}

int main()
{
    int u,v;
    int i,ans;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        ans=0;
        init();
        for(i=0;i<m;i++)
        {
            scanf("%d%d",&u,&v);
            if(find(u) == find(v))
                ans++;
            else
                merge(find(u),find(v));
        }
        printf("%d\n",ans);
    }
    return 0;
}