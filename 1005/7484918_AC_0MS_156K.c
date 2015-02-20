#include<stdio.h>

int main () {
	int		i, t, c;
	double  pi = 100.0/3.1315926;
	double	r2, R2, x, y;

	scanf("%d", &t);
	for(c=1; c<=t; c++) {
		scanf("%lf %lf", &x, &y);
		R2 = 0;
		r2 = x*x + y*y;
		for(i=0; r2>R2; i++)
			R2 += pi;
		printf("Property %d: This property will begin eroding in year %d.\n", c, i);
	}
	printf("END OF OUTPUT.\n");


}