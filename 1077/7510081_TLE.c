#include<stdio.h>
#include<string.h>

int		factor[10] = {1, 2, 6, 24, 120, 720, 5040, 40320, 362880};

struct  flag {
	int		parent;
	char	mathod;
};

struct flag Flag[362881];
char		Q[362881][11],   help[11];
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


int main() {
	int		i, k, Qhash, hash, isFind, p;
	char	a;
	char	path[362881];

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

	for(i=0; i<362881; i++)
		Flag[i].parent = -1;
	
	isFind = 0;
	front = rear = 0;
	Flag[getHash(help)].parent = -2;
	strcpy(Q[rear++], help);
	while(front!=rear) {
		Qhash = getHash(Q[front]);
		if(Qhash==0) {
			isFind = 1;
			break;
		}
		p = Q[front][9] - 48;
		if(p-3>=0) {
			strcpy(Q[rear], Q[front]);
			swap(Q[rear], p, p-3);
			Q[rear][9] = p-3+48;
			hash = getHash(Q[rear]);
			if(Flag[hash].parent==-1)  {
				Flag[hash].parent = Qhash;
				Flag[hash].mathod = '1';
				rear++;
			}
		}
		if(p%3!=0) {
			strcpy(Q[rear], Q[front]);
			swap(Q[rear], p, p-1);
			Q[rear][9] = p-1 +48;
			hash = getHash(Q[rear]);
			if(Flag[hash].parent==-1)  {
				Flag[hash].parent = Qhash;
				Flag[hash].mathod = '2';
				rear++;
			}
		}
		if((p+1)%3!=0) {
			strcpy(Q[rear], Q[front]);
			swap(Q[rear], p, p+1);
			Q[rear][9] = p+1+48;
			hash = getHash(Q[rear]);
			if(Flag[hash].parent==-1)  {
				Flag[hash].parent = Qhash;
				Flag[hash].mathod = '3';
				rear++;
			}
		}
		if(p+3<=8) {
			strcpy(Q[rear], Q[front]);
			swap(Q[rear], p, p+3);
			Q[rear][9] = p+3+48;
			hash = getHash(Q[rear]);
			if(Flag[hash].parent==-1)  {
				Flag[hash].parent = Qhash;
				Flag[hash].mathod = '4';
				rear++;
			}
		}
		front++;
	}

	if(isFind==0) {
		printf("unsolvable\n");
		return 1;
	}

	i = 0;
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

