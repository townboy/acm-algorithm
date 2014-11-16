******************************
    Author : townboy
    Submit time : 2012-07-17 13:19:32
    Judge Status : Accepted
    HDOJ Runid : 6238911
    Problem id : 1104
    Exe.time : 62MS
    Exe.memory : 4672K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<string>
#include<queue>
#include<iostream>

using namespace std;

int n,m,k,aim,yu;
int hash[1100000];

int moo(int a,int b)
{
    if(a >= 0)
    {
        return a%b;
    }
    while(a < 0)
    {
        a+=b;        
    }
    return a;
}

struct node 
{
    int x;
    string path;
    int t;
};
struct node tem,ru;

void bfs()
{
    queue<node>q;
    ru.path.clear();
    ru.t=0;
    ru.x=moo(n,yu);
    q.push(ru);
    while(!q.empty())
    {
        tem=q.front();
        q.pop();
        if(moo(tem.x,k) == aim)
        {
            printf("%d\n",tem.t);
            cout<<tem.path<<endl;
            return ;
        }    
        if(1 == hash[tem.x])
        {
            continue;        
        }
        hash[tem.x]=1;
        ru=tem;
        ru.x=moo(ru.x+m,yu);
        ru.path+='+';
        ru.t++;
        q.push(ru);
    
        ru=tem;
        ru.x=moo(ru.x-m,yu);
        ru.path+='-';
        ru.t++;
        q.push(ru);
            
        ru=tem;
        ru.x=moo(ru.x*m,yu);
        ru.path+='*';
        ru.t++;
        q.push(ru);

        ru=tem;
        ru.x=moo(moo(ru.x,m),yu);
        ru.path+='%';
        ru.t++;
        q.push(ru);
    }
    printf("0\n");
    return ;
}

void chu()
{
    memset(hash,0,sizeof(hash));
}

int gcd(int da,int xiao)
{
    int tem;
    if(xiao > da)
    {
        tem=xiao;
        xiao=da;
        da=tem;    
    }    
    while(0 != xiao)
    {
        tem=da%xiao;
        da=xiao;
        xiao=tem;    
    }
    return da;
}

int main()
{
    while(scanf("%d%d%d",&n,&k,&m),!(0 == n&&0 == m&&0 == k))
    {
        chu();
        yu=k*m/gcd(k,m);
        aim=moo(n+1,k);
        bfs();
    }
    return 0;
}