#include<stdio.h>

int main () {
	int		i,n, m, t;
	int		f[11][11];

	for(i=1; i<=10; i++) {
		f[1][i] = 1;
		f[0][i] = 1;
		f[i][0] = 0;
	}

	for(m=2; m<=10; m++)
		for(n=1; n<=10; n++) {
			if(n>m) f[m][n] = f[m][m];
			else	f[m][n] = f[m][n-1] + f[m-n][n];
		}

	scanf("%d", &t);
	while(t--) {
		scanf("%d %d", &m, &n);
		printf("%d\n", f[m][n]);
	}
	return 1;
}