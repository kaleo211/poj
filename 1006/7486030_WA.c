#include<stdio.h>
#include<string.h>

int	max(int a, int b) {
	return a>b?a:b;
}

int	main () {
	int		i,  C=1, p, e, k, d;
	int		Time[21253];
		
	while(scanf("%d %d %d %d", &p, &e, &i, &d) && p!=-1) {
		memset(Time, 0, sizeof(Time));
		
		for(k=0; k<=924; k++) {
			p = (p+23)%21253;
			Time[p]++;
		}
		for(k=0; k<=759; k++) {
			e = (e+28)%21253;
			Time[e]++;
		}
		for(k=0; k<=644; k++) {
			i = (i+33)%21253;
			Time[i]++;
		}

		for(k=1,d++; ;k++, d = (d+1)%21253) {
			if(Time[d]>=3)		break;
		}

		printf("Case %d: the next triple peak occurs in %d days.\n", C++, k);
	}
	return 1;
}