#include<stdio.h>

int		parent[3000];
int		weight[3000];

int find(int x) {
	int		i;
	for(i=x; parent[i]>=0; i=parent[i]) 
		;
	return i;
}

int	calW(int x) {
	int		i,  sum=0;
	for(i=x; parent[i]>=0; i=parent[i]) 
		sum += weight[i];
	return sum;
}

void merge(int x, int y) {
	int		xP = find(x), yP=find(y);

	if( (calW(x) + calW(y)) %2==1 ) 
		weight[xP] = 0;
	else 
		weight[xP] = 1;

	parent[xP] = yP; 
	return;
}


int main() {
	int		i,  t,  n,  m, k,  isFind, a, b;
	
	scanf("%d", &t);
	for(k=1; k<=t; k++) {
		scanf("%d %d", &n, &m);
		for(i=0; i<2001; i++) {
			parent[i] = -1;
			weight[i] = 0;
		}

		isFind = 0;
		while(m--) {
			scanf("%d %d", &a, &b);
			if( find(a)!=find(b) ) 
				merge(a, b);
			else {
				if( (calW(a)+calW(b))%2==0 )
					isFind = 1;
			}
		}
		printf("Scenario #%d:\n", k);
		if(isFind==1) printf("Suspicious bugs found!\n\n");
		else printf("No suspicious bugs found!\n\n");
	}
	return 1;
}