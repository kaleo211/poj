#include<stdio.h>
char	a[1000000], b[1000000];
int main() {
	int		n, i, plus;
	scanf("%d", &n);
	getchar();
	for(i=0; i<n; i++) {
		a[i] = getchar();
		getchar();
		b[i] = getchar();
		getchar();
	}

	plus=0;
	for(i=n-1; i>=0; i--) {
		a[i] += b[i]-48 + plus;
		plus = 0;
		if(a[i]>57) {
			a[i] -= 10;
			plus = 1;
		}
	}
	for(i=0; i<n; i++)
		putchar(a[i]);
	printf("\n");
	return 0;
}