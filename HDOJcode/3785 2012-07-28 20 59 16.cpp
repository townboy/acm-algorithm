******************************
    Author : townboy
    Submit time : 2012-07-28 20:59:16
    Judge Status : Accepted
    HDOJ Runid : 6365510
    Problem id : 3785
    Exe.time : 156MS
    Exe.memory : 272K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<queue>

using namespace std; 

int m,size,n; 
priority_queue<int,vector<int>,greater<int> >q; 
 
void fun(int x)
{
    if(size < m)
    {
        size++; 
        q.push(x); 
        return ; 
    }
    if(x > q.top())
    {
        q.pop();
        q.push(x); 
    } 
} 

int minn(int a,int b)
{
    return a<b?a:b;
} 

int main()
{
    int x,flag,pr[20],i;
    while(scanf("%d%d",&n,&m),n+m) 
    {
        size=0; 
        m=minn(n,m); 
        for(i=0;i<n;i++)
        {
            scanf("%d",&x);
            fun(x);
        }
        flag=0;
        while(!q.empty())
        {
            pr[flag]=q.top();
            flag++;
            q.pop();             
        }
        for(i=m-1;i>=0;i--)
        {
            if(m-1 != i)
            {
                printf(" "); 
            }
            printf("%d",pr[i]); 
        } 
        printf("\n"); 
     } 
    return 0; 
} 