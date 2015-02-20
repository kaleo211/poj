#include<stdio.h>
#include<string.h>
int main() {
	int		n,  len, i;
	char	sum[1001];
	while(scanf("%s", sum)) {
		if(strcmp(sum,"0")==0) break;
		len = strlen(sum);

		n=0;
		for(i=0; i<len; i++)
			n += sum[i] - 48;
		n %= 9;
		n = (n==0)?9:n;
		printf("%I64d\n", n );
	}
	return 1;
}