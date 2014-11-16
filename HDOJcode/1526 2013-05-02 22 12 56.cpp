******************************
    Author : townboy
    Submit time : 2013-05-02 22:12:56
    Judge Status : Accepted
    HDOJ Runid : 8221001
    Problem id : 1526
    Exe.time : 0MS
    Exe.memory : 372K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>
#include<iostream>
#include<string>
#include<map>

#define INF 0x3f3f3f3f
#define maxn 1100
#define maxe 1000010

using namespace std;

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

map<string,int>mp;
int ji;

int id(string tem){
    if(0 == mp[tem])
        mp[tem]=++ji;
    return mp[tem];
}

int main()
{
    int u,v;
    int tem,sum,s,t;
    string ch,ch2;
    int f,i,cas;
    scanf("%d",&cas);
    for(i=0;i<cas;i++)
    {
        init();
        mp.clear();
        ji=0;
        n=802;
        s=801;
        t=802;
        scanf("%d",&tem);
        for(f=0;f<tem;f++)
        {
            cin>>ch;
            u=id(ch);
            add(s,u,1);
        }
        scanf("%d",&sum);
        for(f=0;f<sum;f++)
        {
            cin>>ch>>ch2;
            u=id(ch2);
            add(u,t,1);
        }
        scanf("%d",&tem);
        for(f=0;f<tem;f++)
        {
            cin>>ch>>ch2;
            u=id(ch);
            v=id(ch2);
            add(v,u,INF);
        }
        if(0 != i)
            printf("\n");
        printf("%d\n",sum-sap(s,t));
    }
    return 0;
}