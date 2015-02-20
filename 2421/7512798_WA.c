#include<stdio.h>

int		parent[101];


int	find(int x) {
	int		i;
	for(i=x; parent[i]>=0; i=parent[i]) 
		;
/*	while(i!=x) {
		temp = parent[x];
		parent[x] = i;
		x = temp;
} */
	return i;
}

/*
void unite(int a, int b) {
	int		temp;
	temp = parent[a] + parent[b];
	if(parent[a] < parent[b]) {
		parent[a] = temp;
		parent[b] = a;
	}
	else {    
		parent[b] = temp;
		parent[a] = b;
	}
} */


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
					if( find(i)!=find(j))
						if(min > distence[i][j]) {
							min = distence[i][j];
							x = i;
							y = j;
						}
				}
			if(min==1001) break;
			road += min;
			distence[x][y] = 1001;
			parent[x] = y;
		}
		printf("%d\n", road);
	}
	return 1;
}