******************************
    Author : townboy
    Submit time : 2012-11-13 23:48:23
    Judge Status : Accepted
    HDOJ Runid : 7152510
    Problem id : 4360
    Exe.time : 203MS
    Exe.memory : 744K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<queue>
#include<vector>
#include<memory.h>
#define INF ((__int64)1<<50)

using namespace std;

struct node 
{
    int v;
    int len;
    int flag;
};
struct node ru;

vector<node>q[1400];
int n,m,num[1400][4],hash[1400][4];
__int64 dis[1400][4];
char ans[4]={'L','O','V','E'};

void chu()
{
    int i,f;
    for(i=1;i<=n;i++)
    {
        q[i].clear();
        for(f=0;f<4;f++)
        {
            dis[i][f]=INF;
        }    
    }
    memset(hash,0,sizeof(hash));
    memset(num,0,sizeof(num));
}

void add(int u,int v,int len,int flag)
{
    ru.len=len;
    ru.flag=flag;
    ru.v=v;
    q[u].push_back(ru);
    ru.v=u;
    q[v].push_back(ru);
}

void spfa()
{
    int size,v,len;
    int i,tem,flag,newflag;
    queue<int>que;
    
    dis[1][3]=0;
    num[1][3]=0;
    que.push(1);
    que.push(3); 
    
    while(!que.empty())
    {
        tem=que.front();
        que.pop();
        flag=que.front();
        que.pop();
        hash[tem][flag]=0;
    
        size=q[tem].size();
        for(i=0;i<size;i++)
        {
            v=q[tem][i].v;
            len=q[tem][i].len;
            newflag=q[tem][i].flag;
    
            if(newflag != (flag+1)%4)
            {
                continue;
            }
            if(dis[v][newflag] > dis[tem][flag]+len)
            {
                dis[v][newflag]=dis[tem][flag]+len;
                num[v][newflag]=num[tem][flag]+(0 == newflag?1:0);
                que.push(v);
                que.push(newflag);
            }
            else if(dis[v][newflag] == dis[tem][flag]+len)
            {
                if(num[v][newflag] < num[tem][flag]+(0 == newflag?1:0))
                {
                    num[v][newflag] = num[tem][flag]+(0 == newflag?1:0);    
                    que.push(v);
                    que.push(newflag);            
                }
            }
            else if(1 == v && 3 == newflag && 0 == num[1][3])
            {
                dis[v][newflag]=dis[tem][flag]+len;
                num[v][newflag]=num[tem][flag]+(0 == newflag?1:0);
                que.push(v);
                que.push(newflag);
            }
        }    
    }
}

int main()
{
    int u,v,len;
    int i,f,g,cas;
    char ch[10];
    scanf("%d",&cas);
    for(i=0;i<cas;i++)
    {
        scanf("%d%d",&n,&m);
        chu();
        for(f=0;f<m;f++)
        {
            scanf("%d%d%d%s",&u,&v,&len,ch);
            for(g=0;g<4;g++)
            {
                if(ch[0] == ans[g])
                {
                    add(u,v,len,g);
                    break;
                }
            }
        }
        spfa();
        if(1 == n)
        {
            if(0 == num[1][3])
            {
                printf("Case %d: Binbin you disappoint Sangsang again, damn it!\n",i+1);
            }
            else
            {
                printf("Case %d: Cute Sangsang, Binbin will come with a donkey after travelling %I64d meters and finding %d LOVE strings at last.\n",i+1,dis[n][3],num[n][3]);    
            }
            continue;
        }
        if(INF == dis[n][3])
        {
            printf("Case %d: Binbin you disappoint Sangsang again, damn it!\n",i+1);
            continue;
        }
        printf("Case %d: Cute Sangsang, Binbin will come with a donkey after travelling %I64d meters and finding %d LOVE strings at last.\n",i+1,dis[n][3],num[n][3]);
    }
    return 0;
}