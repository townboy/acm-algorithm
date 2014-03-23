//2.1矩阵乘法加速			
// 对于循环同构的矩阵 可以实现O(n^2)的复杂度
						
int n,m,mod;					// 矩阵大小，迭代次数，取模值
int ret[10][10];				// 结果矩阵
int init[10][10],buf[10][10];		//初始矩阵，中间矩阵

void mul(int a[][10],int b[][10])		// 传址调用
{
	int i,f,k;

	memset(buf,0,sizeof(buf));

	for(i=0;i<n;i++)
	{
		for(k=0;k<n;k++)
		{
			if(0 == a[i][k])
				continue;
			for(f=0;f<n;f++)
			{
				if(0 == b[k][f])
					continue;
				buf[i][f]=(buf[i][f]+a[i][k]*b[k][f])%mod;
			}
		}
	}
	
	for(i=0;i<n;i++)
		for(f=0;f<n;f++)
			a[i][f]=buf[i][f];
}

void matrix()
{
	int i,f;
	for(i=0;i<n;i++)
		for(f=0;f<n;f++)
			ret[i][f]=(i == f);
			
	for(;m;m>>=1)
	{
		if(1&m)
			mul(ret,init);
		mul(init,init);
	}
}

