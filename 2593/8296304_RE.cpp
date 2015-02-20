#include<stdio.h>
#define max(a,b) (a>b?a:b)

int main() {
	int		n, i;
	int		a[50002], dp1[50002], dp11[50002], dp2[50002];

	while(scanf("%d", &n) && n) {
		for(i=1; i<=n; i++)
			scanf("%d", &a[i]);
	
		dp1[0] = dp11[0] = -10001;
		for(i=1; i<=n; i++) {
			dp1[i] = max(a[i], dp1[i-1]+a[i]);
			dp11[i] = max(dp11[i-1], dp1[i]);
		}

		int result = -100001;
		dp2[1] = a[1];
		for(i=2; i<=n; i++) {
			dp2[i] = max(dp11[i-1], dp2[i-1]) + a[i];
			result = max(result, dp2[i]);
		}
		printf("%d\n", result);
	}
	return 0;
}