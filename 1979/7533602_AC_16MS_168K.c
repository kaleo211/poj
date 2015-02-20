#include<stdio.h>
#include<string.h>
int		visit[21][21];
char	map[21][21];
int		sum,  h,  w;
int dfs(int	i, int j) {
	visit[i][j] = 1;
	sum++;
	if(i+1<=h && map[i+1][j]=='.' && visit[i+1][j]==0)
		dfs(i+1, j);
	if(i-1>=1 && map[i-1][j]=='.' && visit[i-1][j]==0)
		dfs(i-1, j);
	if(j+1<=w && map[i][j+1]=='.' && visit[i][j+1]==0)
		dfs(i, j+1);
	if(j-1>=1 && map[i][j-1]=='.' && visit[i][j-1]==0)
		dfs(i, j-1);
	return 1;
}

int main() {
	int		i,   j,  x,  y;
	char	a;
	while(scanf("%d %d", &w, &h) && h!=0) {
		scanf("%c", &a);
		for(i=1; i<=h; i++) {
			for(j=1; j<=w; j++) {
				scanf("%c", &map[i][j]);
				if(map[i][j]=='@') {
					x=i;
					y=j;
				}
			}
			scanf("%c", &a);
		}
		memset(visit, 0, sizeof(visit));
		sum = 0;
		dfs(x, y);
		printf("%d\n", sum);
	}
	return 1;
}