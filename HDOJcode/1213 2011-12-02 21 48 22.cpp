******************************
    Author : townboy
    Submit time : 2011-12-02 21:48:22
    Judge Status : Accepted
    HDOJ Runid : 5100157
    Problem id : 1213
    Exe.time : 0MS
    Exe.memory : 184K
    https://github.com/townboy
******************************


#include<stdio.h>
int c[2000];
int find(int x)
{
    while(c[x]!=x)
    {
        x=c[x];
    }
    return x;
}
void merge(int n1,int n2)
{
    c[n1]=n2;
}
int main(void)
{
    int num,i,f,ren,shu,r1,r2,ji;
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        scanf("%d%d",&ren,&shu);
        for(f=1;f<=ren;f++)
        {    
            c[f]=f;
        }
        for(f=0;f<shu;f++)
        {
            scanf("%d%d",&r1,&r2);
            if(find(r1)!=find(r2))
            {
                merge(find(r1),find(r2));
            }
        }
        ji=0;
        for(f=1;f<=ren;f++)
        {
            if(c[f]==f)
            {
                ji++;
            }
        }
        printf("%d\n",ji);
    
    
    }




} 