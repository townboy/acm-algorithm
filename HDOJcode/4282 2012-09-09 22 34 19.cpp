******************************
    Author : townboy
    Submit time : 2012-09-09 22:34:19
    Judge Status : Accepted
    HDOJ Runid : 6730440
    Problem id : 4282
    Exe.time : 109MS
    Exe.memory : 584K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<math.h>

int k;
__int64 fang[1300][32];

int main()
{
    __int64 nn,n,he,ans,z,y,x;
    int i,f;

    for(i=1;i<1300;i++)
    {
        for(f=1;f<=31;f++)
        {
            fang[i][f]=(__int64)(pow(i,f)+0.5);            
        }
    }

    while(scanf("%d",&k),k)
    {
        ans=0;
        if(k == (int)sqrt((double)k)*(int)sqrt((double)k))
        {
            he=sqrt((double)k);
            ans=he-(he/2+1);
        }
        for(z=3;z<=31;z++)
        {
            for(x=1;;x++)
            {
                n=fang[x][z]+(__int64)x*z;
                if(n > k/2+10)
                {
                    break;
                }
                for(y=x+1;;y++)
                {
                    nn=fang[y][z]+fang[x][z]+(__int64)x*y*z;
                    if(nn == k)
                    {
                        ans++;
                        break;
                    }
                    if(nn > k)
                    {
                        break;
                    }
                }
            }
        }            
        printf("%I64d\n",ans);
    }
    return 0;
}