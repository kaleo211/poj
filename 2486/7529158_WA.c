#include<stdio.h>
#include<string.h>

int		tree[101][101], visit[101], apple[101];
int		k, n, max;

int main() {
	int		 i,  a,  b;
	int		Q[101], rear, front;
	int		deep[101], sum[101], u;
	while(scanf("%d %d", &n, &k)!=EOF) {
		max = 0;
		memset(tree, 0, sizeof(tree));
		for(i=1; i<=n; i++)
			scanf("%d", &apple[i]);
		for(i=1; i<n; i++) {
			scanf("%d %d", &a, &b); 
			tree[a][b] = 1;
			tree[b][a] = 1;
		}
		rear = 1;	front = 0;
		Q[0] = 1;
		deep[1] = 0;
		sum[1] = apple[1];
		while(front!=rear) {
			u = Q[front++];
			for(i=1; i<=n; i++)
				if(tree[u][i]&&!visit[i]) {
					sum[i] = sum[u] + apple[i];
					deep[i] = deep[u] + 1;
					if(deep[i] >= k-1) {
						if(sum[i] > max) max = sum[i];
					}
					else if(deep[i] < k-1) {
						Q[rear++] = i;
					}
				}
			visit[u] = 1;
		}
		printf("%d\n", max);
	}
	return 1;
}