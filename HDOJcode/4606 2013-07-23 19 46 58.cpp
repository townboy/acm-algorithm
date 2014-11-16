******************************
    Author : townboy
    Submit time : 2013-07-23 19:46:58
    Judge Status : Accepted
    HDOJ Runid : 8681669
    Problem id : 4606
    Exe.time : 1796MS
    Exe.memory : 1152K
    https://github.com/townboy
******************************


#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstdlib>
#include<map>
using namespace std;
const double eps=1e-7;


int n,m,p;

inline int dcmp(double x){
    return x<-eps?-1:x>eps;
}
inline double sqr(double x){
    return x*x;
}
struct Point{
    double x,y;
    Point(){}
       Point(double x,double y):x(x),y(y){}    
    Point operator - (const Point &p)const{
        return Point(x-p.x,y-p.y);
    }
    Point operator + (const Point &p)const{
        return Point(x+p.x,y+p.y);
    }

    double operator * (const Point &p){
        return x*p.y - y*p.x;
    }
    double operator ^ (const Point &p){
        return x*p.x + y*p.y;
    }
    double Distance(Point p){
        return sqrt(sqr(x-p.x)+sqr(y-p.y));
    }
    void input(){
        scanf("%lf%lf",&x,&y);
    }
    
};
struct Line{
    Point a,b;
    Line(){}
    Line(Point _a,Point _b):a(_a),b(_b){}
    double operator * (const Point &p)const{
        return (b-a) * (p-a);
    }
    double operator ^ (const Point &p)const{
        return (p-a) ^ (p-b);
    }
    void input(){
        a.input(); b.input();
    }
    int SegCrossSeg(const Line &v){
        int d1 = dcmp( (*this)*v.a);
        int d2 = dcmp( (*this)*v.b);
        int d3 = dcmp(v*a);
        int d4 = dcmp(v*b);
        if ( (d1^d2)==-2 && (d3^d4)==-2) return 2;
        return (
                  ( d1==0 && dcmp( (*this) ^ v.a ) <= 0)
                || (d2==0 && dcmp( (*this)^v.b ) <= 0)
                || (d3==0 && dcmp(v^a)<=0 )
                || (d4==0 && dcmp(v^b)<=0 )
                );
    }
};
const int N=310;
vector<Point> pp;
Line bar[N];

int idx[N];

double dis[N][N];
int check(int u,int v){
    Line t = Line(pp[u],pp[v]);
    for (int i=0;i<m;i++){
        if (t.SegCrossSeg(bar[i])==2) return 0;
    }
    return 1;
}
void init(){
    int sz=pp.size();
    for (int i=0;i<sz;i++){
        for (int j=i+1;j<sz;j++){
            if (check(i,j)){
                dis[i][j]=dis[j][i]= pp[i].Distance(pp[j]);
            }else dis[i][j]=dis[j][i]= -1;
        }
    }
    
    for (int k=0;k<sz;k++){
        for (int i=0;i<sz;i++){
            if (dis[i][k]==-1) continue;
            for (int j=0;j<sz;j++){
                if (dis[k][j]==-1) continue;
                if (dis[i][j]==-1 || dis[i][j]>dis[i][k]+dis[k][j]){
                    dis[i][j] = dis[i][k]+dis[k][j];
                }
            }
        }
    }
    
    /*for (int i=0;i<n;i++){
        for (int j=0;j<n;j++) 
            cout<<dis[i][j]<<" ";cout<<endl;
    }
    */
}

#define maxn 310
#define maxe 100000
#define INF 0x3f3f3f3f

int net[maxn],size,maxflow,mincost;
int nn,dist[maxn],pre[maxn],pe[maxn];
bool hash[maxn];
queue<int>q;
    
struct xx{
    int v,next;
    int cap;
    int cost;
    xx(){}
    xx(int _v,int _next,int _cap,int _cost)
    :v(_v),next(_next),cap(_cap),cost(_cost){}
};
struct xx edge[maxe];

void G_init(){
    size=0;
    memset(net,-1,sizeof(net));
}

void add(int u,int v,int cap,int cost)
{
    edge[size] = xx(v,net[u],cap,cost);
    net[u]=size++;
    edge[size] = xx(u,net[v],0,-cost);
    net[v]=size++;
}

int spfa(int s,int t)
{
    int i,u,v;
    while(!q.empty())    q.pop();
    memset(hash,0,sizeof(hash));
    memset(pre,-1,sizeof(pre));
    for(i=1;i<=nn;i++)    dist[i]=INF;
    dist[s]=0;
    hash[s]=1;
    q.push(s);
    while(!q.empty())
    {
        u=q.front();
        q.pop();
        hash[u]=0;
        for(i=net[u];i!=-1;i=edge[i].next)
        {
            v=edge[i].v;
            if(edge[i].cap && dist[v]>dist[u]+edge[i].cost)
            {
                dist[v]=dist[u]+edge[i].cost;
                pre[v]=u; 
                pe[v]=i;
                if(0 == hash[v]){
                    hash[v]=1;
                    q.push(v);
                }
            }
        }
    }
    if(-1 == pre[t]) 
        return 0;
    return 1;
}

void mcmf(int s,int t)
{
    int i,aug,v;
    maxflow=0;
    mincost=0;
    while(1 == spfa(s,t))
    {
        aug=INF;
        for(v=t;v!=s;v=pre[v])
            aug=min(aug,edge[pe[v]].cap);
        maxflow+=aug;
        mincost+=dist[t]*aug;
        for(v=t;v!=s;v=pre[v]){
            edge[pe[v]].cap-=aug;
            edge[pe[v]^1].cap+=aug;
        }
    }
}

map<int,int> mp;

bool pan(double len) {
    nn = 3 + 2*n;
    int s1 = nn-2 , s2 = nn-1 , t = nn;
    G_init();
    add(s1,s2,p,0);
    for(int i = 1 ;i <= n;i++) {
        add(s2,i,1,0);
        add(i, i+n, 1,-1);
        add(i+n,t,1,0);
    }

    for(int i = 0; i < n;i++)
        for(int f = 0; f < n;f++) {
            if(i == f)
                continue;
            if(mp[i+1] > mp[f+1])
                continue;
            if(-1 == dis[i][f])
                continue;
            if(dis[i][f] < len)
                add(i+1+n , f+1,1,0);
                
        }
    mcmf(s1,t);
    if(-n == mincost)
        return true;
    return false;
}

double solve(){
    double l = 0 , r = 300000 ,mid ;
    while(r - l > eps) {
        mid = (l+r)/2;
        if( true == pan(mid)) 
            r = mid;
        else 
            l = mid;
    }
    return mid;
}

int main(){
    int T;
    scanf("%d",&T);
    while (T--){
        scanf("%d%d%d",&n,&m,&p);
        pp.clear();
        for (int i=0;i<n;i++){
            Point t;
            t.input();
            pp.push_back(t);
        }
        for (int i=0;i<m;i++){
            bar[i].input();
            pp.push_back(bar[i].a);
            pp.push_back(bar[i].b);
        }

        mp.clear();
        for (int i=0;i<n;i++) {
            int tem;
            scanf("%d",&tem);
            mp[tem] = i;
        }

        init();
        printf("%.2lf\n",solve());
    }
    return 0;
}

