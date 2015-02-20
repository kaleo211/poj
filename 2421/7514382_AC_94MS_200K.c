#include<stdio.h>

int		parent[101];

int	find(int x) {
	int		i, temp;
	for(i=x; parent[i]>=0; i=parent[i]) ;
	while(i!=x) {
		temp = parent[x];
		parent[x] = i;
		x = temp;
	}
	return i;
}

void merge(int a, int b) {
	int		temp = parent[a] + parent[b];
	if(parent[a] < parent[b]) {
		parent[a] = temp;
		parent[b] = a;
	}
	else {
		parent[a] = b;
		parent[b] = temp;
	}
}

int main() {
	int		n, i, j, q, min, road, y, x, count;
	int		distance[101][101];

//	while(scanf("%d", &n) !=EOF) {
		scanf("%d", &n);
		for(i=0; i<=100; i++)
			parent[i] = -1;

		for(i=1; i<=n; i++)
			for(j=1; j<=n; j++)
				scanf("%d", &distance[i][j]);

		scanf("%d", &q);
		while(q--) {
			scanf("%d %d", &i, &j);
			distance[i][j] = 0;
			distance[j][i] = 0;
		}
		
		road = 0;
		count = 0;
		while(1) {
			min = 100001;
			for(i=1; i<n; i++)
				for(j=i+1; j<=n; j++) {
					if(min > distance[i][j]) {
						min = distance[i][j];
						x = i;
						y = j;
					}
				}

			distance[x][y] = 100001;
			if( find(x)!=find(y) ) {
				road += min;
				merge(find(x), find(y));
				count++;
				if(count >= n-1) break;
			}
		}
		printf("%d\n", road);
//	}
	return 1;
}