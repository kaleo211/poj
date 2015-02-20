#include<stdio.h>

int main() {
	int		t,  n,  i,   max,  a,  b;
	int		time[201];
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		for(i=0; i<201; i++)
			time[i] = 0;
		while(n--) {
			scanf("%d %d", &a, &b);
			a = (a+1)/2;
			b = (b+1)/2;
			for(i=a; i<=b; i++)
				time[i]++;
		}
		max = 0;
		for(i=1; i<=200; i++)
			if(max < time[i]) max = time[i];
		printf("%d\n", max*10);
	}
	return 1;
}