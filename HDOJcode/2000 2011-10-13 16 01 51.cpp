******************************
    Author : townboy
    Submit time : 2011-10-13 16:01:51
    Judge Status : Accepted
    HDOJ Runid : 4749269
    Problem id : 2000
    Exe.time : 0MS
    Exe.memory : 208K
    https://github.com/townboy
******************************


#include<stdio.h>
void main()
{
    char a,b,c;
    while(scanf("%c%c%c",&a,&b,&c)!=EOF)
    {
        getchar();
    if(a<b&&b<c)
        printf("%c %c %c\n",a,b,c);
    else if(a<c&&c<b)
        printf("%c %c %c\n",a,c,b);
else if(b<a&&a<c)
printf("%c %c %c\n",b,a,c);
else if(b<c&&c<a)
printf("%c %c %c\n",b,c,a);
else if(c<a&&a<b)
printf("%c %c %c\n",c,a,b);
else if(c<b&&b<a)
printf("%c %c %c\n",c,b,a);
    }
}