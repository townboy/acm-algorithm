******************************
    Author : townboy
    Submit time : 2012-06-18 00:08:37
    Judge Status : Accepted
    HDOJ Runid : 6076106
    Problem id : 1507
    Exe.time : 406MS
    Exe.memory : 524K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>
#include<vector>
using namespace std;
int dir[4][2]={0,1,0,-1,1,0,-1,0};
int mk[10010],match[10010],map[110][110];
vector<int>q[10010];
int n,m;

void chu()
{
    int i;
    memset(map,0,sizeof(map));
    for(i=1;i<=n*m;i++)
    {
        q[i].clear();
        match[i]=-1;
    }
}

int dfs(int x)
{
    int t,i=q[x].size(),v,b;
    for(b=0;b<i;b++)
    {    
        v=q[x][b];
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

int turn(int a,int b)
{
    return a*n+b+1;
}

void pr()
{
    int i,t;
    for(i=1;i<=n*m;i++)
    {
        if(-1 == match[i])
        {
            continue;
        }
        match[match[i]]=i;
    }
    for(i=1;i<=n*m;i++)
    {
        if(-1 == match[i])
        {
            continue;
        }
        t=match[i];
        printf("(%d,%d)--(%d,%d)\n",(i-1)/n+1,(i-1)%n+1,(t-1)/n+1,(t-1)%n+1);
        match[t]=-1;
    }    
    printf("\n");
}

int xyl()
{
    int max=0,i;
    for(i=1;i<=m*n;i++)
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
    int i,f,g,res,num,x,y;
//    freopen("D:\\in.txt","r",stdin);
    while(scanf("%d%d",&m,&n),!(0 == m && 0 == n))
    {
        
        chu();

        scanf("%d",&num);
        for(i=0;i<num;i++)
        {
            scanf("%d%d",&x,&y);
            x--;
            y--;
            map[x][y]=1;
        }    
        
        for(i=0;i<m;i++)
        {
            for(f=0;f<n;f++)
            {
                if(1 == ((f+i)&1))
                {
                    continue;
                }
                if(1 == map[i][f])
                {
                    continue;
                }
                for(g=0;g<4;g++)
                {
                    if(i+dir[g][0] > m-1 || i+dir[g][0] < 0 || f+dir[g][1]<0 || f+dir[g][1]>n-1)
                    {
                        continue;
                    }
                    if(1 == map[i+dir[g][0]][f+dir[g][1]])
                    {
                        continue;
                    }
                    q[turn(i,f)].push_back(turn(i+dir[g][0],f+dir[g][1]));
                }
            }
        }
        res=xyl();
        printf("%d\n",res);
        
        pr();
    }
    return 0;
}
