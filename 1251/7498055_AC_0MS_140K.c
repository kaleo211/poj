//

#include<stdio.h>

int	map[28][28];
int parent[28];


int find(int x) {
	int		i,  temp;
	for(i=x; parent[i]>=0; i=parent[i]) ;
	while(i!=x) {
		temp = parent[x];
		parent[x] = i;
		x = temp;
	}
	return i;
} 

int unio(int x, int y) {
	parent[x] = y;
	return 1;
}

int main() {
	int		n,  i,  j, leng,  m,  x,  y,  min,  count,  sum;
	char	a[3],  b[3];
	while(scanf("%d", &n) && n!=0) {
		
		for(i=0; i<28; i++)
			for(j=0; j<28; j++)
				map[i][j] = 101;
		
		for(i=0; i<n-1; i++) {
			scanf("%s %d", a, &m);
				while(m--) {
					scanf("%s %d", b, &leng);
					map[a[0]-65][b[0]-65] = leng;
					map[b[0]-65][a[0]-65] = leng;
				}
		}


		for(i=0; i<28; i++)
			parent[i] = -1;

		count = 0;
		sum = 0;
		while(1) {
			min = 101;
			for(i=0; i<n; i++)
				for(j=0; j<i; j++) 
					if(min > map[i][j])  {
						min = map[i][j];
						x = i;
						y = j;
					}
			map[x][y] = 101;
			if(find(x)!=find(y)) {
				sum += min;
				unio(find(x), find(y));
				count++;
				if(count==n-1) break;
			}
		}
		printf("%d\n", sum);

	}
	return 1;
}