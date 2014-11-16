******************************
    Author : townboy
    Submit time : 2012-07-13 19:50:43
    Judge Status : Accepted
    HDOJ Runid : 6203873
    Problem id : 2492
    Exe.time : 156MS
    Exe.memory : 1040K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>

int que[21000]; 
int in[110000],leftbig[21000],leftsma[21000],ribig[21000],risma[21000];

int lowbit(int t)
{
    return t&(-t); 
} 

int plus(int pos,int v)
{
    while(pos <= 100000)
    {
        in[pos]+=v;
        pos+=lowbit(pos);
    }     
} 

void chu()
{
    memset(in,0,sizeof(in));
}

int sum(int end)
{
    int sum=0;
    while(end > 0)
    {
        sum+=in[end];
        end-=lowbit(end); 
    } 
    return sum; 
} 

int main()
{
    __int64 summ; 
    int i,f,k,num;
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        scanf("%d",&k);
        for(f=0;f<k;f++)
        {
            scanf("%d",&que[f]);
        }
        chu();    
        for(f=0;f<k;f++)
        {
            leftsma[f]=sum(que[f]-1); 
            leftbig[f]=sum(100000)-sum(que[f]); 
            plus(que[f],1); 
        }        

        chu();    
        for(f=k-1;f>-1;f--)
        {
            risma[f]=sum(que[f]-1); 
            ribig[f]=sum(100000)-sum(que[f]); 
            plus(que[f],1); 
        }        
        summ=0;
        for(f=0;f<k;f++)
        {
            summ+=leftsma[f]*ribig[f]+leftbig[f]*risma[f];        
        }
        printf("%I64d\n",summ); 
    }
    return 0;
}