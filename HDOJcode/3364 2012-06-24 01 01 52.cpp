******************************
    Author : townboy
    Submit time : 2012-06-24 01:01:52
    Judge Status : Accepted
    HDOJ Runid : 6094965
    Problem id : 3364
    Exe.time : 93MS
    Exe.memory : 276K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>
#include<iostream>
using namespace std;

int n,m,save[55][55];
int map[55][55];

void swap(int &a,int &b)
{
    int tem=a;
    a=b;
    b=tem;
}

void debug()
{
    int i,f;
    for(i=0;i<n;i++)
    {
        for(f=0;f<=m;f++)
        {
            printf("%d ",save[i][f]);
        }
        printf("\n");
    }
    printf("\n");
}

__int64 gauss()
{
    int row,col,i,f;
    for(row=col=0;row<n&&col<m;col++,row++)
    {
        for(i=row;i<n;i++)
        {
            if(0 != save[i][col])
            {
                break;
            }
        }
        if(n == i)
        {    
            row--;
            continue;
        }
        if(row != i)
        {
            for(f=col;f<=m;f++)
            {
                swap(save[i][f],save[row][f]);    
            }
        }
        for(i=row+1;i<n;i++)
        {
            if(0 != save[i][col])
            {
                for(f=col;f<=m;f++)
                {
                    save[i][f]=save[i][f]^save[row][f];
                }
            }
        }
    }
    for(i=row;i<n;i++)
    {
        if(0 != save[i][m])
        {
            return 0;
        }
    }
    return (__int64)1<<(m-row); 
}

void chu()
{
    memset(map,0,sizeof(map));
}

int main()
{
    int num,i,f,g,h,Q,k,j;
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        chu();
        scanf("%d%d",&n,&m);
        for(f=0;f<m;f++)
        {
            scanf("%d",&k);
            for(g=0;g<k;g++)
            {
                scanf("%d",&j);
                map[j-1][f]=1;
            }
        }
        printf("Case %d:\n",i+1);
        scanf("%d",&Q);
        for(f=0;f<Q;f++)
        {
            for(g=0;g<n;g++)
            {
                for(h=0;h<m;h++)
                {
                    save[g][h]=map[g][h];
                }
            }
            for(g=0;g<n;g++)
            {
                scanf("%d",&save[g][m]);
            }
            printf("%I64d\n",gauss());
        }
    }
    return 0;
}