#include<stdio.h>
#include<math.h>

int main () {
	int		n,  i,  j,  d,  C=1,  temp, count;
	int		X[1001],  Y[1001];
	double  r;
	double	max[1001],  min[1001];

	while(scanf("%d %d", &n, &d) && n!=0) {
		
		for(i=1; i<=n; i++) {
			scanf("%d %d", &X[i], &Y[i]);
			if(Y[i] > d) printf("Case %d: -1\n", C++);
		}

		for(i=n; i>1; i--)
			for(j=1; j<i; j++)
				if(X[j] > X[j+1]) {
					temp = X[j];
					X[j] = X[j+1];
					X[j+1] = temp;
					temp = Y[j];
					Y[j] = Y[j+1];
					Y[j+1] = temp;
				}

		for(i=1; i<=n; i++) {
			max[i] = X[i] + sqrt(d*d - Y[i]*Y[i]);
			min[i] = X[i] - sqrt(d*d - Y[i]*Y[i]);
		}
		
		r = max[1];
		count=1;
		for(i=2; i<=n; i++) {
			if(min[i] > r) {
				r = max[i];
				count++;
			}
		}
		printf("Case %d: %d\n", C++, count);
			
	}
	return 1;
}