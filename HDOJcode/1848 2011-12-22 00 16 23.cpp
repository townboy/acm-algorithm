******************************
    Author : townboy
    Submit time : 2011-12-22 00:16:23
    Judge Status : Accepted
    HDOJ Runid : 5192751
    Problem id : 1848
    Exe.time : 125MS
    Exe.memory : 164K
    https://github.com/townboy
******************************


#include<stdio.h>
int main(void)
{
    int a[20],t[3],sg[3][1100],zan[30],j,f,h,i,g,flag,ans,ji;
    a[0]=1;
    a[1]=2;
    for(ji=2;;ji++)
    {
        a[ji]=a[ji-1]+a[ji-2];
        if(a[ji]>1000)
        {
            break;
        }
    }
    while(scanf("%d%d%d",&t[0],&t[1],&t[2]),!(0==t[0]&&0==t[1]&&0==t[2]))
    {
        for(h=0;h<3;h++)
        {
            sg[h][0]=0;
        }
        for(h=0;h<3;h++)
        {
            for(i=1;i<=t[h];i++)
            {
                j=0;
                for(f=0;f<=ji;f++)
                {
                    if(i-a[f]<0)
                    {
                        break;
                    }
                    else
                    {
                        zan[j]=sg[h][i-a[f]];
                        j++;
                    }            
                }
                for(f=0;;f++)
                {
                    flag=1;
                    for(g=0;g<j;g++)
                    {
                        if(zan[g]==f)
                        {
                            flag=0;
                            break;
                        }
                    }
                    if(1==flag)
                    {
                        sg[h][i]=f;
                        break;
                    }
                }
            }
        }
        ans=0;
        for(h=0;h<3;h++)
        {
            ans=ans^sg[h][t[h]];
        }
        if(0==ans)
        {
            printf("Nacci\n");
        }
        else
        {
            printf("Fibo\n");
        }
    }
return 0;
}