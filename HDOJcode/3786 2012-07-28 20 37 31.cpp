******************************
    Author : townboy
    Submit time : 2012-07-28 20:37:31
    Judge Status : Accepted
    HDOJ Runid : 6365341
    Problem id : 3786
    Exe.time : 0MS
    Exe.memory : 276K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
#include<queue>
using namespace std;

int s,t,map[30][30];

void chu()
{
    memset(map,0,sizeof(map));
}

int bfs()
{
    int tem,hash[30],val[30],i;
    memset(hash,0,sizeof(hash));
    memset(val,-1,sizeof(val));
    queue<int>q;
    val[s]=0;
    q.push(s);
    while(!q.empty())
    {
        tem=q.front();
        q.pop();
        if(t == tem)
        {
            return val[tem];
        }
        for(i=0;i<26;i++)
        {
            if(1 == map[tem][i])
            {
                if(-1 == val[i])
                {
                    val[i]=val[tem]+1;
                    q.push(i);
                }    
            }
        }
    }
    return -1;
}

void fun(int a,int b)
{
    int ans;
    s=a;
    t=b;
    ans=bfs();
    if(-1 != ans)
    {
        for(;ans>2;ans--)
        {
            printf("great-");    
        }
        if(1 == ans)
        {
            printf("child\n");
        }
        else
        {
            printf("grandchild\n");
        }
        return ;            
    }
    s=b;
    t=a;
    ans=bfs();
    if(-1 == ans)
    {
        printf("-\n");
    }
    else
    {
        for(;ans>2;ans--)
        {
            printf("great-");    
        }
        if(1 == ans)
        {
            printf("parent\n");
        }
        else
        {
            printf("grandparent\n");
        }
    }
}

int main()
{
    char ch[10];
    int child,n,k,m,i;
    while(scanf("%d%d",&n,&m),n+m)
    {
        chu();
        for(i=0;i<n;i++)
        {
            scanf("%s",&ch);
            child=ch[0]-'A';
            if('-' != ch[1])
            {    
                map[child][ch[1]-'A']=1;    
            }
            
            if('-' != ch[2])
            {
                map[child][ch[2]-'A']=1;            
            }
        }
        
        for(i=0;i<m;i++)
        {
            scanf("%s",ch);
            fun(ch[0]-'A',ch[1]-'A');
        }
    }
    return 0;
}