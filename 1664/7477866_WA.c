#include<stdio.h>

int main () {
	int		i, j, n, m, t, k;
	int		f[11][11];

	for(i=1; i<=10; i++) {
		f[1][i] = 1;
		f[i][0] = 1;
	}

	for(i=2; i<=10; i++)
		for(j=1; j<=10; j++) {
			f[i][j] = 0;
			for(k=0; k<=j; k++)
				f[i][j] += f[i-1][k];
			f[i][j] /= 2;
		}

	scanf("%d", &t);
	while(t--) {
		scanf("%d %d", &m, &n);
		printf("%d\n", f[n][m]);
	}
	return 1;
}