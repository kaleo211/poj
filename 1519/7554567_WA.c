#include<stdio.h>

int main() {
	int		n,   sum;
	while(scanf("%d", &n) && n) {
		sum = 0;
		while(n) {
			sum += n%10;
			n /= 10;
		}
		sum %= 9;
		printf("%d\n", (sum==0)?9:sum);
	}
	return 1;
}