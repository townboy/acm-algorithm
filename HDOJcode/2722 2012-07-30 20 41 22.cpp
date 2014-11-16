******************************
    Author : townboy
    Submit time : 2012-07-30 20:41:22
    Judge Status : Accepted
    HDOJ Runid : 6379964
    Problem id : 2722
    Exe.time : 15MS
    Exe.memory : 1892K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>
#include<queue>
#define INF 0x7fffffff
using namespace std;

int map[450][450],n,m,val[210000],hash[210000];

int turn(int x,int y)
{
    return (x-1)*m+y;
}

void chu()
{
    int i;
    memset(map,0,sizeof(map));
    for(i=1;i<=n*m;i++)
    {
        val[i]=INF;
    }
    memset(hash,0,sizeof(hash));
}

int spfa()
{
    int tem,i,xin;
    queue<int>q;
    q.push(1);
    val[1]=0;
    while(!q.empty())
    {
        tem=q.front();
        q.pop();
        hash[tem]=0;
        for(i=1;i<=n*m;i++)
        {
            if(0 == map[tem][i])
            {
                continue;
            }
            xin=val[tem]+2520/map[tem][i];
            if(val[i] > xin)
            {
                val[i]=xin;
                if(0 == hash[i])
                {
                    hash[i]=1;
                    q.push(i);
                }
            }
        }
    }
    return val[n*m];
}

void debug()
{
    int i,f;
    for(i=1;i<=n*m;i++)
    {
            printf("%d ",val[i]);
    }
    printf("\n");
}

int main()
{
    int i,f,len,ans;
    char dir[10];
    while(scanf("%d%d",&n,&m),n+m)
    {
        n++;
        m++;
        chu();
        for(i=1;i<=2*n-1;i++)
        {
            if(1 == i%2)
            {
                for(f=1;f<=m-1;f++)
                {
                    scanf("%d %s",&len,dir);
                    if('*' == dir[0])
                    {
                        map[turn((i+1)/2,f)][turn((i+1)/2,f+1)]=map[turn((i+1)/2,f+1)][turn((i+1)/2,f)]=len;
                    }
                    else if('<' == dir[0])
                    {
                        map[turn((i+1)/2,f+1)][turn((i+1)/2,f)]=len;                    
                    }
                    else
                     {
                         map[turn((i+1)/2,f)][turn((i+1)/2,f+1)]=len;
                     }
                }
            }
            else 
            {
                for(f=1;f<=m;f++)
                {
                    scanf("%d %s",&len,dir);
                    if('*' == dir[0])
                    {
                        map[turn((i+1)/2,f)][turn((i+1)/2+1,f)]=map[turn((i+1)/2+1,f)][turn((i+1)/2,f)]=len;
                    }
                    else if('^' == dir[0])
                    {
                        map[turn((i+1)/2+1,f)][turn((i+1)/2,f)]=len;                    
                    }
                    else
                     {
                         map[turn((i+1)/2,f)][turn((i+1)/2+1,f)]=len;
                     }            
                }
            }
        }        
        ans=spfa();
        if(INF == ans)
        {
            printf("Holiday\n");
        }
        else 
        {
            printf("%d blips\n",ans);
        }
    }
    return 0;
}