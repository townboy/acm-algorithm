******************************
    Author : townboy
    Submit time : 2013-03-24 14:45:22
    Judge Status : Accepted
    HDOJ Runid : 7866121
    Problem id : 4514
    Exe.time : 968MS
    Exe.memory : 4672K
    https://github.com/townboy
******************************


#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
using namespace std;

const int N=100010;
struct Edge{
    int v,w;
};
vector<Edge> G[N];
int fa[N];
int dis[N];
queue<int> q;
bool vis[N];
int find(int x){
    return x==fa[x]?x:fa[x]=find(fa[x]);
}
int bfs(int u){
    int root=u;
    memset(vis,0,sizeof(vis));
    dis[u]=0;
    vis[u]=true;
    q.push(u);
    while(!q.empty()){
        u=q.front(); q.pop();
        if(dis[u]>dis[root]) root=u;
        int sz=G[u].size();
        for(int i=0;i<sz;i++){
            int v=G[u][i].v;
            int w=G[u][i].w;
            if(vis[v]) continue;
            vis[v]=true;
            dis[v]=dis[u]+w;
            q.push(v);
        }
    }
    return root;
}
int main(){
    int n,m;
    while(~scanf("%d%d",&n,&m)){
        for(int i=0;i<n;i++){
            G[i].clear();
            fa[i]=i;
            dis[i]=-1;
        }
        bool flag=false;
        if(m>=n) flag=true;
        for(int i=0;i<m;i++){
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            u--; v--;
            if(flag) continue;
            int fu=find(u);
            int fv=find(v);
            if(fu==fv) flag=true;
            fa[fv]=fu;
            G[u].push_back((Edge){v,w});
            G[v].push_back((Edge){u,w});
        }
        if(flag){
            printf("YES\n");
            continue;
        }
        for(int i=0;i<n;i++) if(fa[i]==i){
            int root=bfs(i);
            bfs(root);
        }
        int ans=0;
        for(int i=0;i<n;i++)
            if(dis[i]>ans) ans=dis[i];
        printf("%d\n",ans);
    }
    return 0;
}
