#include<stdio.h>

int main() {
	int		k, n, sum;
	while(scanf("%d %d", &n, &k) !=EOF) {
		sum = n;
		while(1) {
			sum += n/k;
			n = n%k + n/k;
			if(n<k) break;
		}
		printf("%d\n", sum);
	}
	return 0;
}