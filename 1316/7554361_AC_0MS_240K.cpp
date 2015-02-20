#include<stdio.h>
#include<string.h>

int main() {
	int		n=1,  sum,  k,   flag[20001];

	memset(flag,  0,  sizeof(flag));
	
	for(n=1; n<10000; n++) {
		sum = k = n;
		while(k) {
			sum += k%10;
			k /= 10;
		}
		flag[sum]++;
	}
	for(n=1; n<10000; n++)
		if(flag[n]==0) printf("%d\n",n);
	return 1;
}