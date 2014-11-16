******************************
    Author : townboy
    Submit time : 2012-04-27 22:40:52
    Judge Status : Accepted
    HDOJ Runid : 5860610
    Problem id : 4235
    Exe.time : 640MS
    Exe.memory : 4164K
    https://github.com/townboy
******************************


#include<stdio.h>

int res[1100000],ha[15],hb[15],hc[15],ja,jb,jc;

int digita(int x)
{
    ja=0;
    while(0 != x)
    {
        ha[ja++]=x%10;
        x=x/10;
    }
    return ja;
}

int digitb(int x)
{
    jb=0;
    while(0 != x)
    {
        hb[jb++]=x%10;
        x=x/10;
    }
    return jb;
}


int digitc(int x)
{
    jc=0;
    while(0 != x)
    {
        hc[jc++]=x%10;
        x=x/10;
    }
    return jc;
}

int san(int x)
{
    int i;
    for(i=0;i<jc;i++)
    {
        if(x == hc[i])
        {
            hc[i]=-1;
            return 1;
        }
    }
    return 0;
}

int check(int a,int b)
{
    int i;
    if(digita(a) +digitb(b) != digitc(a*b))
    {
        return 0;
    }
    
    for(i=0;i<ja;i++)
    {
        if(0 == san(ha[i]))
        {
            return 0;
        }
    }
    
    for(i=0;i<jb;i++)
    {
        if(0 == san(hb[i]))
        {
            return 0;
        }
    }
    return 1;
}

void dabiao()
{
    int i,f;
    for(i=1;i<1010000;i++)
    {
        for(f=1;f<=i;f++)
        {
            if(i*f>1005000)
            {
                break;
            }
            if(1 == res[i*f])
            {
                continue;
            }
            res[i*f]=check(i,f);
        }
    }
}

int main()
{
    int x,i;
    dabiao();
//    printf("daole\n");
    while(scanf("%d",&x),0!=x)
    {
        for(i=x;;i++)
        {
            if(res[i]==1)
            {
                printf("%d\n",i);
                break;
            }
        }
    }
    return 0;
}