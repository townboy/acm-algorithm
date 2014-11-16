******************************
    Author : townboy
    Submit time : 2012-07-16 19:59:53
    Judge Status : Accepted
    HDOJ Runid : 6232255
    Problem id : 3648
    Exe.time : 1437MS
    Exe.memory : 6436K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>
#define lowbit(t) (t&(-t))

int MAX,n,r;
int in[1100000],old[510][510],neww[510][510],k;

void plus(int pos,int v)
{
    while(pos <= MAX)
    {
        in[pos]+=v;
        pos+=lowbit(pos);
    }    
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
/*
int find_kth(int k)
{
    k=(2*r+1)*(2*r+1)/2+1;
    int left=0,right=MAX,mid;
    while(left != right-1)
    {
        mid=(left+right)>>1;
        if(sum(mid) < k)
        {
            left=mid;
        }
        else
        {
            right=mid;
        }
    }
    return right;
}
*/

int find_kth(int k)
{
    int sum=0,pos=0,i;
    for(i=20;i>=0;i--)
    {
        pos+=(1<<i);
        if(pos > MAX || sum+in[pos]>=k)
        {
            pos-=(1<<i);
        }
        else
        {
            sum+=in[pos];
        }
    }
    return pos+1;
}

void up(int ax,int ay)
{
    int p,i,f;
    for(f=ay-r;f<=ay+r;f++)
    {
        plus(old[ax-r-1][f],-1);
        plus(old[ax+r][f],1);
    }    
    p=find_kth(k);
    neww[ax][ay]=p;
}

void left(int ax,int ay)
{
    int p,i,f;
    for(i=ax-r;i<=ax+r;i++)
    {
        plus(old[i][ay-r-1],-1);    
        plus(old[i][ay+r],1);    
    }
    p=find_kth(k);
    neww[ax][ay]=p;
}

void right(int ax,int ay)
{
    int p,i,f;
    for(i=ax-r;i<=ax+r;i++)
    {
        plus(old[i][ay+r+1],-1);    
        plus(old[i][ay-r],1);
    }
    p=find_kth(k);
    neww[ax][ay]=p;
}

void fun()
{
    int ax,ay;
    int i,f,p;
    for(i=1;i<=2*r+1;i++)
    {
        for(f=1;f<=2*r+1;f++)
        {
            plus(old[i][f],1);        
        }
    }
    p=find_kth(k);
    neww[r+1][r+1]=p;
    for(ax=r+1;ax<=n-r;ax++)
    {
        if(1 == 1&(ax-r))
        {
            for(ay=r+1;ay<=n-r;ay++)
            {
                if(ax==ay&&ax==r+1)
                {
                    continue;
                }
                if(ay == r+1)
                {
                    up(ax,ay);
                }
                else
                {
                    left(ax,ay);
                }            
            }
        }
        else
        {
            for(ay=n-r;ay>=r+1;ay--)
            {
                if(ay == n-r)
                {
                    up(ax,ay);    
                }
                else
                {
                    right(ax,ay);
                }        
            }
        }    
    }
}

void chu()
{    
    memset(in,0,sizeof(in));
}

inline void inn(int &num){
     char in=getchar();
     bool IsN=false;
     while(in!='-'&&(in<'0'||in>'9')){
           in=getchar();
     }
     if(in=='-'){ IsN=true;num=0; }
     else num=in-'0';
     in=getchar();
     while(in>='0'&&in<='9'){
           num*=10;num+=in-'0';
           in=getchar();
     }
     if(IsN) num=-num;
}

inline void out(int num){
      if(num<0){
            putchar('-');
            num=-num;
      }
      if(num==0){
            putchar('0');
            return;
      }
      char str[20];
      int bas=0;
      for(;num;num/=10) str[bas++]=num%10+'0';
      while(bas--) putchar(str[bas]);
}

int main()
{
    int i,f;
    while(scanf("%d%d",&n,&r),n+r)
    {
        chu();
        k=((2*r+1)*(2*r+1)+1)/2;
        MAX=-1;
        for(i=1;i<=n;i++)
        {
            for(f=1;f<=n;f++)
            {
                inn(old[i][f]);
                old[i][f]++;
                if(old[i][f]>MAX)
                {
                    MAX=old[i][f];
                }
            }
        }
        fun();
        for(i=r+1;i<=n-r;i++)
        {
            for(f=r+1;f<=n-r;f++)
            {
                 out(neww[i][f]-1);
                 printf(" ");
            }
            printf("\n");
        }            
    }
    return 0;
}