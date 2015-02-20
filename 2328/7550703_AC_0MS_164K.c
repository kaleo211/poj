#include<stdio.h>
#include<string.h>
int main() {
	int		n,  max = 11,  min = 0;
	char	a[7],  b[7];
	while(scanf("%d", &n) && n) {
		scanf("%s %s",a, b);
		if(strcmp(b,"on")==0) {
			if(n<max && n>min) printf("Stan may be honest\n");
			else printf("Stan is dishonest\n");
			max = 11;
			min = 0;
		}
		else if(strcmp(b, "high")==0) {
			if(n < max)		max = n;
		}
		else if(strcmp(b,"low")==0) {
			if(n > min)		min = n;
		}
	}
	return 1;
}