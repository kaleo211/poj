#include<stdio.h>

int main () {
	unsigned int		t, r, x, y;

	scanf("%d", &t);
	while (t--) {

		scanf("%x,%d,%d",&r, &x, &y);

		r = ( ~(1<<x) ) & r;
		r = ( ~(1<<(y-2)) ) & r;
		r = ( 1<<(y-1) ) | r;
		r = ( 1<<y ) | r;
		printf("%x\n",r);
	}
	return 1;
}