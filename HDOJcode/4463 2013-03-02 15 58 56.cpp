******************************
    Author : townboy
    Submit time : 2013-03-02 15:58:56
    Judge Status : Accepted
    HDOJ Runid : 7676184
    Problem id : 4463
    Exe.time : 15MS
    Exe.memory : 284K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h> 
#include<math.h> 
#include<stdlib.h> 

int p,q; 
int n,pos[110][2],set[110]; 
double ans;

struct node 
{
    int x;
    int y;
    double len; 
}; 
struct node que[10000]; 

int cmp(const void *a,const void*b)
{
    if( (*(struct node *)a).len < (*(struct node *)b).len) 
        return -1;
    return 1;
} 

void chu()
{
    int i;
    for(i=1;i<=n;i++)
        set[i]=i; 
    ans=0; 
}

int find(int x)
{
    return x==set[x]?x:set[x]=find(set[x]); 
} 

void merge(int a,int b)
{
    set[a]=b; 
} 

int main()
{
    int x,y;
    double len; 
    int ji,i,f;
    while(scanf("%d",&n),n)
    {
        chu(); 
        scanf("%d%d",&p,&q); 
        for(i=1;i<=n;i++)
            scanf("%d%d",&pos[i][0],&pos[i][1]); 
    
        len=sqrt((double)(pos[p][0]-pos[q][0])*(pos[p][0]-pos[q][0])+(pos[p][1]-pos[q][1])*(pos[p][1]-pos[q][1]));    
        ji=0; 
        for(i=1;i<=n;i++)
            for(f=i+1;f<=n;f++)
            {
                que[ji].x=i;
                que[ji].y=f;
                que[ji].len=sqrt((double)(pos[i][0]-pos[f][0])*(pos[i][0]-pos[f][0])+(pos[i][1]-pos[f][1])*(pos[i][1]-pos[f][1])); 
                ji++;
            }
        
        qsort(que,n*(n-1)/2,sizeof(que[0]),cmp);
        ans=len;
        merge(p,q);
        ji=0; 
        for(i=0;i<n*(n-1)/2;i++)
        {
            x=que[i].x;
            y=que[i].y;
            len=que[i].len;
            if(find(x) != find(y))
            {
                merge(find(x),find(y));
                ans+=len;
                ji++;
                if(n-2 == ji)
                    break;
            }
        } 
        printf("%.2lf\n",ans); 
    } 
    return 0; 
} 