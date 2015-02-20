#include<stdio.h>
#include<string.h>

int	max(int a, int b) {
	return a>b?a:b;
}

int	main () {
	int		i,  C=1, p, e, k, fla, d;
	char	P[21253], E[21253], I[21253];
		
	while(scanf("%d %d %d %d", &p, &e, &i, &d) && p!=-1) {
		memset(P, 'n', sizeof(P));
		memset(E, 'n', sizeof(E));
		memset(I, 'n', sizeof(I));
		
		for(k=0; k<=924; k++) {
			p = (p+23)%21252;
			e = (e+28)%21252;
			i = (i+33)%21252;
			P[p] = 'y';
			E[e] = 'y';
			I[i] = 'y';
		}

		fla = 0;
		for(k=1,d++; d<=21252; k++, d++) {
			if(P[d]=='y' && E[d]=='y' && I[d]=='y')			{fla=1;break;}
		}
		if(fla==1)
			printf("Case %d: the next triple peak occurs in %d days.\n", C++, k);
		else 
			printf("Case %d: the next triple peak occurs in %d days.\n", C++, k-1);
	}
	return 1;
}