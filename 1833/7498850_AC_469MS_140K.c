#include<stdio.h>

int		num[1025];

int	swap(int i, int j) {
	int		temp;
	temp = num[i];
	num[i] = num[j];
	num[j] = temp;
	return 1;
}


int main () {
	int		m, i, n, k,  flaL,  flaR;

	scanf("%d", &m);
	while(m--) {
		scanf("%d %d", &n,  &k);
		for(i=1; i<=n; i++)
			scanf("%d", &num[i]);

		while(k--) {
			flaL = 0;
			for(i = n-1; i>=0; i--)
				if(num[i] < num[i+1]) {
					flaL = i;
					break;
				}
			if(i!=0) {
				for(i = n; i>=1; i--)
					if(num[i] > num[flaL]) {
						flaR = i;
						break;
					}
				swap(flaR, flaL);
			}
			for(i=1; i<=(n-flaL)/2; i++)
				swap(flaL+i, n-i+1);
		}
		printf("%d", num[1]);
		for(i=2; i<=n; i++)
			printf(" %d",num[i]);
		printf("\n");
	}
}