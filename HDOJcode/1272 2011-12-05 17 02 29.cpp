******************************
    Author : townboy
    Submit time : 2011-12-05 17:02:29
    Judge Status : Accepted
    HDOJ Runid : 5115881
    Problem id : 1272
    Exe.time : 31MS
    Exe.memory : 968K
    https://github.com/townboy
******************************


#include<stdio.h>
int a[110000],b[110000];
void merge(int x,int y)
{
    a[x]=y;
}
int find(int x)
{
    while(a[x]!=x)
    {
        x=a[x];
    }
    return x;
}
int main(void)
{
    int c,d,i,flag,ji,last;
    while(scanf("%d%d",&c,&d),!((-1==c)&&(-1==d)))
    {
        for(i=1;i<=100000;i++)
        {
            a[i]=i;
            b[i]=0;
        }
        flag=1;
        merge(find(c),find(d));
        b[c]=1;
        b[d]=1;
        if((0==c)&&(0==d))
        {
            printf("Yes\n");
            continue;
        }
        while(scanf("%d%d",&c,&d),!((0==c)&&(0==d)))
        {
            b[c]=1;
            b[d]=1;
            if(find(c)!=find(d))
            {
                merge(find(c),find(d));
            }
            else
            {
                flag=0;
            }
        }
        if(0==flag)
        {
            printf("No\n");
        }
        else
        {
            ji=0;
            flag=1;
            for(i=1;i<=100000;i++)
            {
                if(1==b[i])
                {
                    if(0==ji)
                    {
                        last=find(i);
                    }
                    else
                    {
                        if(find(i)!=last)
                        {
                            flag=0;
                            break;
                        }
                    }
                    ji=1;
                }
            }
            if(1==flag)
            {
                printf("Yes\n");
            }
            else
            {
                printf("No\n");
            }
            
        }
    }


    return 0;
}