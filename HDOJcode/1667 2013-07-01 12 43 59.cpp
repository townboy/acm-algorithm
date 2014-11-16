******************************
    Author : townboy
    Submit time : 2013-07-01 12:43:59
    Judge Status : Accepted
    HDOJ Runid : 8512744
    Problem id : 1667
    Exe.time : 546MS
    Exe.memory : 300K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<memory.h>
#include<algorithm>

using namespace std;

int deep;
int Ro[7][7];
char dir[20];
int in[8][2] = {2,2,2,3,2,4,3,2,3,4,4,2,4,3,4,4};

int read(){
    scanf("%d",&Ro[0][2]);
    if(0 == Ro[0][2])
        return 0;
    scanf("%d %d %d",&Ro[0][4],&Ro[1][2],&Ro[1][4]);
    for(int i = 0;i < 7;i++)
        scanf("%d",&Ro[2][i]);
    scanf("%d %d",&Ro[3][2],&Ro[3][4]);
    for(int i = 0;i < 7;i++)
        scanf("%d",&Ro[4][i]);
    scanf("%d %d",&Ro[5][2],&Ro[5][4]);
    scanf("%d %d",&Ro[6][2],&Ro[6][4]);
}
void debug(){
    for(int i=0;i<7;i++){
        for(int f=0;f<7;f++)
            printf("%d ",Ro[i][f]);
        cout << endl;
    }
    cout << endl;
}
    
int check(){
    for(int i=1;i<8;i++)
        if(Ro[in[i][0]][in[i][1]] != Ro[in[i-1][0]][in[i-1][1]])
            return 0;
    return 1;
}

int h(){
    int n[4];
    memset(n,0,sizeof(n));
    for(int i=0;i<8;i++)
        n[Ro[in[i][0]][in[i][1]]]++;
    return 8 - max(n[3],max(n[1],n[2]));
}

void TA(){
    int tem = Ro[0][2];
    for(int i=0;i<6;i++)
        Ro[i][2] = Ro[i+1][2];
    Ro[6][2] = tem;
}

void TB(){
    int tem = Ro[0][4];
    for(int i=0;i<6;i++)
        Ro[i][4] = Ro[i+1][4];
    Ro[6][4] = tem;
}

void TC(){
    int tem = Ro[2][6];
    for(int f=6;f>0;f--)
        Ro[2][f] = Ro[2][f-1]; 
    Ro[2][0] = tem;
}

void TD(){
    int tem = Ro[4][6];
    for(int f=6;f>0;f--)
        Ro[4][f] = Ro[4][f-1]; 
    Ro[4][0] = tem;
}

void TE(){
    int tem = Ro[6][4];
    for(int i=6;i>0;i--)
        Ro[i][4] = Ro[i-1][4];
    Ro[0][4] = tem;
}

void TF(){
    int tem = Ro[6][2];
    for(int i=6;i>0;i--)
        Ro[i][2] = Ro[i-1][2];
    Ro[0][2] = tem;
}

void TG(){
    int tem = Ro[4][0];
    for(int f=0;f<6;f++)
        Ro[4][f] = Ro[4][f+1];
    Ro[4][6] = tem;
}

void TH(){
    int tem = Ro[2][0];
    for(int f=0;f<6;f++)
        Ro[2][f] = Ro[2][f+1];
    Ro[2][6] = tem;
}


int IDAstar(int d){
    if(1 == check())
        return 1;
    if(d + h() > deep)
        return 0;
        
    int tem[7][7];
    memcpy(tem,Ro,sizeof(tem));
    
    TA();
    dir[d]='A';
    if(1 == IDAstar(d+1))
        return 1;
    memcpy(Ro,tem,sizeof(tem));
    
    TB();
    dir[d]='B';
    if(1 == IDAstar(d+1))
        return 1;
    memcpy(Ro,tem,sizeof(tem));
    
    TC();
    dir[d]='C';
    if(1 == IDAstar(d+1))
        return 1;
    memcpy(Ro,tem,sizeof(tem));
    
    TD();
    dir[d]='D';
    if(1 == IDAstar(d+1))
        return 1;
    memcpy(Ro,tem,sizeof(tem));
    
    TE();
    dir[d]='E';
    if(1 == IDAstar(d+1))
        return 1;
    memcpy(Ro,tem,sizeof(tem));
    
    TF();
    dir[d]='F';
    if(1 == IDAstar(d+1))
        return 1;
    memcpy(Ro,tem,sizeof(tem));
    
    TG();
    dir[d]='G';
    if(1 == IDAstar(d+1))
        return 1;
    memcpy(Ro,tem,sizeof(tem));
    
    TH();
    dir[d]='H';
    if(1 == IDAstar(d+1))
        return 1;
    memcpy(Ro,tem,sizeof(tem));
    
    return 0;
}

void ans(){
    if(0 == deep){
        cout << "No moves needed" << endl;
        cout << Ro[2][2] << endl;
        return ;
    }
    for(int i=0;i<deep;i++)
        printf("%c",dir[i]);
    puts("");
    cout << Ro[2][2] << endl;
}

int main()
{
    while(true){
        if(0 == read())
            return 0;
        for(deep = 0;;deep ++){
            if(1 == IDAstar(0))
                break;
        }
        ans();
    }
    return 0;
}