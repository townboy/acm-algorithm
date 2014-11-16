9.1 位运算(状态压缩)
/*取出最右边的1:	 		x & (-x)

把最右边的1变为0:		x & (x-1)

位运算遍历子集（st为原始集合）：

*/
for (int mask = st ; mask ; mask = st & (mask - 1)) {
........
}

//求32位整数中二进制1的个数
int countone(int n)
{
    n=(n&0x55555555)+((n>>1)&0x55555555);
    n=(n&0x33333333)+((n>>2)&0x33333333);
    n=(n&0x0f0f0f0f)+((n>>4)&0x0f0f0f0f);
    n=(n&0x00ff00ff)+((n>>8)&0x00ff00ff);
    n=(n&0x0000ffff)+((n>>16)&0x0000ffff);
    return n;
}


//9.2 读入外挂					
/*
 * qscan.cpp
 *
 *  Created on: 2010-10-12
 *      Author: Amb
*/

//无符号整型输入
inline void in(int &num){
     char in=getchar();
     while(in<'0'||in>'9'){
           in=getchar();
     }
     num=in-'0';
     in=getchar();
     while(in>='0'&&in<='9'){
           num*=10; num+=in-'0';
           in=getchar();
     }
}

//有符号整型输入
inline void in(int &num){
     char in=getchar();
     bool IsN=false;
     while(in!='-'&&(in<'0'||in>'9')){
           in=getchar();
     }
     if(in=='-'){ IsN=true;num=0; }
     else num=in-'0';
     in=getchar();
     while(in>='0'&&in<='9'){
           num*=10;num+=in-'0';
           in=getchar();
     }
     if(IsN) num=-num;
}

//无符号浮点输入
inline void in(double &num){
     char in;double Dec=0.1;
     bool IsD=false;
     do{
           in=getchar();
     }while(in!='.'&&(in<'0'||in>'9'));
     if(in=='.') { IsD=true;num=0; }
     else num=in-'0';
     if(!IsD){
           in=getchar();
           while(in>='0'&&in<='9'){
                num*=10;num+=in-'0';
                in=getchar();
           }
     }
     if(in=='.'){
           in=getchar();
           while(in>='0'&&in<='9'){
                num+=Dec*(in-'0');Dec*=0.1;
                in=getchar();
           }
     }
}


//整数输出
inline void out(int num){
      if(num<0){
            putchar('-');
            num=-num;
      }
      if(num==0){
            putchar('0');
            return;
      }
      char str[20];
      int bas=0;
      for(;num;num/=10) str[bas++]=num%10+'0';
      while(bas--) putchar(str[bas]);
}


//9.3 栈外挂					
#pragma comment(linker, "/STACK:102400000,102400000")    
int size = 256 << 20; // 256MB
char *p = (char*)malloc(size) + size;
__asm__("movl %0, %%esp\n" :: "r"(p));

// sort(first,last);O(nlogn)
// unique(first,last); 
返回一个迭代器，新的数组的末尾，使用之前需要保证有序。O(n)
// lower_bound(first,last,val);
使用之前需要保证升序，返回第一个大于等于val的迭代器。O(nlogn)
// upper_bound(first,last,val);
使用之前需要保证升序，返回第一个大于val的迭代器。
// random_shuffle(first,last);
随机重新排列之间的元素。
// binary_search(first,last,val);
判断在这之间的元素中是否存在val，返回true or false 需要数据升序。
// void swap (T &a[N], T &b[N]));
交换两个元素或者两个数组。
// void reverse (BidirectionalIterator first, BidirectionalIterator last);
    将整个数组倒置。


