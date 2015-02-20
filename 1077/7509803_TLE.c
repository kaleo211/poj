#include<stdio.h>
#include<string.h>

int		factor[10] = {1, 2, 6, 24, 120, 720, 5040, 40320, 362880};

struct  flag {
	int		parent;
	char	mathod;
};

struct		flag Flag[362881];
char		Q[362881][11],   help[11],  u[11];
int			front, rear;


int	getHash(char *statu) {
	int		i, j, hash = 0,  count;

	for(i=1; i<=8; i++) {
		count = 0;
		for(j=0; j<i; j++)
			if(statu[j] > statu[i]) count++;
		hash += factor[i-1]*count;
	}
	return hash;
}

int	swap(char *tar, int i, int j) {
	char	b;
	b = tar[i];
	tar[i] = tar[j];
	tar[j] = b;
	return 1;
}

void inQ() {
	int		i;
	for(i=0; i<11; i++)
		Q[rear][i] = help[i];
	rear++;
}

void outQ() {
	int		i;
	for(i=0; i<11; i++)
		u[i] = Q[front][i];
	front++;
}


int main() {
	int		i, k, Qhash, tarHash, hash, isFind, p;
	char	target[11]={'1', '2', '3', '4', '5', '6', '7', '8', '9','8', '\0'};
	char	a;
	char	path[362880];

	i=0;
	while(scanf("%c", &a) && a!=10) {
		if(a<='8' && a>='0')
			help[i++] = a;
		else if(a=='x')  {
			help[9] = i+48;
			help[i++] = '9';
		}
	}
	help[10] = '\0';

	tarHash = getHash(target);
	for(i=0; i<362881; i++)
		Flag[i].parent = -1;
	
	isFind = 0;
	front = 0;
	rear = 0;
	Flag[getHash(help)].parent = -2;
	inQ();
	while(front!=rear) {
		outQ();
		Qhash = getHash(u);
		if(Qhash==tarHash) {
			isFind = 1;
			break;
		}
		p = u[9] - 48;
		for(i=1; i<=4; i++) {
			if(p!=0 && p!=1 && p!=2) {
				strcpy(help, u);
				swap(help, p, p-3);
				help[9] = p-3+48;
				hash = getHash(help);
				if(Flag[hash].parent==-1)  {
					Flag[hash].parent = Qhash;
					Flag[hash].mathod = '1';
					inQ();
				}
			}
			if(p!=0 && p!=3 && p!=6) {
				strcpy(help, u);
				swap(help, p, p-1);
				help[9] = p-1 +48;
				hash = getHash(help);
				if(Flag[hash].parent==-1)  {
					Flag[hash].parent = Qhash;
					Flag[hash].mathod = '2';
					inQ();
				}
			}
			if(p!=2 && p!=5 && p!=8) {
				strcpy(help, u);
				swap(help, p, p+1);
				help[9] = p+1+48;
				hash = getHash(help);
				if(Flag[hash].parent==-1)  {
					Flag[hash].parent = Qhash;
					Flag[hash].mathod = '3';
					inQ();
				}
			}
			if(p!=6 && p!=7 && p!=8) {
				strcpy(help, u);
				swap(help, p, p+3);
				help[9] = p+3+48;
				hash = getHash(help);
				if(Flag[hash].parent==-1)  {
					Flag[hash].parent = Qhash;
					Flag[hash].mathod = '4';
					inQ();
				}
			}
		}
	}

	if(isFind==0) {
		printf("unsolvable\n");
		return 1;
	}

	i = Qhash;
	k = 0;
	while(i!=-2) {
		if(Flag[i].mathod=='1') path[k++] = 'u';
		else if(Flag[i].mathod=='2') path[k++] = 'l';
		else if(Flag[i].mathod=='3') path[k++] = 'r';
		else if(Flag[i].mathod=='4') path[k++] = 'd';
		i = Flag[i].parent;
	}

	for(i=k-1; i>=0; i--)
		printf("%c", path[i]);
	printf("\n");

	return 1;
}

