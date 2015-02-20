#include<stdio.h>
#include<math.h>

int main () {
	int		n,  i,  j,  d,  C=1, count, fla;
	int		X[1001],  Y[1001];
	double  r,  temp;
	double	max[1001],  min[1001];

	while(scanf("%d %d", &n, &d) && n!=0) {
		fla = 0;
		for(i=1; i<=n; i++) {
			scanf("%d %d", &X[i], &Y[i]);
			if(Y[i] > d) {fla=1; break;} 
			max[i] = X[i] + sqrt(d*d - Y[i]*Y[i]);
			min[i] = X[i] - sqrt(d*d - Y[i]*Y[i]);
		}

		if(fla==1){
				printf("Case %d: -1\n", C++);
				continue;
		}

		for(i=n; i>1; i--)
			for(j=1; j<i; j++)
				if(min[j] > min[j+1]) {
					temp = min[j];
					min[j] = min[j+1];
					min[j+1] = temp;
					temp = max[j];
					max[j] = max[j+1];
					max[j+1] = temp;
				}
		
		r = max[1];
		count=1;
		for(i=2; i<=n; i++) {
			if(min[i] > r) {
				r = max[i];
				count++;
			}
			else {
				if(max[i] < r)
					r = max[i];
			}
		}
		printf("Case %d: %d\n", C++, count);
			
	}
	return 1;
}