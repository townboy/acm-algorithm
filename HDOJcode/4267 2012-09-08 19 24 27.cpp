******************************
    Author : townboy
    Submit time : 2012-09-08 19:24:27
    Judge Status : Accepted
    HDOJ Runid : 6722175
    Problem id : 4267
    Exe.time : 312MS
    Exe.memory : 29212K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>

int old[51000],tree[12][12][51000];

int lowbit(int t)
{
    return t&(-t);
}

int sum(int end,int in[51000])
{
    int sum=0;
    while(end > 0)
    {
        sum+=in[end];
        end-=lowbit(end);
    }
    return sum;
}

void plus(int pos,int num,int in[51000])
{
    while(pos<=50050)
    {
        in[pos]+=num;
        pos+=lowbit(pos);
    }
}

void chu()
{
    memset(tree,0,sizeof(tree));
}

int query(int pos)
{
    int start,i,fan=0,yu;
    for(i=1;i<=10;i++)
    {
        start=pos/i+1;
        yu=pos%i; 
        fan+=sum(start,tree[i][yu]);
    } 
    return fan+old[pos]; 
}

int main()
{
    int a,b,k,c,q,i,flag;
    int start,len,yu,n;
    
    
    while(scanf("%d",&n)!=EOF)
    {
        chu();
        for(i=1;i<=n;i++)
        {
            scanf("%d",&old[i]);
        }
        scanf("%d",&q);
        for(i=0;i<q;i++)
        {
            scanf("%d",&flag);
            if(1 == flag)
            {
                scanf("%d%d%d%d",&a,&b,&k,&c);            
                len=(b-a)/k+1;
                yu=a%k;        
                start=a/k+1; 
                plus(start,c,tree[k][yu]);              
                plus(start+len,-c,tree[k][yu]); 
            }
            else
            {    
                scanf("%d",&a);
                printf("%d\n",query(a));
            }
        }        
    }
    return 0;
}