******************************
    Author : townboy
    Submit time : 2013-05-08 01:00:39
    Judge Status : Accepted
    HDOJ Runid : 8258192
    Problem id : 3817
    Exe.time : 0MS
    Exe.memory : 272K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<algorithm>

using namespace std;

int main()
{        
    int delta;
    int cas,i,f;
    int edge[3];
    scanf("%d",&cas);
    for(i=0;i<cas;i++)
    {
        for(f=0;f<3;f++){
            scanf("%d",edge+f);
            edge[f]*=edge[f];
        }
        sort(edge,edge+3);
        delta=edge[0]+edge[1]-edge[2];
        printf("Case %d: ",i+1);
        if(0 == delta)
            puts("Right triangle");
        else if(delta > 0)
            puts("Acute triangle");
        else
            puts("Obtuse triangle");
    }
    return 0;
}