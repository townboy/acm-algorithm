******************************
    Author : townboy
    Submit time : 2012-10-12 13:57:22
    Judge Status : Accepted
    HDOJ Runid : 6908486
    Problem id : 2923
    Exe.time : 93MS
    Exe.memory : 300K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<string>
#include<iostream>
#include<memory.h>
#include<map>

using namespace std;

map<string,int>mp;
int sum,flag,ji,n,m,c,id[1100],len;
int path[110][110];
char chh[100];
void turn()
{
    int i,len=strlen(chh);
    flag=0;
    if('<' == chh[0])
    {
        flag+=1;
    }
    if('>' == chh[len-1])
    {    
        flag+=2;
    }
    sum=0;
    for(i=2;i<len-2;i++)
    {
        sum*=10;
        sum+=chh[i]-'0';
    }
}

void chu()
{
    mp.clear();
    ji=0;
    memset(path,-1,sizeof(path));
}

int name(string ch)
{
    if(0 == mp[ch])
    {
        ji++;
        mp[ch]=ji;
    }
    return mp[ch];
}

void flyod()
{
    int i,f,k;
    for(k=1;k<=n;k++)
    {
        for(i=1;i<=n;i++)
        {
            for(f=1;f<=n;f++)
            {
                if(-1 == path[i][k] || -1 == path[k][f])
                {
                    continue;
                }
                if(-1 == path[i][f])
                {
                    path[i][f]=path[i][k]+path[k][f];
                    continue;
                }
                path[i][f]=min(path[i][f],path[i][k]+path[k][f]);
            }
        }
    }
}

void add(int u,int v,int len)
{
    if(-1 == path[u][v])
    {
        path[u][v]=sum;
        return ;
    }
    path[u][v]=min(path[u][v],len);
}

int main()
{
    string ch1,ch2,ch;
    int i,u,v,cas=0,ans;
    while(scanf("%d%d%d",&n,&c,&m),n+c+m)
    {
        chu();
        cas++;
        for(i=1;i<=c+1;i++)
        {
            cin>>ch;
            id[i]=name(ch);
        }
        for(i=0;i<m;i++)
        {
            cin>>ch1;
            scanf("%s",chh);
            cin>>ch2;            
            u=name(ch1);
            v=name(ch2);
            turn();
            if(1 == flag)
            {
                add(v,u,sum);
            }
            else if(2 == flag)
            {
                add(u,v,sum);
            }
            else
            {
                add(u,v,sum);
                add(v,u,sum);
            }
        }
        printf("%d. ",cas);
        flyod();
        ans=0;
        for(i=2;i<=c+1;i++)
        {
            ans+=path[id[i]][id[1]];
            ans+=path[id[1]][id[i]];
        }
        printf("%d\n",ans);
    }
    return 0;
}