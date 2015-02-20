#include<stdio.h>

int main() {
	int		i, fact=1;
	double	k=1;
	for(i=0; i<10; )	{
		if(i==0 || i==1) printf("%d %0.0lf\n", i, k);
		else if(i==2) printf("%d %0.1lf\n", i, k);
		else printf("%d %0.9lf\n", i, k);
		i++;
		fact *= i;
		k += 1.0/fact;
	}
}
