******************************
    Author : townboy
    Submit time : 2012-07-11 20:15:21
    Judge Status : Accepted
    HDOJ Runid : 6184258
    Problem id : 1892
    Exe.time : 250MS
    Exe.memory : 9496K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>

int maxm=1050,maxn=1050;
int in[1100][1100],pos[1100][1100];

int lowbit(int t)
{
    return t&(-t);
}

int sum(int m,int n)
{
    int n0=n,sum=0;
    while(m > 0)
     {
         n=n0;
         while(n > 0)
         {
             sum+=in[m][n];
            n-=lowbit(n);
        }
        m-=lowbit(m);
     }
    return sum;     
}

void swap(int &big,int& sma)
{
    int tem;
    if(big < sma)
    {
        tem=big;
        big=sma;
        sma=tem;    
    }
}

int getsum(int x1,int y1,int x2,int y2)
{
    return sum(x1,y1)+sum(x2-1,y2-1)-sum(x1,y2-1)-sum(x2-1,y1);    
}

void plus(int m,int n,int v)
{
    int n0=n;
    while(m < maxm)
    {
        n=n0;
        while(n < maxn)
        {
            in[m][n]+=v;
            n+=lowbit(n);
        }
        m+=lowbit(m);
    }
}

void chu()
{
    int i,f;
    memset(in,0,sizeof(in));
    for(i=1;i<=1050;i++)
    {
        for(f=1;f<=1050;f++)
        {
            pos[i][f]=1;
            in[i][f]=(lowbit(i))*(lowbit(f));
        }
    }
}

int main()
{
    char ch[10];
    int x1,x2,y1,y2,v;
    int num,i,k,f,n,m;
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        chu();
        printf("Case %d:\n",i+1);
        scanf("%d",&k);
        for(f=0;f<k;f++)
        {
            scanf("%s",ch);
            if('A' == ch[0])
            {
                scanf("%d%d%d",&m,&n,&v);
                m++;
                n++;
                plus(m,n,v);    
                pos[m][n]+=v;
            }
            else if('S' == ch[0])
            {
                scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
                x1++;
                x2++;
                y1++;
                y2++;
                swap(x1,x2);
                swap(y1,y2);        
                printf("%d\n",getsum(x1,y1,x2,y2));
            }
            else if('D' == ch[0])
            {
                scanf("%d%d%d",&m,&n,&v);
                m++;
                n++;
                if(pos[m][n] <= v)
                {
                    plus(m,n,-pos[m][n]);
                    pos[m][n]=0;    
                }
                else
                {                    
                    plus(m,n,-v);
                    pos[m][n]-=v;    
                }
            }
            else
            {
                scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&v);
                x1++;
                x2++;
                y1++;
                y2++;
                if(pos[x1][y1] <= v)
                {
                    plus(x1,y1,-pos[x1][y1]);
                    plus(x2,y2,pos[x1][y1]);
                    pos[x2][y2]+=pos[x1][y1];    
                    pos[x1][y1]=0;    
                }
                else
                {                    
                    plus(x1,y1,-v);
                    plus(x2,y2,v);
                    pos[x1][y1]-=v;    
                    pos[x2][y2]+=v;    
                }
            }
        }
    }
    return 0;
}