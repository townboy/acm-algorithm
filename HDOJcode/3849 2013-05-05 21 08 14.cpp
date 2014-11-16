******************************
    Author : townboy
    Submit time : 2013-05-05 21:08:14
    Judge Status : Accepted
    HDOJ Runid : 8242950
    Problem id : 3849
    Exe.time : 500MS
    Exe.memory : 10668K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<string>
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<memory.h>
#define maxn 10010

using namespace std;

string road[110000][2];
int state[110000],n,m;

vector<int>tt[maxn];

struct BCC
{
    int n,dfs_clock,bcc_cnt;
    int dfn[maxn],low[maxn],bccno[maxn];
    vector<int>G[maxn];
    stack<int>S;
    void init(int _n){
        dfs_clock=bcc_cnt=0;
        n=_n;
        for(int i=1;i<=n;i++)
            G[i].clear();
        memset(dfn,0,sizeof(dfn));
        while(!S.empty())
            S.pop();
    }
    void dfs(int u,int fa){
        int v,size=G[u].size(),x,flag=1;
        S.push(u);
        dfn[u]=low[u]=++dfs_clock;
        for(int i=0;i<size;i++)
        {
            v=G[u][i];
            if(v == fa && 1==flag)
            {    
                flag=0;
                continue;
            }
            if(0 == dfn[v])
            {
                dfs(v,u);
                low[u]=min(low[u],low[v]);
            }
            else
                low[u]=min(low[u],dfn[v]);
        }
        if(low[u] == dfn[u])
        {
            bcc_cnt++;
            do{
                x=S.top();S.pop();
                bccno[x]=bcc_cnt;
            }while(x != u);
        }
    }
    void add(int u,int v,int tem){
        G[u].push_back(v);
        tt[u].push_back(tem);
    }
    void find_bcc(){
        dfs(1,-1);
    }
    void ans(){
        int sum=0,i,f,size,no,v;
        for(i=1;i<=n;i++)
        {
            if(0 == dfn[i]){
                puts("0");
                return ;
            }
            size=G[i].size();
            for(f=0;f<size;f++)
            {
                v=G[i][f];
                no=tt[i][f];
                if(bccno[i] != bccno[v])
                    sum++,state[no]=1;
            }
        }
        printf("%d\n",sum/2);
        for(i=0;i<m;i++)
            if(1 == state[i])
                cout<<road[i][0]<<" "<<road[i][1]<<endl;
    }
};
BCC lentty;

int ji;
map<string,int>mp;

int id(string x){
    if(0 == mp[x])
        mp[x]=++ji;
    return mp[x];
}

void init(){
    memset(state,0,sizeof(state));
    ji=0;
    mp.clear();
    lentty.init(n);
    for(int i=1;i<=n;i++)
        tt[i].clear();
}

int main()
{
    int u,v;
    char uu[20],vv[20];
    int i,cas,f;
    scanf("%d",&cas);
    for(i=0;i<cas;i++)
    {
        scanf("%d%d",&n,&m);    
        init();
        
        for(f=0;f<m;f++)
        {
            scanf("%s%s",uu,vv);
            u=id(uu);
            v=id(vv);
            lentty.add(u,v,f);
            lentty.add(v,u,f);
            road[f][0]=uu;
            road[f][1]=vv;
        }
        lentty.find_bcc();
        lentty.ans();
    }
    return 0;
}