******************************
    Author : townboy
    Submit time : 2012-07-31 19:54:57
    Judge Status : Accepted
    HDOJ Runid : 6388369
    Problem id : 4324
    Exe.time : 375MS
    Exe.memory : 10108K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<queue>
#include<vector>
using namespace std;

vector<int>q[2005];
int n,du[2005];

void chu()
{
    int i;
    for(i=1;i<=n;i++)
    {
        q[i].clear();
    }
    memset(du,0,sizeof(du));
}

int topo()
{
    int ans,i,tem,size;
    queue<int>que;
    for(i=1;i<=n;i++)
    {
        if(0 == du[i])
        {
            que.push(i);
        }
    }
    ans=0;
    while(!que.empty())
    {
        ans++;
        tem=que.front();
        que.pop();
        size=q[tem].size();
        for(i=0;i<size;i++)
        {
            du[q[tem][i]]--;
            if(0 == du[q[tem][i]])
            {
                que.push(q[tem][i]);
            }    
        }
    }
    if(ans == n)
    {
        return 0;
    }
    return 1;
}

int main()
{
    char ch[2005];
    int i,f,g,ans,num;
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        scanf("%d",&n);
        chu();
        for(f=1;f<=n;f++)
        {
            scanf("%s",ch);
            for(g=1;g<=n;g++)
            {
                if('1' == ch[g-1])
                {
                    q[f].push_back(g);
                    du[g]++;
                }
            }
        }
        ans=topo();
        printf("Case #%d: ",i+1);
        if(1 == ans)
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }
    return 0;
}