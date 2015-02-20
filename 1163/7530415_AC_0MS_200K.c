#include<stdio.h>

int main() {
	int		i,  j,  map[101][101],  n;
	while(scanf("%d", &n)!=EOF) {
		for(i=1; i<=n; i++)
			for(j=1; j<=i; j++)
				scanf("%d", &map[i][j]);

		for(i=n-1; i>=1; i--)
			for(j=1; j<=i; j++)
				if(map[i+1][j] > map[i+1][j+1]) map[i][j] = map[i][j] + map[i+1][j];
				else map[i][j] = map[i][j] + map[i+1][j+1];
		printf("%d\n", map[1][1]);
	}
	return 1;
}
