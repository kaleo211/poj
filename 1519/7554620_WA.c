#include<stdio.h>

int main() {
	__int64		n,   sum;
	while(scanf("%I64d", &n) && n) {
		sum = 0;
		while(n) {
			sum += n%10;
			n /= 10;
		}
		sum %= 9;
		sum = (sum==0)?9:sum;
		printf("%I64d\n", sum );
	}
	return 1;
}