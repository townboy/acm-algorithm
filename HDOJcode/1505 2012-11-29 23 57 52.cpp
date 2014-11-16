******************************
    Author : townboy
    Submit time : 2012-11-29 23:57:52
    Judge Status : Accepted
    HDOJ Runid : 7291426
    Problem id : 1505
    Exe.time : 109MS
    Exe.memory : 8224K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>
#include<memory.h>

int n,m,map[1010][1010];
int hei[1010][1010],dis[1010];
int que[1010],head,tail,left[1010],right[1010];

int max(int a,int b)
{
    return a>b?a:b;
}

void yu()
{
    int i,f;
    for(i=1;i<=n;i++)
    {
        for(f=1;f<=m;f++)
        {
            if(0 == map[i][f])
                hei[i][f]=-1;
            else if(-1 == hei[i-1][f])
                hei[i][f]=1;
            else
                hei[i][f]=hei[i-1][f]+1;    
        }
    }
}

void chu()
{
    head=0;
    tail=-1;
}

void add(int x,int src)
{
    while(tail >= head)
    {
        if(x <= que[tail])
            tail--;
        else
            break;
    }
    tail++;
    dis[tail]=src;
    que[tail]=x;
}

int dp()
{
    int i,f,start,ans=0;
    for(i=1;i<=n;i++)
    {
        chu();
        start=1;        
        for(f=1;f<=m;f++)
        {
            if(-1 == hei[i][f])
            {    
                chu();
                start=f+1;        
                continue;
            }    
            add(hei[i][f],f);
            if(head == tail)
                left[f]=start;
            else
                left[f]=dis[tail-1]+1;
        }
        
        chu();
        start=m;
        for(f=m;f>=1;f--)
        {
            if(-1 == hei[i][f])
            {
                chu();
                start=f-1;
                continue;
            }
            add(hei[i][f],f);
            if(head == tail)
                right[f]=start;
            else
                right[f]=dis[tail-1]-1;
        }
        for(f=1;f<=m;f++)
        {
            if(-1 == hei[i][f])
            {
                continue;
            }
            ans=max(ans,hei[i][f]*(right[f]-left[f]+1));
        }
    }
    return ans;
}

int main()
{
    char ch[10];
    int i,cas,f,g;
    scanf("%d",&cas);
    for(i=0;i<cas;i++)
    {
        scanf("%d%d",&n,&m);

        for(f=1;f<=n;f++)
        {
            for(g=1;g<=m;g++)
            {
                scanf("%s",ch);
                map[f][g]= 'R' == ch[0]?0:1;
            }
        }
        yu();        
        printf("%d\n",3*dp());
    }
    return 0;
}