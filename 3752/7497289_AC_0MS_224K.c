#include<stdio.h>
#include<string.h>

char	map[300][300];
char	now;
int		m, n;

int dfs(int i, int j, int direc) {
	if(map[i][j]!='n') return 1;
	map[i][j] = now;
	now = (now+1)%26;
	if( direc==1 ) {
		if(j+1<=n && map[i][j+1]=='n') 
			dfs(i, j+1, 1);
		else dfs(i+1, j, 2);
	}
	else if(direc==2) {
		if(i+1<=m &&map[i+1][j]=='n')
			dfs(i+1, j, 2);
		else dfs(i, j-1, 3);
	}
	else if(direc==3) {
		if(j-1>=1 && map[i][j-1]=='n')
			dfs(i, j-1, 3);
		else dfs(i-1, j, 4);
	}
	else if(direc==4) {
		if(i-1>=1 && map[i-1][j]=='n')
			dfs(i-1, j, 4);
		else dfs(i, j+1, 1);
	}
	return 1;
}

int main() {
	int		i, j;
	while (scanf("%d %d", &m, &n)!=EOF) {
		memset(map, 'n', sizeof(map));
		dfs(1, 1, 1);
		now = 0;
		for(i=1; i<=m; i++) {
			for(j=1; j<=n; j++)
				printf("   %c", map[i][j]+65);
			printf("\n");
		}
	}
}