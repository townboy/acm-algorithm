******************************
    Author : townboy
    Submit time : 2013-02-25 16:54:38
    Judge Status : Accepted
    HDOJ Runid : 7651725
    Problem id : 1873
    Exe.time : 31MS
    Exe.memory : 268K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<queue>

using namespace std;

struct node 
{
    int id;
    int val;
    friend bool operator < (node a,node b)
    {
        if(a.val < b.val)
            return true;
        else if(a.val > b.val)
            return false;
        else if(a.id < b.id)
            return false;
        else
            return true;
    }
};
struct node ru;
priority_queue<node>que[3];
int n;

void chu()
{
    int i;
    for(i=0;i<3;i++)
        while(!que[i].empty())
            que[i].pop();
}

int main()
{
    int i,a,b,ji;
    char ch[10];
    while(scanf("%d",&n)!=EOF)
    {
        chu();
        ji=0;
        for(i=0;i<n;i++)
        {
            scanf("%s",ch);
            if(0 == strcmp("IN",ch))
            {
                ji++;
                scanf("%d%d",&a,&b);        
                ru.id=ji;
                ru.val=b;
                que[a-1].push(ru);                
            }
            else
            {
                scanf("%d",&a);
                if(true == que[a-1].empty())
                    printf("EMPTY\n");
                else
                {
                    printf("%d\n",que[a-1].top().id);
                    que[a-1].pop();
                }
            }
        }
    }
    return 0;
}