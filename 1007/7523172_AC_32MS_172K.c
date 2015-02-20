#include<stdio.h>

int main() {
	int		i, j,  k, min,  miner, m,  n;
	char	dna[101][51];  
	int		value[101];
	scanf("%d %d", &n, &m);
	for(i=0; i<m; i++) 
		scanf("%s", dna[i]);

	for(i=0; i<m; i++) {
		value[i] = 0;
		for(j=0; j<n-1; j++)
			for(k=j+1; k<n; k++)
				if(dna[i][j] > dna[i][k]) value[i]++;
	}
	for(j=0; j<m; j++) {
		min = 9999999;
		for(i=0; i<m; i++) {
			if(min > value[i]) {
				min=value[i];
				miner = i;
			}
		}
		value[miner] = 9999999;
		for(i=0; i<n; i++)
			printf("%c",dna[miner][i]);
		printf("\n");
	}
	return 1;
}