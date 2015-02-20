#include<stdio.h>

int main() {
	int		count,  i,  j,  k;
	int		a[17];
	while(scanf("%d", &a[0]) && a[0]!=-1) {
		i = 1;
		count = 0;
		while(scanf("%d", &a[i]) && a[i++]) ;
		for(j=0; j<i; j++)
			for(k=j+1; k<i; k++)
				if((double)a[j]/a[k]==2 || (double)a[k]/a[j]==2)
					count++;
		printf("%d\n", count);
	}
	return 1;
}