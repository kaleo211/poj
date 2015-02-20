#include<stdio.h>
#include<string.h>

int		r, c;
int		map[101][101];
int		high[10001];
int		deep;
int		maxdeep;

int dfs(int i, int j, int deep) {

	if(i-1>=1 && map[i][j]>map[i-1][j]) {
		if(high[(i-2)*c+j]!=0) {
			if(deep + high[(i-2)*c+j] > maxdeep) maxdeep = deep + high[(i-2)*c+j];
		}
		else dfs(i-1, j, deep+1);
	}

	if(i+1<=r && map[i][j]>map[i+1][j]) {
		if(high[i*c+j]!=0) {
			if(deep + high[i*c+j] > maxdeep) maxdeep = deep + high[i*c+j];
		}
		else dfs(i+1, j, deep+1);
	}

	if(j-1>=1 && map[i][j]>map[i][j-1]) {
		if(high[(i-1)*c+j-1]!=0) {
			if(deep + high[(i-1)*c+j-1] > maxdeep) maxdeep = deep + high[(i-1)*c+j-1];
		}
		else dfs(i, j-1, deep+1);
	}

	if(j+1<=c && map[i][j]>map[i][j+1]) {
		if(high[(i-1)*c+j+1]!=0)  {
			if(deep + high[(i-1)*c+j+1] > maxdeep) maxdeep = deep + high[(i-1)*c+j+1];
		}
		else dfs(i, j+1, deep+1);
	}

	if(deep > maxdeep) maxdeep = deep;
	return 1;

}


int main () {
	int i, j, max;
	while(scanf("%d %d", &r, &c)!=EOF && r!=0) {

		for(i=1; i<=r; i++)
			for(j=1; j<=c; j++)
				scanf("%d" ,&map[i][j]);

		memset(high, 0, sizeof(high));
		for(i=1; i<=r; i++)
			for(j=1; j<=c; j++) {
				maxdeep = 0;
				dfs(i, j, 1);
				high[ (i-1)*c + j ] = maxdeep;
			}

		max = 0;
		for(i=1; i<=r*c; i++)
			if(max < high[i]) max = high[i];

		printf("%d\n",max);
	}
	return 1;
}