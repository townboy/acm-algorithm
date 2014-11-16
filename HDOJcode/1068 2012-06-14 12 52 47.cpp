******************************
    Author : townboy
    Submit time : 2012-06-14 12:52:47
    Judge Status : Accepted
    HDOJ Runid : 6063957
    Problem id : 1068
    Exe.time : 1343MS
    Exe.memory : 1656K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<queue>
#include<memory.h>
using namespace std;

int n,m;
int map[600][600],cx[600],cy[600],disx[600],disy[600];

int bfs()
{
    int flag=0,i,j;
    queue<int> q;
    memset(disx,0,sizeof(disx));
    memset(disy,0,sizeof(disy));
    for(i=0;i<n;i++)
    {
        if (-1 == cx[i])
        {
            q.push(i);
        }
    }

    while ( !q.empty() )
    {
        i=q.front();
        q.pop();
        for(j=0;j<m;j++)
        {
            if((1 == map[i][j]) && (0 == disy[j]))
            {
                disy[j]=disx[i]+1;
                   if (-1 != cy[j])
                {
                    disx[cy[j]]=disy[j]+1;
                    q.push(cy[j]);
                } 
                else
                {
                    flag=1;
                }
            }
        }
    }
    return flag;
}

int dfs(int i)
{
    int j;
    for(j=0;j<m;j++)
    {
        if (disy[j] == disx[i]+1 && 1 == map[i][j])
        {
            disy[j]=0;
            if ( -1 == cy[j] || 1 == dfs(cy[j]) )
            {
                cy[j]=i;
                cx[i]=j;
                return 1;
            }
        }
    }
    return 0;
}

void chu()
{
    int i;
    for(i=0;i<n;i++)
    {
        cx[i]=-1;
    }
    for(i=0;i<m;i++)
    {
        cy[i]=-1;
    }
}

int hopcroft_karp()
{ 
    int ans=0,i;
    chu();
    while(1 == bfs())
    {
        for(i=0;i<n;i++)
        {
            if(-1 == cx[i] && 1 == dfs(i))
            { 
                ans++;
            }
        }
    }
    return ans;
}

void inti()
{
    memset(map,0,sizeof(map));
}

int main()
{
    int s,num,f,e,i,res;
//    freopen("F:\\in.txt","r",stdin);
    while(scanf("%d",&n)!=EOF)
    {
        m=n;
        inti();
        for(i=0;i<n;i++)
        {
            scanf("%d: (%d)",&s,&num);
            for(f=0;f<num;f++)
            {
                scanf("%d",&e);
                map[s][e]=1;
            }
        }
        res=hopcroft_karp()/2;
        printf("%d\n",n-res);
    }
    return 0;
}
