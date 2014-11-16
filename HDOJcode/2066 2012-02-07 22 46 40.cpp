******************************
    Author : townboy
    Submit time : 2012-02-07 22:46:40
    Judge Status : Accepted
    HDOJ Runid : 5327553
    Problem id : 2066
    Exe.time : 15MS
    Exe.memory : 4208K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<queue>
using namespace std;
int hash[1015],map[1015][1015],s,t,d,mu[1000],chu[1000];
struct node
{
    int val;
    int time;
    friend bool operator < (node a,node b)
    {
        return a.time>b.time;
    }
};
struct node tem,ru;
int bfs()
{
    int i;
    priority_queue<node>q;
    ru.val=0;
    ru.time=0;
    q.push(ru);
    while(!q.empty())
    {
        tem=q.top();
        q.pop();
        for(i=0;i<d;i++)
        {
            if(mu[i]==tem.val)
            {
                return tem.time;
            }
        }
        hash[tem.val]=1;
        if(0==tem.val)
        {
            for(i=0;i<s;i++)
            {
                ru.val=chu[i];
                ru.time=0;
                q.push(ru);
            }
        }
        else
        {
            for(i=0;i<1006;i++)
            {
                if(0!=map[tem.val][i])
                {
                    if(1==hash[i])
                    {
                        continue;
                    }
                    ru.val=i;
                    ru.time=tem.time+map[tem.val][i];
                    q.push(ru);
                }
            }
        }
    }
    return -1;
}
int main()
{
    int i,f,a,b,dis,res;
    while(scanf("%d%d%d",&t,&s,&d)!=EOF)
    {
        for(i=0;i<1010;i++)
        {
            for(f=0;f<1010;f++)
            {
                map[i][f]=0;
            }
            hash[i]=0;
        }
        for(i=0;i<t;i++)
        {
            scanf("%d%d%d",&a,&b,&dis);
            if(0==map[a][b])
            {
                map[a][b]=dis;
                map[b][a]=dis;
            }
            else
            {
                if(dis<map[a][b])
                {
                    map[a][b]=dis;
                    map[b][a]=dis;
                }
            }
        }
        for(i=0;i<s;i++)
        {
            scanf("%d",&chu[i]);
        }
        for(i=0;i<d;i++)
        {
            scanf("%d",&mu[i]);
        }
        res=bfs();
        printf("%d\n",res);    
    }
    return 0;
}