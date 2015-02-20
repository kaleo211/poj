#include<stdio.h>
#include<math.h>
int main() {
	int		save, B, b,  n,  a,  i,  pre,  j;
	while(scanf("%d %d", &B, &n) && B!=0) {
		i = n-1;
		a = B;
		while(i) {
			a = (int)sqrt(a);
			i = i/2;
		}
		for(i=a; ; i++) {
			b = 1;
			for(j=1; j<=n; j++)
				b *= i;
			if(B<=b) {
				if(b-B + pre < 0)  save = i;
				break;
			}

			if(B>b) {
				pre = b - B;
				save = i;
			}
		}
		printf("%d\n", save);
	}
	return 1;
}