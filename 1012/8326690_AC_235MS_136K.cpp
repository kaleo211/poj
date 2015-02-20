#include<stdio.h>
#include<string.h>
int main() {
	int		n, k, now, mount;
	bool		result;
	int		arr[15];
	memset(arr, 0, sizeof(arr));
	while(scanf("%d", &k) && k) {
		if(!arr[k]) {
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
						arr[k] = n;
						break;
					}
				}
				if(result)
					break;
			}
		}
		printf("%d\n", arr[k]);
	}
	return 0;
}