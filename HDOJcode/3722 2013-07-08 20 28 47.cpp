******************************
    Author : townboy
    Submit time : 2013-07-08 20:28:47
    Judge Status : Accepted
    HDOJ Runid : 8548256
    Problem id : 3722
    Exe.time : 234MS
    Exe.memory : 1980K
    https://github.com/townboy
******************************


#include<iostream>
#include<memory.h>
#include<algorithm>
#include<stdio.h>
#include<queue>
#include<vector>
#define INF 0x3f3f3f3f
#define maxn 500
#define maxe 100000

using namespace std;

int val[210][210];
int num;
char ch[210][1100];

void init(){
    for(int i = 0 ; i < num;i++){
        char tem[1100];
        memcpy(tem, ch[i] ,  sizeof(tem));
        int len = strlen(ch[i]);
        for(int f = 0 ; f < len/2 ;f++){
            char aa = tem[f];
            tem[f] = tem[len-1-f];
            tem[len-1-f] = aa;
        }
        for(int f = 0 ; f < num; f++){
            int cnt = 0 ; 
            if(i == f){
                val[i][f] = 0;
                continue;
            }
            for(int g = 0 ; g < len; g++){
                if(tem[g] == ch[f][g])
                    cnt ++;
                else 
                    break;
            }
            val[i][f] = cnt;
        }
    }
}

void debug(){
    for(int i = 0; i < num;i++){
        for(int f= 0 ; f< num;f++)
            cout << val[i][f] << " " ;
        cout << endl;
    }    
}

int net[maxn],size,maxflow,mincost;
int n ,dist[maxn],pre[maxn],pe[maxn];
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

xx edge[maxe];

void G_init(){
    size = 0 ;
    memset(net,-1,sizeof(net));
}

void add(int u,int v,int cap,int cost){
    edge[size] = xx(v,net[u],cap,cost);
    net[u] = size ++;
    edge[size] = xx(u,net[v],0,-cost);
    net[v] = size++;
}

int spfa(int s,int t){
    int i,u,v;
    while(!q.empty()) q.pop();
    memset(hash,0,sizeof(hash));
    memset(pre,-1,sizeof(pre));
    for(int i = 1;i <= n;i++) dist[i] = INF;
    dist[s] = 0 ; 
    hash[s] = 1 ;
    q.push(s);
    
    while(!q.empty()){
        u = q.front();
        q.pop();
        hash[u] = 0;
        for(i = net[u]; i != -1; i = edge[i].next){
            v = edge[i].v;
            if(edge[i].cap && dist[v] > dist[u] + edge[i].cost){
                dist[v] = dist[u] + edge[i].cost;
                pre[v] = u;
                pe[v] = i ;
                if(0 == hash[v]) {
                    hash[v] = 1;
                    q.push(v);
                }
            }
        }
    }
    if(-1 == pre[t] )
        return 0;
    return 1;
}

void mcmf(int s, int t){
    int i ,aug,v;
    maxflow = 0;
    mincost = 0;
    while(1 == spfa(s,t)){
        aug = INF;
        for(v = t ;v != s;v = pre[v])
            aug = min(aug ,edge[pe[v]].cap);
        maxflow += aug;
        mincost += dist[t]*aug;
        for(v = t; v !=s ;v = pre[v]){
            edge[pe[v]].cap -= aug;
            edge[pe[v]^1].cap += aug;
        }
    }
}

int solve(){
    G_init();
    n = 2*num + 2;
    int s = n-1 , t = n;
    for(int i = 1; i <= num; i++){
        add(s,i , 1, 0);
        add(i+num ,t, 1, 0);
    }
    for(int i = 0 ; i < num ;i++)
        for(int f = 0 ;f < num ;f++)
            add(1+i , f+1+num , 1, -val[i][f]);
    mcmf(s,t);
    return -mincost;
}


int main(){
    while(cin >> num){
        for(int i = 0 ;i < num;i++)
            scanf("%s",ch[i]);
        init();
        cout << solve() << endl;
    }
    return 0;
}
