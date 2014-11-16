******************************
    Author : townboy
    Submit time : 2012-06-17 14:38:37
    Judge Status : Accepted
    HDOJ Runid : 6074383
    Problem id : 4185
    Exe.time : 640MS
    Exe.memory : 7304K
    https://github.com/townboy
******************************


#include<vector>
#include<stdio.h>
#include<memory.h>
using namespace std;
char map[610][610];
vector<int>q[360010];
int match[360010],mk[360010],dir[4][2]={0,1,0,-1,1,0,-1,0};
int n;

void chu()
{
    int i;
    for(i=1;i<=n*n;i++)
    {
        q[i].clear();
        match[i]=-1;
    }
}

int turn(int f,int g)
{
    return f*n+g+1;
}

int dfs(int x)
{    
    int v;
    int i,t,d=q[x].size();
    for(i=0;i<d;i++)
    {
        v=q[x][i];
        if(0 == mk[v])
        {
            mk[v]=1;
            t=match[v];
            match[v]=x;
            if(-1 == t || 1 == dfs(t))
            {
                return 1;
            }
            match[v]=t;
        }
    }
    return 0;
}

int xyl()
{
    int max=0,i;
    for(i=1;i<=n*n;i++)
    {
        memset(mk,0,sizeof(mk));
        if(1 == dfs(i))
        {
            max++;
        }
    }
    return max;
}

int main()
{
    int num,i,f,g,h,res;
//    freopen("D:\\in.txt","r",stdin);
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        scanf("%d",&n);
        getchar();
        
        chu();
        for(f=0;f<n;f++)
        {
            for(g=0;g<n;g++)
            {
                scanf("%c",&map[f][g]);
            }
            getchar();
        }

        for(f=0;f<n;f++)
        {
            for(g=0;g<n;g++)
            {
                if(1 == ((f+g)&1))
                {
                    continue;
                }
                if('.' == map[f][g])
                {
                    continue;
                }
                for(h=0;h<4;h++)
                {
                    if(f+dir[h][0]<0 || f+dir[h][0]>n-1 || g+dir[h][1]<0 || g+dir[h][1]>n-1)
                    {
                        continue;
                    }
                    if('#' == map[f+dir[h][0]][g+dir[h][1]])
                    {
                        q[turn(f,g)].push_back(turn(f+dir[h][0],g+dir[h][1]));
                    }
                }
            }
        }
        
        res=xyl();
        printf("Case %d: %d\n",i+1,res);
    }
    return 0;
}