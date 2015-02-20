#include<stdio.h>
#include<string.h>

int		num[10000000];

int main () {
	int		n, i, sum,  j;
	char	a;

	char	tar[10];
	memset(num, 0, sizeof(num));
	scanf("%d", &n);
	scanf("%c", &a);
	for(i=1; i<=n; i++) {
		sum = 0;
		while(scanf("%c", &a) && a!=10) {
     			if(a<='9' && a>='0')		sum = sum*10 + a - 48;
			else if(a>='A' && a<='C')	sum = sum*10 + 2;
  			else if(a>='D' && a<='F')	sum = sum*10 + 3;
			else if(a>='G' && a<='I')	sum = sum*10 + 4;
			else if(a>='J' && a<='L')	sum = sum*10 + 5;
			else if(a>='M' && a<='O')	sum = sum*10 + 6;
			else if(a>='P' && a<='S' && a!='Q')	sum = sum*10 + 7;
			else if(a>='T' && a<='V')	sum = sum*10 + 8;
			else if(a>='W' && a<='Y')	sum = sum*10 + 9;
		}
		num[sum]++;
	}
	for(i=0; i<10000000; i++)
		if(num[i]>=2) {
			sum = i;
			j = 7;
			while(j>=0) {
				if(j!=3) {
					tar[j] = sum%10 + 48;
					sum /= 10;
				}
				else tar[j] = '-';
				j--;
			}
			tar[8] = '\0';
			printf("%s %d\n", tar, num[i]);
		}
	return 1;
}