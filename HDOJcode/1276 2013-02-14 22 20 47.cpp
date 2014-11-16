******************************
    Author : townboy
    Submit time : 2013-02-14 22:20:47
    Judge Status : Accepted
    HDOJ Runid : 7615748
    Problem id : 1276
    Exe.time : 0MS
    Exe.memory : 248K
    https://github.com/townboy
******************************


#include<stdio.h>

int ci;
int n,que[5100];

void chu()
{
    int i;
    for(i=0;i<n;i++)
        que[i]=i+1;
    que[n]=-1;
    ci=0;
}    

int sum()
{
    int pos=0;
    while(-1 != que[pos])
    {
        pos++;        
    }
    return pos;
}

void fun()
{
    int ji=-1,i;
    if(0 == ci%2)
    {
        for(i=0;;i++)
        {
            if(-1 == que[i])
                break;
            if(0 == (i&1))
            {
                ji++;        
                que[ji]=que[i];
            }
        }    
        ji++;
        que[ji]=-1;
    }
    else
    {
        ji=-1;
        for(i=0;;i++)
        {
            if(-1 == que[i])
                break;
            if(0 != (i+1)%3)
            {
                ji++;        
                que[ji]=que[i];
            }
        }    
        ji++;
        que[ji]=-1;        
    }
    ci++;
}

int main()
{
    int f,i,cas;
    scanf("%d",&cas);
    for(i=0;i<cas;i++)
    {
        scanf("%d",&n);
        chu();
        while(sum() > 3)
        {
            fun();                    
        }
        for(f=0;;f++)
        {
            if(-1 == que[f])
                break;
            if(0 != f)
                printf(" ");
            printf("%d",que[f]);
        }
        printf("\n");
    }
    return 0;
}