#include<cstdio>
#include<cstring>

int		map[1004][1004];
bool	visit[1004];
int		weight[1004];

int main() {
	int		N, i, j, m, n, now, front, tail;
	int		Queue[1004];
	scanf("%d", &N);
	for(int k=1; k<=N; k++) {
		scanf("%d %d", &n, &m);

		memset(map, 0, sizeof(map));
		memset(visit, 0, sizeof(visit));
		memset(weight, 0, sizeof(weight));

		for(int h=0; h<m; h++)  {
			scanf("%d %d", &i, &j);
			scanf("%d", &map[i-1][j-1]);
			map[j-1][i-1] = map[i-1][j-1];
		}
		Queue[0] = 0;
		front = 0;
		tail = 1;
		weight[0] = 1000000;
		while(front<tail) {
			now = Queue[front];
			for(i=0; i<n; i++)
				if(map[now][i] && (!visit[i])) {
					if(weight[i]<weight[now] && weight[i]<map[now][i])
						weight[i] = (map[now][i] < weight[now])?map[now][i]:weight[now];
					if(!weight[i])
						Queue[tail++] = i;
				}
			visit[now] = true;
			front++;
		}
		printf("Scenario #%d:\n%d\n",k, weight[n-1]);
	}
	return 0;
}