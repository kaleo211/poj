#include<stdio.h>

int	cal(int n) {
	int		sum=0;
	while(n) {
		sum += n%10;
		n /= 10;
	}
	if(sum<10) return sum;
	else return cal(sum);
	
}

int main() {
	int		n;
	while(scanf("%d", &n) && n) {
		printf("%d\n", cal(n));
	}
	return 1;
}