#include<stdio.h>

int main() {
	int		t,    x,  y;
	scanf("%d", &t);
	while(t--) {
		scanf("%d %d", &x, &y);
		if(x==y) {
			if(x%2==0) printf("%d\n", 2*x);
			else		printf("%d\n", 2*x-1);
			continue;
		}
		if(x==y+2) {
			if(x%2==0)	printf("%d\n",2*x-2);
			else		printf("%d\n",2*x-3);
			continue;
		}
		printf("No Number\n");
	}
	return 1;
}