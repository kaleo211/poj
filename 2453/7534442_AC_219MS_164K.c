#include<stdio.h>
int main() {
	int		i,  j,  sum,  num,  n;
	while(scanf("%d", &n)&& n!=0) {
		sum = 0;
		for(i=0; i<21; i++)
			if((1<<i) & n) sum++;
		
		for(i=n+1; ;i++) {
			num = 0;
			for(j=0; j<21; j++) {
				if((1<<j) & i)	num++;
			}
			if(num==sum) {
				printf("%d\n", i);
				break;
			}
		}
		
	}
	return 1;
}