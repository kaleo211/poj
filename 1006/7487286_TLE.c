#include<stdio.h>
#include<string.h>

int	main () {
	int		i,  C=1, p, e, k, d;
	int		Time[21253];
		
	while(scanf("%d %d %d %d", &p, &e, &i, &d)) {
		if(p==-1 && e==-1 && i==-1 && d==-1) break;
		memset(Time, 0, sizeof(Time));
		
		for(k=1; k<=924; k++) {
			p = (p+23)%21252;
			Time[p]++;
		}
		for(k=1; k<=759; k++) {
			e = (e+28)%21252;
			Time[e]++;
		}
		for(k=1; k<=644; k++) {
			i = (i+33)%21252;
			Time[i]++;
		}

		for(k=1,d++ ; ; k++, d = (d+1)%21252) {
			if(Time[d]>=3)		break;
		}

		printf("Case %d: the next triple peak occurs in %d days.\n", C++, k);
	}
	return 1;
}