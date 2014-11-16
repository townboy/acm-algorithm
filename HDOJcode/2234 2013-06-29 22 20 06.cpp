******************************
    Author : townboy
    Submit time : 2013-06-29 22:20:06
    Judge Status : Accepted
    HDOJ Runid : 8509249
    Problem id : 2234
    Exe.time : 4906MS
    Exe.memory : 248K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<memory.h>

using namespace std;

int matrix[4][4];
int deep;
int l[4]={1,2,3,0},r[4]={3,0,1,2};

int check(){
    int i,f;
    for(i=0;i<4;i++)
    {
        for(f=1;f<4;f++)
            if(matrix[i][f] != matrix[i][f-1])
                break;
        if(f != 4)
            break;
    }    
    if(4 == i)    return 1;
    
    for(f=0;f<4;f++)
    {
        for(i=1;i<4;i++)
            if(matrix[i][f] != matrix[i-1][f])
                break;
        if(i != 4)
            break;
    }    
    if(4 == f)    return 1;
    return 0;
}

int ID(int h){
    int i,f,left[4][4];
    int now[4];
    if(1 == check())    return 1;
    if(h == deep)    return 0;
    memcpy(left,matrix,sizeof(left));
    for(i=0;i<4;i++){
        memcpy(matrix,left,sizeof(left));
        for(f=0;f<4;f++)
            now[f] = matrix[i][f];
        for(f=0;f<4;f++)
            matrix[i][f] = now[l[f]];
        if(1 == ID(h+1))
            return 1;
        memcpy(matrix,left,sizeof(left));
        for(f=0;f<4;f++)
            matrix[i][f] = now[r[f]];
        if(1 == ID(h+1))
            return 1;
    }
    
    for(f=0;f<4;f++){
        memcpy(matrix,left,sizeof(left));
        for(i=0;i<4;i++)
            now[i] = matrix[i][f];
        for(i=0;i<4;i++)
            matrix[i][f] = now[l[i]];
        if(1 == ID(h+1))
            return 1;
        memcpy(matrix,left,sizeof(left));
        for(i=0;i<4;i++)
            matrix[i][f] = now[r[i]];
        if(1 == ID(h+1))
            return 1;
    }
    memcpy(matrix,left,sizeof(left));
    return 0;
}

int main()
{
    int f,g;
    int i,cas;
    scanf("%d",&cas);
    for(i=0;i<cas;i++)
    {
        for(f=0;f<4;f++)
            for(g=0;g<4;g++)
                scanf("%d",&matrix[f][g]);
        for(deep=0;deep<=5;deep++){
            if(1 == ID(0)){
                printf("%d\n",deep);
                break;
            }
        }
        if(6 == deep)
            printf("-1\n");
    }
    return 0;
}