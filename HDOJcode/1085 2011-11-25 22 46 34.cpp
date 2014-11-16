******************************
    Author : townboy
    Submit time : 2011-11-25 22:46:34
    Judge Status : Accepted
    HDOJ Runid : 5055993
    Problem id : 1085
    Exe.time : 187MS
    Exe.memory : 328K
    https://github.com/townboy
******************************


#include<stdio.h>
int main(void)
{
    int num,i,f,k,p[5]={0,1,2,5},n[10];
    __int64    c1[10000],c2[10000];
    while(scanf("%d%d%d",&n[1],&n[2],&n[3]),!((0==n[1])&&(0==n[2])&&(0==n[3])))
    {
        num=n[1]+n[2]*2+n[3]*5;
        for(i=0;i<=num+1;i++)
        {
            c1[i]=0;
            c2[i]=0;
        }
        for(i=0;i<=n[1];i++)
        {
            c1[i]=1;
        }
        for(i=2;i<=3;i++)
        {
            for(f=0;f<=num;f++)
            {
                for(k=0;(k<=p[i]*n[i])&&(k+f<=num);k=k+p[i])
                {
                    c2[k+f]=c2[k+f]+c1[f];
                }     
            }
            for(f=0;f<=num;f++)
            {
                c1[f]=c2[f];
                c2[f]=0;
            }
        }
        for(i=1;i<=num+1;i++)
        {
            if(c1[i]==0)
            {
                printf("%d\n",i);
                break;
            }
        }    
    }
    return 0;
} 
