******************************
    Author : townboy
    Submit time : 2012-08-02 19:18:33
    Judge Status : Accepted
    HDOJ Runid : 6415549
    Problem id : 4339
    Exe.time : 1187MS
    Exe.memory : 6504K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<string.h>
#include<memory.h>

int in[1100000],aim;
char a[1100000],b[1100000];

int lowbit(int t)
{
    return t&(-t);
}

int find_kth(int k)
{
    int sum=0,pos=0,i;
    for(i=20;i>=0;i--)
    {
        pos+=(1<<i);
        if(pos > aim || sum+in[pos]>=k)
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

void plus(int pos,int num)
{
    while(pos<=aim)
    {
        in[pos]+=num;
        pos+=lowbit(pos);
    }
}

void chu()
{
    memset(in,0,sizeof(in));
}

int minn(int a,int b)
{
    return a<b?a:b;
}

int main()
{
    char ch;
    int flag;
    int now,la,lena,lenb,num,f,q,i,u,v,s;
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        getchar();
        gets(a);
        gets(b);
        chu();
        lena=strlen(a);
        lenb=strlen(b);
        
        aim=minn(lena,lenb);
        for(f=0;f<aim;f++)
        {
            if(a[f] != b[f])
            {
                plus(f+1,1);
            }
        }
        
        printf("Case %d:\n",i+1);
        
        scanf("%d",&q);
        for(f=0;f<q;f++)
        {
            scanf("%d",&flag);
            if(1 == flag)
            {
                scanf("%d%d %c",&u,&v,&ch);
                if(v+1 > aim)
                {
                    continue;
                }
                if(1 == u)
                {
                    now=(ch == b[v]);
                    la=(a[v] == b[v]);
                    a[v]=ch;    
                    if(la == now)
                    {
                        continue;
                    }
                    plus(v+1,la-now);
                }
                else
                {
                    now=(ch == a[v]);
                    la=(a[v] == b[v]);
                    b[v]=ch;         
                     if(la == now)
                     {
                        continue; 
                     }
                    plus(v+1,la-now);                
                }
            }
            else
            {
                scanf("%d",&s);
                s++;
                printf("%d\n",find_kth(sum(s-1)+1)-s);    
            }
        }
    }
    return 0;
}