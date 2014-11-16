******************************
    Author : townboy
    Submit time : 2011-10-20 22:33:02
    Judge Status : Accepted
    HDOJ Runid : 4792743
    Problem id : 1108
    Exe.time : 15MS
    Exe.memory : 184K
    https://github.com/townboy
******************************


#include<stdio.h>
void main ()
{
    int a,b,i;
while(scanf("%d%d",&a,&b)!=EOF)
{
for(i=a;;i++)
{
if(i%a==0&&i%b==0)
{
printf("%d\n",i);
break;
}

}


}



}