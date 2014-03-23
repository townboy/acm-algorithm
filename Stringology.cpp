//8.1 kmp算法
int fail[10000];
void init(int B[],int m){
	fail[0] = -1;
	for(int i = 1 ,f = -1;i < m; i++){
		while(f >= 0 && B[f+1]!=B[i])
			f = fail[f];
		if(B[f+1] == B[i])
			f ++ ;
		fail[i] = f;
	}
}

bool kmp(int A[],int B[],int n,int m){
	for(int i = 0, f = 0; i < n ;i++){
		while( f > 0 && B[f] != A[i])
			f = fail[f-1] + 1;
		if(B[f] == A[i])
			f ++ ;
		if(f == m)
			return true;
	}
	return false;
}


/*8.2 字典树
[ 静态 ]
*/

int size ;
int next[10000][26];

void init(){
	size = 0;
	memset(next[0],0,sizeof(next[0]));
}

void build(char* str){
	int c,p=0,i,f;
	for(i=0; str[i] ;i++){	
		c=str[i]-'a';
		if(-1 == next[p][c]){
			size ++;
			next[p][c] = size ;
			memset(next[size],-1,sizeof(next[size]));
		}
		p = next[p][c];
	}	
}

//8.3 ac自动机
// 统计有多少单词在文章中出现过
#define MAX_NODE 500100
#define CHILD_NUM 26

struct ACAutomaton {
	int chd[MAX_NODE][CHILD_NUM];
	int val[MAX_NODE];
	int fail[MAX_NODE];

	int Q[MAX_NODE];

	int ID[128];

	int sz;
	
	void Initialize() {
		fail[0] = 0;
		for (int i = 0 ; i < CHILD_NUM ; i ++) {
			ID[i+'a'] = i;
		}
	}

	void Reset() {
		memset(chd[0] , 0 , sizeof(chd[0]));
		sz = 1;
	}
	
	void Insert(char *a) {
		int p = 0;
		for ( ; *a ; a ++) {
			int c = ID[*a];
			if (!chd[p][c]) {
				memset(chd[sz] , 0 , sizeof(chd[sz]));
				val[sz] = 0;
				chd[p][c] = sz ++;
			}
			p = chd[p][c];
		}
		val[p] ++;
	}

	void Construct() {
		int *s = Q , *e = Q;
		for (int i = 0 ; i < CHILD_NUM ; i ++) {
			if (chd[0][i]) {
				fail[ chd[0][i] ] = 0;
				*e ++ = chd[0][i];
			}
		}
		while (s != e) {
			int u = *s++;
			for (int i = 0 ; i < CHILD_NUM ; i ++) {
				int &v = chd[u][i];
				if (v) {
					*e ++ = v;
					fail[v] = chd[ fail[u] ][i];
				} else {
					v = chd[ fail[u] ][i];
				}
			}
		}
	}
	
	int work(char wen[]) {
		int ans = 0;
		for(int i = 0,f = 0 ; wen[i] ; i++) {
			int c = ID[wen[i]];
			f = chd[f][c];
			int tem = f;
			while(tem){
				if(0 != val[tem]){
					ans += val[tem];
					val[tem] = 0;
				}
				tem = fail[tem];
			}
		}
		return ans;
	}
}AC;

