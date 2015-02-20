#include<stdio.h>

int		num[100001];
int		left[100001], right[100001];


int main() {
	int		i, max,  n;
	while(scanf("%d", &n) && n!=0) {
		for(i=1; i<=n; i++) 
			scanf("%d", &num[i]);

		left[1] = num[1];
		for(i=2; i<=n; i++) {
			if(left[i-1] > 0) left[i] = left[i-1] + num[i];
			else left[i] = num[i];
		}
		max = left[1];
		for(i=2; i<=n; i++) {
			if(max > left[i]) left[i] = max;
			else	max = left[i];
		}

		right[n] = num[n];
		for(i=n-1; i>=1; i--) {
			if(right[i+1]>0) right[i] = right[i+1] + num[i];
			else right[i] = num[i];
		}	
		max = right[n];
		for(i=n-1; i>=1; i--) {
 			if(max > right[i]) right[i] = max;
			else max = right[i];
		}

		max = left[1] + right[2];
		for(i=2; i<=n-1; i++)
			if(left[i]+right[i+1] > max) max = left[i]+right[i+1];

		printf("%d\n", max);
	}
	return 1;
}