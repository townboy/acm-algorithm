******************************
    Author : townboy
    Submit time : 2013-06-29 18:50:01
    Judge Status : Accepted
    HDOJ Runid : 8508580
    Problem id : 4560
    Exe.time : 203MS
    Exe.memory : 432K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>
#include<iostream>
#include<algorithm>

#define maxn 1000
#define maxe 20000

using namespace std;

int gap[maxn],dis[maxn],pre[maxn],cur[maxn];
int size,n,head[maxn];

struct Node{
    int c,v,next;
    Node(){}
    Node(int _v,int _c,int _next):v(_v),c(_c),next(_next){}
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

void add(int u,int v,int c,int cc = 0){
    E[size] = Node(v,c,head[u]);
    head[u] = size++;
    E[size] = Node(u,cc,head[v]);
    head[v] = size++;
}
void init(){
    memset(head,-1,sizeof(head));
    size=0;
}

int good[80][80];
int nn,mm,l,k;

int check(int round)
{    
    int s,t,i,f;
    n = nn + 2*mm +2;
    s = n-1;
    t = s+1;
    init();
    for(i = 1;i<=nn;i++)
        add(s,i,round);
    for(i = nn+1;i <= nn+mm;i++)
        add(i,i+mm,k);
    for(i = nn+mm+1;i<=nn+mm+mm;i++)
        add(i,t,round);
    for(i=1;i<=nn;i++)
        for(f=1;f<=mm;f++)
            if(1 == good[i][f])
                add(i,f+nn+mm,1);
            else 
                add(i,f+nn,1);
    if(nn*round == sap(s,t))
        return 1;
    return 0;
}

int er(){
    int l = 0,r = mm+1,mid;
    while(l < r-1){
        mid = (l+r)>>1;
        if(check(mid) == 0)
            r = mid;
        else
            l = mid;
    }
    return l;
}

int main()
{
    int ans,a,b;
    int f,i,cas;
    scanf("%d",&cas);
    for(i=0;i<cas;i++)
    {
        scanf("%d %d %d %d",&nn,&mm,&l,&k);
        memset(good,0,sizeof(good));
        for(f=0;f<l;f++){
            scanf("%d %d",&a,&b);
            good[a][b]=1;
        }
        ans = er();
        printf("Case %d: %d\n",i+1,ans);
    }
    return 0;
}