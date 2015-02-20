#include<stdio.h>

int main() {
	int		clock[10], a[10], i, j, fla,  min=19683, sum, b[10];
	for(i=1; i<=9; i++) 
		scanf("%d", &clock[i]);

	for(a[1]=0; a[1]<4; a[1]++)
	for(a[2]=0; a[2]<4; a[2]++)
	for(a[3]=0; a[3]<4; a[3]++)
	for(a[4]=0; a[4]<4; a[4]++)
	for(a[5]=0; a[5]<4; a[5]++)
	for(a[6]=0; a[6]<4; a[6]++)
	for(a[7]=0; a[7]<4; a[7]++)
	for(a[8]=0; a[8]<4; a[8]++)
	for(a[9]=0; a[9]<4; a[9]++) {
		if(	(clock[1]+a[1]+a[2]+a[4])%4==0 &&
			(clock[2]+a[1]+a[2]+a[3]+a[5])%4==0 &&
			(clock[3]+a[2]+a[3]+a[6])%4==0 &&
			(clock[4]+a[1]+a[4]+a[5]+a[7])%4==0 &&
			(clock[6]+a[1]+a[3]+a[5]+a[7]+a[9])%4==0 &&
			(clock[5]+a[3]+a[5]+a[6]+a[9])%4==0 &&
			(clock[7]+a[4]+a[7]+a[8])%4==0 &&
			(clock[8]+a[5]+a[7]+a[8]+a[9])%4==0 && 
			(clock[9]+a[6]+a[8]+a[9])%4==0     )   {

			for(sum=0, i=1; i<=9; i++)
				sum += a[i];
			if(sum < min) {
				min = sum;
				for(i=1; i<=9; i++)
					b[i] = a[i];
			}
		}

	}
	fla = 0;
	for(i=1; i<=9; i++)
		for(j=1; j<=b[i]; j++) {
			if(fla) printf(" ");
			fla = 1;
			printf("%d",i);
		}
	printf("\n");
	return 1;
}