******************************
    Author : townboy
    Submit time : 2012-07-27 17:08:47
    Judge Status : Accepted
    HDOJ Runid : 6352924
    Problem id : 4318
    Exe.time : 2421MS
    Exe.memory : 26292K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<queue>
#include<vector>
#include<stdlib.h>

using namespace std;

struct node
{
    int v;
    double sun;
};
struct node zan;
int n,s,t,hash[51000];
double val[51000],m;
vector<node>q[51000];

void chu()
{
    int i;
    for(i=1;i<=n;i++)
    {    
        q[i].clear();
        val[i]=-1;
    }
    memset(hash,0,sizeof(hash));
}

double spfa()
{
    double sun;
    int tem,ru,i,size;
    queue<int>que;
    que.push(s);
    val[s]=m;
    hash[s]=1;
    while(!que.empty())
    {
        tem=que.front();
        que.pop();
        hash[tem]=0;
        size=q[tem].size();
        for(i=0;i<size;i++)
        {
            ru=q[tem][i].v;
            sun=val[tem]*(1-q[tem][i].sun);
            if(val[ru] < sun)
            {
                val[ru]=sun;
                if(0 == hash[ru])
                {
                    hash[ru]=1;
                    que.push(ru);
                }
            }
        }
    }
    return val[t];
}

int main()
{
    int i,f,k,v;
    double ans,sun;
    while(scanf("%d",&n)!=EOF)
    {
        chu();
        for(i=1;i<=n;i++)
        {
            scanf("%d",&k);
            for(f=0;f<k;f++)
            {
                scanf("%d%lf",&v,&sun);
                zan.v=v;
                zan.sun=sun/100;
                q[i].push_back(zan);
            }
        }

        scanf("%d%d%lf",&s,&t,&m);
        ans=spfa();
        printf("%.2lf\n",(m-ans));
    }
    return 0;
}
