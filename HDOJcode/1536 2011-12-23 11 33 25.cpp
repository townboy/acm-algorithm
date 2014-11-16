******************************
    Author : townboy
    Submit time : 2011-12-23 11:33:25
    Judge Status : Accepted
    HDOJ Runid : 5196820
    Problem id : 1536
    Exe.time : 78MS
    Exe.memory : 388K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<stdlib.h>
int cmp(const void* a,const void* b)
{
    return *(int*)a-*(int*)b;    
}
int main(void)
{
    int snum,s[200],sg[20000],ge[200][200],f,g,zu,max,i,zan[200],ans;
    while(scanf("%d",&snum),snum)
    {
        for(i=0;i<snum;i++)
        {
            scanf("%d",&s[i]);
        }
        qsort(s,snum,sizeof(s[0]),cmp);
        scanf("%d",&zu);
        max=-1;
        for(i=0;i<zu;i++)
        {
            scanf("%d",&ge[i][0]);
            for(f=1;f<=ge[i][0];f++)
            {
                scanf("%d",&ge[i][f]);
                if(max<ge[i][f])
                {
                    max=ge[i][f];
                }
            }
        }
        for(i=0;i<=max;i++)
        {
            for(g=0;g<=110;g++)
            {
                zan[g]=0;
            }        
            for(f=0;f<snum;f++)
            {
                if((i-s[f])>=0)
                {
                    zan[sg[i-s[f]]]=1;
                }
                else
                {
                    break;
                }
            }
            for(f=0;;f++)
            {
                if(0==zan[f])
                {
                    sg[i]=f;
                    break;
                }
            }
        }

        for(i=0;i<zu;i++)
        {
            ans=0;
            for(f=1;f<=ge[i][0];f++)
            {
                ans=ans^sg[ge[i][f]];
            }
            if(0==ans)
            {
                printf("L");
            }
            else
            {
                printf("W");
            }
        }
        printf("\n");
    }
return 0;
}