#include<stdio.h>
#include<math.h>

int main() {
	int		n, a, b, sub, step;
	scanf("%d", &n);
	while(n--) {
		scanf("%d %d", &a, &b);
		sub = b - a;
		step = (int)sqrt(sub);

		if(step==0)
			printf("0\n");
		else if(step*step==sub)
			printf("%d\n", 2*step-1);
		else if(step*step+step>=sub)
			printf("%d\n", 2*step);
		else 
			printf("%d\n", 2*step+1);
	}
	return 0;
}