#include<stdio.h>

int main() {
	int		A[12], B[12],  i,  j, sum, countA, countB, a, b;
	while(scanf("%d %d", &a, &b)!=EOF) {
		countA = countB = 0;
		while(a) {
			A[countA++] = a%10;
			a /= 10;
		}
		while(b) {
			B[countB++] = b%10;
			b /= 10;
		}

		sum = 0;
		for(i=0; i<countA; i++)
			for(j=0; j<countB; j++) 
				sum += A[i] * B[j];
		printf("%d\n", sum);
	}
	return 1;
}