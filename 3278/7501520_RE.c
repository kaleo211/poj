#include<stdio.h>

int main() {
	int		n,  k,  i,  u;
	int		Q[100001],  front, rear;
	int		time[100001];
	while(scanf("%d %d", &n, &k)!=EOF) {
		if(n>=k) {printf("%d\n", n-k);continue;}

		front = 0;
		rear = 1;
		Q[0] = n;
		for(i=0; i<100001; i++)
			time[i] = 100001;
		time[n] = 0;

		while(front!=rear) {
			u = Q[front++];
			if(u==k) break;
			for(i=1; i<=3; i++) {
				if(i==1 && time[u*2] > time[u] + 1) {
					time[u*2] = time[u] + 1; 
					Q[rear++] = u*2;
				}
				else if(i==2 && time[u+1]>time[u] + 1) {
					time[u+1] = time[u] + 1; 
					Q[rear++] = u + 1;
				}
				else if(i==3 && time[u-1]>time[u] + 1) {
					time[u-1] = time[u] + 1; 
					Q[rear++] = u - 1;
				}
			}
		}

		printf("%d\n", time[k]);
		
	}
}