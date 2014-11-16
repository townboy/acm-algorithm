******************************
    Author : townboy
    Submit time : 2012-06-28 21:04:32
    Judge Status : Accepted
    HDOJ Runid : 6106447
    Problem id : 1997
    Exe.time : 0MS
    Exe.memory : 232K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<stdlib.h>
#include<queue>
using namespace std;
queue<int>que[3];

int n;

int check(int one,int two,int three)
{
    if(0 == n)
    {
        return 1;
    }
    if(n == que[one].front())
    {
        que[one].pop();
        n--;
        if(1 == check(one,three,two))
        {
            return 1;
        }            
        return 0;
    }
    if(n == que[two].front())
    {
        que[two].pop();
        n--;
        if(1 == check(three,two,one))
        {
            return 1;
        }
        return 0;
    }
    return 0;    
}

void chu()
{
    int i;
    for(i=0;i<3;i++)
    {
        while(!que[i].empty())
        {
            que[i].pop();
        }
    }
}

int main()
{
    int num,i,f,g,x,k;
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        chu();
        scanf("%d",&n);
        for(f=0;f<3;f++)
        {
            scanf("%d",&k);
            for(g=0;g<k;g++)
            {
                scanf("%d",&x);
                que[f].push(x);
            }    
        }
        if(1 == check(0,2,1))
        {
            printf("true\n");
        }
        else
        {
            printf("false\n");
        }
    }
    return 0;
}