#include<stdio.h>
#include<string.h>

int		factor[9] = {1,1, 2, 6, 24, 120, 720, 5040, 40320};
char		help[11];
char		path[362889];						//辅助输出路径
char		mathod[362889];					//记录空格移动的方向
int		parent[362889];					//记录父节点

struct  flag {
	char		stat[11];
	int		hash;
};

flag Q[362889];

int	getHash(char *statu) {					//康拓展开实现hash
	int		i, j, hash = 0,  count;
	for(i=0; i<8; i++) {
		count = 0;
		for(j=i+1; j<9; j++)
			if(statu[j] < statu[i]) count++;
		hash += factor[8-i]*count;
	}
	return hash;
}

int	swap(char *tar, int i, int j) {
	char		b;
	b = tar[i];
	tar[i] = tar[j];
	tar[j] = b;
	return 1;
}

int main() {
	int		i, k,  isFind=0;
	char		a;

	for(i=0; i<362889;)
		parent[i++] = -1;

	i=0;
	while(scanf("%c", &a) && a!=10) {
		if(a<='8' && a>='1')
			help[i++] = a;
		else if(a=='x')  {
			help[9] = i+48;
			help[i++] = '9';
		}
	}
	help[10] = '\0';
	
	int		count=0;
	for(i=0; i<8; i++)
		for(int j=i+1; j<9; j++)
			if(help[i]>help[j] && help[i]!='9' && help[j]!='9') count++;
	if(count%2) {
		printf("unsolvable\n");
		return 0;
	}

	flag		P;
	strcpy(P.stat, help);
	P.hash = getHash(help);
	parent[P.hash] = -2;
	int	front=0, tail=1;
	Q[0] = P;
	flag		tmp, tar;
	while(front<tail) {
		tmp = Q[front++];
		if(tmp.hash==0) {
			isFind = 1;
			break;
		}

		int s = tmp.stat[9] - 48;
		if(s-3>=0) {                 //空格上移
			tar = tmp;
			swap(tar.stat, s, s-3);
			tar.stat[9] = s-3+48;
			tar.hash = getHash(tar.stat);
			if(parent[tar.hash]==-1)  {
				parent[tar.hash] = tmp.hash;
				mathod[tar.hash] = 'u';
				Q[tail++] = tar;
			}
		}
		if(s%3!=0) {                         //空格左移
			tar = tmp;
			swap(tar.stat, s, s-1);
			tar.stat[9] = s-1+48;
			tar.hash = getHash(tar.stat);
			if(parent[tar.hash]==-1)  {
				parent[tar.hash] = tmp.hash;
				mathod[tar.hash] = 'l';
				Q[tail++] = tar;
			}
		}
		if(s+3<=8) {							//空格下移
			tar = tmp;
			swap(tar.stat, s, s+3);
			tar.stat[9] = s+3+48;
			tar.hash = getHash(tar.stat);
			if(parent[tar.hash]==-1)  {
				parent[tar.hash] = tmp.hash;
				mathod[tar.hash] = 'd';
				Q[tail++] = tar;
			}
		}
		if((s+1)%3!=0) {                    //空格右移
			tar = tmp;
			swap(tar.stat, s, s+1);
			tar.stat[9] = s+1+48;
			tar.hash = getHash(tar.stat);
			if(parent[tar.hash]==-1)  {
				parent[tar.hash] = tmp.hash;
				mathod[tar.hash] = 'r';
				Q[tail++] = tar;
			}
		}
	}

	if(isFind==0) {
		printf("unsolvable\n");
		return 0;
	}

	i = 0,k = 0;					//记录搜索路径
	while(i!=-2) {
		path[k++] = mathod[i];
		i = parent[i];
	}

	for(i=k-2; i>=0; i--)			//输出搜索路径
		printf("%c", path[i]);
	printf("\n");
	return 0;
}


