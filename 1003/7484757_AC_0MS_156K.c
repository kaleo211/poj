#include<stdio.h>

int main () {
	double		c, sum;
	int		i;
	while(scanf("%lf", &c) && c!=0) {
		sum = 0;
		for(i=1; sum<c;i++) 
			sum += (double)1/(i+1);
		printf("%d card(s)\n", i-1);
	}
	return 1;
}