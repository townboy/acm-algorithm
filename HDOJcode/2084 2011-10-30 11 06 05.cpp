******************************
    Author : townboy
    Submit time : 2011-10-30 11:06:05
    Judge Status : Accepted
    HDOJ Runid : 4855406
    Problem id : 2084
    Exe.time : 31MS
    Exe.memory : 300K
    https://github.com/townboy
******************************


#include<stdio.h>
int max(int x,int y)
{
    if(x>=y)
        return x;
    else
        return y;

}


int main (void)
{
    int num,i,f,g,a[110][110],z[110][110],high;
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        scanf("%d",&high);
        for(f=1;f<=high;f++)
        {
            for(g=1;g<=f;g++)
            {    
                scanf("%d",&a[f][g]);
                z[f][g]=0;
            }
        }
        
        for(g=1;g<=high;g++)
            z[high][g]=a[high][g];
        
        
        for(f=high-1;f>=1;f--)
        {
            for(g=f;g>=1;g--)
                z[f][g]=max(z[f+1][g],z[f+1][g+1])+a[f][g];
        }    
       
        printf("%d\n",z[1][1]);
    }
    return 0;
}