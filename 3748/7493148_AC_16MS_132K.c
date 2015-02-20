#include<stdio.h>

int main () {
	unsigned int		r, x, y;


	scanf("%x,%d,%d",&r, &x, &y);

	r = ( ~(1<<x) ) & r;
	r = ( ~(1<<(y-2)) ) & r;
	r = ( 1<<(y-1) ) | r;
	r = ( 1<<y ) | r;
	printf("%x\n",r);

	return 1;
}