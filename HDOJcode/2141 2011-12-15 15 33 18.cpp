******************************
    Author : townboy
    Submit time : 2011-12-15 15:33:18
    Judge Status : Accepted
    HDOJ Runid : 5167231
    Problem id : 2141
    Exe.time : 515MS
    Exe.memory : 1208K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int d[300000];
int cmp(const void*a,const void*b)
{
    return *(int*)a-*(int*)b;
}
int main(void)
{
    int l,n,m,i,f,mid,x,flag,a[1000],b[1000],c[1000],num,hao,ji,left,right;
    __int64 tem;
    hao=0;
    while(scanf("%d%d%d",&l,&n,&m)!=EOF)
    {
        hao++;
        for(i=0;i<l;i++)
        {
            scanf("%d",&a[i]);
        }
        for(i=0;i<n;i++)
        {
            scanf("%d",&b[i]);
        }
        for(i=0;i<m;i++)
        {
            scanf("%d",&c[i]);
        }
        scanf("%d",&num);
        printf("Case %d:\n",hao);
        ji=0;
        for(i=0;i<l;i++)
        {
            for(f=0;f<n;f++)
            {
                tem=b[i]+c[f];
                if(tem<pow(2,63))
                {
                    d[ji]=tem;
                    ji++;
                }
            }
        }
        qsort(d,ji,sizeof(d[0]),cmp);
        for(i=0;i<num;i++)
        {
            scanf("%d",&x);
            flag=0;
             for(f=0;f<l;f++)
            {
                left=0;
                right=ji-1;
                while(right>=left)
                {
                    mid=(left+right)/2;
                    if(x==(a[f]+d[mid]))
                    {
                        flag=1;
                        break;
                    }
                    else if((a[f]+d[mid])>x)
                    {
                        right=mid-1;
                    }
                    else
                    {
                        left=mid+1;
                    }
                }
                if(1==flag)
                {
                    break;
                }
            }
            if(1==flag)
            {
                printf("YES\n");
            }
            else
            {
                printf("NO\n");
            }
        }
    }
        
return 0;

}