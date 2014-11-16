******************************
    Author : townboy
    Submit time : 2012-07-24 16:28:54
    Judge Status : Accepted
    HDOJ Runid : 6315443
    Problem id : 3450
    Exe.time : 296MS
    Exe.memory : 1824K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>
#include<map>
#define INF 0x7fffffff
using namespace std;

int id[110000],in[110000],ji,que[110000];
map<int,int>mp;

int lowbit(int t)
{
    return t&(-t);
}

int sum(int end)
{
    int sum=0;
    while(end > 0)
    {
        sum+=in[end];
        sum%=9901;
        end-=lowbit(end);
    }
    return sum;
}

void add(int pos,int v)
{
    while(pos <= ji+1)
    {
        in[pos]+=v;
        in[pos]%=9901;
        pos+=lowbit(pos);
    }
}

int ups(int x)
{
    int l=1,r=ji+1,mid;
    while(l != r-1)
    {
        mid=(l+r)>>1;
        if(id[mid]<=x)
        {
            l=mid;
        }
        else 
        {
            r=mid;    
        }
    }
    return l;
}

int ds(int x)
{
    int l=0,r=ji,mid;
    while(l != r-1)
    {
        mid=(l+r)>>1;
        if(id[mid]>=x)
        {
            r=mid;
        }
        else 
        {
            l=mid;    
        }
    }
    return l;
}

void chu()
{
    memset(in,0,sizeof(in));
    mp.clear();        
}

int main()
{
    int i,d,n,ans,up,down,zen;
    map<int,int>::iterator it;
    while(scanf("%d%d",&n,&d)!=EOF)
    {
        chu();
        ans=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&que[i]);
            mp[que[i]]=1;
        }
        ji=0;    
        for(it=mp.begin();it!=mp.end();it++)
        {
            ji++;
            id[ji]=it->first;
        }    
        id[ji+1]=INF;
        id[0]=-INF;
        for(i=0;i<n;i++)
        {
            up=ups(que[i]+d);
            down=ds(que[i]-d);
            zen=sum(up)-sum(down);
            zen%=9901;
            ans+=zen;
            ans%=9901;
            add(ups(que[i]),zen+1);
        }
        printf("%d\n",(ans+9901)%9901);
    }
    return 0;
}