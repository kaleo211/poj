#include<stdio.h>
#include<string.h>
int main () {
	int		t,  i, num[4];

	char	ip[33];
	scanf("%d", &t);
	while(t--) {
		scanf("%s", ip);
		memset(num, 0, sizeof(num));
		for(i=31; i>=0; i--) {
			if(ip[i]=='1') {
				num[i/8] += 1<<((31-i)%8);
			}
		}
		printf("%d", num[0]);
		for(i=1; i<4; i++) 
			printf(".%d",num[i]);
		printf("\n");
	}
	return 1;
}