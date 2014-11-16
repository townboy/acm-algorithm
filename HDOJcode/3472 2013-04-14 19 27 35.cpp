******************************
    Author : townboy
    Submit time : 2013-04-14 19:27:35
    Judge Status : Accepted
    HDOJ Runid : 8083055
    Problem id : 3472
    Exe.time : 15MS
    Exe.memory : 308K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>
#include<queue>
#include<iostream>
#define maxn 1000
#define maxe 2100000
#define INF 0x3f3f3f3f

using namespace std;

int n,m,s,t;
int size,net[maxn];
int gap[maxn];//gapÓÅ»¯ 
int dist[maxn];//¾àÀë±êºÅ 
int pre[maxn];//Ç°Çý 
int curedge[maxn];//µ±Ç°»¡ 
int hash[maxn];

struct node
{
    int v,next;
    int cap;
    int flow;
};
struct node edge[maxe];

void init()
{
    size=0;
    memset(net,-1,sizeof(net));
}

void add(int u,int v,int cap)
{
    edge[size].v = v;
    edge[size].cap = cap;
    edge[size].flow = 0;
    edge[size].next = net[u];
    net[u] = size;
    ++size;

    edge[size].v = u;
    edge[size].cap = 0;
    edge[size].flow = 0;
    edge[size].next = net[v];
    net[v] = size;
    ++size;
}

int isap()
{
    int curflow,u,temp,neck,i;
    int maxflow;
    memset(gap,0,sizeof(gap));
    memset(pre,-1,sizeof(pre));
    memset(dist,0,sizeof(dist));
    for(i=1;i<=n;i++) 
        curedge[i]=net[i];//½«µ±Ç°»¡³õÊ¼»°³ÉÁÚ½Ó±íµÄµÚÒ»Ìõ±ß 
    gap[0]=n;
    maxflow=0;
    u=s;
    while(dist[s] < n)
    {
        if(u==t)
        {        //ÕÒµ½Ò»ÌõÔö¹ãÂ· 
            curflow=INF;
            for(i=s;i!=t;i=edge[curedge[i]].v)    //ÑØ×ÅÔö¹ãÂ·ÕÒµ½×îÐ¡Ôö¹ãÁ÷Á¿ 
                if(curflow > edge[curedge[i]].cap)
                {
                    neck=i;
                    curflow=edge[curedge[i]].cap;
                }
            for(i=s;i!=t;i=edge[curedge[i]].v)
            {    //¸üÐÂ 
                temp=curedge[i];
                edge[temp].cap-=curflow;
                edge[temp].flow+=curflow;
                temp^=1;
                edge[temp].cap+=curflow;
                edge[temp].flow-=curflow;
            }
            maxflow+=curflow;
            u=neck;//ÏÂ´ÎÖ±½Ó´Ó¹Ø¼ü±ßµÄu¿ªÊ¼ÐÂÒ»ÂÖµÄÔö¹ã 
        }
        for(i=curedge[u];i!=-1;i=edge[i].next)//ÕÒµ½Ò»ÌõÔÊÐí»¡ 
            if(edge[i].cap>0 && dist[u]==dist[edge[i].v]+1)    break;
        if(i!=-1)    //Èç¹ûÕÒµ½ ½«uÖ¸Ïòv 
        {
            curedge[u]=i;
            pre[edge[i].v]=u;
            u=edge[i].v;
        }
        else
        {        //ÕÒ²»µ½ 
            if(0 == --gap[dist[u]])    break;//³öÏÖ¶Ï²ã
            curedge[u] = net[u];//°Ñµ±Ç°»¡ÖØÐÂÉèÎªÁÚ½Ó±íÖÐÂú×ãÒªÇóµÄµÚÒ»Ìõ»¡
            for(temp=n,i=net[u];i!=-1;i=edge[i].next)
                if(edge[i].cap > 0)
                    temp=temp<dist[edge[i].v]?temp:dist[edge[i].v];
            dist[u]=temp+1;//½«Õâ¸öµãµÄ¾àÀë±êºÅÉèÎªÓÉËü³ö·¢µÄËùÓÐ»¡µÄÖÕµãµÄ¾àÀë±êºÅµÄ×îÐ¡Öµ¼Ó1
            gap[dist[u]]++;
            if(u != s)
                u=pre[u];
        }
    }
    return maxflow;
}

int in[27],out[27];
int nn,set[27],fl[27];

void chu()
{
    int i;
    for(i=1;i<=26;i++)
        set[i]=i;
    init();
    memset(fl,0,sizeof(fl));
    memset(in,0,sizeof(in));
    memset(out,0,sizeof(out));
}

int find(int x){
    return x==set[x]?x:set[x]=find(set[x]);
}

void merge(int a,int b){
    set[a]=b;
}

int check()
{
    int sum=0;
    int i,head=0,k=0,ad[26];
    for(i=1;i<=26;i++)
    {
        if(set[i] == i && 1 == fl[i])
            head++;
        if(1 == (in[i]+out[i])%2)
            ad[k++]=i;
    }
    if(1 != head)
        return 0;
    if(0 != k && 2 != k)
        return 0;
    if(2 == k)
    {
        in[ad[1]]++;
        out[ad[0]]++;
        add(ad[0],ad[1],1);
    }
    n=28;
    s=27;
    t=28;
    for(i=1;i<=28;i++)
    {
        if(in[i] == out[i])    continue;
        if(in[i] > out[i])
            sum+=(in[i]-out[i])/2,add(i,t,(in[i]-out[i])/2);
        else
            add(s,i,(out[i]-in[i])/2);
    }
    if(sum == isap())
        return 1;
    return 0;
}

int main()
{
    char ch[25];
    int dir,u,v;
    int i,cas,len,f,ans;
    scanf("%d",&cas);
    for(i=0;i<cas;i++)
    {
        chu();
        scanf("%d",&nn);
        for(f=0;f<nn;f++)
        {
            scanf("%s%d",ch,&dir);
            len=strlen(ch);
            u=ch[0]-'a'+1; v=ch[len-1]-'a'+1;
            in[v]++;
            out[u]++;
            merge(find(u),find(v));
            fl[u]=fl[v]=1;
            if(1 == dir)
                add(u,v,1);
        }
        ans=check();
        printf("Case %d: ",i+1);
        puts(1==ans?"Well done!":"Poor boy!");
    }
    return 0;
}