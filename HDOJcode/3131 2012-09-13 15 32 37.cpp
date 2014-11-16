******************************
    Author : townboy
    Submit time : 2012-09-13 15:32:37
    Judge Status : Accepted
    HDOJ Runid : 6757293
    Problem id : 3131
    Exe.time : 4046MS
    Exe.memory : 696K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<string.h>
#include<map>
using namespace std;

__int64 ans;
int que[20],n;
char ch[200];
map<__int64,int>mp;

__int64 abss(__int64 x)
{
    return x<0?-x:x;
}

int check(int x)
{
    while(0 != x)
    {
        if(3 == x%10)
        {
            return 1;    
        }
        x/=10;
    }
    return 0;
}

void dfs(__int64 now,int wei)
{
    if(n+1 == wei)
    {
        if(1 == check(now))
        {
            mp[now]++;
            if(-1 ==  ans)
            {    
                ans=now;
            }
            else
            {
                if(mp[now] > mp[ans] || (mp[now] == mp[ans] && now > ans))
                {
                    ans=now;
                }
            }
        }    
        return ;
    }
    dfs(now+que[wei],wei+1);
    dfs(now*que[wei],wei+1);
    dfs(abss(now-que[wei]),wei+1);
    if(0 != que[wei])
    {
        dfs(now/que[wei],wei+1);
    }
}

void solve()
{
    dfs(que[1],2);
}

void chu()
{
    mp.clear();
    ans=-1;
    n=0;
}

int main()
{
    int len,sum;
    int i;

    while(gets(ch)!=NULL)
    {
        sum=0;
        chu();
        if('#' == ch[0])
        {
            break;
        }
        len=strlen(ch);
        for(i=0;i<len;i++)
        {
            if(' ' == ch[i])
            {
                n++;
                que[n]=sum;
                sum=0;
            }
            else
            {
                sum*=10;
                sum+=ch[i]-'0';        
            }
        }
        n++;
        que[n]=sum;
                
        solve();
        if(-1 == ans)
        {
            printf("No result\n");
        }
        else
        {
            printf("%I64d\n",ans);
        }
    }
    return 0;
}