******************************
    Author : townboy
    Submit time : 2013-04-09 11:25:24
    Judge Status : Accepted
    HDOJ Runid : 8036636
    Problem id : 2148
    Exe.time : 15MS
    Exe.memory : 256K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<algorithm>

using namespace std;

int n,k;
int score[1100];

int main()
{
    int own;
    int i,cas,f;
    scanf("%d",&cas);
    for(i=0;i<cas;i++)
    {
        scanf("%d%d",&n,&k);
        for(f=0;f<n;f++)
        {
            scanf("%d",score+f);
            if(f == k-1)
                own=score[f];
        }
        sort(score,score+n);
        for(f=n-1;f>-1;f--)
        {
            if(score[f] <= own)
                break;
        }
        printf("%d\n",n-f-1);
    }
    return 0;
}