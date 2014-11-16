******************************
    Author : townboy
    Submit time : 2013-05-02 21:08:15
    Judge Status : Accepted
    HDOJ Runid : 8220377
    Problem id : 1532
    Exe.time : 15MS
    Exe.memory : 300K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>

#define maxn 1100
#define maxe 1000010

int gap[maxn],dis[maxn],pre[maxn],cur[maxn];
int size,n,head[maxn];

struct Node{
    int c,v,next;
}E[maxe];

int sap(int s,int t) {
    memset(dis,0,sizeof(dis));
    memset(gap,0,sizeof(gap));
    for(int i=1;i<=n;i++)    cur[i] = head[i];
    int u = pre[s] = s,maxflow = 0,aug = -1;
    gap[0] = n;
    while(dis[s] < n) {
loop:        for(int &i = cur[u]; i != -1; i = E[i].next) {
            int v = E[i].v;
            if(E[i].c && dis[u] == dis[v] + 1) {
                if(aug==-1 || aug>E[i].c)    aug=E[i].c;
                pre[v] = u;
                u = v;
                if(v == t) {
                    maxflow += aug;
                    for(u = pre[u];v != s;v = u,u = pre[u]) {
                        E[cur[u]].c -= aug;
                        E[cur[u]^1].c += aug;
                    }
                    aug = -1;
                }
                goto loop;
            }
        }
        int mindis = n;
        for(int i = head[u]; i != -1 ; i = E[i].next) {
            int v = E[i].v;
            if(E[i].c && mindis > dis[v]) {
                cur[u] = i;
                mindis = dis[v];
            }
        }
        if( (--gap[dis[u]]) == 0)    break;
        gap[ dis[u] = mindis+1 ] ++;
        u = pre[u];
    }
    return maxflow;
}

void add(int u,int v,int c,int cc = 0) {
    E[size].c = c;    E[size].v = v;
    E[size].next = head[u];    head[u] = size++;
    E[size].c = cc;    E[size].v = u;
    E[size].next = head[v];    head[v] = size++;
}
void init(){
    memset(head,-1,sizeof(head));
    size=0;
}

int main()
{
    int u,v,len;
    int i,m;
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        init();
        for(i=0;i<m;i++)
        {
            scanf("%d%d%d",&u,&v,&len);
            add(u,v,len);
        }
        printf("%d\n",sap(1,n));
    }
    return 0;
}