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

int main() {
	int		i, j, L, R, n;

	while(scanf("%s", labels)!=EOF) {
		n = strlen(labels);
		for(i=n-1; i>0; i--)
			for(j=0; j<i; j++)
				if(labels[j] > labels[j+1])
					swap(j, j+1);

		while(1) {
			printf("%s\n",labels);
			
			L = -1;
			for(i=n-2; i>=-1; i--)
				if(labels[i] < labels[i+1]) {
					L = i;
					break;
				}
			if(i==-1) break;
			for(i=n-1; i>=0; i--)
				if(labels[i] > labels[L]) {
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