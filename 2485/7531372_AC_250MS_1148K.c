#include<stdio.h>

int		parent[501];

int find(int x) {
	int		i, temp;
	for(i=x; parent[i]>=0; i = parent[i]) ;
	while(i!=x) {
		temp = parent[x];
		parent[x] = i;
		x = parent[x];
	}
	return i;
}

void merge(int x, int y) {
	int		temp = parent[x] + parent[y];
	if(parent[x] < parent[y]) {
		parent[x] = temp;
		parent[y] = x;
	}
	else {
		parent[x] = y;
		parent[y] = temp;
	}
}

int main() {
	int		i,  j,  k,  n,  t,   way[501][501], x,   y,  max,  min;
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		for(i=1; i<=n; i++)
			for(j=1; j<=n; j++)
				scanf("%d", &way[i][j]);

		max = 0;
		for(i=0; i<501; i++)
			parent[i] = -1;
		for(k=1; k<=n-1; k++) {
			min = 65539;
			for(i=2; i<=n; i++)
				for(j=1; j<i; j++)
					if(min > way[i][j] && find(i)!=find(j)) {
						min = way[i][j];
						x = i;
						y = j;
					}
			way[x][y] = 65539;
			if(max < min) max = min;
			merge(find(x), find(y));
		}
		printf("%d\n", max);
	}
	return 1;
}