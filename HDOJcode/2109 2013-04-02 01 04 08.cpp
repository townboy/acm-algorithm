******************************
    Author : townboy
    Submit time : 2013-04-02 01:04:08
    Judge Status : Accepted
    HDOJ Runid : 7963617
    Problem id : 2109
    Exe.time : 15MS
    Exe.memory : 228K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<algorithm>

using namespace std;

int chi[110],jap[110];

int main()
{
    int n;
    int a1,a2;
    int i;
    while(scanf("%d",&n),n)
    {
        a1=a2=0;
        for(i=0;i<n;i++)
            scanf("%d",chi+i);
        for(i=0;i<n;i++)
            scanf("%d",jap+i);
        sort(chi,chi+n);
        sort(jap,jap+n);
        for(i=0;i<n;i++)
        {
            if(chi[i] > jap[i])
                a1+=2;
            else if(chi[i] == jap[i])
                a1++,a2++;
            else 
                a2+=2;
        }
        printf("%d vs %d\n",a1,a2);
    }
    return 0;
}