******************************
    Author : townboy
    Submit time : 2012-04-12 23:55:19
    Judge Status : Accepted
    HDOJ Runid : 5763420
    Problem id : 1789
    Exe.time : 15MS
    Exe.memory : 264K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<queue>
using namespace std;

struct node1 
{
    int dead;
    int sco;
    friend bool operator< (node1 a,node1 b)
    {
        return a.dead>b.dead;
    }
};

struct node2 
{
    int dead;
    int sco;
    friend bool operator< (node2 a,node2 b)
    {
        return a.sco>b.sco;
    }
};

node1 que[1100],tem;
node2 ru;

int main()
{
    priority_queue<node1> q;
    priority_queue<node2> chu;
    int num,n,i,f,sum,t;
//    freopen("D:\\in.txt","r",stdin);
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        sum=0;
        scanf("%d",&n);
        for(f=0;f<n;f++)
        {
            scanf("%d",&que[f].dead);
        }
        
        for(f=0;f<n;f++)
        {
            scanf("%d",&que[f].sco);
            q.push(que[f]);
        }
        
        t=0;
        while(!q.empty())
        {
            tem=q.top();
            q.pop();
            if(tem.dead>t)
            {
                ru.dead=tem.dead;
                ru.sco=tem.sco;
                chu.push(ru);
                t++;
            }
            else
            {
                ru.dead=tem.dead;
                ru.sco=tem.sco;
                chu.push(ru);
                ru=chu.top();
                chu.pop();
                sum+=ru.sco;
            }
        }
        
        printf("%d\n",sum);
        
        while(!q.empty())
        {
            q.pop();
        }

        while(!chu.empty())
        {
            chu.pop();
        }
    }
    return 0;
}