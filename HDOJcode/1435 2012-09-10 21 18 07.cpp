******************************
    Author : townboy
    Submit time : 2012-09-10 21:18:07
    Judge Status : Accepted
    HDOJ Runid : 6738708
    Problem id : 1435
    Exe.time : 156MS
    Exe.memory : 980K
    https://github.com/townboy
******************************


#include<map>
#include<stdio.h>
#include<memory.h> 
#define maxn 210 
#define INF 100000000 
using namespace std;

map<int,int>mapos,fepos;

int maid[maxn],feid[maxn]; 
int xlike[maxn][maxn],ylike[maxn][maxn];
int xrank[maxn][maxn],yrank[maxn][maxn];
int xmat[maxn],ymat[maxn],n;
int macap[maxn],fecap[maxn]; 
double maxx[maxn],may[maxn],maz[maxn],fex[maxn],fey[maxn],fez[maxn]; 

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
    mapos.clear();
    fepos.clear();
} 

struct node 
{
    double val;
    int id;    
};
struct node que[maxn]; 

int cmp(const void *a,const void *b)
{
    double aa=(*(struct node*)a).val; 
    double bb=(*(struct node*)b).val;
    if(aa > bb)
    {
        return 1; 
    } 
    return -1; 
} 

void build()
{
    int i,f;
    for(i=1;i<=n;i++)
    {
        for(f=1;f<=n;f++)
        {
            que[f-1].id=f;
            que[f-1].val=((maxx[i]-fex[f])*(maxx[i]-fex[f])+(may[i]-fey[f])*(may[i]-fey[f])+(maz[i]-fez[f])*(maz[i]-fez[f]))*INF+fecap[f]; 
        }        
        qsort(que,n,sizeof(que[0]),cmp);
        for(f=1;f<=n;f++)
        {
            xlike[i][f]=que[f-1].id;
            xrank[i][que[f-1].id]=f;        
        } 
    } 
    for(i=1;i<=n;i++)
    {
        for(f=1;f<=n;f++)
        {
            que[f-1].id=f;
            que[f-1].val=((fex[i]-maxx[f])*(fex[i]-maxx[f])+(fey[i]-may[f])*(fey[i]-may[f])+(fez[i]-maz[f])*(fez[i]-maz[f]))*INF+macap[f]; 
        }        
        qsort(que,n,sizeof(que[0]),cmp);
        for(f=1;f<=n;f++)
        {
            ylike[i][f]=que[f-1].id;
            yrank[i][que[f-1].id]=f;        
        }
    } 
} 

int main()
{
    int id,i,f,num; 
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        chu(); 
        scanf("%d",&n);
        for(f=1;f<=n;f++)
        {
            scanf("%d",&id);
            mapos[id]=f;
            maid[f]=id;
            scanf("%d%lf%lf%lf",&macap[f],&maxx[f],&may[f],&maz[f]); 
        }
        for(f=1;f<=n;f++)
        {
            scanf("%d",&id);
            fepos[id]=f;
            feid[f]=id;
            scanf("%d%lf%lf%lf",&fecap[f],&fex[f],&fey[f],&fez[f]); 
        }        
        build(); 
        stable_match();
        for(f=1;f<=n;f++)
        {
            printf("%d %d\n",maid[f],feid[xmat[f]]); 
        }        
    }
    return 0;
}