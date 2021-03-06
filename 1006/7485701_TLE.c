#include<stdio.h>
#include<string.h>

int	max(int a, int b) {
	return a>b?a:b;
}

int	main () {
	int		i,  C=1, p, e, k, d;
	char	P[21253], E[21253], I[21253];
		
	while(scanf("%d %d %d %d", &p, &e, &i, &d) && p!=-1) {
		memset(P, 'n', sizeof(P));
		memset(E, 'n', sizeof(E));
		memset(I, 'n', sizeof(I));
		
		for(k=0; k<=925; k++) {
			p = (p+23)%21252;
			e = (e+28)%21252;
			i = (i+33)%21252;
			P[p] = 'y';
			E[e] = 'y';
			I[i] = 'y';
		}

		for(k=1,d++; ; k++, d = (d+1)%21252) {
			if(P[d]=='y' && E[d]=='y' && I[d]=='y')			break;
		}

		printf("Case %d: the next triple peak occurs in %d days.\n", C++, k);
	}
	return 1;
}