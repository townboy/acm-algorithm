******************************
    Author : townboy
    Submit time : 2013-04-10 19:27:16
    Judge Status : Accepted
    HDOJ Runid : 8049599
    Problem id : 1827
    Exe.time : 218MS
    Exe.memory : 312K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>

#define INF 0x3f3f3f3f
#define N 1005
#define M 100005

struct edge
{
    int u,v;
    int val;
};
struct edge e[M];

int aim;
int pre[N],vis[N],id[N];
int val[N],hash[N];
int dmst(int r,int n,int m)
{
    int u,v,i,f,res=0,cnt,k,tv;
    while(1)
    {
        aim=0;
        memset(hash,0,sizeof(hash));
        memset(id,-1,sizeof(id));
        memset(vis,-1,sizeof(vis));
        for(i=1;i<=n;i++) 
            val[i]=INF;
        val[r]=0;
        for(i=0;i<m;i++)
        {
            u=e[i].u;
            v=e[i].v;
            if(u == v)    continue;
            if(val[v] > e[i].val)
            {
                if(r == u && 0 == hash[v])
                {
                    aim++;
                    hash[v]=1;
                }
                val[v] = e[i].val;
                pre[v] = u;
            }
        }
        for(i=1;i<=n;i++)
            if(INF == val[i]) 
                return -1;
        cnt=0;
        for(i=1;i<=n;i++)
        {
            res+=val[i];
            for(f=i;f!=r;f=pre[f])
            {
                if(vis[f]==i || -1!=id[f]) 
                    break;
                vis[f]=i;
            }
            if(f!=r && -1==id[f])
            {
                cnt++;
                id[f]=cnt;
                for(k=pre[f];k!=f;k=pre[k])
                    id[k]=cnt;
            }
        }
        if(0 == cnt)
            break;
        for(i=1;i<=n;i++)
            if(-1 == id[i]) 
            {
                cnt++;
                id[i]=cnt;
            }
        for(i=0;i<m;i++)
        {
            tv=e[i].v;
            e[i].u=id[e[i].u];
            e[i].v=id[e[i].v];
            if(e[i].u != e[i].v)
                e[i].val-=val[tv];
        }
        n=cnt;
        r=id[r];
    }
    return res;
}

int main()
{
    int cost[1100];
    int n,m;
    int i,cnt,ans;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        cnt=0;
        for(i=1;i<=n;i++)
            scanf("%d",cost+i);
        for(cnt=0;cnt<m;cnt++)
        {
            scanf("%d %d",&e[cnt].u,&e[cnt].v);
            e[cnt].val=0;
        }
        for(i=1;i<=n;i++)
        {
            e[cnt].u=n+1,e[cnt].v=i,e[cnt].val=cost[i];
            cnt++;
        }
        ans=dmst(n+1,n+1,cnt);
        printf("%d %d\n",aim,ans);
    }
    return 0;
}