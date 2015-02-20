#include<stdio.h>

int		parent[100];


int	find(int x) {
	int		i, temp;
	for(i=x; parent[i]>=0; i = parent[i]);
	while(i!=x) {
		temp = parent[x];
		parent[x] = i;
		x = temp;
	}
	return i;
}

int	unio(int x, int y) {
	parent[find(x)] = find(y);
	return 1;
}

int main () {
	int		n, i, j;
	int		x, y, sum, min, count;	
	int		map[101][101];

	while(scanf("%d",&n)!=EOF) {

		for(i=1; i<=n; i++)
			parent[i] = -1;

		for(i=1; i<=n; i++)
			for(j=1; j<=n; j++)
				scanf("%d", &map[i][j]);

		count = 0;
		sum = 0;
		while(1){
			min = 100000;
			for(i=1; i<=n; i++)
				for(j=1; j<i; j++) 
					if(min>map[i][j]) {
						min = map[i][j];
						x = i;
						y = j;
					}
			map[x][y] = 100000;
			if(find(x)!=find(y)) {
				sum += min;
				unio(x, y);
				count++;
				if(count>=n-1) break;
			}
		}
		printf("%d\n", sum);

	}



	return 1;
}