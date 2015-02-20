#include<stdio.h>

int main() {
	char	A[11], B[11],  i,  j, sum;
	while(scanf("%s %s", A, B)!=EOF) {
		sum = 0;
		for(i=0; A[i]!='\0'; i++)
			for(j=0; B[j]!='\0'; j++) 
				sum += (A[i]-48)*(B[j]-48);
		printf("%d\n", sum);
	}
	return 1;
}