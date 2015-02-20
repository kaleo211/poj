#include<stdio.h>

int main() {
	int		i,  sum,  s;
	while(scanf("%d", &s)!=EOF) {
		sum = 0;
		for(i=1; ; i++) {
			sum += i;
			if(sum==s) break;
			else if(sum>s)
				if((sum-s)%2==0) break;
		}
		printf("%d\n",i);
	}
	return 1;
}