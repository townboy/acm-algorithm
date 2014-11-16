******************************
    Author : townboy
    Submit time : 2012-07-18 16:46:04
    Judge Status : Accepted
    HDOJ Runid : 6254384
    Problem id : 1829
    Exe.time : 375MS
    Exe.memory : 8784K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>
#include<vector>
#include<queue>
using namespace std;

int d[2100];
vector<int>q[2100];

void chu()
{
    int i;
    for(i=1;i<=2050;i++)
        q[i].clear();
    memset(d,0,sizeof(d));
}

int bfs(int s)
{
    int tem,i;
    queue<int>fun;
    d[s]=1;
    fun.push(s);
    while(!fun.empty())
    {
        tem=fun.front();
        fun.pop();
        for(i=0;i<q[tem].size();i++)
        {
            if(0 == d[q[tem][i]])
            {
                if(1 == d[tem])
                {
                    d[q[tem][i]]=2;
                }
                else
                {
                    d[q[tem][i]]=1;                
                }
                fun.push(q[tem][i]);
            }
            if(1 == d[q[tem][i]])
            {
                if(1 == d[tem])
                {
                    return 1;            
                }
            }
            if(2 == d[q[tem][i]])
            {
                if(2 == d[tem])
                {
                    return 1;
                }
            }
        }    
    }
    return 0;    
}

int main()
{
    int num,i,f,u,v,uu,vv,m,n;
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        chu();
        scanf("%d%d",&n,&m);
        for(f=0;f<m;f++)
        {
            scanf("%d%d",&u,&v);
            q[u].push_back(v);            
            q[v].push_back(u);            
        }
        
        for(f=1;f<=n;f++)
        {
            if(0 == d[f])
            {
                if(1 == bfs(f))
                {
                    break;    
                }
            }
        }
        printf("Scenario #%d:\n",i+1);
        if(f == n+1)
        {
            printf("No suspicious bugs found!\n");
        }
        else
        {
            printf("Suspicious bugs found!\n");
        }
        printf("\n");
    }
    return 0;
}