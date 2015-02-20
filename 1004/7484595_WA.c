#include<stdio.h>

int main() {
	double	sum=0, a;
	int		i;

	for(i=1; i<=12; i++) {
		scanf("%lf", &a);
		sum += a;
	}

	printf("%0.2lf\n", sum/12);

	return 1;
}