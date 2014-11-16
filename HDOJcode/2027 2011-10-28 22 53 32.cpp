******************************
    Author : townboy
    Submit time : 2011-10-28 22:53:32
    Judge Status : Accepted
    HDOJ Runid : 4844973
    Problem id : 2027
    Exe.time : 0MS
    Exe.memory : 212K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<string.h>
void main()
{   
    int num,i,ci,a,e,o,u,f,len;
    char ch[1000];
    scanf("%d",&num);
    getchar();
    for(f=0;f<num;f++)
    {
        gets(ch);
          len=strlen(ch);
         a=e=i=o=u=0;
        for(ci=0;ci<len;ci++)
        {
           
            switch(ch[ci])
            {
                case 97:
                case 65:a++;break;
                case 101:
                case 69:e++;break;
                case 73:
                case 105:i++;break;
                case 79:
                case 111:o++;break;
                case 117:
                case 85:u++;break;
                default: ;
            }
        
        
        }
        printf("a:%d\ne:%d\ni:%d\no:%d\nu:%d\n",a,e,i,o,u);
        if(f<num-1)
            printf("\n");
    
    
    }

}
