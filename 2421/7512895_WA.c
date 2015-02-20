#include<stdio.h>

int		parent[101];


int	find(int x) {
	int		i;
	for(i=x; parent[i]>=0; i=parent[i]) ;
	return i;
}

int main() {
	int		n, i, j, q, min, road, y, x;
	int		distence[101][101];
	while(scanf("%d", &n) !=EOF) {
		for(i=0; i<=100; i++)
			parent[i] = -1;

		for(i=1; i<=n; i++)
			for(j=1; j<=n; j++)
				scanf("%d", &distence[i][j]);
		scanf("%d", &q);
		while(q--) {
			scanf("%d %d", &i, &j);
			distence[i][j] = 1001;
			parent[i] = j;
		}
		
		road = 0;
		while(1) {
			min = 1001;
			for(i=1; i<n; i++)
				for(j=i+1; j<=n; j++) {
					if(min > distence[i][j]) {
						min = distence[i][j];
						x = i;
						y = j;
					}
				}
			if(min==1001) break;
			distence[x][y] = 1001;
			if( find(x)!=find(y)) {
				road += min;
				parent[x] = y;
			}
		}
		printf("%d\n", road);
	}
	return 1;
}