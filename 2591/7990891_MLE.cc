#include<stdio.h>

__int64		save[10000005];

int main() {
	int		n, a, b, i;

	save[1] = 1;
	a = b = 1;

	for(i=2; i<=10000000; i++) {
		if(2*save[a] < 3*save[b]) 
			save[i] = save[a++]*2 + 1;

		else if(2*save[a] > 3*save[b])
			save[i] = save[b++]*3 + 1;
		else {
			save[i] = save[b++]*3 + 1;
			a++;
		}
	}

	while(scanf("%d", &n)!=EOF) {
		printf("%I64d\n", save[n]);
	}
	return 0;
}
