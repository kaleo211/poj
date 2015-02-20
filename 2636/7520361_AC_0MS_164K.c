#include<stdio.h>

int main() {
	int		t,  sum,  a,  n,  i;
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		sum = 0;
		i = n;
		while(n--) {
			scanf("%d", &a);
			sum += a;
		}
		printf("%d\n", sum-i+1);
	}
	return 1;
}