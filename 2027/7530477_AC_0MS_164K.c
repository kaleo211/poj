#include<stdio.h>

int main() {
	int		n, a, b;
	scanf("%d", &n);
	while(n--) {
		scanf("%d %d", &a, &b);
		if(a<b) printf("NO BRAINS\n");
		else printf("MMM BRAINS\n");
	}
	return 1;
}