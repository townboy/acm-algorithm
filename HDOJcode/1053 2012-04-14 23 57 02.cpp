******************************
    Author : townboy
    Submit time : 2012-04-14 23:57:02
    Judge Status : Accepted
    HDOJ Runid : 5776922
    Problem id : 1053
    Exe.time : 0MS
    Exe.memory : 272K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<string.h>
#include<memory.h>
#include<queue>
using namespace std;

struct node 
{
    int x;
    friend bool operator<(node a,node b)
    {
        return a.x>b.x;
    }
};
struct node ru,minn,maxx;

int main()
{
    int sum,hash[30],i,ji;
    char ch[10000];
    priority_queue<node>q;
    while(gets(ch)!=NULL)
    {
        if(0==strcmp(ch,"END"))
        {
            break;
        }
        sum=0;
        memset(hash,0,sizeof(hash));
        for(i=0;i<strlen(ch);i++)
        {
            if('_'==ch[i])
            { 
                hash[26]++;
                continue;
            }
            hash[ch[i]-'A']++;
        }
        ji=0;
        for(i=0;i<=26;i++)
        {
            if(0!=hash[i])
            {
                ji++;
                ru.x=hash[i];
                q.push(ru);
            }
        }
        while(1)
        {
            minn=q.top();
            q.pop();
            if(q.empty())
            {
                break;
            }
            maxx=q.top();
            q.pop();
            sum+=(minn.x+maxx.x);
            ru.x=(minn.x+maxx.x);
            q.push(ru);
        }
        if(1==ji)
        {
             printf("%d %d 8.0\n",strlen(ch)*8,strlen(ch));
             continue;
        }
        printf("%d %d %.1lf\n",strlen(ch)*8,sum,(double)strlen(ch)*8/sum);
    }
    return 0;
}