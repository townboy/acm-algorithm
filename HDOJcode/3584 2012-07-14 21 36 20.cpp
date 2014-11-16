******************************
    Author : townboy
    Submit time : 2012-07-14 21:36:20
    Judge Status : Accepted
    HDOJ Runid : 6214858
    Problem id : 3584
    Exe.time : 125MS
    Exe.memory : 5412K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>

int in[110][110][110],n; 

int minn(int a,int b)
{
    return a<b?a:b; 
} 

int lowbit(int t)
{
    return t&(-t); 
} 

void chu()
{
    memset(in,0,sizeof(in)); 
} 

int sum(int x,int y,int z)
{
    int i,f,g,sum=0; 
    for(i=x;i>0;i-=lowbit(i))
    {
        for(f=y;f>0;f-=lowbit(f))
        {
            for(g=z;g>0;g-=lowbit(g))
            {
                sum+=in[i][f][g]; 
            } 
        }    
    }    
    return sum; 
}

int getsum(int x1,int y1,int z1,int x2,int y2,int z2)
{
    return sum(x2,y2,z2)-sum(x1-1,y2,z2)-sum(x2,y1-1,z2)-sum(x2,y2,z1-1)+sum(x2,y1-1,z1-1)+sum(x2,y1-1,z1-1)+sum(x1-1,y2,z1-1)+sum(x1-1,y1-1,z1-1); 
} 

void plus(int x,int y,int z,int v)
{
    int i,f,g; 
    for(i=x;i<=100;i+=lowbit(i))
    {
        for(f=y;f<=100;f+=lowbit(f))
        {
            for(g=z;g<=100;g+=lowbit(g))
            {
                in[i][f][g]+=v; 
            } 
        }    
    }    
} 

int main()
{
    int m,i,sta,x2,y2,z2,x1,y1,z1,x,y,z;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        chu();
        for(i=0;i<m;i++)
        {
            scanf("%d",&sta);
            if(0 == sta)
            {
                scanf("%d%d%d",&x,&y,&z);
                printf("%d\n",sum(x,y,z)&1);
            }    
            else
            {
                scanf("%d%d%d",&x1,&y1,&z1);
                scanf("%d%d%d",&x2,&y2,&z2);
                plus(x1,y1,z1,1);

                plus(x2+1,y1,z1,-1);
                plus(x1,y2+1,z1,-1);
                plus(x1,y1,z2+1,-1);

                plus(x2+1,y2+1,z1,1);
                plus(x1,y2+1,z2+1,1);
                plus(x2+1,y1,z2+1,1);

                plus(x2+1,y2+1,z2+1,-1);
            }
        }
    }
    return 0;
}