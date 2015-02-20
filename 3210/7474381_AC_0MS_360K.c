#include<stdio.h>

int main () {
	int		n, x;
	while(scanf("%d", &n) && n!=0) {

		if(n%2==0) {printf("No Solution!\n");continue;}

		else			x = n - 1;

		printf("%d\n", x);
	}
	return 1;
}