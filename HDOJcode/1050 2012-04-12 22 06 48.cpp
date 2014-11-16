******************************
    Author : townboy
    Submit time : 2012-04-12 22:06:48
    Judge Status : Accepted
    HDOJ Runid : 5762443
    Problem id : 1050
    Exe.time : 0MS
    Exe.memory : 188K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>
int main()
{
    int i,f,g,num,n,max,map[210],s,e;
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        memset(map,0,sizeof(map));
        max=0;
        scanf("%d",&n);
        
        for(f=0;f<n;f++)
        {
            scanf("%d%d",&s,&e);
            if(s<e)
            {
                for(g=(s+1)/2;g<=(e+1)/2;g++)
                {
                    map[g]++;
                }
            }
            else
            {
                for(g=(s+1)/2;g>=(e+1)/2;g--)
                {
                    map[g]++;
                }
            } 
        }
        
        for(f=1;f<201;f++)
        {
            if(map[f]>max)
            {
                max=map[f];
            }
        }
        printf("%d\n",max*10);
    }
    return 0;
}