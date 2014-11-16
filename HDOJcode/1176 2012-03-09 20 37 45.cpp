******************************
    Author : townboy
    Submit time : 2012-03-09 20:37:45
    Judge Status : Accepted
    HDOJ Runid : 5507889
    Problem id : 1176
    Exe.time : 78MS
    Exe.memory : 14312K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>
int map[100010][12],f[100010][12],hash[100010][12];
int main()
{
    int n,i,g,x,t,h,max,p;
    while(scanf("%d",&n),n)
    { 
        memset(map,0,sizeof(map));
        memset(f,0,sizeof(f));
        memset(hash,0,sizeof(hash));
        max=0;
        for(i=0;i<n;i++)
        {
            scanf("%d%d",&x,&t);
            if(t>max)
            {
                max=t;
            }
            map[t][x]++;
        }
        f[0][5]=map[0][5];
        hash[0][5]=1;
        for(i=1;i<=max+5;i++)
        {
            for(g=0;g<12;g++)
            {
                f[i][g]=map[i][g];
                for(h=-1;h<2;h++)
                {
                    if(g+h<0||g+h>11)
                    {
                        continue;
                    }
                    if(0==hash[i-1][g+h])
                    {
                        continue;
                    }
                    hash[i][g]=1;
                    if(f[i-1][g+h]+map[i][g]>f[i][g])
                    {
                        f[i][g]=f[i-1][g+h]+map[i][g];
                    }
                }
            }
        }
        p=0;
        for(i=0;i<12;i++)
        {
            if(p<f[max+3][i])
            {
                p=f[max+3][i];
            }
        }
        printf("%d\n",p);
    }
    return 0;
}