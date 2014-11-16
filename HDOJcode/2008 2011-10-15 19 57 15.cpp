******************************
    Author : townboy
    Submit time : 2011-10-15 19:57:15
    Judge Status : Accepted
    HDOJ Runid : 4762171
    Problem id : 2008
    Exe.time : 0MS
    Exe.memory : 200K
    https://github.com/townboy
******************************


#include<stdio.h>
void main()
{
    int n,fu,ling,zheng,i;
    float a;
while(scanf("%d",&n)!=EOF)
{
    fu=ling=zheng=0;
    if( n!=0)
    {
for(i=0;i<n;i++)
{
scanf("%f",&a);
if(a<0)
fu++;
else if(a==0)
ling++;
else
zheng++;
}
    

printf("%d %d %d\n",fu,ling,zheng);
}


}




}