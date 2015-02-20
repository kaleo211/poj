#include<stdio.h>
int main() {
	int		n, k;
	bool		result;
	while(scanf("%d", &k) && k) {
		for(n=k+1; ;n++) {
			int	now = 1;
			int	mount = 2*k;
			while(1) {
				now = (now + n - 1)%mount;
				if(now==0) now=mount;
				mount--;
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