******************************
    Author : townboy
    Submit time : 2012-09-28 17:56:29
    Judge Status : Accepted
    HDOJ Runid : 6841715
    Problem id : 4009
    Exe.time : 968MS
    Exe.memory : 5672K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>
#include<math.h>

#define INF 0x7fffffff
#define N 1005
#define M 1300005

struct edge
{
    int u,v;
    int val;
};
struct edge e[M];

int loc[1100][3];

int pre[N],vis[N],id[N];
int val[N];
int dmst(int r,int n,int m)
{
    int res=0;
    int u,v,i,f,cnt,k,tv;
    while(1)
    {
        memset(id,-1,sizeof(id));
        memset(vis,-1,sizeof(vis));
        for(i=1;i<=n;i++) 
        {
            val[i]=INF;
        }
        val[r]=0;
        for(i=0;i<m;i++)
        {
            u=e[i].u;
            v=e[i].v;
            if(u == v) 
            {
                continue;
            }
            if(val[v] > e[i].val)
            {
                val[v] = e[i].val;
                pre[v] = u;
            }
        }
        for(i=1;i<=n;i++)
        {
            if(INF == val[i]) 
            {
                return -1;
            }
        }
        cnt=0;
        for(i=1;i<=n;i++)
        {
            res+=val[i];
            for(f=i;f!=r;f=pre[f])
            {
                if(vis[f]==i || -1!=id[f]) 
                {
                    break;
                }
                vis[f]=i;
            }
            if(f!=r && -1==id[f])
            {
                cnt++;
                id[f]=cnt;
                for(k=pre[f];k!=f;k=pre[k])
                {
                    id[k]=cnt;
                }
            }
        }
        if(0 == cnt)
        { 
            break;
        }
        for(i=1;i<=n;i++)
        {
            if(-1 == id[i]) 
            {
                cnt++;
                id[i]=cnt;
            }
        }
        for(i=0;i<m;i++)
        {
            tv=e[i].v;
            e[i].u=id[e[i].u];
            e[i].v=id[e[i].v];
            if(e[i].u != e[i].v)
            {
                e[i].val-=val[tv];
            }
        }
        n=cnt;
        r=id[r];
    }
    return res;
}

int main()
{
    int ans;
    int i,f,m,v,k,g,n,x,y,z;
    while(scanf("%d%d%d%d",&n,&x,&y,&z),n+x+y+z)
    {
        for(i=1;i<=n;i++)
        {
            for(f=0;f<3;f++)
            {
                scanf("%d",&loc[i][f]);        
            }
        }        
        m=0;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&k);
            for(f=0;f<k;f++)
            {
                scanf("%d",&v);    
                if(v == i)
                {
                    continue;
                }
                e[m].u=i;
                e[m].v=v;
                e[m].val=0;
                for(g=0;g<3;g++)
                {
                    e[m].val+=abs(loc[i][g]-loc[v][g]);
                }
                e[m].val*=y;
                if(loc[i][2] < loc[v][2])
                {
                    e[m].val+=z;    
                }
                m++;
            }
        }
        for(i=1;i<=n;i++)
        {
            e[m].u=n+1;
            e[m].v=i;
            e[m].val=loc[i][2]*x;
            m++;
        }
        ans=dmst(n+1,n+1,m);
        if(-1 == ans)
        {
            printf("poor XiaoA\n");
        }
        else
        {
            printf("%d\n",ans);
        }
    }
    return 0;
}