******************************
    Author : townboy
    Submit time : 2013-01-22 20:58:41
    Judge Status : Accepted
    HDOJ Runid : 7532206
    Problem id : 4139
    Exe.time : 984MS
    Exe.memory : 8896K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>

int n,m,x,s,other;
int hash[1100000],num[1100000];

void pre()
{
    int i,f;
    memset(hash,0,sizeof(hash));
    for(i=2;i<2000;i++)
    {
        if(0 == hash[i])
        {
            for(f=i*i;f<=1000000;f+=i)
            {
                hash[f]=1;
            }
        }
    }
}

void chu()
{
    memset(num,0,sizeof(num));
    s=1;
    x=1;
}

int cal(int tem,int yin)
{
    int ji=0;
    while(0 == tem%yin)
    {
        ji++;
        tem/=yin;
    }
    other=tem;
    return ji;
}

void fun()
{
    int mul_tem,tem,i,f;
    for(i=2;i<=1000;i++)
    {
        if(1 == hash[i])
            continue;
        
        for(f=i*i;f<=1000000;f+=i)
        {
            if(num[f] > 0)
            {
                tem=num[f];
                mul_tem=tem*cal(f,i);        
                num[f]=0;
                num[i]+=mul_tem;
                num[other]+=tem;
            }
            if(num[f] < 0)
            {
                tem=-num[f];
                mul_tem=tem*cal(f,i);        
                num[f]=0;
                num[i]-=mul_tem;
                num[other]-=tem;
            }            
        }
    }
}

int main()
{
    int f,i,cas,tem,g;
    
    pre();
    scanf("%d",&cas);
    for(i=0;i<cas;i++)
    {
        scanf("%d%d",&n,&m);
        chu();
        for(f=0;f<n;f++)
        {
            scanf("%d",&tem);
            num[tem]++;                
        }
        for(f=0;f<m;f++)
        {
            scanf("%d",&tem);
            num[tem]--;
        }

        fun();
        for(f=1;f<=1000000;f++)
        {
            if(num[f] > 0)
            {
                for(g=0;g<num[f];g++)
                {
                    s*=f;
                }
            }
            if(num[f] < 0)
            {
                for(g=0;g<(-num[f]);g++)
                {
                    x*=f;    
                }
            }
        }    
        printf("Case #%d: %d / %d\n",i+1,s,x);    
    }
    return 0;
}