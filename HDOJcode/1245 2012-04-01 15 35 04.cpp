******************************
    Author : townboy
    Submit time : 2012-04-01 15:35:04
    Judge Status : Accepted
    HDOJ Runid : 5684369
    Problem id : 1245
    Exe.time : 125MS
    Exe.memory : 336K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<math.h>
#include<queue>
using namespace std;

int hash[120],n;
double map[110][110],val[120];

void chu()
{
    int i,f;
    for(i=0;i<=105;i++)
    {
        hash[i]=0;
        val[i]=10000000;
        for(f=0;f<=105;f++)
        {
            map[i][f]=-1;
        }
    }
}

struct yu
{
    int x;
    int y;
};
yu eyu[120]; 

struct node 
{
    int step;
    int num;
    double d;
    friend bool operator < (node a,node b)
    {
        if(a.d>b.d)
        {
            return true ;
        }
        if(a.d<b.d)
        {
            return false ;
        }
        if(a.step>b.step)
        {
            return true ;
        }
        else
        {
            return false ;
        }
    }
};
node ru,tem,fan;

int minn(int a,int b,int c,int d)
{
    int min=100;
    if(a<min)
    {
        min=a;
    }
    if(b<min)
    {
        min=b;
    }
    if(c<min)
    {
        min=c;
    }
    if(d<min)
    {
        min=d;
    }
    return min;
}

node bfs()
{
    int i;
    priority_queue<node> q;
    ru.num=0;
    ru.d=0;
    ru.step=0;
    val[0]=0;
    q.push(ru);
    while(!q.empty())
    {
        tem=q.top();
        q.pop();
        if(1==hash[tem.num])
        {
            continue;
        }
        if(n+1==tem.num)
        {
            return tem;
        }
        hash[tem.num]=1;
        for(i=1;i<=n+1;i++)
        {
            if(-1==map[tem.num][i])
            {
                continue;
            }
            if(1==hash[i])
            {
                continue;
            } 
            if(tem.d+map[tem.num][i]<=val[i])
            {
                val[i]=tem.d+map[tem.num][i];
                ru.num=i;
                ru.step=tem.step+1;
                ru.d=val[i];
                q.push(ru);
            }
        }
    }
    fan.d=-1;
    fan.step=0;
    return fan;
}

int main()
{
    int i,f,d;
    double dis;
    node res;
//    freopen("D:\\in.txt","r",stdin);
    while(scanf("%d%d",&n,&d)!=EOF)
    {
        chu();

        for(i=1;i<=n;i++)
        {
            scanf("%d%d",&eyu[i].x,&eyu[i].y);
        }
        
        for(i=1;i<=n;i++)
        {
            if((eyu[i].x*eyu[i].x+eyu[i].y*eyu[i].y)<=7.5*7.5)
            {
                continue;  
            }
            if(sqrt((eyu[i].x*eyu[i].x+eyu[i].y*eyu[i].y))-7.5<=d)
            {
                map[i][0]=map[0][i]=sqrt((eyu[i].x*eyu[i].x+eyu[i].y*eyu[i].y))-7.5;
            }
            if(minn(50-eyu[i].x,eyu[i].x+50,50-eyu[i].y,eyu[i].y+50)<=d)
            {
                map[i][n+1]=map[n+1][i]=minn(50-eyu[i].x,eyu[i].x+50,50-eyu[i].y,eyu[i].y+50);
            }
            for(f=1;f<=n;f++)
            {
                if(i==f)
                {
                    continue;
                }
                dis=sqrt((eyu[i].x-eyu[f].x)*(eyu[i].x-eyu[f].x)+(eyu[i].y-eyu[f].y)*(eyu[i].y-eyu[f].y));
                if(dis>d)
                {
                    continue;
                }
                map[i][f]=dis;
            }
        }
         res=bfs();
        if(-1==res.d)
        {
            printf("can't be saved\n");
        }
        else
        {
            printf("%.2lf %d\n",res.d,res.step);
        }
    }
    return 0;
}