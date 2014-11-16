******************************
    Author : townboy
    Submit time : 2011-10-15 19:19:32
    Judge Status : Accepted
    HDOJ Runid : 4761927
    Problem id : 2007
    Exe.time : 0MS
    Exe.memory : 184K
    https://github.com/townboy
******************************


#include<stdio.h>
void main()
{
int min,max,even,odd,i,zhong;
while(scanf("%d%d",&min,&max)!=EOF)
{if(max<min)
{
    zhong=max;
   max=min;
   min=zhong;

}
    even=odd=0;
for(i=min;i<=max;i++)
{if (i%2==0)
even=i*i+even;
else 
odd=i*i*i+odd;
}
printf("%d %d\n",even,odd);
}
}