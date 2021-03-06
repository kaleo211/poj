#include<stdio.h>
#include<string.h>

int		trade[1003][1003];
int		parent[1003];
int		dis[1003];
char	visit[1003];
int		path[1003];

 
int main () {
	int		n,  i,  K, a, b, u, length;
	int		Q[1003],front, rear;
	
	while(scanf("%d %d", &n, &K)!=EOF) {
	
		memset(trade, 0, sizeof(trade));
		for(i=0; i<1001; i++) {
			parent[i] = -1;
			visit[i] = 'n';
			dis[i] = 0;
		}

		for(i=1; i<=n; i++) {
			scanf("%d %d",&a, &b);
			trade[a][b] = 1;
		}

		Q[0] = 1;
		front = 0;
		rear = 1;
		visit[1] = 'y';
		while(front < rear) {
			u = Q[front++];
			for(i=1; i<=K; i++) {
				if(visit[i]=='n' && trade[u][i]==1) {
					if(dis[i]==0) {
						dis[i] = dis[u] + 1;
						parent[i] = u;
					}
					visit[i] = 'y';
					Q[rear++] = i;
				}
			}
		}

		length = dis[K];
		if(length==0) {
			printf("%d\n",length-1);
		}
		else {
			printf("%d\n", dis[K]+1);

			for(i=K; i!=-1; i=parent[i] )
				path[length--] = i;
			
			for(i=0; i<=dis[K]; i++)
				printf("%d\n", path[i]);
		}
	}
}
