******************************
    Author : townboy
    Submit time : 2012-11-24 22:10:14
    Judge Status : Accepted
    HDOJ Runid : 7246691
    Problem id : 1506
    Exe.time : 46MS
    Exe.memory : 1780K
    https://github.com/townboy
******************************


#include<stdio.h>

int leftque[110000],rightque[110000]; 
int hei[110000],left[110000],right[110000];
int n,dis[110000];
int lefthead,lefttail,righthead,righttail;

__int64 max(__int64 a,__int64 b)
{
    return a>b?a:b; 
} 

void chu()
{
    lefthead=righthead=0;
    lefttail=righttail=-1;
}

void leftadd(int x)
{
    while(lefthead <= lefttail)
    {
        if(x <= leftque[lefttail])
        {
            lefttail--; 
        } 
        else
        {
            break; 
        } 
    }    
    lefttail++;
    leftque[lefttail]=x;    
}

void rightadd(int x)
{
    while(righthead <= righttail)
    {
        if(x <= rightque[righttail])
        {
            righttail--; 
        } 
        else
        {
            break; 
        } 
    }    
    righttail++;
    rightque[righttail]=x;        
}

void debug()
{
    int i;
    for(i=1;i<=n;i++)
    {
        printf("%d ",right[i]); 
    } 
    printf("\n");  
} 

int main()
{
    int i;
    __int64 ans; 
    while(scanf("%d",&n),n)
    {
        chu();
        for(i=1;i<=n;i++)
        {
            scanf("%d",&hei[i]);
        }
        for(i=1;i<=n;i++)
        {
            leftadd(hei[i]);    
            dis[lefttail]=i;
            if(lefthead == lefttail)
            {
                left[i]=1; 
            } 
            else
            {
                left[i]=dis[lefttail-1]+1;            
            } 
        }

        for(i=n;i>=1;i--)
        {
            rightadd(hei[i]);    
            dis[righttail]=i;
            if(righthead == righttail)
            {
                right[i]=n; 
            } 
            else
            {
                right[i]=dis[righttail-1]-1;            
            } 
        }
        ans=0;
        for(i=1;i<=n;i++)
        {
            ans=max(ans,((__int64)hei[i])*(right[i]-left[i]+1)); 
        } 
        printf("%I64d\n",ans); 
    }
    return 0;
}