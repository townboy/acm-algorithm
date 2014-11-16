******************************
    Author : townboy
    Submit time : 2012-09-10 01:42:55
    Judge Status : Accepted
    HDOJ Runid : 6731546
    Problem id : 1914
    Exe.time : 0MS
    Exe.memory : 264K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>
#define maxn 35

int xlike[maxn][maxn],ylike[maxn][maxn];
int xrank[maxn][maxn],yrank[maxn][maxn];
int xmat[maxn],ymat[maxn],n;

char female[maxn];
int nan[30],nv[30];

void find(int x,int y)
{
    int tx;
    if(-1 == ymat[y])
    {
        xmat[x]=y;
        ymat[y]=x;
        return ;
    }
    tx=ymat[y];
    if(yrank[y][x] < yrank[y][tx])
    {
        xmat[x]=y;
        ymat[y]=x;
        find(tx,xlike[tx][xrank[tx][y]+1]);
    }
    else
    {
        find(x,xlike[x][xrank[x][y]+1]);
    }
}

void stable_match()
{
    int i;
    memset(xmat,-1,sizeof(xmat));
    memset(ymat,-1,sizeof(ymat));
    for(i=1;i<=n;i++)
    {
        find(i,xlike[i][1]);
    }
}

void chu()
{
    memset(nan,-1,sizeof(nan));
}

void debug()
{
    int i,f;
    for(i=1;i<=n;i++)
    {
        for(f=1;f<=n;f++)
        {
            printf("%d ",xlike[i][f]);
        }
        printf("\n");
    }
    printf("\n");
    for(i=1;i<=n;i++)
    {
        for(f=1;f<=n;f++)
        {
            printf("%d ",xrank[i][f]);
        }
        printf("\n");
    }
}    

int main()
{
    char x[10],ch[100],id;
    int i,f,num,g;
    
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        chu();
        scanf("%d",&n);
        for(f=1;f<=n;f++)
        {
            scanf("%s",x);
            nan[x[0]-'a']=f;
        }
        for(f=1;f<=n;f++)
        {
            scanf("%s",x);
            nv[x[0]-'A']=f;            
            female[f]=x[0];
        }
        
        for(f=1;f<=n;f++)
        {
            getchar();
            scanf("%c:",&id);
            scanf("%s",ch);
            for(g=1;g<=n;g++)
            {
                xlike[nan[id-'a']][g]=nv[ch[g-1]-'A'];
                xrank[nan[id-'a']][nv[ch[g-1]-'A']]=g;
            }
        }
        for(f=1;f<=n;f++)
        {
            getchar();
            scanf("%c:",&id);
            scanf("%s",ch);
            for(g=1;g<=n;g++)
            {
                ylike[nv[id-'A']][g]=nan[ch[g-1]-'a'];
                yrank[nv[id-'A']][nan[ch[g-1]-'a']]=g;
            }
        }

        stable_match();
        
        if(0 != i)
        {
            printf("\n");
        }
        for(f=0;f<26;f++)
        {
            if(-1 == nan[f])
            {
                continue;
            }
            printf("%c %c\n",f+'a',female[xmat[nan[f]]]);        
        }
    }
    return 0;
}