#include<stdio.h>
#include<string.h>

char	map[101][101];
int		visit[101][101];
int		w,  h;

int	dfs(int x, int y) {
	int		i,  j;
	visit[x][y] = 1;
	for(i=-1; i<=1; i++)
		for(j=-1; j<=1; j++)
			if(x+i<=h&&x+i>=1 && y+j>=1&&y+j<=w)
				if(visit[x+i][y+j]==0 && map[x+i][y+j] =='W')
					dfs(x+i, y+j);
	return 1;
}


int main() {
	int		i,  j,  sum;
	char	a;
	while(scanf("%d %d", &h, &w)!=EOF) {
		scanf("%c", &a);
		for(i=1; i<=h; i++) {
			for(j=1; j<=w; j++)
				scanf("%c", &map[i][j]);
			scanf("%c", &a);
		}
		sum=0;
		memset(visit, 0, sizeof(visit));
		for(i=1; i<=h; i++)
			for(j=1; j<=w; j++)
				if(map[i][j]=='W' && visit[i][j]==0) {
					sum++;
					dfs(i, j);
				}
		printf("%d\n", sum);
	}
}