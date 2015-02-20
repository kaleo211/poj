#include<stdio.h>

int main() {
	int		i, sum;
	char	a;
	while(scanf("%c", &a) && a!='#') {
		if(a==' ') sum = 0;
		else sum = a - 64;
		i = 1;
		while(scanf("%c", &a) && a!=10) {
			i++;
			if(a!=' ') {
				sum += i*(a-64);
			}
		}
		printf("%d\n", sum);
	}
	return 1;
}