#include<stdio.h>
#include<string.h>
int main() {
	int		i, n, j, m, t;
	int		value[21], obj[21];
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		for(i=1, value[0]=0; i<=n; i++) {
			scanf("%d", &value[i]);
			obj[i] = value[i] - value[i-1];
		}
		for(i=1; i<=n; i++) {
			int pos = i;
			while(pos>0) {
				if(obj[pos]>0) {
					obj[pos]--;
					if(i!=1) printf(" ");
					printf("%d", i-pos+1);
					break;
				}
				pos--;
			}
		}
		printf("\n");
	}
	return 0;
}