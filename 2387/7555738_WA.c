#include<stdio.h>
#include<string.h>

int		map[1001][1001];

int main() {
	int		n,  t,  i,  u,  j,  front,  rear, len;
	int		Q[1001],  visit[1001], dis[1001];

	scanf("%d %d", &t, &n);
	memset(map, 0, sizeof(map));
	while(t--) {
		scanf("%d %d %d", &i, &j, &len);
		map[i][j] = len;
		map[j][i] = len;
	}

	memset(visit, 0, sizeof(visit));
	memset(dis, 0, sizeof(dis));
	Q[0] = n;
	rear = 1;
	front = 0;
	visit[n] = 1;
	while(rear!=front) {
		u = Q[front++];
		for(i=n; i>=1; i--) {
			if(map[u][i]) {
				if(dis[u]+map[u][i]<dis[i] || dis[i]==0) {
					dis[i] = dis[u] + map[u][i];
				}
				if(visit[i]==0) {
					Q[rear++] = i;
					visit[i] = 1;
				}
			}
		}
	}
	printf("%d\n", dis[1]);
	return 1;
}