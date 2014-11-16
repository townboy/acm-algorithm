/*全排列哈希--康托展开
将全排列数字转化成一个int数字进行哈希，原理就是将这个排列转化成这个排列中第几小的数字，n位全排列，康托值是0-n!-1。
*/
struct node{    
　　int s[9];    
　　int state;
};
node tem;
int conto(node tem){   
　　int ans=0,exist[10],num;
　　memset(exist,0,sizeof(exist));    
　　for(int i = 0;i<9;i++){
       num=0;        
　　	for(int f = 1;f<tem.s[i];f++)            
　　	if(0 == exist[f])
           	num++;
　　	ans += fac[i] * num;
　　	exist[tem.s[i]] = 1;
	}    
	return ans;
}

//字符串哈希
unsigned BKDRHash(char str[]){
	unsigned _s=131,_h=0;
	for(int i=0;str[i];i++){
		_h=_h*_s+str[i];
	}
	return (_h&0x7FFFFFFF);
}

