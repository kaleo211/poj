//字典序全排列

#include<stdio.h>
#include<string.h>

char	labels[202];

int swap(int i, int j) {
	int		temp;
	temp = labels[i];
	labels[i] = labels[j];
	labels[j] = temp;
	return 1;
}

int cmp(int i, int j) {
	if(labels[i]<='Z' && labels[j]>='a')  {
		if(labels[j] - labels[i] >=32) return -1;
		else return 1;
	}
	else if(labels[j]<'Z' && labels[i]>='a' ) {
		if(labels[i] - labels[j] >=32) return 1;
		else return -1;
	}
	else {
		if(labels[i] > labels[j]) return 1;
		else return -1;
	}
}

int main() {
	int		i, j, L, R, n, t;

	scanf("%d", &t);
	while(t--) {
		scanf("%s", labels);
		n = strlen(labels);
		for(i=n-1; i>0; i--)
			for(j=0; j<i; j++)
				if(cmp(j,j+1)==1)
					swap(j, j+1);

		while(1) {
			printf("%s\n",labels);
			
			L = -1;
			for(i=n-2; i>=-1; i--)
				if(cmp(i+1, i)==1) {
					L = i;
					break;
				}
			if(i==-1) break;
			for(i=n-1; i>=0; i--)
				if(cmp(i,L)==1) {
					R = i;
					break;
				}
			swap(L, R);
			for(i=1; i<=(n-1-L)/2; i++)
				swap(L+i, n-i);
		}
	
	}
	return 1;
}