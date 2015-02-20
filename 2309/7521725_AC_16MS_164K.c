#include<stdio.h>

int main() {
	int		t,  n,  k,  i;
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		k = 1;
		for(i=0; ; i++)
			if((n & (1<<i))==0) k = 1<<(i+1);
			else break;
		printf("%d %d\n", n-k+1, n+k-1);
	}
	return 1;
}