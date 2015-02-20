#include<stdio.h>
int main() {
	int		n, k, now, mount;
	bool		result;
	while(scanf("%d", &k) && k) {
		for(n=k+1; ;n++) {
			now = 1;
			mount = 2*k;
			while(1) {
				now = (now + n - 1)%mount--;
				if(now==0) now=mount+1;
				if(now<=k) {
					result=0;
					break;
				}
				if(mount==k) {
					result=1;
					break;
				}
			}
			if(result) {
				printf("%d\n", n);
				break;
			}
		}
	}
	return 0;
}