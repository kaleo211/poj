#include<stdio.h>

int main() {
	int		n,  k,   count;
	while(scanf("%d",&n)!=EOF) {
		count = k = 1;
		k %= n;
		while(k) {
			count++;
			k = (k*10+1) % n;
		}
		printf("%d\n",count);
	}
	return 1;
}