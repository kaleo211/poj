#include<stdio.h>
#include<math.h>

int main() {
	int		n, i, j;
	double	comb[101],  temp;

	while(scanf("%d", &n)!=EOF) {

		for(i=1; i<=n; i++)
			scanf("%lf",&comb[i]);

		for(i=n; i>1; i--)
			for(j=1; j<i; j++)
				if(comb[j]  > comb[j+1]) {
					temp = comb[j];
					comb[j] = comb[j+1];
					comb[j+1] = temp;
				}
	
		for(i=n-1; i>=1; i--)
			comb[i] = 2*sqrt(comb[i]*comb[i+1]);

		printf("%0.3lf\n", comb[1]);

	}
	return 1;
}