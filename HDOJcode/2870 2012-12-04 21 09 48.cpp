******************************
    Author : townboy
    Submit time : 2012-12-04 21:09:48
    Judge Status : Accepted
    HDOJ Runid : 7330555
    Problem id : 2870
    Exe.time : 281MS
    Exe.memory : 5704K
    https://github.com/townboy
******************************


#include<stdio.h>

char map[1100][1100];
int n,m,fea[1100][1100];
int que[1100],head,tail,id[1100];
int left[1100],right[1100];

int max(int a,int b)
{
    return a>b?a:b;
}

void chu()
{
    int i,f;
    for(i=2;i<=n;i++)
        for(f=1;f<=m;f++)
            if(0 != fea[i][f])
                fea[i][f]+=fea[i-1][f];                
}

void add(int x)
{
    while(tail >= head)
    {
        if(x <= que[tail])
            tail--;
        else
            break;
    }
    tail++;
    que[tail]=x;
}

void que_chu()
{
    head=0;
    tail=-1;
}

int dp()
{
    int i,f,ans=0;
    for(i=1;i<=n;i++)
    {
        que_chu();
        for(f=1;f<=m;f++)
        {
            add(fea[i][f]);
            id[tail]=f;
            if(tail == head)
                left[f]=1;
            else
                left[f]=id[tail-1]+1;
        }
        
        que_chu();
        for(f=m;f>=1;f--)
        {
            add(fea[i][f]);
            id[tail]=f;
            if(tail == head)
                right[f]=m;
            else
                right[f]=id[tail-1]-1;
        }
        for(f=1;f<=m;f++)
        {
            ans=max(ans,fea[i][f]*(right[f]-left[f]+1));
        }
    }
    return ans;
}

int main()
{
    int i,f,ans;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        ans=0;
        getchar();
        for(i=1;i<=n;i++)
        {    
            gets(&map[i][1]);
        }
        
        for(i=1;i<=n;i++)
            for(f=1;f<=m;f++)
                if('a' == map[i][f] || 'w' == map[i][f] || 'y' == map[i][f] || 'z' == map[i][f])
                    fea[i][f]=1;
                else
                    fea[i][f]=0;        
        chu();
        ans=max(ans,dp());        

        for(i=1;i<=n;i++)
            for(f=1;f<=m;f++)
                if('b' == map[i][f] || 'w' == map[i][f] || 'x' == map[i][f] || 'z' == map[i][f])
                    fea[i][f]=1;
                else
                    fea[i][f]=0;        
        chu();
        ans=max(ans,dp());        

        for(i=1;i<=n;i++)
            for(f=1;f<=m;f++)
                if('c' == map[i][f] || 'x' == map[i][f] || 'y' == map[i][f] || 'z' == map[i][f])
                    fea[i][f]=1;
                else
                    fea[i][f]=0;
        chu();
        ans=max(ans,dp());        
        
        printf("%d\n",ans);
    }
    return 0;
}