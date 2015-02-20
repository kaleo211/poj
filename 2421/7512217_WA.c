#include<stdio.h>

int		parent[101];


int	find(int x) {
	int		i, temp;
	for(i=x; parent[i]>=0; i=parent[i]) 
		;
	while(i!=x) {
		temp = parent[x];
		parent[x] = i;
		x = temp;
	}
	return i;
}

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
			unite(find(i), find(j));
		}
		
		road = 0;
		while(1) {
			min = 1001;
			for(i=2; i<=n; i++)
				for(j=1; j<i; j++) {
					if(parent[i]==-1 || parent[j]==-1)
						if(min > distence[i][j]) {
							min = distence[i][j];
							x = i;
							y = j;
						}
				}
			if(min==1001) break;
			road += min;
			unite(find(x), find(y));
		}
		printf("%d\n", road);
	}
	return 1;
}